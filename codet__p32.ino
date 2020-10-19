#include <Wire.h>
#include <RTC.h>
static DS3231 RTC;
#include <EEPROM.h>
#include <OneWire.h>
#include <DallasTemperature.h>
const int oneWireBus = 32; 
int tt=30 ;  
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);
#define RXD2 18
#define TXD2 19
const int potPin = 34;
const int potPin1 = 35;
int potValue=0 , potValue1=0;
unsigned char v=1,u=1;
String i;
int n=0; 
int  a1=0,a2=0,a3=0,a4=0,a5=0,a6=0;
int  tem1=30,tem22=30;
int  aa1=0,aa2=0,aa3=0,aa4=0,aa5=0,aa6=0;
int lamp1=0,lamp2=0,lamp11=0,lamp22=0,lp1,lp2=0;
int h1=0,m1=0,h2=0,m2=0,h3,m3,kk=1,ht1,mt1,ht2,mt2,ht3,mt3;
int Celcius=0;
char x;
int ch ;


TaskHandle_t Task1;
TaskHandle_t Task2;



void setup() {

  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  RTC.begin();
  RTC.setHourMode(CLOCK_H24);
  RTC.setTime(0,0,50);
  sensors.begin();
   
   Serial2.print("page page0");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
   Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial2.write(0xff);
   Serial2.write(0xff);
   pinMode(33, OUTPUT);
   pinMode(25, OUTPUT);
   pinMode(26, OUTPUT);
   pinMode(27, OUTPUT);
   pinMode(13, OUTPUT);
   pinMode(23, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(16, OUTPUT);
   pinMode(17, OUTPUT);
   pinMode(2, OUTPUT);

   
   pinMode(36, INPUT);
   pinMode(39, INPUT);
   pinMode(34, INPUT);
   pinMode(35, INPUT);
   pinMode(32, INPUT);

  // attach the channel to the GPIO to be controlled
  ledcAttachPin(26, 1); // assign RGB led pins to channels
  ledcAttachPin(27, 2); // assign RGB led pins to channels
  ledcAttachPin(13, 3);

  //húdfjfbsbgfsd
  ledcAttachPin(2, 4); // assign RGB led pins to channels
  ledcAttachPin(4, 5); // assign RGB led pins to channels
  ledcAttachPin(16, 6);
  ledcAttachPin(17, 7);

  ledcSetup(1, 2000, 8); // 12 kHz PWM, 12-bit resolution
  ledcSetup(2, 2000, 8); // 12 kHz PWM, 12-bit resolution
  ledcSetup(3, 2000, 8); // 12 kHz PWM, 12-bit resolution
  ledcSetup(4, 2000, 8); // 12 kHz PWM, 12-bit resolution
  ledcSetup(5, 2000, 8); // 12 kHz PWM, 12-bit resolution
  ledcSetup(6, 2000, 8); // 12 kHz PWM, 12-bit resolution
  ledcSetup(7, 2000, 8); // 12 kHz PWM, 12-bit resolution
  
   
  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
                    Task1code,   /* Task function. */
                    "Task1",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task1,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */                  
 // delay(500); 

  //create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
                    Task2code,   /* Task function. */
                    "Task2",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task2,      /* Task handle to keep track of created task */
                    1);          /* pin task to core 1 */
///delay(500); 
}

