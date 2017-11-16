#include <dtostrg.h>

double number;
char buff[30];

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  number = 0;
  number = 1 / number;
  Serial.println("10 10");
  Serial.println(dtostrg(number, 10, 10, buff));
  Serial.println(dtostrg(-number, -10, 10, buff));


  number = 1234.567890;
  Serial.println();
  Serial.println("10 10");
  Serial.println(dtostrg(number, 10, 10, buff));
  Serial.println(dtostrg(-number, 10, 10, buff));

  Serial.println();
  Serial.println("10 5");
  Serial.println(dtostrg(number, 10, 5, buff));
  Serial.println(dtostrg(number, -10, 5, buff));
  Serial.println(dtostrg(-number, 10, 5, buff));
  Serial.println(dtostrg(-number, -10, 5, buff));

  Serial.println();
  Serial.println("10 3");
  Serial.println(dtostrg(number, 10, 3, buff));
  Serial.println(dtostrg(-number, 10, 3, buff));

  number = 1.234567890e-3;
  Serial.println();
  Serial.println("10 10");
  Serial.println(dtostrg(number, 10, 10, buff));
  Serial.println(dtostrg(-number, 10, 10, buff));

  Serial.println();
  Serial.println("10 3");
  Serial.println(dtostrg(number, 10, 3, buff));
  Serial.println(dtostrg(number, -10, 3, buff));
  Serial.println(dtostrg(-number, 10, 3, buff));
  Serial.println(dtostrg(-number, -10, 3, buff));


  number = 1.234567890e-11;
  Serial.println();
  Serial.println("10 10");
  Serial.println(dtostrg(number, 10, 10, buff));
  Serial.println(dtostrg(-number, 10, 10, buff));

  Serial.println();
  Serial.println("10 3");
  Serial.println(dtostrg(number, 10, 3, buff));
  Serial.println(dtostrg(-number, 10, 3, buff));

  number = 1.234567890e11;
  Serial.println();
  Serial.println("10 10");
  Serial.println(dtostrg(number, 10, 10, buff));
  Serial.println(dtostrg(-number, 10, 10, buff));

  Serial.println();
  Serial.println("10 3");
  Serial.println(dtostrg(number, 10, 3, buff));
  Serial.println(dtostrg(number, -10, 3, buff));
  Serial.println(dtostrg(-number, 10, 3, buff));
  Serial.println(dtostrg(-number, -10, 3, buff));

  number = 0;
  Serial.println();
  Serial.println("10 15");
  Serial.println(dtostrg(number, 10, 15, buff));
  Serial.println(dtostrg(-number, 10, 15, buff));

  number = 1;
  Serial.println("10 10");
  Serial.println(dtostrg(number, 10, 10, buff));
  Serial.println(dtostrg(-number, 10, 10, buff));
}

void loop() {
  // put your main code here, to run repeatedly:

}
