#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <WiFi.h>
#include <NTPClient.h>
#include "DHTesp.h"

#define BLYNK_TEMPLATE_ID "Replace_your_ID"
#define BLYNK_TEMPLATE_NAME "Replace_your_Template_Name"
#define BLYNK_DEVICE_NAME "Replace_your_Device_Name"

#define BLYNK_FIRMWARE_VERSION "0.1.0"

#define BLYNK_PRINT Serial
#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_WROVER_BOARD
#define USE_ESP32S2_DEV_KIT

// Define the GPIO connected with Relays and switches
#define RelayPin1 23  // D23
#define RelayPin2 15  // D15
#define RelayPin3 4  // D4
#define RelayPin4 19  // D19
#define RelayPin5 18  // D18
#define RelayPin6 5   // D5
#define RelayPin7 25  // D25
#define RelayPin8 26  // D26

#define SwitchPin1 35  // tx0
#define SwitchPin2 12  // D12
#define SwitchPin3 14  // D14
#define SwitchPin4 27  // D27
#define SwitchPin5 33  // D33
#define SwitchPin6 32  // D32
#define SwitchPin7 16  // rx2
#define SwitchPin8 17  // tx2

#define TombolPin 34

#define DHT_PIN 13

DHTesp dhtSensor;

#define wifiLed 2   // D2

#define VPIN_BUTTON_1 V1
#define VPIN_BUTTON_2 V2
#define VPIN_BUTTON_3 V3
#define VPIN_BUTTON_4 V4
#define VPIN_BUTTON_5 V5
#define VPIN_BUTTON_6 V6
#define VPIN_BUTTON_7 V7
#define VPIN_BUTTON_8 V8

#define VPIN_BUTTON_C V9

#define VPIN_MENU V10

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

bool isRelayOn_1 = false;
unsigned long lastRelayOnTime_1 = 0;
unsigned long lastRelayOffTime_1 = 0;

bool isRelayOn_2 = false;
unsigned long lastRelayOnTime_2 = 0;
unsigned long lastRelayOffTime_2 = 0;

bool isRelayOn_3 = false;
unsigned long lastRelayOnTime_3 = 0;
unsigned long lastRelayOffTime_3 = 0;

bool isRelayOn_4 = false;
unsigned long lastRelayOnTime_4 = 0;
unsigned long lastRelayOffTime_4 = 0;

bool isRelayOn_5 = false;
unsigned long lastRelayOnTime_5 = 0;
unsigned long lastRelayOffTime_5 = 0;

bool isRelayOn_6 = false;
unsigned long lastRelayOnTime_6 = 0;
unsigned long lastRelayOffTime_6 = 0;

bool isRelayOn_7 = false;
unsigned long lastRelayOnTime_7 = 0;
unsigned long lastRelayOffTime_7 = 0;

bool isRelayOn_8 = false;
unsigned long lastRelayOnTime_8 = 0;
unsigned long lastRelayOffTime_8 = 0;

// Relay State
bool toggleState_1 = LOW; 
bool toggleState_2 = LOW; 
bool toggleState_3 = LOW; 
bool toggleState_4 = LOW; 
bool toggleState_5 = LOW; 
bool toggleState_6 = LOW; 
bool toggleState_7 = LOW; 
bool toggleState_8 = LOW; 

// Switch State
bool SwitchState_1 = LOW;
bool SwitchState_2 = LOW;
bool SwitchState_3 = LOW;
bool SwitchState_4 = LOW;
bool SwitchState_5 = LOW;
bool SwitchState_6 = LOW;
bool SwitchState_7 = LOW;
bool SwitchState_8 = LOW;

#include <BlynkSimpleEsp32.h> // Include the Blynk library for ESP32

BLYNK_CONNECTED() {
  // Request the latest state from the server
  Blynk.syncVirtual(VPIN_BUTTON_1);
  Blynk.syncVirtual(VPIN_BUTTON_2);
  Blynk.syncVirtual(VPIN_BUTTON_3);
  Blynk.syncVirtual(VPIN_BUTTON_4);
  Blynk.syncVirtual(VPIN_BUTTON_5);
  Blynk.syncVirtual(VPIN_BUTTON_6);
  Blynk.syncVirtual(VPIN_BUTTON_7);
  Blynk.syncVirtual(VPIN_BUTTON_8);
  Blynk.syncVirtual(VPIN_MENU);
}

