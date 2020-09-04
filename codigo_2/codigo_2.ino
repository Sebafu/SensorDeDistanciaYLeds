/*
   ################
   #   Lab15125   #
   ################
 
   Este codigo tiene como objetivo dar muestra de un uso practico de:
   Sensor ultrasonico ping (parallax)

   Según la hoja de datos de Parallax para el PING))), 
   hay 73,746 microsegundos por pulgada o 29,034 microsegundos por centimetro 
   (es decir, el sonido viaja a 1130 pies (o 34442.4cm) por segundo). 
   Este da la distancia recorrida por el ping, ida y vuelta, 
   por lo que dividimos por 2 para obtener la distancia del obstáculo.
   ver: 
   https://www.parallax.com/sites/default/files/downloads/28015-PING-Sensor-Product-Guide-v2.0.pdf
        [En el PDF: TO_IN = 73_746' Inches ; TO_CM = 29_034' Centimeters ]

   El circuito:
     * +V conectado a sensor PING))) en +5V
     * GND conectado a sensor PING))) en GND (ground)
     * SIG conectado a sensor PING))) en pin digital 7
     * LED conectado a pin 9 (PWM)

   Funcion
   readUltrasonicDistance(int triggerPin, int echoPin): Referencia obtenida de sensor ultrasonico tinkercad.com
*/


/*
Inicio declaracion funcion readUltrasonicDistance
*/
int inches = 0;// declara variables en pulgadas 
long cm = 0;  // declara variables en cm en Long para mayor número de decimales
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Inicializar LOW para limpiar trigger por 2 microsegundos
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Inicializar trigger en HIGH por 8 microsegundos para comenzar
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(8);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // lectura de pin echo con el retorno de la señal
  return pulseIn(echoPin, HIGH);
}
/*
Fin declaracion funcion readUltrasonicDistance
*/


/*
Inicio funcion setup
*/
void setup()
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
}
/*
Fin funcion setup
*/


/*
Inicio funcion loop
*/
void loop()
{
  float distancia = 0.01723 * readUltrasonicDistance(2, 2);

  if((distancia <= 336) && (distancia >= 200)) { //se restringío más la distancia
    digitalWrite(4, HIGH); //se prende la luz roja 
  } 
  else {
    digitalWrite(4, LOW); 
  }
  if((distancia < 200) && (distancia >= 100)) {
    digitalWrite(7, HIGH); //se prende la luz amarilla
  } 
  else {
    digitalWrite(7, LOW); 
  }
  if((distancia < 100) && (distancia >=2)) {
    digitalWrite(8, HIGH); //se prende la luz verde
  } 
  else {
    digitalWrite(8, LOW); 
  }
   
  /* COMPARACIÓN DE RANGO ENTRE MONITOR EN SERIE Y VALOR VISUAL DEL SENSOR*/                                    
  Serial.print("distancia [cm] calibrada: ");// IMPRIMIR EN MONITOR EN SERIE 
  Serial.println(distancia+1.8);//IMPRIME VALOR DISTANCIA "CALIBRADA"
  delay(10); // Delay a little bit to improve simulation performance

}
/*
Inicio funcion loop
*/

/*
 #######################
 #   Fin de programa   #
 #######################
*/