
void pinSetup()
{
  pinMode(16, OUTPUT);  //Demonstration pin
}

/*
 * 
 * https://components101.com/microcontrollers/esp32-devkitc
 * https://components101.com/sites/default/files/component_pin/ESP32-Pinout.png
      ------------
 3.3v-|          |-
   EN-|          |-
  SVP-|          |-
  SVN-|          |-
 IO34-|          |-
 IO35-|          |-
 IO32-|          |-
 IO33-|          |-
 IO25-|          |-
 IO26-|          |-
 IO27-|          |-GPIO18
 IO14-|          |-GPIO5
 IO12-|          |-GPIO17  - night button input
  GND-|          |-GPIO16  - light output
 IO13-|          |-GPIO4
  SD2-|          |-IO15
  SD3-|          |-SD1
  GND-|          |-SD0
   5v-|          |-CLK
      ----OOOO----

*/
