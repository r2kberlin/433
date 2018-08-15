#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();

//const int RADAR_SENSOR = 8;
//const int RadarLED = 12;
//int val = 0;

int bewegungsstatus=0;
int PIR_SENSOR = 8;
//int PirLED = 5;
int PirVCC=12;
int PirGCC=11; 

void setup() {
//  Serial.begin(9600); //4Radar
//  
//  pinMode (RADAR_SENSOR, INPUT);
//  pinMode (RadarLED, OUTPUT);
mySwitch.enableTransmit(7);
  pinMode(PIR_SENSOR, INPUT);
 //pinMode(PirLED, OUTPUT);
 pinMode(PirVCC, OUTPUT);
 pinMode(PirGCC, OUTPUT);
  digitalWrite(PirVCC, HIGH);  //VCC für PIR Modul
  digitalWrite(PirGCC, LOW);  //VCC für PIR Modul
}
 
void loop() {
//  int value = digitalRead(RADAR_SENSOR);
//  digitalWrite(RadarLED, value > 0 ? HIGH : LOW);
//  delay(1000);



//digitalWrite(11, LOW);   für PIR Modul

bewegungsstatus=digitalRead(PIR_SENSOR); //Hier wird der Pin7 ausgelesen (Befehl:digitalRead). Das Ergebnis wird unter der Variable „bewegungsstatus“ mit dem Wert „HIGH“ für 5Volt oder „LOW“ für 0Volt gespeichert.

if (bewegungsstatus == HIGH)              //Verarbeitung: Wenn der bewegungsstatus ist (Das Spannungssignal ist hoch)
{                                       //Programmabschnitt des IF-Befehls öffnen.
  {

mySwitch.send(21696, 24); // Der 433mhz Sender versendet die Dezimalzahl „21696
delay (50); 

    
//  digitalWrite(PirLED, HIGH);
//  delay(5000);
//  digitalWrite(PirLED, LOW);
  }
}
//else
//  {
//  digitalWrite(PirLED, LOW);
//  }
 // int s = digitalRead(PirPin);
 // digitalWrite(PirLED, s);
}


