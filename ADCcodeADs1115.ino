

#include <Wire.h>
#include <Adafruit_ADS1015.h>
 
Adafruit_ADS1115 ads(0x48);
float Voltage1 ;
float Voltage2 ;
float Voltage3 ;
float Voltage4 ;
 
void setup(void)
{
Serial.begin(9600);
Serial.println("Hello!");
 
Serial.println("Getting single-ended readings from AIN0..3");
Serial.println("ADC Range: +/- 6.144V (1 bit = 3mV/ADS1015, 0.1875mV/ADS1115)");
// Descomentar el que interese
   ads.setGain(GAIN_TWOTHIRDS);  //+/- 6.144V  1 bit = 0.1875mV (default)
  // ads.setGain(GAIN_ONE);        +/- 4.096V  1 bit = 0.125mV
  // ads.setGain(GAIN_TWO);        +/- 2.048V  1 bit = 0.0625mV
  // ads.setGain(GAIN_FOUR);       +/- 1.024V  1 bit = 0.03125mV
  // ads.setGain(GAIN_EIGHT);      +/- 0.512V  1 bit = 0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    +/- 0.256V  1 bit = 0.0078125mV 
 
ads.begin();
}
 
void loop(void)
{
int16_t adc0, adc1, adc2, adc3;
 
adc0 = ads.readADC_SingleEnded(0);
adc1 = ads.readADC_SingleEnded(1);
adc2 = ads.readADC_SingleEnded(2);
adc3 = ads.readADC_SingleEnded(3);

 Voltage1 = (adc0 * 0.1875) / 1000;
 Voltage2 = (adc1 * 0.1875) / 1000;
 Voltage3 = (adc2 * 0.1875) /1000;
 Voltage4 = (adc3 * 0.1875) /1000;

float fadc1= adc1*0.1875;
float fadc3= adc3*0.1875;

Serial.print("AIN0: ");
Serial.println(adc0);
Serial.print("\tVoltage 1: ");
Serial.println(Voltage1);
Serial.print("AIN1: ");
Serial.println(fadc1);
Serial.print("\tVoltage 2: ");
Serial.println(Voltage2);
Serial.print("AIN2: ");
Serial.println(adc2);
Serial.print("\tVoltage 3: ");
Serial.println(Voltage3);
Serial.print("AIN3: ");
Serial.println(fadc3);
Serial.print("\tVoltage 4: ");
Serial.println(Voltage4);
Serial.println(" ");
 
delay(1000);
}