// When App button is pushed - switch the state

BLYNK_WRITE(VPIN_BUTTON_1) {
  toggleState_1 = param.asInt();
  if (toggleState_1 == 1) {
        digitalWrite(RelayPin1, HIGH);
        if (!isRelayOn_1) {
            lastRelayOnTime_1 = timeClient.getEpochTime();
        }
        isRelayOn_1 = true;
        
    } else {
        digitalWrite(RelayPin1, LOW);
        if (isRelayOn_1) {
            lastRelayOffTime_1 = timeClient.getEpochTime();
        }
        isRelayOn_1 = false;
        
    }
}

BLYNK_WRITE(VPIN_BUTTON_2) {
  toggleState_2 = param.asInt();
  if (toggleState_2 == 1) {
        digitalWrite(RelayPin2, HIGH);
        if (!isRelayOn_2) {
            lastRelayOnTime_2 = timeClient.getEpochTime();
        }
        isRelayOn_2 = true;
        
    } else {
        digitalWrite(RelayPin2, LOW);
        if (isRelayOn_2) {
            lastRelayOffTime_2 = timeClient.getEpochTime();
        }
        isRelayOn_2 = false;
        
    }
}

BLYNK_WRITE(VPIN_BUTTON_3) {
  toggleState_3 = param.asInt();
  if (toggleState_3 == 1) {
        digitalWrite(RelayPin3, HIGH);
        if (!isRelayOn_3) {
            lastRelayOnTime_3 = timeClient.getEpochTime();
        }
        isRelayOn_3 = true;
        
    } else {
        digitalWrite(RelayPin3, LOW);
        if (isRelayOn_3) {
            lastRelayOffTime_3 = timeClient.getEpochTime();
        }
        isRelayOn_3 = false;
        
    }
}

BLYNK_WRITE(VPIN_BUTTON_4) {
  toggleState_4 = param.asInt();
  if (toggleState_4 == 1) {
        digitalWrite(RelayPin4, HIGH);
        if (!isRelayOn_4) {
            lastRelayOnTime_4 = timeClient.getEpochTime();
        }
        isRelayOn_4 = true;
        
    } else {
        digitalWrite(RelayPin4, LOW);
        if (isRelayOn_4) {
            lastRelayOffTime_4 = timeClient.getEpochTime();
        }
        isRelayOn_4 = false;
        
    }
}

BLYNK_WRITE(VPIN_BUTTON_5) {
  toggleState_5 = param.asInt();
  if (toggleState_5 == 1) {
        digitalWrite(RelayPin5, HIGH);
        if (!isRelayOn_5) {
            lastRelayOnTime_5 = timeClient.getEpochTime();
        }
        isRelayOn_5 = true;
        
    } else {
        digitalWrite(RelayPin5, LOW);
        if (isRelayOn_5) {
            lastRelayOffTime_5 = timeClient.getEpochTime();
        }
        isRelayOn_5 = false;
        
    }
}

BLYNK_WRITE(VPIN_BUTTON_6) {
  toggleState_6 = param.asInt();
  if (toggleState_6 == 1) {
        digitalWrite(RelayPin6, HIGH);
        if (!isRelayOn_6) {
            lastRelayOnTime_6 = timeClient.getEpochTime();
        }
        isRelayOn_6 = true;
        
    } else {
        digitalWrite(RelayPin6, LOW);
        if (isRelayOn_6) {
            lastRelayOffTime_6 = timeClient.getEpochTime();
        }
        isRelayOn_6 = false;
        
    }
}

BLYNK_WRITE(VPIN_BUTTON_7) {
  toggleState_7 = param.asInt();
  if (toggleState_7 == 1) {
        digitalWrite(RelayPin7, HIGH);
        if (!isRelayOn_7) {
            lastRelayOnTime_7 = timeClient.getEpochTime();
        }
        isRelayOn_7 = true;
        
    } else {
        digitalWrite(RelayPin7, LOW);
        if (isRelayOn_7) {
            lastRelayOffTime_7 = timeClient.getEpochTime();
        }
        isRelayOn_7 = false;
        
    }
}

