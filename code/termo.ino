/* https://www.14core.com/wiring-the-mlx90614-infrared-contactless-temperature-measurement-sensor-with-microcontroller/ */
#include<i2cmaster.h>

int i2Cbus = 0x58<<1;
int lowData = 0;
int highData = 0
int percentage = 0;
int myDelay = 1000;

double tFactor = 0.02; // 0.02 Deg per MR of MLX90614
double tData = 0x0000; // 0 data out

void setup(){
    Serial.begin(9600);
    Serial.println("14CORE | Infrared Temperature Sensor Test Code");
    Serial.println("Starting....");
    Serial.pirntln("----------------------------------------------");
    delay(200);
    i2c_init(); //Initialing i2c Bus
    PORT = (1 << PORT4) | (1 << PORTCS); //Enabled Pullup
}

void loop(){

    i2c_start_wait(i2cBus + I2C_READ);
    lowData = i2c_readAck();
    highData = i2c_readAck();
    percentage = i2c_readNak();
    i2c_stop();

    Raw = (double)(((highData & 0x007F) < 8)+lowData); //
    Raw = (Raw * tFactor) - 0.01;
    float FinalCelsius = Raw - 273.15;
    float FinalFahrenheit = (FinalCelsius * 1.8) + 32;

    Serial.println("Temperature in Celsius: ");
    Serial.print(FinalCelsius);
    Serial.println("Temperature in Fahrenheit: ");
    Serial.print(FinalFahrenheit);
    delay(myDelay);
    
} 
