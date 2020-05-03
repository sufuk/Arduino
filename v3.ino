#include <Wire.h>
#include <NewPing.h>
#include <LCD.h>
#include <LiquidCrystal.h>
#include <LcdBarGraph.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
LcdBarGraph lbg(&lcd, 16, 0, 1);
#define TRIGGER_PIN  9
#define ECHO_PIN     10
#define MAX_DISTANCE 30
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
void setup() {
 Serial.begin(115200);
  lcd.begin(16,2);
  pinMode(8,INPUT);

}
 
void loop() {
  if(digitalRead(8) == HIGH){
 /* Serial.print("Ping: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");
*/
  lcd.setCursor(1,0); 
  lcd.print("Distance: ");
  lcd.print(sonar.ping_cm());
  lcd.print(" cm");
  lcd.setCursor(1,1);
  lbg.drawValue(sonar.ping_cm(), MAX_DISTANCE);
  delay(500);
}
}
