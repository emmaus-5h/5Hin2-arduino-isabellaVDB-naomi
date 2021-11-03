
/*****************************************
   Voorbeeld TestCode
   Voor circuit met 2 leds en 2 knoppen
   Breid de code zelf uit
   zodat je deze kunt gebruiken om te testen
   of alle componenten (nog) goed
   zijn aangesloten op je Arduino
   Emmauscollege
   v20210210GEE
 *****************************************/

/*****************************************
   variabelen die je gebruikt maken
 *****************************************/
// gebruikte pinnen
const int pinLedA   = 9; // pin van LED A
const int pinLedB   = 8; // pin van LED B
const int pinledC   = 7; // pin van LED C
const int pinKnopA  = 12; // pin van knop A
const int pinKnopB  = 11; // pin van knop B
const int pinKnopC  = 10; // pin van know C

/*****************************************
   setup()
 *****************************************/
void setup() {
  // enable console en stuur opstartbericht
  Serial.begin(9600);
  Serial.println("Test start");

  // zet pinmode voor leds
  pinMode(pinLedA, OUTPUT);
  pinMode(pinLedB, OUTPUT);
  pinMode(pinLedC, OUTPUT);

  // zet pinmode voor knoppen
  pinMode(pinKnopA, INPUT);
  pinMode(pinKnopB, INPUT);
  pinMode(pinKnopC, INPUT);

  // zet LEDs aan
  digitalWrite(pinLedA, HIGH);
  digitalWrite(pinLedB, HIGH);
  digitalWrite(pinLedC, HIGH);
  // wacht seconde zodat je kunt zien dat de LEDs het doen
  delay(1000);
}

/*****************************************
   loop()
 *****************************************/
void loop() {
  // zet LedA aan/uit afhankelijk van stand van knopA
  if (digitalRead(pinKnopA) == LOW) {
    digitalWrite(pinLedA, LOW);
  } else {
    digitalWrite(pinLedA, HIGH);
  }

  // zet LedB aan/uit afhankelijk van stand van nopB
  if (digitalRead(pinKnopB) == LOW) {
    digitalWrite(pinLedC, LOW);
  } else {
    digitalWrite(pinLedC, HIGH);
  }

  // kleine vertraging, 100 keer per seconde loopen is genoeg
  delay(10);
}
