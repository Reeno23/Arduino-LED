// On 32x16 matrix: Red=red, blue=blue, orange=green, black&yellow=Black/Ground ::: So, Digital 10(button), 11(led), 12, 13, and analog 4(potentiometer) & 5(photocell) are still open.
// Orange to G1 |Digital 3|                     Red to R1 |Digital 2|
// Black to GND                                 Blue to B1 |Digital 4|
// Orange to G2 |Digital 6|                     Red to R2 |Digital 5|
// Yellow to GND                                Blue to B2 | |Digital 7|
// White (Row Address Pin B) |Analog 1|         White (Row Address Pin A) |Analog 0|
// White (Ground)                               White (Row Address Pin C) |Analog 2|
// Yellow (Data Latch, LAT) |Analog 3|          Orange (CLK) |Digital 8|
// White (Ground)                               Orange (OE Output) |Digital 9|

// **** All code above is irrelevant to this project. It's just a self-note of information to hook up the matrix. ****

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

#define CLK 8  // MUST be on PORTB!
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2

int buttonPin = 10; // Number of the button
int buttonState = 0; // To read if button is off or on
int buttonHist = 0;     // previous state of the button
int sensorPin = A4; // Potentiometer analog input
int sensorValue = 0; // To store potentiometer reading
//long int random; // A random number used for the games


RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

void setup() {
  matrix.begin();
  uint8_t r=0, g=0, b=0;
  pinMode(buttonPin, INPUT);     
  Serial.begin(9600); // Starts serial monitor
  Serial.println("Enter 1 or 2");  // 1 is the first game with two numbers to choose from. Game 2 allows the user to enter a number from 3-9 to draw various things on the screen.
  
  start();

}

