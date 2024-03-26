#include <NewPing.h>

int ECHO = 7;
int TRIG = 11;
int maxdist=150;
int Traveltime;
float distance; // used float to avoid zero in result
NewPing sonar (TRIG,ECHO,maxdist); //create object sonar
void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
   pinMode(ECHO,INPUT);

}

void loop() {
  Traveltime= sonar.ping();
   distance = (Traveltime/2)*0.0343;
    Serial.print(distance);Serial.println("cm ");
    delay(1000);

}
/*
#include <NewPing.h> // include NewPing library
int trigPin = 7; // trigger pin
int echoPin = 8; // echo pin
int maxdist = 100; // set maximum scan distance (cm)
int echoTime; // echo time
float distance;
NewPing sonar(trigPin, echoPin , maxdist); // associate sonar with
// NewPing library
void setup()
{
Serial.begin(9600); // set baud rate for Serial Monitor
}
void loop()
{
echoTime = sonar.ping(); // echo time (μs)
distance = (echoTime/2.0)*0.0343; // distance between sensor and target
Serial.print("echo time: "); // print text "echo time: "
Serial.print(echoTime); // print echo time
Serial.print(" microsecs\t"); // print text " microsecs" and tab
Serial.print("distance: "); // print text "distance: "
Serial.print(distance,2); // print distance with 2 DP
Serial.println(" cm"); // " cm" followed by a new line
delay(500);
}*/