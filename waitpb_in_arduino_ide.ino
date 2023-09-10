#include <waitpb.h>
waitpb w(5,6,7,2000);
//waitpb w1(2,3,4);

void setup() {
  // put your setup code here, to run once:
w.begin();
//w1.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
w.waitms();
//w1.waitms(3);
}
