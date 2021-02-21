#include <dht.h>

#define temperature_sensor_pin A0; //Analog input for Temperature Sensor on A0 Pin
#define moisture_Sensor_pin A1; //Analog input for Moisture Sensor on A1 Pin

float temperature_value = 0;
int moisture_value=0;

dht DHT; //Intialization of DHT Library variable

void setup()
{
    Serial.begin(9600);
    serial.println("Started Reading from Temperature and Moisture Sensor")
    delay(1000); //Delay to let system boot
}

void loop()
{
    DHT.read11(temperature_sensor_pin);
    
    Serial.print("Current Humidity on the Plant = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("Current Temperature on the Plant = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");


    for (int i = 0; i <= 100; i++) 
        { 
        moisture_value = moisture_value + analogRead(moisture_Sensor_pin); //Adding current Mositure Sensor value to moisture_sensor variable
        delay(100); //Letting time sensor to capture next data
        } 
    moisture_value = moisture_value/100.0; //Converting Moisture Value into Percentage
    Serial.println(moisture_value); 
    delay(30); 
    
    delay(5000);//Wait 5 seconds before accessing  Temperature and Humidity sensor again.
}