BLYNK_WRITE(VPIN_BUTTON_8) {
  toggleState_8 = param.asInt();
  if (toggleState_8 == 1) {
        digitalWrite(RelayPin8, HIGH);
        if (!isRelayOn_8) {
            lastRelayOnTime_8 = timeClient.getEpochTime();
        }
        isRelayOn_8 = true;
        
    } else {
        digitalWrite(RelayPin8, LOW);
        if (isRelayOn_8) {
            lastRelayOffTime_8 = timeClient.getEpochTime();
        }
        isRelayOn_8 = false;
        
    }
}

BLYNK_WRITE(VPIN_BUTTON_C) {
  all_SwitchOff();
}

int selectedRelay = 1; 

BLYNK_WRITE(VPIN_MENU) {
  int menuState = param.asInt();
  if (menuState >= 1 && menuState <= 8) {
    selectedRelay = menuState;
    updateDisplay(); 
  }
}

void all_SwitchOff() {
  toggleState_1 = 0; digitalWrite(RelayPin1, LOW); Blynk.virtualWrite(VPIN_BUTTON_1, toggleState_1); delay(100);
  toggleState_2 = 0; digitalWrite(RelayPin2, LOW); Blynk.virtualWrite(VPIN_BUTTON_2, toggleState_2); delay(100);
  toggleState_3 = 0; digitalWrite(RelayPin3, LOW); Blynk.virtualWrite(VPIN_BUTTON_3, toggleState_3); delay(100);
  toggleState_4 = 0; digitalWrite(RelayPin4, LOW); Blynk.virtualWrite(VPIN_BUTTON_4, toggleState_4); delay(100);
  toggleState_5 = 0; digitalWrite(RelayPin5, LOW); Blynk.virtualWrite(VPIN_BUTTON_5, toggleState_5); delay(100);
  toggleState_6 = 0; digitalWrite(RelayPin6, LOW); Blynk.virtualWrite(VPIN_BUTTON_6, toggleState_6); delay(100);
  toggleState_7 = 0; digitalWrite(RelayPin7, LOW); Blynk.virtualWrite(VPIN_BUTTON_7, toggleState_7); delay(100);
  toggleState_8 = 0; digitalWrite(RelayPin8, LOW); Blynk.virtualWrite(VPIN_BUTTON_8, toggleState_8); delay(100);
}

