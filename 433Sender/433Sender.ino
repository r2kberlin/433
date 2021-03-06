#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();

int taster=7; //Das Wort „taster“ steht jetzt für den Wert 7.
int tasterstatus=0; //Das Wort „tasterstatus“ steht jetzt zunächst für den Wert 0. Später wird unter dieser Variable gespeichert, ob der Taster gedrückt ist oder nicht.

void setup() //Hier beginnt das Setup.
{
  mySwitch.enableTransmit(10);  // Der Sender wird an Pin 10 angeschlossen
  pinMode(taster, INPUT); //Der Pin mit dem Taster (Pin 7) ist jetzt ein Eingang.

}
void loop()
{ //Mit dieser Klammer wird der Loop-Teil geöffnet.
tasterstatus=digitalRead(taster); //Hier wird der Pin7 ausgelesen (Befehl:digitalRead). Das Ergebnis wird unter der Variable „tasterstatus“ mit dem Wert „HIGH“ für 5Volt oder „LOW“ für 0Volt gespeichert.

if (tasterstatus == HIGH)//Verarbeitung: Wenn der taster gedrückt ist (Das Spannungssignal ist hoch)
{//Programmabschnitt des IF-Befehls öffnen.

mySwitch.send(5678, 24); // Der 433mhz Sender versendet die Dezimalzahl „5678“
delay (50); // 50 Millisekunden Pause
} //Programmabschnitt des IF-Befehls schließen.

else //...ansonsten...
{ //Programmabschnitt des else-Befehls öffnen.
mySwitch.send(1234, 24); // Der 433mhz Sender versendet die Dezimalzahl „1234“
} //Programmabschnitt des else-Befehls schließen.
} //Mit dieser letzten Klammer wird der Loop-Teil geschlossen.

