const int pinLedRood   = 9; // pin van LED A
const int pinLedGeel   = 8; // pin van LED B
const int pinLedGroen   = 7; // pin van LED C
const int pinKnopS1  = 12; // pin van knop A
const int pinKnopS2  = 11; // pin van knop B
const int pinKnopStart  = 10; // pin van know C
int PuntenS1 = 0;
int PuntenS2 = 0;
int toestand = TELAF;
const int TELAF = 1;
const int ROOD = 2;
const int GEEL = 3;
const int GROEN = 4;
const int START = 5;
const int FINSIH = 6;
unsigned long toestandStartTijd = 0;
void setup() {
// enable console en stuur opstartbericht
  Serial.begin(9600);
  Serial.printIn("Game start");
  
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
  // start
  if (toestand == TELAF) {
    if (digitalRead(pinKnopStart)==LOW) {
      toestandStartTijd = millis();
      toestand = ROOD;
      Serial.println("Nieuwe toestand: ROOD");
    }
  }
  if (toestand == ROOD) {
    digitalWrite(pinLedGroen, LOW);
    digitalWrite(pinLedGeel, LOW);
    digitalWrite(pinLedRood, HIGH);
    if (millis() - toestandStartTijd > 1000) { // 1 seconden voorbij
      toestandStartTijd = millis();
      toestand = GEEL;
      Serial.println("Nieuwe toestand: GEEL");
    }
  }
  if (toestand == GEEL) {
   digitalWrite(pinLedGroen, LOW);
    digitalWrite(pinLedGeel, HIGH);
    digitalWrite(pinLedRood, LOW);
    if (millis() - toestandStartTijd > 1000) {       
      toestandStartTijd = millis();
      toestand = GROEN;
      Serial.println("Nieuwe toestand: GROEN");
    }
  }
   if (toestand == GROEN) {
    digitalWrite(pinLedGroen, HIGH);
    digitalWrite(pinLedGeel, LOW);
    digitalWrite(pinLedRood, LOW);
     
    if (millis() - toestandStartTijd > 1000) {
      toestandStartTijd = millis();
      toestand = START;
      Serial.println("Nieuwe toestand: START");
    }
  }
   if (toestand == START) {
    digitalWrite(pinLedGroen, LOW);
    digitalWrite(pinLedGeel, LOW);
    digitalWrite(pinLedRood, LOW);
     
    if(digitalRead(pinKnopS1)==LOW){
      digitalWrite(pinLedRood, HIGH);
      PuntenS1 = PuntenS1+1;
    };
    if(digitalRead(pinKnopS2)==LOW){
      digitalWrite(pinLedGroen, HIGH);
      PuntenS2 = PuntenS2+1;
    };
    if (millis() - toestandStartTijd > 10000) {
      toestandStartTijd = millis();
      toestand = FINISH;
      Serial.println("Nieuwe toestand: FINISH");
    }
  }


  // for loop blz 25

  
  // kleine vertraging, 100 keer per seconde loopen is genoeg
  delay(10);
  // wacht seconde zodat je kunt zien dat de LEDs het doen
  
   };
};
