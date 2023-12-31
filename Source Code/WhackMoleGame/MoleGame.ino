const int numLEDs = 3; // Number of LEDs (adjust as needed)
int molePositions[numLEDs]; // Array to store mole positions
int check_correct = 0; // check to press correct

unsigned long startTime;
int molePosition;
int firstpin = 2;
int Button_Var = 0;

//set up for fun
int delay_for_play = 500;
int rounds = 20;

//Player 1
int Player1_1 = 5;
int Player1_2 = 6;
int Player1_3 = 7;

int B_Player1_1 = 0;
int B_Player1_2 = 0;
int B_Player1_3 = 0;

int press1 = 0;
int score1 = 0; // Player's score1

//Player 2
int Player2_1 = 8;
int Player2_2 = 9;
int Player2_3 = 10;

int B_Player2_1 = 0;
int B_Player2_2 = 0;
int B_Player2_3 = 0;

int press2 = 0;
int score2 = 0; // Player's score2


void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0)); // Seed the random number generator
  pinMode(firstpin,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(Player1_1, INPUT);
  pinMode(Player1_2, INPUT);
  pinMode(Player1_3, INPUT);
  pinMode(Player2_1, INPUT);
  pinMode(Player2_2, INPUT);
  pinMode(Player2_3, INPUT);
}


void loop() {
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  // if (Serial.available()) {
    char receivedChar = Serial.read();
    if(receivedChar == 'S'){
      Serial.println("3!");
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      delay(1000);
      Serial.println("2!");
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
      delay(1000);
      Serial.println("1!");
      digitalWrite(2,LOW);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      delay(500);
      Serial.println("Start!");
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      delay(100);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      delay(100);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      delay(100);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      delay(100);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      delay(100);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      delay(100);
      for(int i = 0; i<rounds;i++){
        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH);
        digitalWrite(4,HIGH);
        delay(500);
        molePosition = random(numLEDs); // Randomly select a mole position
        displayMole(molePosition); // Display the mole
        startTime = millis(); // Record the start time for key input
        while (millis() - startTime < delay_for_play) {
          B_Player1_1 = digitalRead(Player1_1);
          B_Player1_2 = digitalRead(Player1_2);
          B_Player1_3 = digitalRead(Player1_3);

          B_Player2_1 = digitalRead(Player2_1);
          B_Player2_2 = digitalRead(Player2_2);
          B_Player2_3 = digitalRead(Player2_3);

          if (check_correct == 0){
            if (B_Player1_1 != 0 & press1 == 0){
              Button_Var = 1;
              check_correct = check_correctz(1, Button_Var, molePosition);
              press1 = 1;
            }else if (B_Player1_2 != 0 & press1 == 0){
              Button_Var = 2;
              check_correct = check_correctz(1, Button_Var, molePosition);
              press1 = 1;
            }else if (B_Player1_3 != 0 & press1 == 0){
              Button_Var = 3;
              check_correct = check_correctz(1, Button_Var, molePosition);
              press1 = 1;
            }else if (B_Player2_1 != 0 & press2 == 0){
              Button_Var = 1;
              check_correct = check_correctz(2, Button_Var, molePosition);
              press2 = 1;
            }else if (B_Player2_2 != 0 & press2 == 0){
              Button_Var = 2;
              check_correct = check_correctz(2, Button_Var, molePosition);
              press2 = 1;
            }else if (B_Player2_3 != 0 & press2 == 0){
              Button_Var = 3;
              check_correct = check_correctz(2, Button_Var, molePosition);
              press2 = 1;
            }
          }  
        }
        clearData(); // Clear the data for the next round
      }
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      delay(200);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      delay(200);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      delay(200);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      delay(200);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      delay(200);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      delay(200);

      //Show score and winner
      Serial.println(String(score1) + ":" + String(score2));
      if (score1 > score2){
        Serial.println("Player1 Win!");
      }else if (score1 < score2){
        Serial.println("Player2 Win!");
      }else {
        Serial.println("Draw!");
      }
      resetGame();
    }
  // }
  else{
    for(int j = 0 ;j<5;j++){
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      delay(500);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      delay(500);
    }
    for(int j = 0 ;j<10;j++){
      digitalWrite(2,LOW);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      delay(100);
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
      delay(100);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      delay(100);
    }
    
  }
}

void displayMole(int position) {
  digitalWrite(2+position,LOW);
}

void clearData() {
  B_Player1_1 = 0;
  B_Player1_2 = 0;
  B_Player1_3 = 0;
  B_Player2_1 = 0;
  B_Player2_2 = 0;
  B_Player2_3 = 0;
  check_correct = 0;
  Button_Var = 0;
  press1 = 0;
  press2 = 0;
}


int checkGuess1(int guess, int molePosition) {

  if (guess == molePosition) {
    score1++;
    Serial.println("Whacked! Player1 Score: " + String(score1));
    digitalWrite(firstpin+molePosition-1,HIGH);
    return 1;
  }
  return 0;
}

int checkGuess2(int guess, int molePosition) {
  if (guess == molePosition) {
    score2++;
    Serial.println("Whacked! Player2 Score: " + String(score2));
    digitalWrite(firstpin+molePosition-1,HIGH);
    return 1;
  }
  return 0;
}

int check_correctz (int num_player, int Button_Var, int molePosition){
  if (num_player == 1){
    return checkGuess1(Button_Var, molePosition+1);
  }else if (num_player == 2){
    return checkGuess2(Button_Var, molePosition+1);
  }
  return 0;
}

void resetGame() {
  score1 = 0;
  score2 = 0;
  check_correct = 0;
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  B_Player1_1 = 0;
  B_Player1_2 = 0;
  B_Player1_3 = 0;
  B_Player2_1 = 0;
  B_Player2_2 = 0;
  B_Player2_3 = 0;
  Button_Var = 0;
}