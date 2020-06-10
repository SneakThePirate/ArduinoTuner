int red1 = 2; //pin numbers for LEDs
int red2 = 3;
int yellow1 = 4;
int yellow2 = 5;
int blue1 = 6;
int blue2 = 7;

int ledArray[] = {2,3,4,5,6,7};

int potent = A4;
int potentNum = 0;

void setup() {
  // put your setup code here, to run once:
/*pinMode(red1, OUTPUT); //recognize LEDs as output
pinMode(red2, OUTPUT);
pinMode(yellow1, OUTPUT);
pinMode(yellow2, OUTPUT);
pinMode(blue1, OUTPUT);
pinMode(blue2, OUTPUT);
*/

for(int i=0;i<6,i++;){ //set all LEDs as OUTPUTS with for loop
  pinMode(ledArray[i], OUTPUT);
}

Serial.begin(9600); //Begin the Serial monitor
pinMode(potent, INPUT); //declaring potentiometer as INPUT
}


void loop() {
  // put your main code here, to run repeatedly:
/*digitalWrite(red1, HIGH); //Turn all LEDs on
digitalWrite(red2, HIGH);
digitalWrite(yellow1, HIGH);
digitalWrite(yellow2, HIGH);
digitalWrite(blue1, HIGH);
digitalWrite(blue2, HIGH);*/

potentNum = analogRead(potent); //gets value from sensor
int num = map(potentNum,0,1023,0,6);

Serial.println(potentNum);
switch(num){ //switch statements to turn LEDs on/off
 case 0:
    digitalWrite(ledArray[0], HIGH);
    digitalWrite(ledArray[1], HIGH);
    digitalWrite(ledArray[2], HIGH);
    digitalWrite(ledArray[3], HIGH);
    digitalWrite(ledArray[4], HIGH);
    digitalWrite(ledArray[5], HIGH);

    break;
  case 1:
    digitalWrite(ledArray[0], HIGH);
    digitalWrite(ledArray[1], HIGH);
    digitalWrite(ledArray[2], HIGH);
    digitalWrite(ledArray[3], HIGH);
    digitalWrite(ledArray[4], HIGH);
    digitalWrite(ledArray[5], LOW);

    break;
    case 2:
    digitalWrite(ledArray[0], HIGH);
    digitalWrite(ledArray[1], HIGH);
    digitalWrite(ledArray[2], HIGH);
    digitalWrite(ledArray[3], HIGH);
    digitalWrite(ledArray[4], LOW);
    digitalWrite(ledArray[5], LOW);

    break;
    case 3:
    digitalWrite(ledArray[0], HIGH);
    digitalWrite(ledArray[1], HIGH);
    digitalWrite(ledArray[2], HIGH);
    digitalWrite(ledArray[3], LOW);
    digitalWrite(ledArray[4], LOW);
    digitalWrite(ledArray[5], LOW);
    break;
   
    case 4:
    digitalWrite(ledArray[0], HIGH);
    digitalWrite(ledArray[1], HIGH);
    digitalWrite(ledArray[2], LOW);
    digitalWrite(ledArray[3], LOW);
    digitalWrite(ledArray[4], LOW);
    digitalWrite(ledArray[5], LOW);
    break;
   
    case 5:
    digitalWrite(ledArray[0], HIGH);
    digitalWrite(ledArray[1], LOW);
    digitalWrite(ledArray[2], LOW);
    digitalWrite(ledArray[3], LOW);
    digitalWrite(ledArray[4], LOW);
    digitalWrite(ledArray[5], LOW);
    break;
   
    case 6:
    digitalWrite(ledArray[0], LOW);
    digitalWrite(ledArray[1], LOW);
    digitalWrite(ledArray[2], LOW);
    digitalWrite(ledArray[3], LOW);
    digitalWrite(ledArray[4], LOW);
    digitalWrite(ledArray[5], LOW);
    break;
}


delay(300);

}
