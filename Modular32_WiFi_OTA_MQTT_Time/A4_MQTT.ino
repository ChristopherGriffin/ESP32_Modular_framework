/*Libraries needed
 * 
 */
  
#include <ArduinoMqttClient.h> //For MQTT


MqttClient mqttClient(wifiClient); //attach the MQTT client to the wificlient instance

void MQTT_setup(){

  Serial.print("Attempting to connect to the MQTT server: ");
  Serial.print(mqtt_server);
  Serial.print(" at port ");
  Serial.println(mqtt_port);


  if (!mqttClient.connect(mqtt_server, mqtt_port)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());

  }
  
  if (mqttClient.connect(mqtt_server, mqtt_port)) {
  Serial.println("You're connected to the MQTT server!");
  Serial.println();
  }
}


void MQTT_loop(){
  if (mqttClient.connect(mqtt_server, mqtt_port) == 1){   //for MQTT connection persistance
   mqttClient.poll();
   mqttClient.beginMessage(topic);
    mqttClient.endMessage();
    //delay(1000);
    }else{
      Serial.println ("Reconnecting to MQTT");
      MQTT_setup();
    }
  }
