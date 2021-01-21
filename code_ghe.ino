#include <EEPROM.h>
#include <Wire.h>
#include <ADXL345.h>
#include "Adafruit_VL53L0X.h"
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

int axis = 0;
int angle = 0;
int angle1 = 0;
float xg,yg,zg;
float soh;
int tilt;
 int x,y,z;
char mode1, mode2, mode3,i=0,j=0,goc;
ADXL345 adxl;
int minVal=265; int maxVal=402;
int pitch,roll;
void setup() {

     EEPROM.begin(512);
     Serial.begin(9600);
     
    adxl.powerOn();
    xTaskCreatePinnedToCore(Task2code, "Task1", 10000, NULL, 1, NULL, 0); 
    lox.begin();
      pinMode(32, OUTPUT);
      pinMode(33, OUTPUT);
      pinMode(25, OUTPUT);
      pinMode(26, OUTPUT);
      pinMode(27, OUTPUT);
      
      digitalWrite(32,LOW);
      digitalWrite(33,LOW);
      digitalWrite(25,LOW);
      digitalWrite(26,LOW);
      digitalWrite(27,LOW);   
  
     // initialize the pushbutton pin as an input:
       pinMode(14, INPUT);
       pinMode(12, INPUT);
       pinMode(23, INPUT);
       pinMode(15,INPUT);
       pinMode(12, INPUT);
       pinMode(4, INPUT);
       pinMode(16, INPUT);
       pinMode(17,INPUT);
       pinMode(5, INPUT);
       pinMode(19, INPUT);
       pinMode(36, INPUT);
       pinMode(39, INPUT);
       pinMode(34, INPUT);
       pinMode(35, INPUT);
  
    }

void Task2code( void * pvParameters ){
  
     for(;;){
      VL53L0X_RangingMeasurementData_t measure;
      lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!
 
      Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);

      double xyz[3];
      double ax,ay,az;
      adxl.readXYZ(&x, &y, &z);  //read the accelerometer values and store them in variables  x,y,z
      xg = x*0.0039;
      yg = y*0.0039;
      zg = z*0.0039;
      soh = yg/zg;
      tilt = (atan(soh)*57.296)-10;
      Serial.print("goc=");
      Serial.print( tilt);
      Serial.println();
      delay(200);
     
  }

}

void loop() {
 
    if(digitalRead(14)==1&&pitch<=40)
       {
         digitalWrite(26,0); 
         digitalWrite(32,0); 
         digitalWrite(25,1); 
         digitalWrite(33,1);
            i=1;
         delay(100);   
         digitalWrite(26, 0); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
        }
        
  //down xl1
    if(digitalRead(23)==1&&pitch>=20 )
        {
          digitalWrite(26,0); 
          digitalWrite(32,0); 
          digitalWrite(25,1); 
         digitalWrite(33,0);
             i=1;
          delay(100);  
         digitalWrite(26, 0); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);

        }
  //up xl2
    if(digitalRead(15)==1&&tilt<=74 )
        {
         digitalWrite(26, HIGH); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
            i=1;
         delay(100); 
         
         digitalWrite(26, 0); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
 
   
        }
    // down xl2
  if(digitalRead(2)==1&&tilt>=(-13) )
       {
         digitalWrite(26, HIGH); 
         digitalWrite(32, 1); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
            i=1;
         delay(100); 
         digitalWrite(26, 0); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
       }
       



//xilanh 
    if(digitalRead(14)==1&&pitch>=40)
       {
         digitalWrite(27,1); 
         delay(150); 
         digitalWrite(27, 0);
         digitalWrite(26, 0); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
        }
        
  //down xl1
    if(digitalRead(23)==1&&pitch<20 )
        {
         digitalWrite(27,1); 
         delay(150); 
         digitalWrite(27, 0);
         digitalWrite(26, 0); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);

        }
        
  //up xl2
    if(digitalRead(15)==1&&tilt>74 )
        {
         digitalWrite(27,1); 
         delay(150); 
         digitalWrite(27, 0);
         digitalWrite(26, 0); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
   
        }
    // down xl2
  if(digitalRead(2)==1&&tilt<(-13) )
       {
          digitalWrite(27,1); 
         delay(150); 
         digitalWrite(27, 0);
         digitalWrite(26, 0); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
       }
       


       //full up down
   if(digitalRead(4)==1)
        {
           i=10;
        } 

        
   if(digitalRead(16)==1)
       {
          i=5;
        }


       
      if(pitch<40&&i==5 )
          {
          digitalWrite(25, HIGH); 
          digitalWrite(32, 0);
          digitalWrite(33, 1); 
          digitalWrite(26, 0) ;
          delay(200);
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0) ;
          }
      if(pitch>=40&&i==5 )
          {
            i=6;
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0) ;
          }

          
       if(tilt<74 && i==6)
          {
         
          digitalWrite(26,1); 
          digitalWrite(32,0);
          digitalWrite(33, 0); 
          digitalWrite(25,0) ;
           delay(200);
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0) ;
          }
     if((i==6 && tilt>=74))
         {
         i=1;
         digitalWrite(27,1); 
         delay(150); 
         digitalWrite(27, 0);
           digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0) ;
          }


