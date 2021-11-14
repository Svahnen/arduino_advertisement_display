// include the LCD library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {  
  // print the string when a newline arrives:
  if (stringComplete) {
    Serial.println(inputString);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    char inchar = (char)  Serial.read();
  if (inchar != '\n')  
    inputString += inchar;
  if(inchar == '\n') {stringComplete = true;}
    }
 }
