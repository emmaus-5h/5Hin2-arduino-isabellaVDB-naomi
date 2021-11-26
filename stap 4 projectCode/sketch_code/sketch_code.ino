const int pinLedRood   = 9; // pin van LED A
const int pinLedGeel   = 8; // pin van LED B
const int pinLedGroen   = 7; // pin van LED C
const int pinKnopS1  = 12; // pin van knop A
const int pinKnopS2  = 11; // pin van knop B
const int pinKnopStart  = 10; // pin van know C
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


  // for loop blz 25

  
  // kleine vertraging, 100 keer per seconde loopen is genoeg
  delay(10);
  // wacht seconde zodat je kunt zien dat de LEDs het doen
  
   };
};
