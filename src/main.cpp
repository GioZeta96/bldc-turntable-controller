#include <Arduino.h>
#include <TFT_eSPI.h>
#include "gui.h"
#include "touch.h"

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  gui::init(tft);
  gui::drawHomeScreen(tft);

  if (!initTouch()) {
    Serial.println("Touch non trovato!");
  } else {
    Serial.println("Touch inizializzato.");
  }
}

void loop() {
  static int currentPitch = 0;
  TS_Point p = getTouchPoint();

  if (p.x != -1) {
    Serial.print("Tocco rilevato in: ");
    Serial.print(p.x); Serial.print(", "); Serial.println(p.y);

    // Mappa i tocchi ai pulsanti
    if (p.y >= 50 && p.y <= 90) {
      if (p.x >= 20 && p.x <= 100) gui::onPressSpeed(33);
      else if (p.x >= 120 && p.x <= 200) gui::onPressSpeed(45);
      else if (p.x >= 220 && p.x <= 300) gui::onPressSpeed(78);
    }

    if (p.y >= 220 && p.y <= 270 && p.x >= 150 && p.x <= 330) {
      gui::onPressStartStop();
    }

    delay(200); // debounce grezzo
  }

  if (p.y >= 310 && p.y <= 360 && p.x >= 40 && p.x <= 320) {
    int newPitch = map(p.x, 40, 320, -8, 8);
    if (newPitch != currentPitch) {
      currentPitch = newPitch;
      gui::drawPitchSlider(tft, currentPitch);
      Serial.print("Nuovo pitch: ");
      //Serial.println(currentPitch);
    }
  }

}
