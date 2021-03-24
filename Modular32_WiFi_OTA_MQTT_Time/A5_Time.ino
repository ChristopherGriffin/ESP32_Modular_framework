
struct tm timeinfo; //place to store time

//This gets the time and applies local offsets
void Get_time(){
  
configTime((gmtOffset_hour * 3600), (daylightOffset_hour * 3600), ntpServer); //get time and fix it for local area

if(!getLocalTime(&timeinfo)){ //did it work?
    Serial.println("Failed to obtain time");
    return;
  }
}
