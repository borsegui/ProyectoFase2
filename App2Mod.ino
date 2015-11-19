//Universidad del Valle de Guatemala
//Jonathan Aguire
//Diego de Leon

# Incluir  <Servo.h>
# Incluir  <SoftwareSerial.h>
# Definir  Txt  0
# Definir  RXT  1
int LED2 = 7;
int LED1 = 8;
int estado = 0;
larga distancia;
mucho tiempoo;
int noteFreqArr [] = {// vector con las Notas de la musica Que se reproducen en el zumbador
49.4, 52.3, 55.4, 58.7, 62.2, 65.9, 69.9, 74, 78.4, 83.1, 88, 93.2,
98.8, 105, 111, 117, 124, 132, 140, 148, 157, 166, 176, 186,
198, 209, 222, 235, 249, 264, 279, 296, 314, 332, 352, 373,
395, 419, 444, 470, 498, 527, 559, 592, 627, 665, 704, 746,
790, 837, 887, 940, 996, 1.050, 1.110, 1.180, 1.250, 1.320, 1.400, 1.490,
1580, 1670, 1770, 1870, 1990, 2100};
Servo1 Servo;
void  setup () {
  // Poner el código de configuración aquí, para ejecutar una vez:
Serial. Comenzar (9600);
  pinMode (LED2, OUTPUT); // Conectado al condujo 2
  pinMode (LED1, OUTPUT); // Conectado al lideró 1
  pinMode (9, OUTPUT); / * activation del pin 9 Como salida: para el pulso ultrasónico * /
  pinMode (10, INPUT); / * activation del pin 8 Como entrada: Tiempo del rebote del ultrasonido * /
  . servo1 adjuntar (6);
   pinMode (2, OUTPUT); // Para El zumbador
}
void  PlayNote (int noteInt, larga duración, a largo aliento = 10) {// párr reproducir las notas musicales
  longitud = longitud - la respiración;
  buzz (2, noteFreqArr [noteInt], longitud);
  si (aliento> 0) {// tomar una pausa corta o 'aliento' Si se especifica
    retardo (respiración);
  }
}


vacío  zumbido (int targetPin, largo frecuencia, tiempo largo) {// párr Reproducir las notas musicales
  larga delayValue = 500000 / frecuencia / 2; // calcular el valor de retardo entre las transiciones
  //// 1 del segundo valor de microsegundos, dividido por la frecuencia, a continuación, divide a la mitad desde
  //// Hay dos fases para cada ciclo
  largas numCycles = Frecuencia * Longitud / 1000; // calcular el número de ciclos de tiempo adecuado
  //// Frecuencia se multiplican, lo que es realmente ciclos por segundo, por el número de segundos para
  //// Obtener el número total de ciclos para producir
  para (a largo i = 0; i <numCycles; i ++) {// para la longitud calculada de tiempo ...
    digitalWrite (targetPin, HIGH); // escribir el pin zumbador alta para empujar el diafragma
    delayMicroseconds (delayValue); // esperar a que el valor de retardo calculado
    digitalWrite (targetPin, LOW); // escribir la baja pin timbre para tirar del diafragma
    delayMicroseconds (delayValue); // espera againf o el valor de retardo calculado
  }
}

