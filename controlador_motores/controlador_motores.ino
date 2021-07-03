// Programación para cada uno de los uC que mueven los motores
// Se va a utilizar el EEPROM para guardar los vaores que lleguen
// Orden de los valores que se van a recibir izq -> der (uC del motor 1 -> uC del motor 6)

#include <EEPROM.h>
#include <Stepper.h>

const byte longitud = 64;
char recibido [longitud];
char tempChars [longitud];

char inData;
char indice = 0;
static boolean recibiendo = false;
char inicio = '<';
char fin = '>';

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

// Recepción de datos con el marcador para saber en dónde empezar y en dónde terminar

void recibirConstMarcador(){
    
  while(Serial.available() > 0 && datosNuevos == false){
    inData = Serial.read();
    if (recibiendo == true){
      if (inData != fin){
        recibido[indice] = inData;
        indice++;
        if (indice > longitud){
          indice = longitud - 1;
        }
      }
       else{
        recibido[indice] = '\0';
        indice = 0;
        recibiendo = false;
        datosNuevos = true;
      }
    }
    else if (inData == inicio){
      recibiendo = true;
    }
  }
}
