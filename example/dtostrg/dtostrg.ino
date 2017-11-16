#include <dtostrg.h>

double number;
char buff[30];

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  number=1234.567890;
  Serial.println("10 10");
  dtostrg(number,10,10,buff);
  Serial.println(buff);
  dtostrg(-number,10,10,buff);
  Serial.println(buff);

  Serial.println();
  Serial.println("10 5");
  dtostrg(number,10,5,buff);
  Serial.println(buff);
  dtostrg(number,-10,5,buff);
  Serial.println(buff);
  dtostrg(-number,10,5,buff);
  Serial.println(buff);
  dtostrg(-number,-10,5,buff);
  Serial.println(buff);

  Serial.println();
  Serial.println("10 3");
  dtostrg(number,10,3,buff);
  Serial.println(buff);
  dtostrg(-number,10,3,buff);
  Serial.println(buff);

  number=1.234567890e-100;
  Serial.println();
  Serial.println("10 10");
  dtostrg(number,10,10,buff);
  Serial.println(buff);
  dtostrg(-number,10,10,buff);
  Serial.println(buff);
  
  dtostrg(number,10,3,buff);
  Serial.println();
  Serial.println("10 3");
  Serial.println(buff);
  dtostrg(-number,10,3,buff);
  Serial.println(buff);

  number=1.234567890e11;
  dtostrg(number,10,10,buff);
  Serial.println();
  Serial.println("10 10");
  Serial.println(buff);
  dtostrg(-number,10,10,buff);
  Serial.println(buff);

  Serial.println();
  Serial.println("10 3");
  dtostrg(number,10,3,buff);
  Serial.println(buff);
  dtostrg(number,-10,3,buff);
  Serial.println(buff);
  dtostrg(-number,10,3,buff);
  Serial.println(buff);  
  dtostrg(-number,-10,3,buff);
  Serial.println(buff);  

  number=0;
  dtostrg(number,10,15,buff);
  Serial.println();
  Serial.println("10 15");
  Serial.println(buff);
  dtostrg(-number,10,15,buff);
  Serial.println(buff);

  number=1;
  Serial.println("10 10");
  dtostrg(number,10,10,buff);
  Serial.println(buff);
  dtostrg(-number,10,10,buff);
  Serial.println(buff);
}

void loop() {
  // put your main code here, to run repeatedly:

}
