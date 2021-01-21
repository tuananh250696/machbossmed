#include <EEPROM.h>
#include <Wire.h>
#include "Adafruit_VL53L0X.h"
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
const int MPU = 0x68; // I2C address of the MPU6050 accelerometer
#include <EEPROM.h>
int16_t AcX, AcY, AcZ;
int axis = 0;
int angle = 0;
int angle1 = 0;
 int H;
 int tilt;
 int i=1;
char mode1, mode2, mode3,j=0,goc;
int pitch,roll;


void setup() {
      EEPROM.begin(512);
  Serial.begin(9600);
     Wire.begin();
     Wire.beginTransmission(MPU);
     Wire.write(0x6B);
    Wire.write(0);
    Wire.endTransmission(true);
    //xTaskCreatePinnedToCore(Task2code, "Task1", 10000, NULL, 1, NULL, 1); 
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
 
    xTaskCreatePinnedToCore(Task2code, "Task1", 24000, NULL, 1, NULL, 0); 
    
     
    }

void Task2code( void * pvParameters ){
  
     for(;;){
      VL53L0X_RangingMeasurementData_t measure;
      lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!
 
      Serial.print("Distance (mm): ");
      H=measure.RangeMilliMeter/10;
      Serial.println(H);

     Wire.beginTransmission(MPU);
      Wire.write(0x3B); // Start with register 0x3B (ACCEL_XOUT_H)
      Wire.endTransmission(false);
      Wire.requestFrom(MPU, 6, true); // Read 6 registers total, each axis value is stored in 2 registers
      AcX = Wire.read() << 8 | Wire.read(); // X-axis value
      AcY = Wire.read() << 8 | Wire.read(); // Y-axis value
      AcZ = Wire.read() << 8 | Wire.read(); // Z-axis value
     
       tilt = atan(-1 * AcX / sqrt(pow(AcY, 2) + pow(AcZ, 2))) * 180 / PI;
      Serial.print(" anglebbbb= ");
      Serial.print(abs(tilt));
      Serial.println();
    delay(400);
     
  }

}

