#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();


const int RADAR_SENSOR = 8;
const int RadarLED = 12;
int val = 0;

int bewegungsstatus=0;
int PIR_SENSOR = 6;
int PirLED = 5;

 
void setup() {
  Serial.begin(9600); //4Radar
  
  pinMode (RADAR_SENSOR, INPUT);
  pinMode (RadarLED, OUTPUT);

  pinMode(PIR_SENSOR, INPUT);
  pinMode(PirLED, OUTPUT);

  
}
 
void loop() {
  int value = digitalRead(RADAR_SENSOR);
  digitalWrite(RadarLED, value > 0 ? HIGH : LOW);
  delay(1000);

bewegungsstatus=digitalRead(PIR_SENSOR); //Hier wird der Pin7 ausgelesen (Befehl:digitalRead). Das Ergebnis wird unter der Variable „bewegungsstatus“ mit dem Wert „HIGH“ für 5Volt oder „LOW“ für 0Volt gespeichert.

if (bewegungsstatus == HIGH)//Verarbeitung: Wenn der bewegungsstatus ist (Das Spannungssignal ist hoch)
{//Programmabschnitt des IF-Befehls öffnen.
  {
  digitalWrite(PirLED, HIGH);
  delay(5000);
  digitalWrite(PirLED, LOW);
  }
}
else
  {
  digitalWrite(PirLED, LOW);
  }
 // int s = digitalRead(PirPin);
 // digitalWrite(PirLED, s);
}


