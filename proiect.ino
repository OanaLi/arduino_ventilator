
//1: FFA25D
//2: FF629D
//3: FFE21D
//4: FF22DD
//5: FF02FD
//6: FFC23D
//7: FFE01F
//8: FFA857
//9: FF906F
//*: FF6897
//0: FF9867
//#: FFB04F
//sus: FF18E7
//jos: FF4AB5
//stanga: FF10EF
//dreapta: FF5AA5
//ok: FF38C7

#include <Wire.h>              
#include <LiquidCrystal_I2C.h>  
#include <DHT.h>                
#include <IRremote.h>           

DHT dht(2, DHT11); 
LiquidCrystal_I2C lcd(0x27, 16, 2); 
IRrecv irrecv(11);

decode_results results;
float temperature, setTemperature = 22.0;
unsigned long previousMillis = 0;  
const int in1Pin = 3; //in2Pin = 4;


void setup() {
  lcd.begin(16, 2);    
  lcd.backlight(); 
  lcd.clear();         

  dht.begin(); 
  irrecv.enableIRIn();

  pinMode(5, INPUT_PULLUP);

  pinMode(in1Pin, OUTPUT);
  //pinMode(in2Pin, OUTPUT); 
  stopFan();

  lcd.setCursor(0, 0); 
  lcd.print("Initializare...");
  delay(2000);         
  lcd.clear();         
}

void loop() {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 2000) {
    previousMillis = currentMillis;
    temperature = getTemp();
    runFan();
  }


  if (irrecv.decode(&results)) {
    if (results.value == 0xFF18E7) 
      setTemperature++;  
    if (results.value == 0xFF4AB5)
      setTemperature--; 
    irrecv.resume();
  }

  printLCD();
}

void printLCD(){
  lcd.setCursor(0, 0); 
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1); 
  lcd.print("Set: ");
  lcd.print(setTemperature);
  lcd.print(" C");
}


float getTemp(){
  float a, sum = 0;
  for(int i = 0; i < 10; i++){
    sum += dht.readTemperature();
  }
  return sum / 10.0;
}

void runFan(){
  if (temperature > setTemperature) {
    startFan();
  } else {
    stopFan();
  }
}

void startFan() {
  digitalWrite(in1Pin, HIGH); 
  //digitalWrite(in2Pin, LOW);
}

void stopFan() {
  digitalWrite(in1Pin, LOW); 
  //digitalWrite(in2Pin, LOW);
}