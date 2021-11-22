// include the library code:
#include <LiquidCrystal.h>

char inKey;  //Received from Serial input
uint8_t Cursor = 0;  //Cursor start position
uint8_t rows = 2;
uint8_t columns = 16;

//initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
    //set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  //initialize the serial communications:
  Serial.begin(9600);
}

void loop()
{
  // when characters arrive over the serial port...
  if (Serial.available()) {
    //wait a bit for the entire message to arrive
    delay(100);
    //clear the screen
    lcd.clear();
    Cursor = 0;
    //read all the available characters
    while (Serial.available() > 0) {
      //display each character to the LCD
      inKey = Serial.read();
      //only print characters that are not newline
      if(inKey != '\n') {
        LCDDisplay(inKey);
      }
    }
  }
}

void LCDDisplay(char character)
{
  int currentRow = 0;

  if (Cursor >= columns)
    currentRow = Cursor/columns;
    
  lcd.setCursor(Cursor%columns, currentRow);
  lcd.write(character);
  
  Cursor++;
}
