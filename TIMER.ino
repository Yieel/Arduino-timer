int lastbuttonstate = LOW, timerstate = LOW, digit1, digit2, buttonstate, startbutton = 10, stopbutton = 9, stopbuttonstate;           // set needed variables and its values and initialize variables
const int digit[10] = {0b0111111, 0b0000110, 0b1011011, 0b1001111, 0b1100110, 0b1101101, 0b1111101, 0b0000111, 0b1111111, 0b1101111};  // set correspoding binary equivalent of segment lighting up for numbers 0 to 9
void setup()
{
  for (int a = 2; a < 9; a++)                       //for loop for initializing pins 2 to 8 to OUTPUT mode, this will be use for the segment lighting output
  {
    pinMode(a, OUTPUT);
  }
  pinMode(10, INPUT);                              //set pins 10 and 9 to input mode, these two pins are for my push buttons to recieve input
  pinMode(9, INPUT);
  pinMode(12, OUTPUT);                             //set pins 12 and 13 to output mode, this is connected to the 7seg display, one pin for one digit and one for the other
  pinMode(13, OUTPUT);
}
void loop()
{
  buttonstate = digitalRead(startbutton);               // buttonstate is equal to input in startbutton, this will be use to start the timer
  stopbuttonstate = digitalRead(stopbutton);            // stopbuttonstate is equal to input in stopbutton, this will be use to start the pause
  if (buttonstate != lastbuttonstate) {                // if button is press making its state HIGH
    lastbuttonstate = buttonstate;                     // then lastbuttonstate is equal to high
    if (buttonstate == LOW) {                          // if buttonstate is low or the button is release from pressing
      for (int b = 20; b >= 0; b--)                    // for loop for countdownt from 20 to 0
      {
        digit2 = b / 10;                              //each true number or rational number like 1,2,3,4,5.. would output in the digit2 
        digit1 = b % 10;                              //each true number or rational number like 1,2,3,4,5.. would output in the digit1
        for ( int c = 0; c < 10; c++)                   // For loop to  give value to  whats inside the parent loop
        {
          digitalWrite(12, HIGH);                      
          digitalWrite(13, LOW);
          dis(digit2);                                //pass value to dis function
          delay(40);
          digitalWrite(13, HIGH);
          digitalWrite(12, LOW);
          dis(digit1);                                //pass value to dis function
          delay(40);
        }
      }
    }
  }
}
void dis(int num)
{
  for (int d = 2; d < 9; d++)
  {
    digitalWrite(d, bitRead(digit[num], d - 2));


  }
}
