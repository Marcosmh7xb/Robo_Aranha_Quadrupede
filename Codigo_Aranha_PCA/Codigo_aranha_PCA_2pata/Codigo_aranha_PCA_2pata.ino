#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <NewPing.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 150   // pulso mínimo (~1ms)
#define SERVOMAX 600   // pulso máximo (~2ms)
#define PinEcho 1
#define PinTrig 2
#define MaxDis 200

int graus[] = {30, 60, 90, 120, 160, 180};

int tempo = 400;

NewPing SerUt(PinEcho, PinTrig, MaxDis);

void setup() {
  pwm.begin();
  pwm.setPWMFreq(50);  // 50Hz padrão para servos
  
}

void centralizar(){
  
  for(int servoMoto = 1; servoMoto <= 8; ++servoMoto){
    int pulse = map(graus[2], 0, 180, SERVOMIN, SERVOMAX);
    pwm.setPWM(servoMoto, 0, pulse);
    delay(300);
  } 
}

void anda(){

  // Pata trazeira esqueda| Pata dianteira direita
  int pulse = map(graus[2], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(2,0, pulse);
  pwm.setPWM(8,0, pulse);
  delay(tempo);
  
  pulse = map(graus[2], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(1, 0, pulse);
  pulse = map(graus[4], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(7, 0, pulse);
  delay(tempo);
 
  pulse = map(graus[6], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(2,0, pulse);
  pulse = map(graus[0], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(8,0, pulse);
  delay(tempo);
  
  pulse = map(graus[3], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(1,0, pulse);
  pwm.setPWM(7,0, pulse);
  delay(tempo);


  // Pata dianteira esqueda | Pata trazeira direita
  pulse = map(graus[3], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(4,0, pulse);
  pulse = map(graus[2], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(6,0, pulse);
  delay(tempo);
  
  pulse = map(graus[2], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(3, 0, pulse);
  pulse = map(graus[4], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(5,0, pulse);
  delay(tempo);
 
  pulse = map(graus[6], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(4,0, pulse);
  pulse = map(graus[0], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(6,0, pulse);
  delay(tempo);

  pulse = map(graus[3], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(3, 0, pulse);
  pwm.setPWM(5,0, pulse);
  delay(tempo);

}
void loop() {
 anda();
}
