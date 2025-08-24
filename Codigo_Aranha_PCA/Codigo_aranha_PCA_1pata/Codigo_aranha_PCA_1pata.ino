#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <NewPing.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 150   // pulso mínimo (~1ms)
#define SERVOMAX 600   // pulso máximo (~2ms)
#define PinEcho A1
#define PinTrig A0
#define MaxDis 200

int tempo = 100;
int pulse;
int graus[] = {0, 30, 60, 90, 120, 160, 180};
NewPing sensorUltra(PinTrig, PinEcho, MaxDis);

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50);  // 50Hz padrão para servos
  
  Wire.begin();
  // Define a taxa de comunicação I2C para 400 kHz (fast mode)
  Wire.setClock(400000);
}

void centralizar(){
  
  for(int servoMoto = 1; servoMoto<= 8; servoMoto += 2){
    int pulse = map(graus[3], 0, 180, SERVOMIN, SERVOMAX);
    pwm.setPWM(servoMoto, 0, pulse);
    delay(300);
  } 

  pulse = map(graus[6], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(2,0, pulse);
  
  pulse = map(graus[6], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(4,0, pulse);

  pulse = map(graus[0], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(6,0, pulse);

  pulse = map(graus[0], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(8,0, pulse);
 
}
void PTE(){
    
  int pulse = map(150, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(2,0, pulse);
  delay(tempo);
    
  pulse = map(70, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(1,0, pulse);
  delay(tempo);
   
  pulse = map(170, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(2,0, pulse);
  delay(tempo);

  pulse = map(graus[3], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(1,0, pulse);
  delay(tempo);
}
void PDE(){

  int pulse = map(140, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(4,0, pulse);
  delay(tempo);

  delay(tempo);
  pulse = map(70, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(3,0, pulse);
  delay(tempo);

  pulse = map(170, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(4,0, pulse);
  delay(tempo);

  pulse = map(graus[3], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(3,0, pulse);
  delay(tempo);
}
void PTD(){

  int pulse = map(20, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(6,0, pulse);
  delay(tempo);

   pulse = map(110, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(5,0, pulse);
  delay(tempo);

  pulse = map(5, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(6,0, pulse);
  delay(tempo);
  
  pulse = map(graus[3], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(5,0, pulse);
  delay(tempo);

}
void PDD(){

  
  int pulse = map(20, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(8,0, pulse);
  delay(tempo);

   pulse = map(110, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(7,0, pulse);
  delay(tempo);

 pulse = map(5, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(8,0, pulse);
  delay(tempo);
  
  pulse = map(graus[3], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(7,0, pulse);
  delay(tempo);
}
void recusar(){

  pulse = map(graus[4], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(4,0, pulse);
  delay(1000);

  for(int C = 0; C < 5; C++){
    
    pulse = map(graus[4], 0, 180, SERVOMIN, SERVOMAX);
    pwm.setPWM(3,0, pulse);
    pulse = map(graus[0], 0, 180, SERVOMIN, SERVOMAX);
    pwm.setPWM(9,0, pulse);
    delay(400);

    pulse = map(graus[1], 0, 180, SERVOMIN, SERVOMAX);
    pwm.setPWM(3,0, pulse);
    pulse = map(graus[6], 0, 180, SERVOMIN, SERVOMAX);
    pwm.setPWM(9,0, pulse);
    delay(400);

  }

  pulse = map(graus[3], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(9,0, pulse);
  pulse = map(graus[6], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(4,0, pulse);
  pulse = map(graus[3], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(3,0, pulse);
  delay(1000);


}
void carrinho(){

  pulse = map(graus[2], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(3,0, pulse);
  pulse = map(graus[4], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(7,0, pulse);
  delay(1000);

  pulse = map(graus[3], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(4,0, pulse);
  pulse = map(graus[3], 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(8,0, pulse);
  delay(6000);
}

void loop() {


  int distancia = sensorUltra.ping_cm();  // Lê a distância em centímetros 
    Serial.print("Distância: "); 
    Serial.println(distancia); // Mostra a distância no Monitor Serial

    delay(1000);

    if (distancia < 10 && distancia != 0) { // Se houver obstáculo próximo

      int numero = random(1, 101); // Gera um número aleatório
      Serial.print("Número aleatório gerado: ");
      Serial.println(numero);

      if (numero % 10 == 0) { // 10% de chance de aceitar o carinho
        centralizar();
        carrinho();
      } 
      else {
        centralizar();
        recusar();
      }

    }    
    else {
      PTE();
      PDD();
      delay(1000);
      PTD(); 
      PDE(); 
      delay(1000);
    }
 }

