#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <Arduino.h>
#include <Scheduler.h>
#include <SoftwareSerial.h>
#define ESP_SPI_FREQ 4000000
SoftwareSerial mySerial(13, 12); // RX, TX

Adafruit_MCP4725 MCP4725;
unsigned char v=1,u=2,m=2,n=1,k=1;
String i; 
char x;
 uint32_t MCP4725_value;
 float MCP4725_reading,MCP4725_set;


class PrintTask : public Task {
protected:


  void setup() 
     {
  
       mySerial.begin(9600);
       Serial.begin(9600);
        MCP4725.begin(0x60); // The I2C Address of my module 
         MCP4725.setVoltage(0, false);
         pinMode(15, INPUT);
         pinMode(14, OUTPUT);
         digitalWrite(14, 0);
         pinMode(2, INPUT);
    
       }
   void loop() {

        if (mySerial.available() > 0) 
           {
              i = mySerial.read();
            //   Serial.print(i);
       if( i=="17")
             {
              
                mySerial.print("p1.pic=1");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
                mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
                mySerial.write(0xff);
                mySerial.write(0xff); 
                m=2;
                  
             }
           
        
       if( i=="18")
             {
            
                mySerial.print("p1.pic=2");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
                mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
                mySerial.write(0xff);
                mySerial.write(0xff); 
                m=3;
                 
           
            }

   
        
       if( i=="19"&&m==2)     
       
       {
             
           v=v+1;
           
          if(v>=3)
          {
            v=1;
           }
          if(v==2)
           {
               u=3;
               n=3;
            mySerial.print("p3.pic=5");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
            mySerial.print("p2.pic=6");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff); 
 
           }
           
          
        if(v==1)
          {
              u=2;
              n=1;
          
            mySerial.print("p2.pic=7");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff); 
            
            mySerial.print("p3.pic=4");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);

           }  
       }          
        if( i=="20"&&m==2)
           {
             u=2;
             n=1;
            mySerial.print("p3.pic=4");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
            mySerial.print("p2.pic=7");  
             mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff); 
 
           } 
            

         if( i=="21"&&m==2)
           
          {
             u=1;
             n=2;
            mySerial.print("p3.pic=8");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);  
             mySerial.print("p2.pic=7");  
             mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);    
          }



          if( i=="22"&&m==2)
           {
            
            mySerial.print("p0.pic=10");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff); 
           } 

         if( i=="23"&&m==2 )
           
         {  k=1;
             mySerial.print("p0.pic=9");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
             mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
             mySerial.write(0xff);
             mySerial.write(0xff);
             mySerial.print("n1.val=0");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
             mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
             mySerial.write(0xff);
             mySerial.write(0xff);
             MCP4725.setVoltage(0, false);

               
        }

        if( i=="24"&&m==2 ) 
        {
          k=2;
          mySerial.print("p0.pic=11");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff); 
          mySerial.print("n1.val=3000");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          MCP4725.setVoltage(2000, false);
          
                  
        }


        if( i=="25"&&m==2 )
        
        {
          k=3;
           mySerial.print("p0.pic=13");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
           mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
           mySerial.write(0xff);
           mySerial.write(0xff);
           mySerial.print("n1.val=5000");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
             mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
             mySerial.write(0xff);
             mySerial.write(0xff);
          MCP4725.setVoltage(2500, false);

     
               
        }

        if( i=="32"&&m==2 )
       
        {
          k=4;
         mySerial.print("p0.pic=12");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
         mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
           mySerial.print("n1.val=7000");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
             mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
             mySerial.write(0xff);
             mySerial.write(0xff);          
         MCP4725.setVoltage(4090, false);
 
        }      
       }


        if (digitalRead(2) == LOW && m==3)
        {
         delay(100);
         if (digitalRead(2) != 0 && m==3)
           {
            k=k+1;
           }
         if(k>=5)
         {
          k=1;
         }
        }

           if( k==1 && m==3)
       
        {
             mySerial.print("p0.pic=9");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
             mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
             mySerial.write(0xff);
             mySerial.write(0xff);
             mySerial.print("n1.val=0");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
             mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
             mySerial.write(0xff);
             mySerial.write(0xff);
             MCP4725.setVoltage(0, false);
             //delay(300);
 
        }

           
        if( k==2 && m==3 ) 
        {
             mySerial.print("p0.pic=11");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
             mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
             mySerial.write(0xff);
             mySerial.write(0xff); 
             mySerial.print("n1.val=3000");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
             mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
             mySerial.write(0xff);
             mySerial.write(0xff);
             MCP4725.setVoltage(2000, false);
            
          
                  
        }

          if( k==3 && m==3)
        
        {
           mySerial.print("p0.pic=13");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
           mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
           mySerial.write(0xff);
           mySerial.write(0xff);
           mySerial.print("n1.val=5000");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
           mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
           mySerial.write(0xff);
           mySerial.write(0xff);
           MCP4725.setVoltage(2500, false);
       
               
        }

        if( k==4 && m==3)
       
        {
         mySerial.print("p0.pic=12");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
         mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
         mySerial.write(0xff);
         mySerial.write(0xff);
         mySerial.print("n1.val=7000");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
         mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
         mySerial.write(0xff);
         mySerial.write(0xff);          
         MCP4725.setVoltage(4090, false);
       
        }
        
        

     if (digitalRead(15) == 1&&m==3)
        {
         delay(100);
         if (digitalRead(15) != 1 && m==3)
           {
            n=n+1;
           }
        if(n>=4)
         {
          n=1;
         }
        }

         if( n==1 && m==3)
           {
             u=2;
            mySerial.print("p3.pic=4");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
            mySerial.print("p2.pic=7");  
             mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff); 
          
 
           } 


         if( n==2&&m==3)
           
          {
             u=1;
            mySerial.print("p3.pic=8");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);  
             mySerial.print("p2.pic=7");  
             mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff); 
              
          }

      if(n==3&&m==3)
           {
               u=3;
            mySerial.print("p3.pic=5");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
            mySerial.print("p2.pic=6");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
          
           }
       
      }
     }print_task;   
  class BlinkTask : public Task 
  {
       protected:

   void setup() {
       
           pinMode(14, OUTPUT);
          digitalWrite(14, 0);
       
       }

    void loop()
    {
    
      if(u==3)
      {
      digitalWrite(14, 1);
      delay(350);   
      digitalWrite(14, 0);
       delay(350);
      }      


         if(u==1)
      {
   
       digitalWrite(14, 0);
      }

        if(u==2)
      {

       digitalWrite(14, 1);
     
      } 
          
     }
 
           private:
           uint8_t state;
        } blink_task;

void setup() {
   


    Scheduler.start(&blink_task);
    Scheduler.start(&print_task);
    Scheduler.begin();

}
void loop()
{

    
}
