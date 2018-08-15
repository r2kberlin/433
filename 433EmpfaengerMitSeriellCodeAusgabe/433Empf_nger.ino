#include <RCSwitch.h>
 
RCSwitch rcSwitch = RCSwitch();
 
void setup() {
  Serial.begin(9600); //Begin der seriellen Kommunikation mit 9600 baud.
  // Empfängermodul ist am digitalen PIN 2 angeschlossen
  // dies ist der Interrupt-Pin "0".
  rcSwitch.enableReceive(0);
}
 
void loop() {
  if (rcSwitch.available()){ //Wenn Daten verfügbar sind.
    //Ausgabe des aktuellen Zeitstempels (seitdem der Arduino gestartet wurde).
    Serial.print("[");
    Serial.print(millis());
    Serial.print("] - ");
    //Ausgabe des gelesenen Wertes
    Serial.println( rcSwitch.getReceivedValue() );
    
    //Zurücksetzen des Empfängers.
    rcSwitch.resetAvailable();
  }
}