void manual_control() {
   if (digitalRead(SwitchPin1) == LOW && SwitchState_1 == LOW) {
    digitalWrite(RelayPin1, LOW);
    Blynk.virtualWrite(VPIN_BUTTON_1, HIGH);
    toggleState_1 = HIGH;
    SwitchState_1 = HIGH;
    if (isRelayOn_1) {
            lastRelayOffTime_1 = timeClient.getEpochTime();
        }
        isRelayOn_1 = false;
  }
  if (digitalRead(SwitchPin1) == HIGH && SwitchState_1 == HIGH) {
    digitalWrite(RelayPin1, HIGH);
    Blynk.virtualWrite(VPIN_BUTTON_1, LOW);
    toggleState_1 = LOW;
    SwitchState_1 = LOW;
    if (!isRelayOn_1) {
            lastRelayOnTime_1 = timeClient.getEpochTime();
        }
        isRelayOn_1 = true;
  }
  if (digitalRead(SwitchPin2) == LOW && SwitchState_2 == LOW) {
    digitalWrite(RelayPin2, LOW);
    Blynk.virtualWrite(VPIN_BUTTON_2, HIGH);
    toggleState_2 = HIGH;
    SwitchState_2 = HIGH;
    if (isRelayOn_2) {
            lastRelayOffTime_2 = timeClient.getEpochTime();
        }
        isRelayOn_2 = false;
  }
  if (digitalRead(SwitchPin2) == HIGH && SwitchState_2 == HIGH) {
    digitalWrite(RelayPin2, HIGH);
    Blynk.virtualWrite(VPIN_BUTTON_2, LOW);
    toggleState_2 = LOW;
    SwitchState_2 = LOW;
    if (!isRelayOn_2) {
            lastRelayOnTime_2 = timeClient.getEpochTime();
        }
        isRelayOn_2 = true;
  }
  if (digitalRead(SwitchPin3) == LOW && SwitchState_3 == LOW) {
    digitalWrite(RelayPin3, LOW);
    Blynk.virtualWrite(VPIN_BUTTON_3, HIGH);
    toggleState_3 = HIGH;
    SwitchState_3 = HIGH;
    if (isRelayOn_3) {
            lastRelayOffTime_3 = timeClient.getEpochTime();
        }
        isRelayOn_3 = false;
  }
  if (digitalRead(SwitchPin3) == HIGH && SwitchState_3 == HIGH) {
    digitalWrite(RelayPin3, HIGH);
    Blynk.virtualWrite(VPIN_BUTTON_3, LOW);
    toggleState_3 = LOW;
    SwitchState_3 = LOW;
    if (!isRelayOn_3) {
            lastRelayOnTime_3 = timeClient.getEpochTime();
        }
        isRelayOn_3 = true;
  }
  if (digitalRead(SwitchPin4) == LOW && SwitchState_4 == LOW) {
    digitalWrite(RelayPin4, LOW);
    Blynk.virtualWrite(VPIN_BUTTON_4, HIGH);
    toggleState_4 = HIGH;
    SwitchState_4 = HIGH;
    if (isRelayOn_4) {
            lastRelayOffTime_4 = timeClient.getEpochTime();
        }
        isRelayOn_4 = false;
  }
  if (digitalRead(SwitchPin4) == HIGH && SwitchState_4 == HIGH) {
    digitalWrite(RelayPin4, HIGH);
    Blynk.virtualWrite(VPIN_BUTTON_4, LOW);
    toggleState_4 = LOW;
    SwitchState_4 = LOW;
    if (!isRelayOn_4) {
            lastRelayOnTime_4 = timeClient.getEpochTime();
        }
        isRelayOn_4 = true;
  }
  if (digitalRead(SwitchPin5) == LOW && SwitchState_5 == LOW) {
    digitalWrite(RelayPin5, LOW);
    Blynk.virtualWrite(VPIN_BUTTON_5, HIGH);
    toggleState_5 = HIGH;
    SwitchState_5 = HIGH;
    if (isRelayOn_5) {
            lastRelayOffTime_5 = timeClient.getEpochTime();
        }
        isRelayOn_5 = false;
  }
  if (digitalRead(SwitchPin5) == HIGH && SwitchState_5 == HIGH) {
    digitalWrite(RelayPin5, HIGH);
    Blynk.virtualWrite(VPIN_BUTTON_5, LOW);
    toggleState_5 = LOW;
    SwitchState_5 = LOW;
    if (!isRelayOn_5) {
            lastRelayOnTime_5 = timeClient.getEpochTime();
        }
        isRelayOn_5 = true;
  }
  if (digitalRead(SwitchPin6) == LOW && SwitchState_6 == LOW) {
    digitalWrite(RelayPin6, LOW);
    Blynk.virtualWrite(VPIN_BUTTON_6, HIGH);
    toggleState_6 = HIGH;
    SwitchState_6 = HIGH;
    if (isRelayOn_6) {
            lastRelayOffTime_6 = timeClient.getEpochTime();
        }
        isRelayOn_6 = false;
  }
  if (digitalRead(SwitchPin6) == HIGH && SwitchState_6 == HIGH) {
    digitalWrite(RelayPin6, HIGH);
    Blynk.virtualWrite(VPIN_BUTTON_6, LOW);
    toggleState_6 = LOW;
    SwitchState_6 = LOW;
    if (!isRelayOn_6) {
            lastRelayOnTime_6 = timeClient.getEpochTime();
        }
        isRelayOn_6 = true;
  }
  if (digitalRead(SwitchPin7) == LOW && SwitchState_7 == LOW) {
    digitalWrite(RelayPin7, LOW);
    Blynk.virtualWrite(VPIN_BUTTON_7, HIGH);
    toggleState_7 = HIGH;
    SwitchState_7 = HIGH;
    if (isRelayOn_7) {
            lastRelayOffTime_7 = timeClient.getEpochTime();
        }
        isRelayOn_7 = false;
  }
  if (digitalRead(SwitchPin7) == HIGH && SwitchState_7 == HIGH) {
    digitalWrite(RelayPin7, HIGH);
    Blynk.virtualWrite(VPIN_BUTTON_7, LOW);
    toggleState_7 = LOW;
    SwitchState_7 = LOW;
    if (!isRelayOn_7) {
            lastRelayOnTime_7 = timeClient.getEpochTime();
        }
        isRelayOn_7 = true;
  }
  if (digitalRead(SwitchPin8) == LOW && SwitchState_8 == LOW) {
    digitalWrite(RelayPin8, LOW);
    Blynk.virtualWrite(VPIN_BUTTON_8, HIGH);
    toggleState_8 = HIGH;
    SwitchState_8 = HIGH;
    if (isRelayOn_8) {
            lastRelayOffTime_8 = timeClient.getEpochTime();
        }
        isRelayOn_8 = false;
  }
  if (digitalRead(SwitchPin8) == HIGH && SwitchState_8 == HIGH) {
    digitalWrite(RelayPin8, HIGH);
    Blynk.virtualWrite(VPIN_BUTTON_8, LOW);
    toggleState_8 = LOW;
    SwitchState_8 = LOW;
    if (!isRelayOn_8) {
            lastRelayOnTime_8 = timeClient.getEpochTime();
        }
        isRelayOn_8 = true;
  }
}

