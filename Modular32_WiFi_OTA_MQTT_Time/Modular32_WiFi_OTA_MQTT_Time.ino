


const char compile_date[] = __DATE__;
long previousMillis = 0;
int oneSecond = 1000;

void setup() {
Serial_setup(); 
WiFi_setup();
printWLANStatus();
OTA_setup();
MQTT_setup();
Get_time();
pinSetup(); 
}

void loop() {
  unsigned long currentMillis = millis();  //**THIS IS YOUR ONE SECOND LOOP**//
  if(currentMillis - previousMillis > oneSecond) {
    //run code 
    WiFi_setup(); //Am I still connected to WiFi, if not fix it
    MQTT_loop(); //Am I still connected to MQTT, if not fix it
    OTA_loop(); //Any new software for me?
    Test_outputs(); //Tests from A6
    previousMillis = currentMillis;
  }
  



}