void loop() {
 
    if(digitalRead(35)==1&&H<=29)
       {
        i=1;
         digitalWrite(26,0); 
         digitalWrite(32,0); 
         digitalWrite(25,1); 
         digitalWrite(33,1);
         delay(200);  
         digitalWrite(26, 0); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
         
           

        }
        
  //down xl1
    if(digitalRead(34)==1&&H>=4 )
        {
          i=1;
          digitalWrite(26,0); 
          digitalWrite(32,0); 
          digitalWrite(25,1); 
         digitalWrite(33,0);
            
          delay(200);  
         digitalWrite(26, 0); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);

        }
  //up xl2
    if(digitalRead(36)==1  )
        {
          i=1;
         digitalWrite(26, HIGH); 
         digitalWrite(32,0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
            
         delay(200); 
         
         digitalWrite(26, 0); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
 
   
        }

       //up xl2
//    if(digitalRead(36)==1  )
//        {
//          i=1;
//         digitalWrite(26, 0); 
//         digitalWrite(32,0); 
//         digitalWrite(25,0); 
//         digitalWrite(33,0);
//          digitalWrite(27,1);
//         
//         delay(200); 
//        
// 
//   
//        }
    // down xl2
  if(digitalRead(39)==1)
       {
        i=1;
         digitalWrite(26, HIGH); 
         digitalWrite(32, 1); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
         
         delay(200); 
         digitalWrite(26, 0); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
       }

 if(digitalRead(34)==1&&H<4)
       {
        i=1;
     digitalWrite(26, 0); 
         digitalWrite(32,0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
          digitalWrite(27,1);
         
         delay(200); 
         digitalWrite(26, 0); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
         digitalWrite(27,0);
           

        }
        
  //down xl1
    if(digitalRead(35)==1&&H>29 )
        {
          i=1;
         digitalWrite(26, 0); 
         digitalWrite(32,0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
          digitalWrite(27,1);
         
         delay(200); 
         digitalWrite(26, 0); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
         digitalWrite(27,0);

        }
 
    // down xl2
//  if(digitalRead(39)==1  )
//       {
//        i=1;
//         digitalWrite(26, 0); 
//         digitalWrite(32,0); 
//         digitalWrite(25,0); 
//         digitalWrite(33,0);
//          digitalWrite(27,1);
//         
//         delay(200); 
//         digitalWrite(26, 0); 
//         digitalWrite(32, 0); 
//         digitalWrite(25,0); 
//         digitalWrite(33,0);
//         digitalWrite(27,0);
//       }

  if(digitalRead(14)==1&&H<=29)
       {
        i=1;
         digitalWrite(26,0); 
         digitalWrite(32,0); 
         digitalWrite(25,1); 
         digitalWrite(33,1);
         delay(200);  
         digitalWrite(26, 0); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
         
           

        }
       if(digitalRead(14)==1&&H>29)
       {
        i=1;
     digitalWrite(26, 0); 
         digitalWrite(32,0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
          digitalWrite(27,1);
         
         delay(200); 
         digitalWrite(26, 0); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
         digitalWrite(27,0);
           

        }
  //down xl1
    if(digitalRead(23)==1&&H>=4 )
        {
          i=1;
          digitalWrite(26,0); 
          digitalWrite(32,0); 
          digitalWrite(25,1); 
         digitalWrite(33,0);
            
          delay(200);  
         digitalWrite(26, 0); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);

        }
         //down xl1
    if(digitalRead(23)==1&&H<4 )
        {
          i=1;
         digitalWrite(26, 0); 
         digitalWrite(32,0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
          digitalWrite(27,1);
         
         delay(200); 
         digitalWrite(26, 0); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
         digitalWrite(27,0);

        }
  //up xl2
    if(digitalRead(15)==1  )
        {
          i=1;
         digitalWrite(26, HIGH); 
         digitalWrite(32, 1); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
            
         delay(200); 
         
         digitalWrite(26, 0); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
 
   
        }

       //up xl2
//    if(digitalRead(15)==1 )
//        {
//          i=1;
//         digitalWrite(26, 0); 
//         digitalWrite(32,0); 
//         digitalWrite(25,0); 
//         digitalWrite(33,0);
//          digitalWrite(27,1);
//         
//         delay(200); 
//         digitalWrite(26, 0); 
//         digitalWrite(32, 0); 
//         digitalWrite(25,0); 
//         digitalWrite(33,0);
//         digitalWrite(27,0);
// 
//   
 //       }
    // down xl2
  if(digitalRead(2)==1 )
       {
        i=1;
         digitalWrite(26, HIGH); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
         
         delay(200); 
         digitalWrite(26, 0); 
         digitalWrite(32, 0); 
         digitalWrite(25,0); 
         digitalWrite(33,0);
       }

//       if(digitalRead(2)==1 )
//        {
//          i=1;
//         digitalWrite(26, 0); 
//         digitalWrite(32,0); 
//         digitalWrite(25,0); 
//         digitalWrite(33,0);
//          digitalWrite(27,1);
//         
//         delay(200); 
//         digitalWrite(26, 0); 
//         digitalWrite(32, 0); 
//         digitalWrite(25,0); 
//         digitalWrite(33,0);
//         digitalWrite(27,0);
// 
//   
//        }
//    // down xl2


        

  //up xl2
  
 

 if(digitalRead(4)==1)
        {
          
           i=10;
           digitalWrite(27,1); 
         delay(200); 
        digitalWrite(27, 0);
        } 

        
   if(digitalRead(16)==1)
       {
          i=5;
           digitalWrite(27,1); 
         delay(200); 
        digitalWrite(27, 0);
        }

       
      if(H<=29&&i==5 )
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
      if(H>29&&i==5 )
          {
          digitalWrite(27,1); 
         delay(200); 
          i=6;
        digitalWrite(27, 0);
           
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0) ;
          }

      if(  i==6)
          {
         
          digitalWrite(26,1); 
          digitalWrite(32,1);
          digitalWrite(33, 0); 
          digitalWrite(25,0) ;
      
          }    
     //
//     if(i==6 && tilt<2)
//         {
//         i=1;
//         digitalWrite(27,1); 
//         delay(200); 
//         digitalWrite(27, 0);
//           digitalWrite(26, 0); 
//          digitalWrite(32, 0);
//          digitalWrite(33, 0); 
//          digitalWrite(25, 0) ;
        //  }

///full dowwn
      if(H>=4&&i==10)
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
         if(H<4&&i==10)
          {
            digitalWrite(27,1); 
             i=11;
         delay(200); 
         digitalWrite(27, 0);
          
           
            digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0) ;
          }
         if(i==11)
          {
          digitalWrite(25,0); 
          digitalWrite(33,0);
          digitalWrite(32, 0); 
          digitalWrite(26, 1);
      
          }
          
//        if(i==11&& tilt<=76)
//          {
//          digitalWrite(25,0); 
//          digitalWrite(33,0);
//          digitalWrite(32, 1); 
//          digitalWrite(26, 1);
//           delay(200);
//          digitalWrite(26, 0); 
//          digitalWrite(32, 0);
//          digitalWrite(33, 0); 
//          digitalWrite(25, 0) ;
//          }
//          
//        if(i==11&& tilt>76)
//          {
//          digitalWrite(27,1);
//          i=1; 
//          delay(200); 
//             
//          
//          digitalWrite(27, 0);
//          digitalWrite(26, 0); 
//          digitalWrite(32, 0);
//          digitalWrite(33, 0); 
//          digitalWrite(25, 0);
//         
//          }
   if(digitalRead(17)==1)
      {
          digitalWrite(27,1); 
            EEPROM.write(1,1);
          EEPROM.commit();  
         i=15;
         delay(200); 
        digitalWrite(27, 0);
   
        }
    
    if(digitalRead(5)==1)
       { 
          digitalWrite(27,1); 
         delay(200); 
         digitalWrite(27, 0);
        delay(200);
          digitalWrite(27,1); 
           EEPROM.write(1,2);
          EEPROM.commit();
          i=20;
         delay(200); 
         digitalWrite(27, 0);
         
       
       }
      
 if(digitalRead(18)==1)
      { 
             digitalWrite(27,1); 
         delay(200); 
         digitalWrite(27, 0);
        delay(200);
          digitalWrite(27,1); 
         delay(200); 
         digitalWrite(27, 0);
         delay(200);
           digitalWrite(27,1); 
              EEPROM.write(1,3);
          EEPROM.commit(); 
            
         i=25;;
         delay(200); 
         digitalWrite(27, 0);
        
        
      }

   if(digitalRead(19)==1&&EEPROM.read(1)==1)
         {    i=1;
             
               EEPROM.write(2,tilt);
               EEPROM.commit(); 
               EEPROM.write(3, H);
               EEPROM.commit(); 
               digitalWrite(27, 1);
               delay(200);
              digitalWrite(27, 0);
         }
        if(digitalRead(19)==1&&EEPROM.read(1)==2)
         {    i=1;
               EEPROM.write(4,tilt);
               EEPROM.commit(); 
               EEPROM.write(5,H);
               EEPROM.commit(); 
               digitalWrite(27, 1);
               delay(200);
                digitalWrite(27, 0);
                delay(200);
                digitalWrite(27, 1);
               delay(200);
                digitalWrite(27, 0);
                delay(200);
         }
         
        if(digitalRead(19)==1&&EEPROM.read(1)==3)
         {    i=1;
               EEPROM.write(6,tilt);
               EEPROM.commit(); 
               EEPROM.write(7, H);
               EEPROM.commit(); 
               digitalWrite(27, 1);
               delay(200);
                digitalWrite(27, 0);
                delay(200);
                digitalWrite(27, 1);
               delay(200);
                digitalWrite(27, 0);
                delay(200);
                digitalWrite(27, 1);
              delay(200);
                digitalWrite(27, 0);
                delay(200);
         }
//LOCAL1
   
   if(EEPROM.read(3)>H&&i==15)
          {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 1); 
          digitalWrite(25, 1);
          delay(200);
          }
     if(EEPROM.read(3)<H&&i==15)
          {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33,0); 
          digitalWrite(25, 1);
          delay(200);
          }       

     if(EEPROM.read(3)==H&&i==15)
          {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);
          
          i=16;
          delay(200);
          }
          //TIT
    
 if( tilt>EEPROM.read(2)&&i==16)
          {
          digitalWrite(26, 1); 
          digitalWrite(32, 1);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);  
          delay(200);
   
          }
    if(i==16&& tilt<EEPROM.read(2))
          {
          digitalWrite(26, 1); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);
          delay(200);
   
          }

              
     if(i==16&& tilt==EEPROM.read(2))
       {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);
          i=1;
          delay(200);
       }
          

   //mode 2 local


    if(EEPROM.read(5)>H&&i==20)
          {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 1); 
          digitalWrite(25, 1);
          delay(200);
          }
      if(EEPROM.read(5)<H&&i==20)
          {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33,0); 
          digitalWrite(25, 1);
          delay(200);
          }       

      if(EEPROM.read(5)==H&&i==20)
          {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);
          i=21;
          delay(200);
          }   
       if( tilt<EEPROM.read(4)&&i==21)
          {
          digitalWrite(26, 1); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);  
          delay(200);
   
          }
       if(i==21&& tilt>EEPROM.read(4))
          {
          digitalWrite(26, 1); 
          digitalWrite(32, 1);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);
          delay(200);
   
          }

               
      if(i==21&& tilt==EEPROM.read(4))
       {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);
          i=1;
          delay(200);
       }
          

    //local mode 3


       if(EEPROM.read(7)>H&&i==25)
          {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 1); 
          digitalWrite(25, 1);
          delay(200);
          }
       if(EEPROM.read(7)<H&&i==25)
          {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33,0); 
          digitalWrite(25, 1);
          delay(200);
          }       

        if(EEPROM.read(7)==H&&i==25)
          {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);
          i=26;
          delay(200);
          }   
        if( tilt<EEPROM.read(6)&&i==26)
          {
          digitalWrite(26, 1); 
          digitalWrite(32, 1);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);  
          delay(200);
   
          }
      if(i==26&& tilt>EEPROM.read(6))
          {
          digitalWrite(26, 1); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);
          delay(200);
   
          }

               
      if(i==26 && tilt==EEPROM.read(6))
       {
          digitalWrite(26, 0); 
          digitalWrite(32, 0);
          digitalWrite(33, 0); 
          digitalWrite(25, 0);
          i=1;
          delay(200);
       }

    
    }
    
