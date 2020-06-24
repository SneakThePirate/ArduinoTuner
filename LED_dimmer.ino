
int yellow1 = 9;



int potent = A4;
int potentNum = 0;

int num = 0;

void setup() {
  // put your setup code here, to run once:

pinMode(yellow1, OUTPUT);
//digitalWrite(yellow1, HIGH);



Serial.begin(9600); //Begin the Serial monitor
pinMode(potent, INPUT); //declaring potentiometer as INPUT
}


void loop() {
  // put your main code here, to run repeatedly:


potentNum = analogRead(potent); //gets value from sensor
num = map(potentNum,0,1023,0,255);
analogWrite(yellow1, num);      //Write to the LED

Serial.println(num);



delay(300);

}
