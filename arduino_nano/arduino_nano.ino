#include <AccelStepper.h>
#include <MultiStepper.h>
#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <RotaryEncoder.h>

//Define encoder pins
#define ENCODER_A 3
#define ENCODER_B 2
#define ENCODER_SW 4
#define ENCODER_DIRECTION 1  //Change to -1 to switch direction of encoder
//Define stepper driver pins
#define DRIVER_STEP 16
#define DRIVER_DIR 17
#define motorInterfaceType 1
#define STEPPER_SPR 3200  //Define stepper motor steps per revolution

RotaryEncoder encoder(ENCODER_A, ENCODER_B, RotaryEncoder::LatchMode::TWO03);
Adafruit_SSD1306 display(128, 64, &Wire, -1);

void oledPrint(int printInt);
int rotarySelect(int currentVal, int maxVal, int minVal);
AccelStepper stepper = AccelStepper(motorInterfaceType, DRIVER_STEP, DRIVER_DIR);


const short maxRpm = 500;
const short minRpm = 1;
//short previousRpm = 0;
short selectedRpm = 60;
short currentRpm = 60;
short printVal = 60;
short savedRpm = 0;
unsigned long time01 = 0;
short stepperDirection = 1;

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  //display.println("SmartRotatingHanger");
  display.print("github.com/apos0");
  display.display();
  delay(3000);
  display.setTextSize(3);
  pinMode(ENCODER_SW, INPUT);
  stepper.setMaxSpeed(maxRpm * (STEPPER_SPR / 60));
  stepper.setSpeed(currentRpm * (STEPPER_SPR / 60));
  time01 = millis();
}

void loop() {

  //Change direction every 15seconds




  if (printVal == 1000 || printVal == 1001) {
    if (printVal == 1001) {
      if (selectedRpm == 0) {
        selectedRpm = savedRpm;
      } else {
        savedRpm = selectedRpm;
        selectedRpm = 0;
      }
      //delay(1000);
    }
    currentRpm = selectedRpm;
    stepper.setSpeed(stepperDirection * currentRpm * (STEPPER_SPR / 60));
  } else if (selectedRpm != 0)
    selectedRpm = printVal;

  oledPrint(selectedRpm);

  printVal = rotarySelect(selectedRpm, maxRpm, minRpm);
}


int rotarySelect(int currentVal, int maxVal, int minVal) {
  static int encPos = 0;
  while (1) {
    stepper.runSpeed();
    if (millis() - time01 >= 60000) {
      time01 = millis();
      stepperDirection *= -1;
      stepper.setSpeed(stepperDirection * currentRpm * (STEPPER_SPR / 60));
    }
    encoder.tick();
    int newPos = encoder.getPosition();

    if (newPos != encPos) {
      int direction = ((int)(encoder.getDirection()));
      switch (direction) {
        case (-1 * ENCODER_DIRECTION):
          if (currentVal > minVal) currentVal--;
          break;

        case (1 * ENCODER_DIRECTION):
          if (currentVal < maxVal) currentVal++;
          break;
      }
      encPos = newPos;
      //delay(20);
      return currentVal;
    }

    if (digitalRead(ENCODER_SW) == 0) {
      unsigned long temp1 = millis();
      while (digitalRead(ENCODER_SW) == 0)
        if ((millis() - temp1) >= 2000) return 1001;

      delay(100);
      return 1000;
    }
  }
}

void oledPrint(int printInt) {
  display.clearDisplay();
  if (printInt == 0) {
    display.setCursor(25, 20);
    display.print(F("STOP"));
  } else {
    display.setCursor(0, 20);
    display.print(F("RPM:"));
    display.println(printInt);
  }
  display.display();
}
