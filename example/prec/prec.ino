#include <dtostrg.h>

double number;
char buff[31];

#ifdef DTOSTR_D
void debug_print(char *msg, double d) {
  Serial.print(msg);
  Serial.println(d);
}
#endif

void setup() {
  // put your setup code here, to run once:

  char width = 29;
  long startt;

  Serial.begin(115200);

  number = 1234.567890123456789;
  Serial.println("number: 1234.567890123456789");

  for (char prec = 0; prec < 29; prec++) {
    Serial.println((int)prec);
    Serial.println(dtostrg(number, width, prec, buff));
    Serial.print(dtostrg(-number, width, prec, buff));
    startt=millis();
    for(int i=0;i<1000;i++){
      dtostrg(number, width, prec, buff);
    }
    startt=millis()-startt;
    Serial.print('\t');
    Serial.println(startt/1000.);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print('#');
  delay(1000);

}
