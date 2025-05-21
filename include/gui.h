#ifndef GUI_H
#define GUI_H

#include <TFT_eSPI.h>

namespace gui {

  // Inizializza display e mostra schermata iniziale
  void init(TFT_eSPI& tft) {
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);

    tft.setTextColor(TFT_YELLOW, TFT_BLACK);
    tft.setTextSize(3);
    tft.drawCentreString("Giradischi Controller", 240, 10, 2);
  }

  void drawSpeedButtons(TFT_eSPI& tft) {
    tft.setTextSize(2);
    tft.setTextColor(TFT_WHITE, TFT_BLUE);

    tft.fillRect(20, 50, 80, 40, TFT_BLUE);
    tft.drawCentreString("33", 60, 60, 2);

    tft.fillRect(120, 50, 80, 40, TFT_BLUE);
    tft.drawCentreString("45", 160, 60, 2);

    tft.fillRect(220, 50, 80, 40, TFT_BLUE);
    tft.drawCentreString("78", 260, 60, 2);
  }

  void drawPitchSlider(TFT_eSPI& tft) {
    tft.setTextSize(2);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);

    tft.drawString("Pitch:", 20, 120, 2);
    tft.drawString("-8%", 100, 160, 2);
    tft.drawString("+8%", 360, 160, 2);

    tft.drawRect(150, 165, 180, 10, TFT_WHITE); // slider
    tft.fillRect(235, 165, 10, 10, TFT_GREEN);  // cursore
  }

  void drawStartStopButton(TFT_eSPI& tft) {
    tft.fillRect(150, 220, 180, 50, TFT_RED);
    tft.setTextColor(TFT_WHITE, TFT_RED);
    tft.drawCentreString("START / STOP", 240, 235, 2);
  }

  void drawHomeScreen(TFT_eSPI& tft) {
    drawSpeedButtons(tft);
    drawPitchSlider(tft);
    drawStartStopButton(tft);
    drawPitchSlider(tft, 0);
  }

  // Placeholder per futura logica touch
  void onPressSpeed(int rpm) {
    // Logica simulata
    Serial.print("Velocità selezionata: ");
    Serial.println(rpm);
  }

  void onPressStartStop() {
    Serial.println("START / STOP premuto");
  }

}
void drawPitchSlider(TFT_eSPI &tft, int pitchValue) {
  // Base dello slider
  tft.fillRect(40, 320, 280, 20, TFT_DARKGREY);
  tft.drawRect(40, 320, 280, 20, TFT_WHITE);

  // Linea centrale
  tft.drawLine(180, 320, 180, 340, TFT_WHITE);

  // Valore attuale
  int knobX = map(pitchValue, -8, 8, 40, 320);
  tft.fillCircle(knobX, 330, 8, TFT_RED);

  // Testo valore
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setCursor(140, 350);
  tft.print("Pitch: ");
  tft.print(pitchValue);
  tft.print(" %");
}


#endif
