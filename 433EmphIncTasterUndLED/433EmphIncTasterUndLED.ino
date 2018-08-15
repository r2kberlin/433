
#include <RCSwitch.h>
#include <SoftwareSerial.h>
int LED=12;
int taster=6; //Das Wort „taster“ steht jetzt für den Wert 7.
int tasterstatus=0; //Das Wort „tasterstatus“ steht jetzt zunächst für den Wert 0. Später wird unter dieser Variable gespeichert, ob der Taster gedrückt ist oder nicht.
RCSwitch mySwitch = RCSwitch();

void setup() 
{
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Empfänger ist an Interrupt-Pin "0" - Das ist am UNO der Pin2
  pinMode(LED, OUTPUT); //Der Pin mit der LED (Pin13) ist jetzt ein Ausgang.
  pinMode(taster, INPUT); //Der Pin mit dem Taster (Pin 7) ist jetzt ein Eingang.
}

void loop() {
  
 tasterstatus=digitalRead(taster);

  if (tasterstatus == HIGH)
    {
      Serial.println("Unbekannter Code");
      digitalWrite(LED, HIGH);
      delay (500);   //und zwar für 0,5 Sekunden (500 Millisekunden).
      digitalWrite(LED, LOW); //danach soll die LED aus sein.
    } 



  
  if (mySwitch.available()) // Wenn ein Code Empfangen wird...
  {
	int value = mySwitch.getReceivedValue(); // Empfangene Daten werden unter der Variable "value" gespeichert.
	if (value  == 0) // Wenn die Empfangenen Daten "0" sind, wird "Unbekannter Code" angezeigt.
    {
      Serial.println("Unbekannter Code");
     // digitalWrite(LED, HIGH);
    } 
    
    else // Wenn der Empfangene Code brauchbar ist, wird er hier an den Serial Monitor gesendet.
    {
      Serial.print("Empfangen: ");
      Serial.println( value );
        if (value == 21696)   //Verarbeitung: Wenn der Arduino die Zahl "5678" empfängt, dann... 
        {   //Programmabschnitt des IF-Befehls öffnen.
        digitalWrite(LED, HIGH); //dann soll die LED leuchten
        delay (500);   //und zwar für 0,5 Sekunden (500 Millisekunden).
        digitalWrite(LED, LOW); //danach soll die LED aus sein.
        }   //Programmabschnitt des IF-Befehls schließen.   
    }
    mySwitch.resetAvailable(); // Hier wird der Empfänger "resettet"
  }
}
