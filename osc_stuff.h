Metro alive = Metro(5000);


void state_loop() {
  // send alive ACK message to show-control
  if(alive.check()) {
    Serial.println("SENDING ACK");
    OSCMessage out("/node/ack");
    out.add( device_id );
    Udp.beginPacket(dest, txport);
    out.send(Udp);
    Udp.endPacket();
    out.empty();
  }
}

void on_gradient(OSCMessage &msg, int addrOffset) {
  Serial.println(">> CMD: gradient");
  // CHANGE THE LED VALUES AND DO FASTLED.SHOW()
}

void on_testpattern(OSCMessage &msg, int addrOffset) {
  Serial.println(">> CMD: test pattern");
}

void on_solid(OSCMessage &msg, int addrOffset) {
  Serial.println(">> CMD: solid");
}

void on_pixels(OSCMessage &msg, int addrOffset) {
  Serial.println(">> CMD: pixels");
}

void on_off(OSCMessage &msg, int addrOffset) {
  Serial.println(">> CMD: OFF");
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
    }
  } // if
}

