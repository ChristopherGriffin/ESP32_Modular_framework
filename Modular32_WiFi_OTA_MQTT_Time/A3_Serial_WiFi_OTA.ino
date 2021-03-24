/*Libraries needed
 * 
 */
#include <WiFi.h>
#include <ArduinoOTA.h>


/*Setup
 * 
 */
//Serial
void Serial_setup()
{
Serial.begin(baud);
Serial.println("");
Serial.print(host_name);
Serial.print(" built on ");
Serial.print(compile_date);
Serial.println("\r\nBooting...");

}

//WiFi
WiFiClient wifiClient; //initialize the wifi client library
int wifisetupdelay = 0;
void WiFi_setup()
{ 
  if (WiFi.status() != WL_CONNECTED) {  //if WiFi isnt connected
  // Connect to WiFi
  Serial.print("Connecting to ");
  Serial.println(wifi_ssid);
  WiFi.begin(wifi_ssid, wifi_psk);
  WiFi.setHostname(host_name);
  //delay(2000);
 
  while ((WiFi.status() != WL_CONNECTED) && (wifisetupdelay <= 10))
  {
     delay(500);
     Serial.print("*");
     wifisetupdelay++;
  }

 /* 
  Serial.println("");
  Serial.println("WiFi connection Successful");
  Serial.print("The IP Address of ");
  Serial.print(WiFi.getHostname());
  Serial.print(" is ");
  Serial.println(WiFi.localIP());// Print the IP address
 */
}
}
//print status of wifi
void printWLANStatus()
{
  if  (WiFi.status() == WL_CONNECTED){
  // Print the ESP32's MAC address
  Serial.print("Hostname: ");
  Serial.println(WiFi.getHostname());
  Serial.print("MAC address: ");
  Serial.println(WiFi.macAddress());

  // Print the SSID of the WLAN network connected to
  Serial.print("Connected to SSID: ");
  Serial.println(WiFi.SSID());

  // Print the ESP32's IP address assigned by the router
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Print the router's subnet mask, usually 255.255.255.0
  Serial.print("Subnet mask: ");
  Serial.println((IPAddress)WiFi.subnetMask());

  // Print the rounter's IP address
  Serial.print("Gateway IP: ");
  Serial.println((IPAddress)WiFi.gatewayIP());

  // Print the WLAN router's signal strength received
  long rssi = WiFi.RSSI();
  Serial.print("Signal strength (RSSI): ");
  Serial.print(rssi);
  Serial.println(" dBm");
  }
}




void OTA_setup()
{
  ArduinoOTA.setHostname(host_name);
  ArduinoOTA.setPort(ota_port);
     ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else { // U_FS
      type = "filesystem";
    }

    // NOTE: if updating FS this would be the place to unmount FS using FS.end()
    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Serial.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      Serial.println("End Failed");
    }
  });
  ArduinoOTA.begin();
  Serial.print("OTA Ready at ");
  Serial.print("IP address: ");
  Serial.print(WiFi.localIP());
  Serial.print(":");
  Serial.println(ota_port);
}

/*Loops
 * 
 */

void OTA_loop()
{
//  if (WiFi.status() != WL_CONNECTED){ 
//      WiFi.begin(wifi_ssid, wifi_psk);

//      while (WiFi.status() != WL_CONNECTED) 
//      {
//          delay(500);
//          Serial.print("*");
//      }
//  }
   ArduinoOTA.handle(); 
}
