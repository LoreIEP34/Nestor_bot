//librerias
  #include "Pines-ESP32.h"
  #include <Ps3Controller.h>
  #include <ESP32Servo.h>
  #include <analogWrite.h>
//definicion de constantes
  #define YES 1
  #define NO 0
  
  #define SIGN_PAD 1
  #define SIGN_BUTTONS 2
  #define SIGN_TRIGGERS 3
  #define SIGN_STICKS 4   
  #define SIGN_MENU 5       

//definicion de los tiempos de espera.
  #define MICRO_WAIT 50
  #define SMALL_WAIT 250
  #define MEDIUM_WAIT 500
  #define LONG_WAIT 1000
//definicion de los servos
  Servo hombro_izq;
  Servo codo_izq;
  Servo grip_izq;

  Servo hombro_der;
  Servo codo_der;
  Servo grip_der;
  
  int lx, ly, rx, ry;
  int servo1, servo2, servo3, servo4;

//funciones de aviso de señal del controll 

  int Sign_Controll(){
    if (Ps3.data.button.up || Ps3.data.button.right || Ps3.data.button.down || Ps3.data.button.left){
      return SIGN_PAD;
    } 
    else if (Ps3.data.button.cross || Ps3.data.button.square || Ps3.data.button.triangle || Ps3.data.button.circle){
      return SIGN_BUTTONS;
    }  
    else if (Ps3.data.button.l1 || Ps3.data.button.r1 || Ps3.data.button.l2 || Ps3.data.button.r2 || Ps3.data.button.l3 || Ps3.data.button.r3){
      return SIGN_TRIGGERS;
    }
    else if (abs(Ps3.event.analog_changed.stick.lx) + abs(Ps3.event.analog_changed.stick.ly) > 2 || abs(Ps3.event.analog_changed.stick.rx) + abs(Ps3.event.analog_changed.stick.ry) > 2){
      //Serial.println("sticks se mueven");
      return SIGN_STICKS;
    }
    else if (Ps3.data.button.select || Ps3.data.button.start || Ps3.data.button.ps){
      return SIGN_MENU;
    }
    else return NO;    
    
  }
  
//funciones de los motores
  void Detener(){
      //MOTOR A
      digitalWrite(PIN_MdP1, LOW);
      digitalWrite(PIN_MdP2, LOW);
      //MOTOR B
      digitalWrite(PIN_MiP1, LOW);
      digitalWrite(PIN_MiP2, LOW);
      Serial.println("          ta quieto");
    
  }
  void Motors_Move(){
    
    if(Ps3.data.button.up){   //adelante
      //MOTOR A{
      digitalWrite(PIN_MdP1, HIGH);
      digitalWrite(PIN_MdP2, LOW);
      //MOTOR B
      digitalWrite(PIN_MiP1, HIGH);
      digitalWrite(PIN_MiP2, LOW);
      Serial.println("            pa lante");  
    }
    else if(Ps3.data.button.down){    //atras
      //MOTOR A
      digitalWrite(PIN_MdP1, LOW);
      digitalWrite(PIN_MdP2, HIGH);
      //MOTOR B
      digitalWrite(PIN_MiP1, LOW);
      digitalWrite(PIN_MiP2, HIGH);
      Serial.println("              pa tras ");
    }      
    else if(Ps3.data.button.right){   //derecha
      //MOTOR A
      digitalWrite(PIN_MdP1, HIGH);
      digitalWrite(PIN_MdP2, LOW);
      //MOTOR B
      digitalWrite(PIN_MiP1, LOW);
      digitalWrite(PIN_MiP2, HIGH);
      Serial.println("            pa diestra");
    }    
    else if(Ps3.data.button.left){    //izquierda
      //MOTOR A
      digitalWrite(PIN_MdP1, LOW);
      digitalWrite(PIN_MdP2, HIGH);
      //MOTOR B
      digitalWrite(PIN_MiP1, HIGH);
      digitalWrite(PIN_MiP2, LOW);
      Serial.println("            pa zurda");
    }       
    }
    
  
//funcion de los servos
  void Muestreo_Sticks(){
    if (abs(Ps3.event.analog_changed.stick.lx) + abs(Ps3.event.analog_changed.stick.ly) > 2) {
      Serial.print(" lx=");
      Serial.print(Ps3.data.analog.stick.lx, DEC);
      Serial.print(" servo1 = ");
      Serial.print(servo1);    
      Serial.print(" ly=");
      Serial.print(Ps3.data.analog.stick.ly, DEC);
      Serial.print(" servo2 =  ");
      Serial.print(servo2);
      Serial.println();
    }

    if (abs(Ps3.event.analog_changed.stick.rx) + abs(Ps3.event.analog_changed.stick.ry) > 2) {
      Serial.print(" rx=");
      Serial.print(Ps3.data.analog.stick.rx, DEC);
      Serial.print(" servo3 = ");
      Serial.print(servo3);
      Serial.print(" ry=");
      Serial.print(Ps3.data.analog.stick.ry, DEC);
      Serial.print(" servo4 = ");
      Serial.print(servo4);
      Serial.println();
    }

  }

  void Mapeo(){
    lx = Ps3.data.analog.stick.lx;
    ly = Ps3.data.analog.stick.ly;
    rx = Ps3.data.analog.stick.rx;
    ry = Ps3.data.analog.stick.ry;

    servo1 = map(lx, -128, 128, 0, 180);
    servo2 = map(ly, -128, 128, 0, 180);
    servo3 = map(rx, -128, 128, 0, 180);
    servo4 = map(ry, -128, 128, 0, 180);
  }


  void Mov_Servos(){
    if (abs(Ps3.event.analog_changed.stick.lx) > 1){    
      hombro_izq.write(servo1);
    }    
    if (abs(Ps3.event.analog_changed.stick.ly) > 1){     
      codo_izq.write(servo2);
    }
    if (abs(Ps3.event.analog_changed.stick.rx) > 1){
      hombro_der.write(servo3);
    }
    if (abs(Ps3.event.analog_changed.stick.ry) > 1){    
      codo_der.write(servo4);
 
 
    }
  }
