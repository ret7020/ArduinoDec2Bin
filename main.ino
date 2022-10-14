int pinId = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 2; i <= 13; ++i)
    pinMode(i, OUTPUT);
  
  for(int i = 2; i <= 13; ++i){
    digitalWrite(i, 1);
    delay(100);
  }
  for(int i = 13; i >= 2; --i){
    digitalWrite(i, 0);
    delay(100);
  }
}


void loop() {
  int a = Serial.parseInt();
  if(a > 0 && a <= 4095){
    pinId = 2;
    for (int i = 2; i <= 13; ++i)
      digitalWrite(i, 0);
    while(a){
      digitalWrite(pinId, a % 2);
      Serial.print(a%2);
      a /= 2;
      pinId++;
    }
  }
}
