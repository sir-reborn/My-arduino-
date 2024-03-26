
int ldr=A0;
int bulb=10;
int buzzer= 12;
int pir=8;
int pirstate= LOW;
int trig=11;
int echo =7;
int travelTime;
float distance;


void setup() {
 pinMode(ldr, INPUT);
 pinMode(pir, INPUT);
 pinMode(echo, INPUT);
 pinMode(trig, OUTPUT);
 pinMode(bulb, OUTPUT);
 pinMode(buzzer, OUTPUT);
 Serial.begin(9600);
 //digitalWrite(bulb, HIGH)
}

void loop() {
  int ldr_R = analogRead(ldr);
  //Serial.println(ldr_R);
  int pir_R= digitalRead(pir);
  Serial.println(pir_R);
 
    if (ldr_R>950)
    {
    if ( pir_R==HIGH && pirstate==LOW)
      {
     analogWrite(bulb,225);
     delay(3000);
      pirstate= HIGH;
      }

      else if (pirstate==HIGH && pir_R==LOW)
      {
       analogWrite(bulb,10);
       pirstate= LOW;
       delay(3000);
      }
    }
    else
  {
  analogWrite(bulb,0);
  delay(500);
  }

  digitalWrite(trig, LOW);
  delayMicroseconds(10);
   digitalWrite(trig, HIGH);
  delayMicroseconds(10);
   digitalWrite(trig, LOW);
  delayMicroseconds(10); 
  travelTime= pulseIn(echo, HIGH);
  distance = (travelTime/2.0)*0.0343;
  //Serial.println(distance);
  delay(100); //this prevents reading zero
  if (distance< 30 && distance>5)
  tone(buzzer,1000);
  else
  noTone(buzzer);

}
//a streer light project, that works only in the night. 
//in the night,it goes bright if it sense someone passing and
// blows an alarm if the person  reaches a distance of 1m.