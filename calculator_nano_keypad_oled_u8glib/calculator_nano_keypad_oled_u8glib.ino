#include <Keypad.h>
#include <Arduino.h>
#include "U8glib.h"

//U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0); // I2C / TWI
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST); // Fast I2C / TWI

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
  // flip screen, if required
  // u8g.setRot180();

  // set SPI backup if required
  //u8g.setHardwareBackup(u8g_backup_avr_spi);

  // assign default color value
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255, 255, 255);
  }
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
  int renderFlag = 0;

  static int randNumber1;
  static int randNumber2;
  static int result;
  static int operand;
  static char nextQuestion = 1;
  static String questionStr;
  static String inString;
  static String strOperand;
  static String resString = "";
  static int rightAnswers = 0;
  static int wrongAnswers = 0;

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
        strOperand = "+";
        break;
      case 2: //"x"
      default:
        result = randNumber1 * randNumber2;
        strOperand = "x";
        break;
    }
    //sprintf(questionStr,"%d%c%d",randNumber1,strOperand
    questionStr = String(randNumber1) + strOperand + String(randNumber2) + "=";
    nextQuestion = 0;
    renderFlag = 1;

    Serial.print(questionStr);
  }

  // Read serial input:
  inChar = myKeypad.getKey();
  if (isDigit(inChar))
  {
    Serial.print(inChar);
    if ((inString == "" && inChar != '0') || (inString != ""))
    {
      inString += inChar;
    }
  }
  else if (inChar == 'A')
  {
    Serial.print('A');
    if (inString.length() > 0)
    {
      inString.remove(inString.length() - 1);
    }
  }
  else if (inChar == '#' && inString != "")
  {
    inVal = inString.toInt();

    if (inVal == result)
    {
      resString = "RIGHT";
      rightAnswers++;
    }
    else
    {
      resString = "WRONG";
      wrongAnswers++;
    }
    nextQuestion = 1;
    Serial.println(resString);
    resString = "V: " + String(rightAnswers) + ", X: " + String(wrongAnswers);
    Serial.println("Right: " + String(rightAnswers) + ", Wrong: " + String(wrongAnswers));
  }

  //check if user is right or wrong:
  int font_height = 17;
  int font_width = 8;
  int font_base = 30;
  int line_margin = 6;
  int strWidth;
  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_fur17);

    questionStr.toCharArray(buf, BUF_LEN);
    u8g.drawStr(0, font_base, buf);
    strWidth = u8g.getStrWidth(buf);

    inString.toCharArray(buf, BUF_LEN);
    u8g.drawStr(strWidth + 2, font_base, buf);

    resString.toCharArray(buf, BUF_LEN);
    u8g.drawStr(0, font_base + font_height + line_margin, buf);

  } while (u8g.nextPage());

  //delay(1000);
}