///full dowwn
      if(pitch>20&&i==10)
          {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 1);
           delay(200);
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0) ;
          }
         if(pitch<=20&&i==10)
          {
           i=11;
            digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0) ;
          }
          
        if(i==11&& tilt>(-14))
          {
          digitalWrite(25,0); 
          digitalWrite(33,0);
          digitalWrite(32, 1); 
          digitalWrite(26, 1);
           delay(200);
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0) ;
          }
          
        if(i==11 && tilt<=(-14))
          {
             i=1;
           digitalWrite(27,1); 
          delay(150); 
          digitalWrite(27, 0);
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);
         
          }

   //execution command




 //model 1   
   if(digitalRead(17)==1)
       { 
         EEPROM.write(1,1);
          EEPROM.commit();  
          delay(5);
         i=15;
         
        
       }
 
    //model 2   
   if(digitalRead(5)==1)
       { 
         EEPROM.write(1,2);
          EEPROM.commit();
            delay(5);
          i=20;
       }
    
    //model 3  
  if(digitalRead(18)==1)
       { 
         EEPROM.write(1,3);
          EEPROM.commit(); 
            delay(5);
         i=25;
       }


   
   if(EEPROM.read(3)>pitch&&i==15)
          {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 1); 
          digitalWrite(25, 1);
          }
     if(EEPROM.read(3)<pitch&&i==15)
          {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33,0); 
          digitalWrite(25, 1);
          }       

     if(EEPROM.read(3)==pitch&&i==15)
          {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);
          i=16;
          }   
 if( tilt<EEPROM.read(2)&&i==16)
          {
          digitalWrite(26, 1); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);  
   
          }
    if(i==16&& tilt>EEPROM.read(2))
          {
          digitalWrite(26, 1); 
          digitalWrite(32, 1);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);
   
          }

               
     if(i==16&& tilt==EEPROM.read(2))
       {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);
          i=1;
       }
          

   //mode 2 local


    if(EEPROM.read(5)>pitch&&i==20)
          {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 1); 
          digitalWrite(25, 1);
          }
      if(EEPROM.read(5)<pitch&&i==20)
          {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33,0); 
          digitalWrite(25, 1);
          }       

      if(EEPROM.read(5)==pitch&&i==20)
          {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);
          i=21;
          }   
       if( tilt<EEPROM.read(4)&&i==21)
          {
          digitalWrite(26, 1); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);  
   
          }
       if(i==21&& tilt>EEPROM.read(4))
          {
          digitalWrite(26, 1); 
          digitalWrite(32, 1);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);
   
          }

               
      if(i==21&& tilt==EEPROM.read(4))
       {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);
          i=1;
       }
          

    //local mode 3


       if(EEPROM.read(7)>pitch&&i==25)
          {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 1); 
          digitalWrite(25, 1);
          }
       if(EEPROM.read(7)<pitch&&i==25)
          {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33,0); 
          digitalWrite(25, 1);
          }       

        if(EEPROM.read(7)==pitch&&i==25)
          {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);
          i=26;
          }   
        if( tilt<EEPROM.read(6)&&i==26)
          {
          digitalWrite(26, 1); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);  
   
          }
      if(i==26&& tilt>EEPROM.read(6))
          {
          digitalWrite(26, 1); 
          digitalWrite(32, 1);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);
   
          }

               
      if(i==26&& tilt==EEPROM.read(6))
       {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);
          i=1;
       }
          



   
         if(digitalRead(19)==1&&EEPROM.read(1)==1)
         {    i=1;
             
               EEPROM.write(2,tilt);
               EEPROM.commit(); 
               EEPROM.write(3, pitch);
               EEPROM.commit(); 
               digitalWrite(27, 1);
               delay(150);
              digitalWrite(27, 0);
         }
        if(digitalRead(19)==1&&EEPROM.read(1)==2)
         {    i=1;
               EEPROM.write(4,tilt);
               EEPROM.commit(); 
               EEPROM.write(5, pitch);
               EEPROM.commit(); 
               digitalWrite(27, 1);
               delay(150);
                digitalWrite(27, 0);
                delay(150);
                digitalWrite(27, 1);
               delay(150);
                digitalWrite(27, 0);
                delay(150);
         }
         
        if(digitalRead(19)==1&&EEPROM.read(1)==3)
         {    i=1;
               EEPROM.write(6,tilt);
               EEPROM.commit(); 
               EEPROM.write(7, pitch);
               EEPROM.commit(); 
               digitalWrite(27, 1);
               delay(150);
                digitalWrite(27, 0);
                delay(150);
                digitalWrite(27, 1);
               delay(150);
                digitalWrite(27, 0);
                delay(150);
                digitalWrite(27, 1);
              delay(150);
                digitalWrite(27, 0);
                delay(150);
         }
         
     
    }//code fulll mode
