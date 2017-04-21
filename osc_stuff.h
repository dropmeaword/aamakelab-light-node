Metro alive = Metro(5000);


void state_loop() {
  // send alive ACK message to show-control
  if(alive.check()) {
//    Serial.println("SENDING ACK");
    OSCMessage out("/node/ack");
    out.add( device_id );
    Udp.beginPacket(dest, txport);
    out.send(Udp);
    Udp.endPacket();
    out.empty();
  }
}

void on_gradient(OSCMessage &msg, int addrOffset) {
  CRGB a, b;

  a.r = msg.getInt(0);
  a.g = msg.getInt(1);
  a.b = msg.getInt(2);

  b.r = msg.getInt(3);
  b.g = msg.getInt(4);
  b.b = msg.getInt(5);

  Serial.print("[");
  Serial.print(a.r);
  Serial.print(",");
  Serial.print(a.g);
  Serial.print(",");
  Serial.print(a.b);
  Serial.print("] -> [");
  Serial.print(b.r);
  Serial.print(",");
  Serial.print(b.g);
  Serial.print(",");
  Serial.print(b.b);
  Serial.println("]");
//  Serial.println("[" + a.r + ", " + a.g + ", " +  a.b + "]"); // -> ["+ b.r +", " + b.g + ", " + b.b + "]");

  paint_gradient(a, b);
}

void on_testpattern(OSCMessage &msg, int addrOffset) {
  paint_testpattern();
}

void on_solid(OSCMessage &msg, int addrOffset) {
  CRGB inc;
  
  if( msg.isInt(0) && msg.isInt(1) && msg.isInt(2) ) {
    inc.r = msg.getInt(0);
    inc.g = msg.getInt(1);
    inc.b = msg.getInt(2);
    paint_one_color( inc );
  }
}

void on_pixels(OSCMessage &msg, int addrOffset) {
}

void on_off(OSCMessage &msg, int addrOffset) {
  paint_one_color( CRGB::Black );
}

void osc_message_pump() {
  OSCMessage in;
  int size;

  if( (size = Udp.parsePacket()) > 0)
  {
    Serial.println("processing OSC package");
    // parse incoming OSC message
    while(size--) {
      in.fill( Udp.read() );
    }

    if(!in.hasError()) {
      in.route("/node/gradient", on_gradient);  // r,g,b,r,g,b
      in.route("/node/solid", on_solid);   // r,g,b
      in.route("/node/testpattern", on_testpattern);   // <void>
      in.route("/node/pixels", on_pixels);   // [r,g,b x 36]
      in.route("/node/off", on_off); // <void>
    } else {
      Serial.println("message has an error");
    }
  } // if
}