void updateDisplay() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);
  display.print("Menu ");
  display.print(selectedRelay);
  display.print(" ");
  if (selectedRelay == 1) {
    if (isRelayOn_1) {
      display.setCursor(0, 42);
      display.print("R1 Menyala Sejak: ");
      display.setCursor(0, 55);
      display.print(getFormattedTime(lastRelayOnTime_1));
    } else {
      display.setCursor(0, 42);
      display.print("R1 Dimatikan Pada: ");
      display.setCursor(0, 55);
      display.print(getFormattedTime(lastRelayOffTime_1));
    }
  } else if (selectedRelay == 2) {
     if (isRelayOn_2) {
      display.setCursor(0, 42);
      display.print("R2 Menyala Sejak: ");
      display.setCursor(0, 55);
      display.print(getFormattedTime(lastRelayOnTime_2));
    } else {
      display.setCursor(0, 42);
      display.print("R2 Dimatikan Pada: ");
      display.setCursor(0, 55);
      display.print(getFormattedTime(lastRelayOffTime_2));
    }
  } else if (selectedRelay == 3) {
     if (isRelayOn_3) {
      display.setCursor(0, 42);
      display.print("R3 Menyala Sejak: ");
      display.setCursor(0, 55);
      display.print(getFormattedTime(lastRelayOnTime_3));
    } else {
      display.setCursor(0, 42);
      display.print("R3 Dimatikan Pada: ");
      display.setCursor(0, 55);
      display.print(getFormattedTime(lastRelayOffTime_3));
    }
  } else if (selectedRelay == 4) {
     if (isRelayOn_4) {
      display.setCursor(0, 42);
      display.print("R4 Menyala Sejak: ");
      display.setCursor(0, 55);
      display.print(getFormattedTime(lastRelayOnTime_4));
    } else {
      display.setCursor(0, 42);
      display.print("R4 Dimatikan Pada: ");
      display.setCursor(0, 55);
      display.print(getFormattedTime(lastRelayOffTime_4));
    }
  } else if (selectedRelay == 5) {
     if (isRelayOn_5) {
      display.setCursor(0, 42);
      display.print("R5 Menyala Sejak: ");
      display.setCursor(0, 55);
      display.print(getFormattedTime(lastRelayOnTime_5));
    } else {
      display.setCursor(0, 42);
      display.print("R5 Dimatikan Pada: ");
      display.setCursor(0, 55);
      display.print(getFormattedTime(lastRelayOffTime_5));
    }
  } else if (selectedRelay == 6) {
     if (isRelayOn_6) {
      display.setCursor(0, 42);
      display.print("R6 Menyala Sejak: ");
      display.setCursor(0, 55);
      display.print(getFormattedTime(lastRelayOnTime_6));
    } else {
      display.setCursor(0, 42);
      display.print("R6 Dimatikan Pada: ");
      display.setCursor(0, 55);
      display.print(getFormattedTime(lastRelayOffTime_6));
    }
  } else if (selectedRelay == 7) {
     if (isRelayOn_7) {
      display.setCursor(0, 42);
      display.print("R7 Menyala Sejak: ");
      display.setCursor(0, 55);
      display.print(getFormattedTime(lastRelayOnTime_7));
    } else {
      display.setCursor(0, 42);
      display.print("R7 Dimatikan Pada: ");
      display.setCursor(0, 55);
      display.print(getFormattedTime(lastRelayOffTime_7));
    }
  } else if (selectedRelay == 8) {
     if (isRelayOn_8) {
      display.setCursor(0, 42);
      display.print("R8 Menyala Sejak: ");
      display.setCursor(0, 55);
      display.print(getFormattedTime(lastRelayOnTime_8));
    } else {
      display.setCursor(0, 42);
      display.print("R8 Dimatikan Pada: ");
      display.setCursor(0, 55);
      display.print(getFormattedTime(lastRelayOffTime_8));
    }
  }

}

