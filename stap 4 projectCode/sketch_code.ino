const int pinLedRood   = 9; // pin van LED A
const int pinLedGeel   = 8; // pin van LED B
const int pinLedGroen   = 7; // pin van LED C
const int pinKnopS1  = 12; // pin van knop A
const int pinKnopS2  = 11; // pin van knop B
const int pinKnopStart  = 10; // pin van know C


// variabelen voor de toestanden
const int TELAFROOD = 1; // tel af tot spel start
const int TELAFGEEL = 2; // speel het spel
const int TELAFGROEN   = 3; // laat zien wie de winnaar is
const int SPEEL = 4;
const int START = 5;
int toestand = TELAFROOD;
unsigned long toestandStartTijd = 0;


void setup() {
  // put your setup code here, to run once:
  // enable console en stuur opstartbericht
  Serial.begin(9600);

  // zet pinmode voor leds
  pinMode(pinLedRood, OUTPUT);
  pinMode(pinLedGeel, OUTPUT);
  pinMode(pinLedGroen, OUTPUT);

  // zet pinmode voor knoppen
  pinMode(pinKnopS1, INPUT);
  pinMode(pinKnopS2, INPUT);
  pinMode(pinKnopStart, INPUT);

};

void loop() {
  // zet LEDs aan
  /*
    if (digitalRead(pinKnopStart) == LOW) {
    digitalWrite(pinLedRood, HIGH);
    delay(1000);
    digitalWrite(pinLedRood, LOW);
    delay(0);

    digitalWrite(pinLedGeel, HIGH);
    delay(1000);
    digitalWrite(pinLedGeel, LOW);
    delay(0);

    digitalWrite(pinLedGroen, HIGH);
    delay(1000);
    digitalWrite(pinLedGroen, LOW);
    delay(0);
    Serial.println("start");
  */
  if (toestand == TELAFROOD) {
    digitalWrite(pinLedRood, HIGH);
    digitalWrite(pinLedGeel, LOW);
    digitalWrite(pinLedGroen, LOW);

    if (millis() - toestandStartTijd > 1000) { // 2 seconden voorbij
      toestandStartTijd = millis();
      toestand = TELAFGEEL;
      Serial.println("Nieuwe toestand: TELAFGEEL");
    }
  }

  
if (toestand == TELAFGEEL) {
    digitalWrite(pinLedRood, LOW);
    digitalWrite(pinLedGeel, HIGH);
    digitalWrite(pinLedGroen, LOW);

    if (millis() - toestandStartTijd > 1000) { // 2 seconden voorbij
      toestandStartTijd = millis();
      toestand = TELAFGROEN;
      Serial.println("Nieuwe toestand: TELAFGROEN");
    }
  }

  if (toestand == TELAFGROEN) {
    digitalWrite(pinLedRood, LOW);
    digitalWrite(pinLedGeel, LOW);
    digitalWrite(pinLedGroen, HIGH);

    if (millis() - toestandStartTijd > 1000) { // 2 seconden voorbij
      toestandStartTijd = millis();
      toestand = START;
      Serial.println("Nieuwe toestand: TELAFGROEN");
    }
  }


  // for loop blz 25


  // kleine vertraging, 100 keer per seconde loopen is genoeg
  delay(10);
  // wacht seconde zodat je kunt zien dat de LEDs het doen

};
