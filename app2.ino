#include <Servo.h>
#include <SoftwareSerial.h>
#define Txt 0
#define Rxt 1
int led2=7;
int led1=8;
int estado=0;
long distancia;
long tiempo;
int noteFreqArr[] = { // vector con las notas de la musica que se reproduce en el buzzer
49.4, 52.3, 55.4, 58.7, 62.2, 65.9, 69.9, 74, 78.4, 83.1, 88, 93.2,
98.8, 105, 111, 117, 124, 132, 140, 148, 157, 166, 176, 186,
198, 209, 222, 235, 249, 264, 279, 296, 314, 332, 352, 373,
395, 419, 444, 470, 498, 527, 559, 592, 627, 665, 704, 746,
790, 837, 887, 940, 996, 1050, 1110, 1180, 1250, 1320, 1400, 1490,
1580, 1670, 1770, 1870, 1990, 2100};
Servo servo1;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  pinMode(led2,OUTPUT); // conectado al led 2
  pinMode(led1,OUTPUT); // conectado al led 1
  pinMode(9, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(10, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
  servo1.attach(6);
   pinMode(2, OUTPUT); // para el buzzer
}
void playNote(int noteInt, long length, long breath = 10) { // para reproduce las notas musicales
  length = length - breath;
  buzz(2, noteFreqArr[noteInt], length);
  if(breath > 0) { //take a short pause or 'breath' if specified
    delay(breath);
  }
}


void buzz(int targetPin, long frequency, long length) { // para reproducir las notas musicales
  long delayValue = 500000/frequency/2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length/ 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i=0; i < numCycles; i++){ // for the calculated length of time...
    digitalWrite(targetPin,HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin,LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait againf or the calculated delay value
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(9,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(9, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo=pulseIn(10, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
  del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
  deja de hacerlo, LOW, la longitud del pulso entrante*/
  distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
  /*Monitorización en centímetros por el monitor serial*/                           
  if (distancia < 20){
if(Serial.available()>0){
 estado = Serial.read(); 
 Serial.println(distancia);
 }
 if (estado =='1'){
   digitalWrite(led1,HIGH);
    while (estado == '1'){
  servo1.write(0);
  playNote(24,500);
  servo1.write(45);
  playNote(17,1000);
  servo1.write(90);
  playNote(19,250);
  servo1.write(0);
  playNote(22,250);
  servo1.write(45);
  playNote(21,250);
  servo1.write(90);
  playNote(19,250);
  servo1.write(0);
  playNote(24,500);
  servo1.write(45);
  playNote(24,500);
  servo1.write(90);
  playNote(24,250);
  servo1.write(0);
  playNote(26,250);
  servo1.write(45);
  playNote(21,250);
  servo1.write(90);
  playNote(22,250);
  servo1.write(0);
  playNote(19,500);
  servo1.write(45);
  playNote(19,500);
  servo1.write(90);
  playNote(19,250);
  servo1.write(0);
  playNote(22,250);
  servo1.write(45);
  playNote(21,250);
  servo1.write(90);
  playNote(19,250);
  servo1.write(0);
  playNote(17,250);
  servo1.write(45);
  playNote(29,250);
  servo1.write(90);
  playNote(28,250);
  servo1.write(0);
  playNote(26,250);
  servo1.write(45);
  playNote(24,250);
  servo1.write(90);
  playNote(22,250);
  servo1.write(0);
  playNote(21,250);
  servo1.write(45);
  playNote(19,250);
  servo1.write(90);
  playNote(17,1000);
  servo1.write(0);
  playNote(19,250);
  servo1.write(45);
  playNote(22,250);
  servo1.write(90);
  playNote(21,250);
  servo1.write(0);
  playNote(19,250);
  servo1.write(45);
  playNote(24,500);
  servo1.write(90);
  playNote(24,500);
  servo1.write(0);
  playNote(24,250);
  servo1.write(45);
  playNote(26,250);
  servo1.write(90);
  playNote(21,250);
  servo1.write(0);
  playNote(22,250);
  servo1.write(45);
  playNote(19,500);
  servo1.write(90);
  playNote(19,500);
  servo1.write(0);
  playNote(19,250);
  servo1.write(45);
  playNote(22,250);
  servo1.write(90);
  playNote(21,250);
  servo1.write(0);
  playNote(19,250);
  servo1.write(45);
  playNote(17,250);
  servo1.write(90);
  playNote(24,250);
  servo1.write(0);
  playNote(19,250);
  servo1.write(45);
  playNote(21,250);
  servo1.write(90);
  playNote(17,250);
  servo1.write(45);
  delay(250);
  servo1.write(90);
  estado = 0;
    }
  }
if(estado=='2'){
   digitalWrite(led1,LOW);
   servo1.write(0);
   estado = 0;
  }
 if (estado =='3'){
   digitalWrite(led2,HIGH);
   servo1.write(0);
   estado = 0;
  }
if(estado=='4'){
   digitalWrite(led2,LOW);
   servo1.write(0);
   estado = 0;
  }
    }
     delay(1000);
}
