#include <Keypad.h>
#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

const byte n_rows = 4;
const byte n_cols = 4;

char keys[n_rows][n_cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte colPins[n_rows] = {7, 6, 5, 4};
byte rowPins[n_cols] = {11, 10, 9, 8};

Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, n_rows, n_cols);

void oledSetup(void)
{
  u8g2.begin();
}
void setup()
{
  Serial.begin(115200);
  randomSeed(analogRead(0));
  oledSetup();

}

#define BUF_LEN 20

void loop()
{
  char inChar;
  int inVal;
  char buf[BUF_LEN];

  static int randNumber1;
  static int randNumber2;
  static int result;
  static int operand;
  static char nextQuestion = 1;
  static String questionStr;
  static String inString;
  static String strOperand;
  static String resString = "";

  if (nextQuestion == 1)
  {
    randNumber1 = random(1, 10);
    randNumber2 = random(1, 10);
    operand = random(1, 4);
    questionStr = "";
    inString = "";
    strOperand = "";
    //resString = "";

    switch (operand)
    {
      case 1: //"+"
        result = randNumber1 + randNumber2;
        strOperand = " + ";
        break;
      case 2: //"X"
      default:
        result = randNumber1 * randNumber2;
        strOperand = " X ";
        break;
    }
    questionStr = String(randNumber1) + strOperand + String(randNumber2) + " = ";
    nextQuestion = 0;

    Serial.print(questionStr);
  }

  // Read serial input:
  inChar = myKeypad.getKey();
  if (isDigit(inChar))
  {
    Serial.print(inChar);
    inString += inChar;
  }
  else if (inChar == 'A')
  {
    Serial.print('A');
    if (inString.length() > 0)
    {
      inString.remove(inString.length() - 1);
    }
  }
  else if (inChar == '#')
  {
    inVal = inString.toInt();

    if (inVal == result)
    {
      resString = "RIGHT";
    }
    else
    {
      resString = "WRONG";
    }
    nextQuestion = 1;
    Serial.println(resString);
  }

  //check if user is right or wrong:
  int font_height = 15;
  int font_width = 8;
  int font_base = 0;

  u8g2.firstPage();
  do {

    u8g2.setFont(u8g2_font_ncenB14_tr);

    questionStr.toCharArray(buf, BUF_LEN);
    u8g2.drawStr(0, font_base, buf);

    inString.toCharArray(buf, BUF_LEN);
    u8g2.drawStr(94, font_base, buf);

    resString.toCharArray(buf, BUF_LEN);
    u8g2.drawStr(0, font_base + font_height + 2, buf);

  } while ( u8g2.nextPage() );

  u8g2.sendBuffer();
  delay(1000);
}
