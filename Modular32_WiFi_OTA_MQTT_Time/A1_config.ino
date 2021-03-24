// configurable constants



//Serial Port
const int     baud         = 115200;

//WiFi Cred
const char    wifi_ssid[]  = "";
const char    wifi_psk[]   = "";
const char    dhcpfail_address[]= "192.168.1.2";

//Hostname
const char    host_name[]  = "ESP32";

//OTA port user pass
const int     ota_port     = 3232;
//const char    ota_user[]   = "otausername";
//const char    ota_pass[]   = "otapassword";

//MQTT IP port and Cred
const char    mqtt_server[]= "";
const int     mqtt_port    = 1883;
//const char  mqtt_user[]  = "mqttuser";
//const int   mqtt_pass[]  = "mqttpass";
const char    topic[]      = "project/";

//NTP
const char* ntpServer               = "pool.ntp.org";  // Use random servers through DNS
const char  ntpfallbackServer[]     = "132.163.97.6"; // time.nist.gov NTP server (fallback)
const long  gmtOffset_hour          = -6;
const bool   daylightOffset_hour    =  1;

//Test String 
String HelloWorld = "Hello World";  
