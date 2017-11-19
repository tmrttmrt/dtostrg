#include <dtostrg.h>

double number;
char buff[30];

#ifdef DTOSTR_D
void debug_print(char *msg, double d) {
  Serial.print(msg);
  Serial.println(d);
}
#endif
void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  number = 1234.567890123456789;
  Serial.println();
  Serial.println("10 3: 1234.567890123456789");
  Serial.println("10 3");
  Serial.println(dtostrg(number, 10, 3, buff));
  Serial.println(dtostrg(number, -10, 3, buff));
  Serial.println(dtostrg(-number, 10, 3, buff));
  Serial.println(dtostrg(-number, -10, 3, buff));

}

void loop() {
  // put your main code here, to run repeatedly:

}
