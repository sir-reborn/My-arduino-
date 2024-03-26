#include <DHT.h>
#include <DHT_U.h>


int dhtPin = 2; // PCB mounted DHT11 on pin 7
#define type DHT11
DHT dht(dhtPin, type); // an object dht is created in class DHT,it is initialised to the output pin and type. The DHT library needs to know which pin the DHT sensor is connected to in order to communicate with it.
float tempC;
float humidity;
float tempF;
void setup()
{
Serial.begin(9600); // define Serial output baud rateu
dht.begin();
delay(500);
}
void loop()
{

tempC = dht.readTemperature();
humidity= dht.readHumidity();
tempF= dht.readTemperature(true);

Serial.print("tempC: ");
Serial.print(tempC);
Serial.print("C");
Serial.print("\thumidity: ");
Serial.println(humidity);
Serial.print("\tempF: ");
Serial.print(tempF);
Serial.print("F");

delay(1000); // delay one second
}