int lastButtonState = LOW;
int currentButtonState = LOW;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
void cekTombolTekan() {
  int reading = digitalRead(TombolPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != currentButtonState) {
      currentButtonState = reading;

      if (currentButtonState == LOW) {
        // Tombol ditekan
        selectedRelay = (selectedRelay % 8) + 1; // Menu berulang dari 1 ke 8
        Blynk.virtualWrite(VPIN_MENU, selectedRelay);
      }
    }
  }

  lastButtonState = reading;
}

void sensorsuhu() {
  TempAndHumidity  data = dhtSensor.getTempAndHumidity();
  display.setCursor(0, 10);
  display.print("Suhu: " + String(data.temperature, 2) + "C");
  display.setCursor(0, 20);
  display.print("Kelembapan: " + String(data.humidity, 1) + "%");
  delay(10000); 
}


void setup() {
  Serial.begin(115200);
  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);
  pinMode(RelayPin5, OUTPUT);
  pinMode(RelayPin6, OUTPUT);
  pinMode(RelayPin7, OUTPUT);
  pinMode(RelayPin8, OUTPUT);

  pinMode(wifiLed, OUTPUT);

  pinMode(SwitchPin1, INPUT_PULLUP);
  pinMode(SwitchPin2, INPUT_PULLUP);
  pinMode(SwitchPin3, INPUT_PULLUP);
  pinMode(SwitchPin4, INPUT_PULLUP);
  pinMode(SwitchPin5, INPUT_PULLUP);
  pinMode(SwitchPin6, INPUT_PULLUP);
  pinMode(SwitchPin7, INPUT_PULLUP);
  pinMode(SwitchPin8, INPUT_PULLUP);
  pinMode(TombolPin, INPUT_PULLUP);
  //During Starting all Relays should TURN OFF
  digitalWrite(RelayPin1, LOW);
  digitalWrite(RelayPin2, LOW);
  digitalWrite(RelayPin3, LOW);
  digitalWrite(RelayPin4, LOW);
  digitalWrite(RelayPin5, LOW);
  digitalWrite(RelayPin6, LOW);
  digitalWrite(RelayPin7, LOW);
  digitalWrite(RelayPin8, LOW);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Jangan lanjutkan, lakukan loop selamanya
  }

  Blynk.begin("Replace_your_token_blynk", "Wokwi-GUEST", "");
  timeClient.begin();
  timeClient.setTimeOffset(0);
  timeClient.forceUpdate(); 
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
}

void loop() {
  Blynk.run();
  manual_control(); 
  cekTombolTekan();
  updateDisplay();
  sensorsuhu();
  display.display();
}
String getFormattedTime(unsigned long epochTime) {
  struct tm timeinfo;
  time_t epoch = (time_t)epochTime;
  localtime_r(&epoch, &timeinfo);

  String timeString = "";
  if (timeinfo.tm_hour < 10) {
    timeString += "0";
  }
  timeString += String(timeinfo.tm_hour) + ":";
  if (timeinfo.tm_min < 10) {
    timeString += "0";
  }
  timeString += String(timeinfo.tm_min) + ":";
  if (timeinfo.tm_sec < 10) {
    timeString += "0";
  }
  timeString += String(timeinfo.tm_sec);

  return timeString;
}
