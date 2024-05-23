#include <ESP32Servo.h>
#include <LiquidCrystal_I2C.h>

#define trigPin 16
#define echoPin 17
#define servoPin 13
#define I2C_ADDR 0x27
#define totalRows 2
#define totalColumns 16
LiquidCrystal_I2C lcd(I2C_ADDR, totalColumns, totalRows);

Servo servo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.attach(servoPin);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
   
}

void loop() {
  long duration, distance;
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = (duration / 2) / 29.1;
  Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println("  cm ");
  lcd.setCursor(4, 0);
  lcd.print("UZAKLIK ");
  lcd.setCursor(4,1);
  lcd.print(distance);
  lcd.print(" cm   ");

  if (distance <= 5) {
    servo.write(90); 
    delay(10000);
    servo.write(0);
    delay(500);
  }


  delay(2500);
lcd.clear();
}
