#include <DHT.h>
#include <DHT_U.h>
#include <Servo.h>
//-------------------------------------------------------------------------------------------------------------------------------------------------
int dhtpin=4;
#define type DHT11
DHT dht(dhtpin, type);
float tempC;
float tempF;
float humidity;
int pot = A0;
int servo=9;
int state;
int prev_height=0;
int height;
String status;
Servo lock;
//************************************************
void setup() {
 Serial.begin(9600);
 lock.attach(9);
  lock.write(90);
  dht.begin();
}

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
void loop() {
  int pressure = analogRead(pot);
  height = map(pressure, 0,1023,0,1000);
  delay(300);
   flight_state1();
   flight_state2();
   flight_state3();
   flight_state4();
    humid();
  prev_height= height;
   if (state==HIGH)
   {
    if(height<=725)
    {
      lock.write(0);
      status= "Parachute open";
    }
   }
   else
  {
     lock.write(90);
    status= "Parachute closed";
  }
  }
  
  
//------------------------------------------------------------------------------------------------------------------------------------------------

  void flight_state1 ()
  {
      if (height>prev_height)
  {
    //Serial.println(" rocket is ascending ");
    delay(50);
    state=LOW;
  }
  }
   //------------------------------------------------------------------------------------------------------------------------------------------------
   void flight_state2 ()
   {
    if (prev_height>height)
  {
    //Serial.println(" rocket is descending ");
    delay(50);
    state=HIGH;
  }
   }
//------------------------------------------------------------------------------------------------------------------------------------------------
   void flight_state3 ()
   {
    if (prev_height==height)
  {
    //Serial.println(" rocket is not moving");
    delay(50);
    state=LOW;
  }
   }
//------------------------------------------------------------------------------------------------------------------------------------------------
   void flight_state4 ()
   {
    if (prev_height>=998)
  {
    //Serial.println(" rocket at apogee ");
    delay(50);
    state=LOW;
  }
   }
//------------------------------------------------------------------------------------------------------------------------------------------------
   void humid()
   {
    tempC= dht.readTemperature();
    tempF= dht.readTemperature(true);
    humidity= dht.readHumidity();
    //Serial.print("temp in C \t"); Serial.print("temp in F \t"); Serial.println("Humidity \t");
    Serial.print(height); Serial.print("cm \t");
    Serial.print(tempC); Serial.print("C \t"); 
    Serial.print(tempF); Serial.print("F \t"); 
   Serial.print(humidity); Serial.print("% \t");
   Serial.println(status); 
   delay(1000);

   }
//------------------------------------------------------------------------------------------------------------------------------------------------
// the task is to make sure a parachute open at 725, only when descending. we achieved this by comparing previous height to current, if the new heigh
//is higher then it is ascending.