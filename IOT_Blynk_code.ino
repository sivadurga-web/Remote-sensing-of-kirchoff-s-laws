#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "K38msFmGbPVsgTsmcJFg2dSqKREMt7l-";
char ssid[] = "AndroidAP";
char pass[] = "11111111";

WidgetTerminal terminal(V2);
//BlynkTimer timer;
double v1 = 2.2,v2 =1.2,v3 = 1.6;
double i1 = 0.1,i2 = 0.3,i3 = 0.2;
int button_1_value = 0,button_2_value = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
BLYNK_WRITE(V0)
{
   button_1_value = param.asInt();
}
BLYNK_WRITE(V1)
{
   button_2_value = param.asInt();
}
BLYNK_WRITE(V2)
{
  terminal.println("OUTPUT voltages");
  terminal.println(String(v1) +" V");
  terminal.println(String(v2) +" V");
  terminal.println(String(v3) + " V");
  terminal.println("Currents");
  terminal.println(String(i1) + " A");
  terminal.println(String(i2) + " A");
  terminal.println(String(i3) +" A");
  terminal.flush();
}
