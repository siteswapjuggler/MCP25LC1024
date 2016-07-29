#include <SPI.h>
#include <MC25LC1024.h>

byte buffer[256];
byte datas[256];
MC25LC1024 eeprom(10);

void setup() {
  Serial.begin(115200);
  for (int i=0;i<256;i++) {
    buffer[i]=i;
    }
  eeprom.writeArray(0,buffer,256);   
  }

void loop() {
  eeprom.readArray(0,datas,256);
  for (int i=0;i<256;i++) {
    Serial.print(datas[i]);
    Serial.print("\t");
    }
  Serial.println();
  delay(1000);
  }