void  loop () {
  // Poner el código principal aquí, para ejecutar en varias ocasiones:
  digitalWrite (9, LOW); / * Por Cuestión de Estabilización del sensor * /
  delayMicroseconds (5);
  digitalWrite (9, HIGH); / * ENVÍO del pulso ultrasónico * /
  delayMicroseconds (10);
  Tiempo = pulseIn (10, HIGH); / * Función párrafo Medir la Longitud del pulso entrante. Mide El Tiempo Que Transcurrido Entre el ENVÍO
  del pulso ultrasónico Y Cuando el sensor de recibir con el rebote, es Decir: Desde Que el pasador 12 empieza un recibir el rebote, ALTA, Que Hasta
  Deja de Hacerlo, BAJO, la longitudinal del pulso entrante * /
  distancia = int (0.017 * Tiempo); / * Fórmula párrafo Calcular la distancia obteniendo entero valor ONU * /
  / * Monitorización en Centímetros por el monitor serie * /                           
  si (distancia <20) {
si (Serial. disponible ()> 0) {
estado = de serie. leer ();
Serial. Println (distancia);
 }
 si (estado == '1') {
   digitalWrite (LED1, HIGH);
    mientras (estado == '1') {
  . servo1 escribir (0);
  PlayNote (24, 500);
  . servo1 escribir (45);
  PlayNote (17, 1.000);
  . servo1 escribir (90);
  PlayNote (19, 250);
  . servo1 escribir (0);
  PlayNote (22, 250);
  . servo1 escribir (45);
  PlayNote (21, 250);
  . servo1 escribir (90);
  PlayNote (19, 250);
  . servo1 escribir (0);
  PlayNote (24, 500);
  . servo1 escribir (45);
  PlayNote (24, 500);
  . servo1 escribir (90);
  PlayNote (24, 250);
  . servo1 escribir (0);
  PlayNote (26, 250);
  . servo1 escribir (45);
  PlayNote (21, 250);
  . servo1 escribir (90);
  PlayNote (22, 250);
  . servo1 escribir (0);
  PlayNote (19, 500);
  . servo1 escribir (45);
  PlayNote (19, 500);
  . servo1 escribir (90);
  PlayNote (19, 250);
  . servo1 escribir (0);
  PlayNote (22, 250);
  . servo1 escribir (45);
  PlayNote (21, 250);
  . servo1 escribir (90);
  PlayNote (19, 250);
  . servo1 escribir (0);
  PlayNote (17, 250);
  . servo1 escribir (45);
  PlayNote (29, 250);
  . servo1 escribir (90);
  PlayNote (28, 250);
  . servo1 escribir (0);
  PlayNote (26, 250);
  . servo1 escribir (45);
  PlayNote (24, 250);
  . servo1 escribir (90);
  PlayNote (22, 250);
  . servo1 escribir (0);
  PlayNote (21, 250);
  . servo1 escribir (45);
  PlayNote (19, 250);
  . servo1 escribir (90);
  PlayNote (17, 1.000);
  . servo1 escribir (0);
  PlayNote (19, 250);
  . servo1 escribir (45);
  PlayNote (22, 250);
  . servo1 escribir (90);
  PlayNote (21, 250);
  . servo1 escribir (0);
  PlayNote (19, 250);
  . servo1 escribir (45);
  PlayNote (24, 500);
  . servo1 escribir (90);
  PlayNote (24, 500);
  . servo1 escribir (0);
  PlayNote (24, 250);
  . servo1 escribir (45);
  PlayNote (26, 250);
  . servo1 escribir (90);
  PlayNote (21, 250);
  . servo1 escribir (0);
  PlayNote (22, 250);
  . servo1 escribir (45);
  PlayNote (19, 500);
  . servo1 escribir (90);
  PlayNote (19, 500);
  . servo1 escribir (0);
  PlayNote (19, 250);
  . servo1 escribir (45);
  PlayNote (22, 250);
  . servo1 escribir (90);
  PlayNote (21, 250);
  . servo1 escribir (0);
  PlayNote (19, 250);
  . servo1 escribir (45);
  PlayNote (17, 250);
  . servo1 escribir (90);
  PlayNote (24, 250);
  . servo1 escribir (0);
  PlayNote (19, 250);
  . servo1 escribir (45);
  PlayNote (21, 250);
  . servo1 escribir (90);
  PlayNote (17, 250);
  . servo1 escribir (45);
  retardo (250);
  . servo1 escribir (90);
  estado = 0;
    }
  }
si (estado == '2') {
   digitalWrite (LED1, LOW);
   . servo1 escribir (0);
   estado = 0;
  }
 si (estado == '3') {
   digitalWrite (LED2, HIGH);
   . servo1 escribir (0);
   estado = 0;
  }
si (estado == '4') {
   digitalWrite (LED2, LOW);
   . servo1 escribir (0);
   estado = 0;
  }
    }
     retardo (1000);
}
