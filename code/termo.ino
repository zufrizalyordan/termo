/*
  @zufrizalyordan
  zufrizalyordan@gmail.com
*/

#include <TinyWireM.h>
#include <Adafruit_MiniMLX90614.h>
#include <Tiny4kOLED.h>

double stemp = 0;
double amb = 0;

Adafruit_MiniMLX90614 mlx = Adafruit_MiniMLX90614();

void setup()
{
    mlx.begin();

    oled.begin();
    oled.setFont(FONT8X16);
    oled.clear();
    oled.on();
    oled.switchRenderFrame();
}

void loop()
{
    updateDisplay();
    delay(2500);
}

void updateDisplay()
{
    oled.clear();
    // Ambil pembacaan dan simpan nilai tersebut
    for (int x = 0; x < 10; x++)
    {
        stemp = mlx.readObjectTempC();
        amb = mlx.readAmbientTempC();
    }

    oled.print("Lokasi: ");
    oled.print(amb);
    oled.print("C");

    oled.print("\nBadan: ");
    oled.print(stemp);
    oled.print("C");
    oled.switchFrame();
}