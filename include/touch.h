#ifndef TOUCH_H
#define TOUCH_H

#include <Adafruit_FT6206.h>

Adafruit_FT6206 ctp = Adafruit_FT6206();

bool initTouch() {
  return ctp.begin(40); // Sensibilità (puoi regolarla)
}

TS_Point getTouchPoint() {
  if (ctp.touched()) {
    TS_Point p = ctp.getPoint();

    // Per schermi con orientamento orizzontale (rotazione 1)
    return TS_Point{p.y, 480 - p.x, p.z};
  } else {
    return TS_Point{-1, -1, 0};
  }
}

#endif
