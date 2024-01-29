int outputPin = 3;
int PitchPin = A4;
int DelayPin = A3;
int Pitch = 0;
int Delay = 0;
int PitchPin2 = A2;
int DelayPin2 = A1;
int Pitch2 = 0;
int Delay2 = 0;
int PickPin = A5;
int Pick = 0;

uint16_t pentatonicTable[54] = {
  0,19,22,26,29,32,38,43,51,58,65,77,86,103,115,129,154,173,206,231,259,308,346,
  411,461,518,616,691,822,923,1036,1232,1383,1644,1845,2071,2463,2765,3288,
  3691,4143,4927,5530,6577,7382,8286,9854,11060,13153,14764,16572,19708,22121,26306
};

uint16_t minorTable[53] = {
  0,28,31,33,37,41,44,49,55,62,65,73,82,87,98,110,124,131,147,165,157,196,220,
  247,262,294,330,350,392,440,494,523,587,659,699,784,880,988,1047,
  1175,1319,1397,1568,1760,1976,2093,2350,2637,2793,3136,3520,3951,4186
};
uint16_t mapPentatonic(uint16_t input) {
  uint8_t value = (1023-input) / (1024/53);
  return (pentatonicTable[value]);
}
uint16_t mapminor(uint16_t input) {
  uint8_t value = (1023-input) / (1024/52);
  return (minorTable[value]);
}
void setup() {
  // put your setup code here, to run once:
  pinMode(outputPin, OUTPUT);
  pinMode(PitchPin, INPUT);
  pinMode(DelayPin, INPUT);
  pinMode(PitchPin2, INPUT);
  pinMode(DelayPin2, INPUT);
  pinMode(PickPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  Pick  = analogRead(PickPin);
  if (Pick <= 512) {
  Pitch2 = 0;
  Delay2 = 0;
  Pitch = analogRead(PitchPin);
  Delay = analogRead(DelayPin);
  tone(outputPin,mapPentatonic(Pitch), Delay);
  delay(Delay);
}
else {
  Pitch2 = analogRead(PitchPin2);
  Delay2 = analogRead(DelayPin2);
  tone(outputPin,mapminor(Pitch2), Delay2);
  delay(Delay2);
  Pitch = 0;
  Delay = 0;
}

  
//  Serial.println(Pick);
//  Serial.println(mapPentatonic(Pitch));
//  Serial.println(Delay);
  Serial.println(mapPentatonic(Pitch2));
//  Serial.println(Delay2);

}
