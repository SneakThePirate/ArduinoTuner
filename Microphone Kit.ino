// Define Variables

  // Define pin inputs and outputs
  int micPin = A1;  //analog input channel #1
  int firstPin = 2; //first pin digital output 
  int lastPin = 5; //last pin digital output 
  
  // Initialize and define variables
  int count = 800;
  
  //Frequency:
    int startTime;
    int endTime;
    int past;
    int current;
    int cycles;
    float freq;

  //RMS:
    unsigned long squared;  //unsigned to prevent oversaturation
    unsigned long meanSq;

// Main Setup
void setup() {
  // Set up LED pins as outputs
  for (int pinNumber = firstPin; pinNumber <= lastPin; pinNumber++) {
    pinMode(pinNumber, OUTPUT);   // Declare the LEDs as outputs
  }

  // Set up mic pin as input
  pinMode(micPin, INPUT);

  // Initialize serial communication with 9600 bps
  Serial.begin(9600);
}


// Code Stuff
void loop() {
  //Reset variables to zero
  startTime = 0;
  endTime = 0;
  meanSq = 0;
  cycles = 0;
  current = 0;
  past = 0;
  
  //Read data from microphone
  startTime = millis(); //set start time
  int data[count];      //declare array

  for (int i = 0; i < count; i++) {
    data[i] = analogRead(micPin); //fill array with mic data
//    Serial.println(data[i]);
    
    //Data for root mean squared
    squared = sq(data[i] - 512);  //'zero' data and square it
    meanSq = meanSq + squared;    //add to the total mean squared

    //Data for frequency
    if (data[i] > 512) {          //if above 'zero'
      current = 1;                //counts as 1
    }
    else if (data[i] <= 512) {    //if at or below 'zero'
      current = 0;                //counts as 0
    }
    if (current < past) {         //if less than previous
      cycles++;                   //add 1 to total number of cycles
    }
    past = current;
  }

  endTime = millis();   //set end time

  //Calculate Frequency:
  freq = cycles / ((endTime - startTime) * 0.001); //freq = cycles / s
//  Serial.println(freq); //display frequency
  

  //Calculate RMS:
  float rms = sqrt(meanSq / count);

  Serial.println(rms);
  
  //Light LEDs corresponding to set thresholds
  if (rms <= 15) {
    for (int j = firstPin; j <= lastPin; j++) {
      digitalWrite(j, LOW);
    }
  }
  else if (rms <= 25) {
    digitalWrite(firstPin, HIGH);
    for (int j = firstPin + 1; j <= lastPin; j++) {
      digitalWrite(j, LOW);
    }
  }
  else if (rms <= 35) {
    for(int j = firstPin; j <= firstPin + 1; j++) {
      digitalWrite(j, HIGH);
    }
    for(int j = firstPin + 2; j <= lastPin; j++)  {
      digitalWrite(j,LOW);
    }
  }
  else if (rms <= 45) {
    for(int j = firstPin; j <= firstPin + 2; j++) {
      digitalWrite(j, HIGH);
    }
    for(int j = firstPin + 3; j <= lastPin; j++)  {
      digitalWrite(j,LOW);
    }
  }
  else if (rms <= 60) {
    for(int j = firstPin; j <= firstPin + 3; j++) {
      digitalWrite(j, HIGH);
    }
    for(int j = firstPin + 4; j <= lastPin; j++)  {
      digitalWrite(j,LOW);
    }
  }
  else if (rms <= 75) {
    for(int j = firstPin; j <= firstPin + 4; j++) {
      digitalWrite(j, HIGH);
    }
    digitalWrite(lastPin, LOW);
  }
  else {
    for(int j = firstPin; j <= lastPin; j++) {
      digitalWrite(j, HIGH);
    }
  }
}
  
