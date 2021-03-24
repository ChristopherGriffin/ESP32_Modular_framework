
//These are for the purpose of testing functions and verify they are correct.
//Comment out all or the ones you do not need
void Test_outputs(){ 
 mqttClient.print(HelloWorld);
 Serial.println (HelloWorld);
 Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}
