const char *ssid = "aamakelab";
const char *pass = "aamakelab";

int device_id = -1;

WiFiUDP Udp;                                // A UDP instance to let us send and receive packets over UDP
//const IPAddress dest(192, 168, 8, 100);
const IPAddress dest(10, 0, 0, 2);
const unsigned int rxport = 54321;          // remote port to receive OSC
const unsigned int txport = 12345;        // local port to listen for OSC packets (actually not used for sending)
IPAddress thisip;

