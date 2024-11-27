//librerias
  #include "control_address.h"
  #include "Funciones.h"  

// definicion de constantes y variables para la maquina de estado
  #define REPOSE 0
  #define WAIT_CONTROLL 1
  #define MOVEMENT 2

 int state = REPOSE;

    
void setup() {
  Serial.begin(115200);

  Ps3.begin(address_0);

  hombro_izq.attach(PIN_SERVO1);
  codo_izq.attach(PIN_SERVO2);
  grip_izq.attach(PIN_SERVO3);

  hombro_der.attach(PIN_SERVO4);
  codo_der.attach(PIN_SERVO5);
  grip_der.attach(PIN_SERVO6);

  pinMode(PIN_MdP1, OUTPUT);
  pinMode(PIN_MdP2, OUTPUT);
  pinMode(PIN_MiP1, OUTPUT);
  pinMode(PIN_MiP2, OUTPUT);
}

void loop() {

  switch(state){
    case REPOSE:
      if (Ps3.isConnected()){
        Serial.println("controll is conected");
        state = WAIT_CONTROLL;      
      }
      else {
      Serial.printf("."); 
      delay(SMALL_WAIT);   
      }      
    break;
    case WAIT_CONTROLL:
      if (Sign_Controll()){
        state = MOVEMENT;
      } 
      if (!Ps3.isConnected()){
        state = REPOSE;
      }                  
    break;     
    case MOVEMENT:
      switch(Sign_Controll()){
        case SIGN_PAD:
          Motors_Move();
        break;
        case SIGN_BUTTONS:
          Detener();
        break;
        case SIGN_TRIGGERS:
          Detener();
        break;          
        case SIGN_STICKS:
          Detener();
          Mapeo();
          Mov_Servos();
          Muestreo_Sticks();          
        break;
        case SIGN_MENU:
          Detener();
        break;
        case NO:
          Detener();
          state= WAIT_CONTROLL;
        break;
      }      
    break;  
  }

}
  