void loop() {
  sensorValue = analogRead(sensorPin);  // Reads potentiometer value and stores to "sensorValue"
  buttonState = digitalRead(buttonPin); // Reads the pushbutton value
  delay(100);
  

    char ch = Serial.read();
    
    if (ch == '1') // Game 1
    {
         Serial.println("Pick a number!");
         matrix.fillScreen(0);
         matrix.setCursor(5, 4); // Start drawing 6 pixels in, and 5 pixels down.
         matrix.setTextSize(1);  // size 1 = numbers/letters are 8 pixels high
   
         int randNum = random(10); // Generates a random number from 0-9.
         int randNum2 = random(10); // Generates a random number from 0-9.
         matrix.setTextColor(matrix.Color333(0,0,7)); // Dark Blue
         matrix.print(randNum);
         matrix.setTextColor(matrix.Color333(0,7,7)); // Teal
         matrix.print('O');
         matrix.setTextColor(matrix.Color333(7,0,0)); // Red
         matrix.print('R');
         matrix.setTextColor(matrix.Color333(0,7,0)); // Dark Green
         matrix.print(randNum2);     // Displays two random numbers to the user to choose from.
    }   
         
   if (sensorValue <= 390 && buttonState == HIGH) { // If potentiometer is less than or equal to halfway turned, and the button is pressed, you are choosing the left number.
      

       matrix.fillScreen(0);
       matrix.setCursor(1, 0);  // Start drawing 2 pixels in, and 1 pixel down.
       matrix.setTextSize(1);   // size 1 = numbers/letters are 8 pixels high
        
         matrix.setTextColor(matrix.Color333(7,0,0)); // Red
         matrix.print('G');
         matrix.setTextColor(matrix.Color333(7,4,0)); // Yellow
         matrix.print('O');
         matrix.setTextColor(matrix.Color333(4,7,0)); // Light Green
         matrix.print('O');
         matrix.setTextColor(matrix.Color333(0,0,7)); // Dark Blue
         matrix.print('D');
         
         matrix.setCursor(1, 9);   // next line
         
         matrix.setTextColor(matrix.Color333(0,7,0)); // Dark Green
         matrix.print('J');
         matrix.setTextColor(matrix.Color333(7,0,4)); // Pink
         matrix.print('O');
         matrix.setTextColor(matrix.Color333(0,7,7)); // Teal
         matrix.print('B');
         matrix.setTextColor(matrix.Color333(0,0,7)); // Dark Blue
         matrix.print('!');    // Displays "Good Job" to the user. They won, as the left number was correct.
   }
     
   if (sensorValue > 391 && buttonState == HIGH) { // If potentiometer is more than halfway turned, and the button is pressed, you are choosing the right number.             
         

       matrix.fillScreen(0);
       matrix.setCursor(1, 0);  // Start drawing 2 pixels in, and 1 pixel down.
       matrix.setTextSize(1);   // size 1 = numbers/letters are 8 pixels high
       
         matrix.setTextColor(matrix.Color333(0,7,7)); // Teal
         matrix.print('S');
         matrix.setTextColor(matrix.Color333(0,0,7)); // Dark Blue
         matrix.print('O');
         matrix.setTextColor(matrix.Color333(7,0,0)); // Red
         matrix.print('R');
         matrix.setTextColor(matrix.Color333(0,7,0)); // Dark Green
         matrix.print('R');
         matrix.setTextColor(matrix.Color333(7,4,0)); // Yellow
         matrix.print('Y'); 
       }   // Displays "Sorry" to the user. They lost as the right number was incorrect.
   

     
     
    
    
    
    if (ch == '2') // Game 2
    {
         matrix.fillScreen(0);
         matrix.setCursor(1, 0);  // Start drawing 2 pixels in, and 1 pixel down.
         matrix.setTextSize(1);   // size 1 = numbers/letters are 8 pixels high
         matrix.setTextColor(matrix.Color333(0,7,7)); // Teal
         matrix.print('T');
         matrix.setTextColor(matrix.Color333(0,0,7)); // Dark Blue
         matrix.print('Y');
         matrix.setTextColor(matrix.Color333(7,0,0)); // Red
         matrix.print('P');
         matrix.setTextColor(matrix.Color333(0,7,0)); // Dark Green
         matrix.print('E');
         
         matrix.setCursor(1, 9);   // next line
         
         matrix.setTextColor(matrix.Color333(0,7,0)); // Dark Green
         matrix.print('3');
         matrix.setTextColor(matrix.Color333(7,0,4)); // Pink
         matrix.print('T');
         matrix.setTextColor(matrix.Color333(0,7,7)); // Teal
         matrix.print('O');
         matrix.setTextColor(matrix.Color333(0,0,7)); // Dark Blue
         matrix.print('9'); 
      Serial.println("Enter numbers from 3-9 to draw stuff!");
    }
      if (ch == '3') {
       matrix.fillScreen(0);
 
       matrix.fillRect(3, 0, 23, 8, matrix.Color333(7, 0, 4));  // Fills the screen up by drawing a filled in pink rectangle
      
         }
      if (ch == '4') { 
         matrix.fillScreen(0);
       
         matrix.drawPixel(0, 3, matrix.Color333(0, 7, 0));
         matrix.drawPixel(3, 8, matrix.Color333(7, 7, 7));
         matrix.drawPixel(7, 4, matrix.Color333(7, 0, 0));
         matrix.drawPixel(5, 6, matrix.Color333(7, 4, 0));        // Colors in 4 pixels scattered around the matrix
       
       
         }
      if (ch == '5') {
       matrix.fillScreen(0);
    
       matrix.fillCircle(23, 7, 7, matrix.Color333(0, 7, 0));     // Draws a dark green circle
      
         }
      if (ch == '6') {
         matrix.fillScreen(0);
         
         matrix.drawRect(0, 0, 18, 19, matrix.Color333(0, 7, 7));
         matrix.drawLine(0, 0, 31, 15, matrix.Color333(7, 0, 0));
         matrix.drawLine(31, 0, 0, 15, matrix.Color333(7, 0, 0));   // Draws a teal rectangle with a red X inside of it
        
           
         }
      if (ch == '7') {
       matrix.fillScreen(0);
  
       matrix.drawRect(0, 0, 32, 16, matrix.Color333(7, 0, 0));  // Draws a box in red
       
         }
      if (ch == '8') {
       matrix.fillScreen(0);
       
       matrix.fillCircle(23, 7, 7, matrix.Color333(7, 4, 0));   // Draws a circle in yellow
       
         }
      if (ch == '9') {
       matrix.fillScreen(0);
       
       matrix.drawLine(0, 0, 31, 15, matrix.Color333(0, 0, 7));
       matrix.drawLine(31, 0, 0, 15, matrix.Color333(7, 0, 4));  // Draws a large X with a dark blue line and a pink line
       
         }
       
      
      if (ch == 'r')
    {
     matrix.fillScreen(0);
    setup(); }

}


 void start() {
       matrix.setCursor(1, 0);  // Start drawing 2 pixels in, and 1 pixel down.
       matrix.setTextSize(1);   // size 1 = numbers/letters are 8 pixels high
   
         matrix.setTextColor(matrix.Color333(0,7,0)); // Dark Green
         matrix.print('H');
         matrix.setTextColor(matrix.Color333(7,4,0)); // Yellow
         matrix.print('E');
         matrix.setTextColor(matrix.Color333(4,7,0)); // Light Green
         matrix.print('L');
         matrix.setTextColor(matrix.Color333(0,0,7)); // Dark Blue
         matrix.print('L');
         matrix.setTextColor(matrix.Color333(0,7,7)); // Teal
         matrix.print('O'); //Displays "Hello" to the user.
       
         
         matrix.setCursor(1, 9);   // next line
         
         matrix.setTextColor(matrix.Color333(0,0,7)); // Dark Blue
         matrix.print('1');
         matrix.setTextColor(matrix.Color333(0,7,7)); // Teal
         matrix.print('O');
         matrix.setTextColor(matrix.Color333(7,0,0)); // Red
         matrix.print('R');
         matrix.setTextColor(matrix.Color333(4,7,0)); // Light Green
         matrix.print('2');   
         matrix.setTextColor(matrix.Color333(0,7,0)); // Dark Green
         matrix.print('?');     // Asks the user: "1 or 2?" Meaning, do you want to play game one or game two?
         
      }