//Task1code: blinks an LED every 1000 ms
void Task1code( void * pvParameters ){
//pinMode(2, OUTPUT);

  for(;;){
   potValue1 = analogRead(potPin1); 
 
  sensors.requestTemperatures(); 
  int temperatureC = sensors.getTempCByIndex(0);

  Serial2.print("n8.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial2.print(temperatureC);
   Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial2.write(0xff);
   Serial2.write(0xff);
   Serial2.print("n13.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
   Serial2.print(RTC.getHours());
   Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial2.write(0xff);
   Serial2.write(0xff);
   Serial2.print("n14.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
   Serial2.print(RTC.getMinutes());
   Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
   Serial2.write(0xff);
   Serial2.write(0xff);

  // Serial.print(potValue1);
   delay(1000);
    //vTaskDelay(1);
   
if (temperatureC>=tt)
  {

     ledcWrite(4, 0);
  }
if (temperatureC<tt)
  {
   ledcWrite(4, 255);
  } 

 if (potValue1 > 240) 
    {  
       Serial2.print("p9.pic=4");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
        digitalWrite(25,0);
        
    }
  if (potValue1 <=240) 
    {
       digitalWrite(25, HIGH);
       Serial2.print("p9.pic=5");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
       Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
       Serial2.write(0xff);
       Serial2.write(0xff);       
    }  
   ht3= (RTC.getHours()*60)+RTC.getMinutes();
   ht1= (h1*60)+m1;
   ht2= (h2*60)+m2;
   if (ht1<= ht3 <ht2 )
    {
      digitalWrite(33, HIGH);
 
    }
   if (ht1>ht3 || ht3>=ht2 )
    {
      digitalWrite(33, 0);
 
    }
  if (ht1==ht3==ht2 )
    {
      digitalWrite(33, 0);
 
    }
  }
  }
//Task2code: blinks an LED every 700 ms
void Task2code( void * pvParameters ){
  EEPROM.begin(512);

  for(;;){
  
   if (Serial2.available() > 0) 
    {
       i = Serial2.read();
        Serial.print(i);
      // Serial.print(potValue1);

   if(i=="48")
      { 
   ledcWrite(3, 255);
      }

   if(i=="49")
      { 
    ledcWrite(3, 0);
      }
   if(i=="50")
      { 
        kk==1;
       Serial2.print("n0.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(h1);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);

         Serial2.print("n11.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(m1);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
        
         Serial2.print("n5.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(h2);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
        
        Serial2.print("n12.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(m2);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
      }
   if(i=="51")                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
      { 
      //digitalWrite(33, 0);
      }

    if(i=="86")
      { 
      digitalWrite(25, HIGH);
      //  vTaskDelay(40/portTICK_PERIOD_MS ); 
        Serial2.print("n1.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(lamp11);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
      digitalWrite(25, 0);
      }
      //
      if(i=="84")
      { 
        kk=kk+1;
       
        if(1>kk)
        {
       kk=1;
       
        }
      
        if(kk>4)
       {
        kk=1;  
        }

        
      }
  
  if(i=="82"&& kk==1)
      { 
         h1=h1-1;
       
        if(0>h1)
        {
       h1=0;
       
        }
      
        if(h1>24)
       {
        h1=24;  
        }
        Serial2.print("n0.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(h1);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
       
      }
   if(i=="83"&& kk==1)
      { 
      
         h1=h1+1;
       
        if(0>h1)
        {
       h1=0;
       
        }
      
        if(h1>24)
       {
        h1=24;  
        }
        Serial2.print("n0.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(h1);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
      }

     if(i=="82"&& kk==2)
      { 
         m1=m1-1;
       
        if(0>m1)
        {
       m1=0;
       
        }
      
        if(m1>60)
       {
        m1=60;  
        }
        Serial2.print("n11.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(m1);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
       
      }
   if(i=="83"&& kk==2)
      { 
      
         m1=m1+1;
       
        if(0>m1)
        {
       m1=0;
       
        }
      
        if(m1>60)
       {
        m1=60;  
        }
        Serial2.print("n11.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(m1);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
      }

   if(i=="82"&& kk==3)
      { 
         h2=h2-1;
       
        if(0>h2)
        {
       h2=0;
       
        }
      
        if(h2>24)
       {
        h2=24;  
        }
        Serial2.print("n5.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(h2);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
       
      }
   if(i=="83"&& kk==3)
      { 
      
         h2=h2+1;
       
        if(0>h2)
        {
       h2=0;
       
        }
      
        if(h2>24)
       {
        h2=24;  
        }
        Serial2.print("n5.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(h2);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
      }

     if(i=="82"&& kk==4)
      { 
         m2=m2-1;
       
        if(0>m2)
        {
       m2=0;
       
        }
      
        if(m2>60)
       {
        m2=60;  
        }
        Serial2.print("n12.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(m2);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
       
      }
   if(i=="83"&& kk==4)
      { 
      
         m2=m2+1;
       
        if(0>m2)
        {
       m2=0;
       
        }
      
        if(m2>60)
       {
        m2=60;  
        }
        Serial2.print("n12.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(m2);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
      }


   if(i=="97")
      { 
      digitalWrite(25, HIGH);
     // vTaskDelay(40/portTICK_PERIOD_MS );
        Serial2.print("n7.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(tt);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
       digitalWrite(25, 0);
      }

   if(i=="80")
      { 
      digitalWrite(25, HIGH);
      tt=tt-1;
       if(30>tt)
        {
       tt=30;
       
        }
      
        if(tt>40)
       {
        tt=40;  
        }
     // vTaskDelay(40/portTICK_PERIOD_MS );
        Serial2.print("n7.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(tt);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
       digitalWrite(25, 0);
      }
    if(i=="81")
      { 
      digitalWrite(25, HIGH);
      tt=tt+1;
       if(30>tt)
        {
       tt=30;
       
        }
      
        if(tt>40)
       {
        tt=40;  
        }
     // vTaskDelay(40/portTICK_PERIOD_MS );
        Serial2.print("n7.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(tt);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
       digitalWrite(25, 0);
      }
   if(i=="87")
      { 
      digitalWrite(25, HIGH);
     // vTaskDelay(40/portTICK_PERIOD_MS );
        Serial2.print("n2.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(lamp22);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
       digitalWrite(25, 0);
      }

   if(i=="88")
      { 
      digitalWrite(25, HIGH);
     //  vTaskDelay(40/portTICK_PERIOD_MS );
        Serial2.print("n3.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(aa2);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
       digitalWrite(25, 0);
      }

   if(i=="89")
      { 
      digitalWrite(25, HIGH);
     //  vTaskDelay(40/portTICK_PERIOD_MS );
         Serial2.print("n4.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(aa3);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
       digitalWrite(25, 0);
      }


     if(i=="96")
      { 
      digitalWrite(25, HIGH);
     //  vTaskDelay(40/portTICK_PERIOD_MS );
      //  mySerial.print("n6.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(aa1);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
       digitalWrite(25, 0);
      }

      ///
   if(i=="113"||i=="100")
      { 
        
       digitalWrite(25, HIGH);
     //  vTaskDelay(40/portTICK_PERIOD_MS );
       
        Serial2.print("n1.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
       Serial2.print(lamp11);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);

        Serial2.print("n2.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(lamp22);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);

        Serial2.print("n3.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(aa2);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);

        Serial2.print("n4.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(aa3);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);

        Serial2.print("n6.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(aa1);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
   
        Serial2.print("n7.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(tt);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
        digitalWrite(25, 0);
        
       }
 //lamp1
   if(i=="64")
      { 
       digitalWrite(25, HIGH);
        lamp1=lamp1-1;
        
        if(0>lamp1)
        {
       lamp1=0;
       
        }
      
        if(lamp1>10)
       {
        lamp1=10;  
        }
     //  vTaskDelay(40/portTICK_PERIOD_MS );
        //lamp11=(lamp1-1)*10;
       Serial2.print("n1.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
       Serial2.print(lamp11);
       Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
       Serial2.write(0xff);
       Serial2.write(0xff);
      digitalWrite(25, 0);
       }
       lamp11=(lamp1)*10;
 
    if(i=="65")
       {
        digitalWrite(25, HIGH);
        lamp1=lamp1+1;
        
        if(0>lamp1)
        {
       lamp1=0;
       
        }
      
        if(lamp1>10)
       {
        lamp1=10;  
        }
     //   vTaskDelay(40/portTICK_PERIOD_MS );
       // lamp11=(lamp1-1)*10;
       Serial2.print("n1.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
       Serial2.print(lamp11);
       Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
       Serial2.write(0xff);
       Serial2.write(0xff);
        digitalWrite(25, 0);    
      }      
    //lamp2
   if(i=="66")
      { 
       digitalWrite(25, HIGH);
       lamp2=lamp2 - 1;
        if(0>lamp2)
        {
       lamp2=0;
       
        }
      
        if(lamp2>10)
       {
        lamp2=10;  
        }
    //   vTaskDelay(40/portTICK_PERIOD_MS );
       
      //  lamp22=lamp2*10;
       Serial2.print("n2.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
       Serial2.print(lamp22);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
        digitalWrite(25, 0);
     
       }
       lamp22=lamp2*10;
 
    if(i=="67")
       {
        digitalWrite(25, HIGH);
        lamp2=lamp2+1;
        
      if(0>lamp2)
        {
       lamp2=0;
       
        }
      
        if(lamp2>10)
       {
        lamp2=10;  
        }
     //  vTaskDelay(40/portTICK_PERIOD_MS );
        
        //lamp22=lamp2*10;
        Serial2.print("n2.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(lamp22);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
        digitalWrite(25, 0);
      
      }
      
         
  //dry
   if(i=="68")
      { 
       digitalWrite(25, HIGH);
       EEPROM.write(1,EEPROM.read(1)-1);
        EEPROM.commit();
        delay(5);
        if(1>EEPROM.read(1))
        {
       EEPROM.write(1,1);
       EEPROM.commit();
        delay(5);
       
        }
      
        if(EEPROM.read(1)>11)
       {
        EEPROM.write(1,11); 
        EEPROM.commit();
        delay(5); 
        }
      //  vTaskDelay(40/portTICK_PERIOD_MS );
     /// aa1=(EEPROM.read(1)-1)*10;
        Serial2.print("n6.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(aa1);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
        digitalWrite(25, 0);
       
     
       }

       aa1=(EEPROM.read(1)-1)*10;
       EEPROM.commit();
       delay(5);
    if(i=="69")
       {
        digitalWrite(25, HIGH);
        EEPROM.write(1,EEPROM.read(1)+1);
        EEPROM.commit();
        delay(5);
        if(1>EEPROM.read(1))
        {
       EEPROM.write(1,1);
       EEPROM.commit();
        delay(5);
       
        }
      
        if(EEPROM.read(1)>11)
       {
        EEPROM.write(1,11);  
        EEPROM.commit();
        delay(5);
        }
     //  vTaskDelay(40/portTICK_PERIOD_MS );
       // aa1=(EEPROM.read(1)-1)*10;
        Serial2.print("n6.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(aa1);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
       Serial2.write(0xff);
       digitalWrite(25, 0);
        
      }
        ///

 ////pump1
     if(i=="70")
      { 
       digitalWrite(25, HIGH);
       EEPROM.write(2,EEPROM.read(2)-1);
       EEPROM.commit();
        delay(5);
       if(1>EEPROM.read(2))
        {
       EEPROM.write(2,1);
       EEPROM.commit();
        delay(5);
       
        }
      
        if(EEPROM.read(2)>11)
       {
        EEPROM.write(2,11);
        EEPROM.commit();
        delay(5);  
        }
     //   vTaskDelay(40/portTICK_PERIOD_MS );
        
      // aa2=(EEPROM.read(2)-1)*10;
        Serial2.print("n3.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(aa2);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
        digitalWrite(25, 0);
     
       }
     
      aa2=(EEPROM.read(2)-1)*10;
      EEPROM.commit();
        delay(5);
    if(i=="71")
       {
        digitalWrite(25, HIGH);
        EEPROM.write(2,EEPROM.read(2)+1);
        EEPROM.commit();
        delay(5);

       if(1>EEPROM.read(2))
        {
       EEPROM.write(2,1);
       EEPROM.commit();
        delay(5);
       
        }
      
        if(EEPROM.read(2)>11)
       {
        EEPROM.write(2,11); 
        EEPROM.commit();
        delay(5); 
        }
    //   vTaskDelay(40/portTICK_PERIOD_MS );
       // aa2=(EEPROM.read(2)-1)*10;
        Serial2.print("n3.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(aa2);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
       Serial2.write(0xff);
       digitalWrite(25, 0);
      }

     ///////////////// 
   if(i=="72")
      { 
       digitalWrite(25, HIGH);
       EEPROM.write(3,EEPROM.read(3)-1);
       EEPROM.commit();
        delay(5);
       
       if(1>EEPROM.read(3))
        {
       EEPROM.write(3,1);
       EEPROM.commit();
        delay(5);
       
        }
      
        if(EEPROM.read(3)>11)
       {
        EEPROM.write(3,11);  
        EEPROM.commit();
        delay(5);
        }
    //   vTaskDelay(40/portTICK_PERIOD_MS );
      // aa3=(EEPROM.read(3)-1)*10;
        Serial2.print("n4.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(aa3);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
        digitalWrite(25, 0);
     
       }
     aa3=(EEPROM.read(3)-1)*10;
     EEPROM.commit();
        delay(5);
 
    if(i=="73")
       {
        digitalWrite(25, HIGH);
        EEPROM.write(3,EEPROM.read(3)+1);
        EEPROM.commit();
        delay(5);
        
        if(1>EEPROM.read(3))
        {
       EEPROM.write(3,1);
       EEPROM.commit();
        delay(5);
       
        }
      
        if(EEPROM.read(3)>11)
       {
        EEPROM.write(3,11);  
        EEPROM.commit();
        delay(5);
        }
    //   vTaskDelay(40/portTICK_PERIOD_MS );
     //  aa3=(EEPROM.read(3)-1)*10;
        Serial2.print("n4.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(aa3);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
         digitalWrite(25, 0);
      }

  ///temperture

    if(i=="74")
      { 
       digitalWrite(25, HIGH);
       EEPROM.write(4,EEPROM.read(4)-1);
       EEPROM.commit();
        delay(5);
    //   vTaskDelay(40/portTICK_PERIOD_MS );
      //  aa4=(EEPROM.read(4)-1)*10;
        Serial2.print("n13.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(aa4);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
        digitalWrite(25, 0);
     
       }
     aa4=(EEPROM.read(4)-1)*10;
     EEPROM.commit();
        delay(5);
    if(i=="75")
       {
        digitalWrite(25, HIGH);
        EEPROM.write(4,EEPROM.read(4)+1);
        EEPROM.commit();
        delay(5);
     //   vTaskDelay(40/portTICK_PERIOD_MS );
        //aa4=(EEPROM.read(4)-1)*10;
        Serial2.print("n13.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial2.print(aa4);
        Serial2.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial2.write(0xff);
        Serial2.write(0xff);
       digitalWrite(25, 0);
      }
 ////////////
      ////
      if(1>=EEPROM.read(4))
        {
       EEPROM.write(4,1);
       EEPROM.commit();
        delay(5);
       
        }
      
        if(EEPROM.read(4)>11)
       {
        EEPROM.write(4,11);  
        EEPROM.commit();
        delay(5);
        }

       }

     lp1=lamp22 * 2.55;
     lp2=lamp11 * 2.55;
    ledcWrite(5, lp1);
    ledcWrite(6, lp2);

   potValue = analogRead(potPin);
  // potValue1 = analogRead(potPin1);
    if (potValue > 650) 
    {
     ledcWrite(7, 0);
   
    }
     if (potValue <= 650) 
    {
    
      ledcWrite(7, a1);
    }

   
 
   if (digitalRead(36)== HIGH) {
    // turn LED on:
    ledcWrite(1, a2);
  }
     if (digitalRead(36)== 0) {
    // turn LED on:
    ledcWrite(1, 0);
  }
     if (digitalRead(39)== HIGH) {
    // turn LED on:
    ledcWrite(2, a3);
  }
     if (digitalRead(39)== 0) {
    // turn LED on:
    ledcWrite(2, 0);
  }


  
        a1=((EEPROM.read(1)-1)*20)+ 55;
      
        a2=((EEPROM.read(2)-1)*20)+ 55;

        a3=((EEPROM.read(3)-1)*20)+ 55;
       
        a4=((EEPROM.read(3)-1)*20)+ 55;
  }
}

void loop() {
  
}
