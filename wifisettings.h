const char *ssid = "aamakelab";
const char *pass = "aamakelab";

int device_id = -1;

WiFiUDP Udp;                                // A UDP instance to let us send and receive packets over UDP
const IPAddress dest(192, 168, 8, 202);
const unsigned int rxport = 54321;          // receive OSC
const unsigned int txport = 12345;        // transmit OSC
IPAddress thisip;

