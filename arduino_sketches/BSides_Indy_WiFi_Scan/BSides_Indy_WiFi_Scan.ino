#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`
#include "ESP8266WiFi.h"
#define UP 1
#define ESC 3
#define ENTER 2
#define DOWN 0
SSD1306 display(0x3c, D2, D1);

const unsigned char PROGMEM fdl_bmp1[] = {
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0B, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xB0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xD8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xAC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x5A, 0x3E, 0x00, 0x01, 0xF0, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x04, 0x10, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x03, 0x81, 0x00, 0x00, 0x00, 0x00, 0x30, 0xC4, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x02, 0xC1, 0x1F, 0x10, 0x0C, 0x01, 0xFF, 0xB5, 0x80, 0x18, 0x01, 0xF3, 0x04, 0x00, 0x0F,
0xF0, 0x02, 0x71, 0x20, 0x90, 0x0C, 0x01, 0xBE, 0xFF, 0x80, 0x10, 0x02, 0x09, 0x84, 0x00, 0x0F,
0xF0, 0x02, 0x19, 0x60, 0x90, 0x16, 0x03, 0x7A, 0x79, 0x80, 0x18, 0x04, 0x09, 0x40, 0x00, 0x0F,
0xF0, 0x02, 0x0D, 0x60, 0x90, 0x22, 0x03, 0x7B, 0xEF, 0xC0, 0x18, 0x04, 0x09, 0x34, 0x00, 0x0F,
0xF0, 0x02, 0x07, 0x40, 0x90, 0x3F, 0x03, 0x7D, 0xA1, 0xE0, 0x18, 0x04, 0x09, 0x1C, 0x00, 0x0F,
0xF0, 0x02, 0x03, 0x60, 0x90, 0x41, 0x04, 0x20, 0x8E, 0x20, 0x0F, 0x32, 0x11, 0x0C, 0x00, 0x0F,
0xF0, 0x03, 0x00, 0x3E, 0x1E, 0x41, 0x82, 0xFF, 0xFF, 0xE0, 0x07, 0xE1, 0xE1, 0x04, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x2C, 0x7C, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0xFF, 0xEF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0xB6, 0x95, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xDE, 0x4B, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x0F, 0x70, 0x02, 0x35, 0xFF, 0x40, 0x0F, 0xE0, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x35, 0xA5, 0x81, 0xFE, 0xF3, 0x00, 0xF5, 0xC8, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x7F, 0xDE, 0x60, 0xBD, 0xFF, 0x05, 0xEF, 0x6E, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x04, 0xF3, 0x60, 0x63, 0x95, 0x03, 0x9D, 0xFB, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x03, 0xFF, 0xBF, 0xFC, 0x7F, 0xFE, 0x1B, 0xFF, 0xDF, 0x80, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x01, 0xEE, 0x31, 0xCE, 0x69, 0xDE, 0x3B, 0x8F, 0x33, 0xC0, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x03, 0x94, 0xBF, 0xF5, 0x3E, 0x7C, 0xAA, 0xDD, 0x7E, 0xC0, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x07, 0xFE, 0xFF, 0xFF, 0xBF, 0xF1, 0xF7, 0xFB, 0xBF, 0xE0, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x0A, 0xC1, 0xB8, 0x5F, 0x8F, 0xC1, 0x79, 0xD7, 0x78, 0xC0, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x0F, 0xF7, 0x7F, 0xDF, 0x57, 0xFB, 0x39, 0xFF, 0xFE, 0x70, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x44, 0x37, 0xE5, 0xB9, 0xE5, 0x59, 0xAF, 0x78, 0xB0, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x01, 0x84, 0x00, 0x45, 0x22, 0xA6, 0x32, 0x01, 0x78, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x07, 0xFD, 0x00, 0x1B, 0xFF, 0xFF, 0xE0, 0x00, 0x3D, 0xE0, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x46, 0x00, 0x07, 0xB7, 0xE7, 0xC0, 0x00, 0x38, 0x20, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x03, 0xFC, 0x00, 0x01, 0xF7, 0xDF, 0xC0, 0x00, 0x3F, 0xC0, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x38, 0x00, 0x01, 0xB7, 0xF5, 0x80, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0xA4, 0x00, 0x00, 0x37, 0x0A, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0xFF, 0x9E, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x0C, 0x00, 0xC6, 0xFF, 0xB5, 0xE2, 0x00, 0x60, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x07, 0x8B, 0xF7, 0xFF, 0xF3, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x10, 0x84, 0xBE, 0xFE, 0x40, 0x90, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x80, 0x7B, 0xDE, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x39, 0x80, 0x6B, 0xCE, 0x01, 0xE4, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x80, 0x5B, 0xD5, 0x00, 0xF4, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x2E, 0xE3, 0xB7, 0xEF, 0xC7, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x2B, 0x9D, 0x72, 0xC3, 0x58, 0xC8, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xEF, 0xEF, 0xF7, 0xDF, 0x98, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x08, 0xDE, 0xC9, 0xB7, 0xF8, 0x80, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x0D, 0x86, 0x16, 0x11, 0xB1, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFA, 0x1F, 0xF8, 0x7D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0D, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0xEE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F
};






void setup() {
  display.init();
  display.flipScreenVertically();
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  pinMode(UP, INPUT_PULLUP);
  pinMode(ESC, INPUT_PULLUP);
  pinMode(ENTER, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
}

String BadSSID[] = "";

String GetWiFiStatus(int StatusCode) {
  if (StatusCode == 255) {
    return("No Shield");
  } else if (StatusCode == 0) {
    return("Idle");
  } else if (StatusCode == 1) {
    return("SSID Unavailable");
  } else if (StatusCode == 2) {
    return("Scan Completed");
  } else if (StatusCode == 3) {
    return("Connected");
  } else if (StatusCode == 4) {
    return("Connect Failed");
  } else if (StatusCode == 5) {
    return("Connection Lost");
  } else if (StatusCode == 6) {
    return("Disconnected");
  } else {
    return("Unknown State " + String(StatusCode));
  }
}

String GetWiFiEncryption(int StatusCode) {
  if (StatusCode == 2) {
    return("WPA PSK");
  } else if (StatusCode == 4) {
    return("WPA2 PSK");
  } else if (StatusCode == 5) {
    return("WEP");
  } else if (StatusCode == 7) {
    return("None");
  } else if (StatusCode == 8) {
    return("WPA/WPA2");
  } else {
    return("Unknown");
  }
}

bool WiFiScanned = false;
int WiFiIndex = 0;
int WiFiCount = 0;
bool DisplayUpdate = true;

void loop() {
 display.clear();
  //display.println((const char *) fdl_bmp1);
  display.drawXbm(0, 0, 128, 64, fdl_bmp1);
  display.display();
  delay(750);
  
  if(WiFi.status() != 3) {
    if(!WiFiScanned)
    {
      display.clear();
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_16);
      display.drawString(0, 0, "Scanning WiFi");
      display.display();

      WiFiCount = WiFi.scanNetworks();
    
      if (WiFiCount == 0) {
        display.clear();
        display.setTextAlignment(TEXT_ALIGN_LEFT);
        display.setFont(ArialMT_Plain_10);
        display.drawString(0, 0, "No Networks Found");
        display.display();
      } else {
        WiFiScanned = true;
        DisplayUpdate = true;
      }
    }
    else
    {
      if (digitalRead(UP) == LOW) {
        WiFiIndex--;
        DisplayUpdate = true;
        if (WiFiIndex < 0) {
          WiFiIndex = 0;
        }
      }
      if (digitalRead(ESC) == LOW) {
        WiFiScanned = false;
        WiFiIndex = 0;
        DisplayUpdate = true;
      }
      if (digitalRead(ENTER) == LOW) {

        WiFi.disconnect();
        char ssid[] = "";
        WiFi.SSID(WiFiIndex).toCharArray(ssid, (WiFi.SSID(WiFiIndex).length() +1));
        
        WiFi.begin(ssid);

        while ((WiFi.status() != 3) && (digitalRead(ESC) != LOW)) {
          display.clear();
          display.setTextAlignment(TEXT_ALIGN_LEFT);
          display.setFont(ArialMT_Plain_10);
          display.drawString(0, 0, "Connecting to " + String(ssid));
          display.drawString(0, 10, GetWiFiStatus(WiFi.status()));
          display.display();
          delay(500);
        }
        
        if (WiFi.status() == 3) {
          display.clear();
          display.setTextAlignment(TEXT_ALIGN_LEFT);
          display.setFont(ArialMT_Plain_10);
          display.drawString(0, 0, "Connected");
          display.drawString(0, 10, "IP: " + String(WiFi.localIP()[0]) + "." + String(WiFi.localIP()[1]) + "." + String(WiFi.localIP()[2]) + "." + String(WiFi.localIP()[3]));
          display.display();
          delay(500);
        }

        if (digitalRead(ESC) == LOW) {
          WiFiScanned = 0;
          WiFiIndex = 0;
          DisplayUpdate = true;
        }
        
      }
      if (digitalRead(DOWN) == LOW) {
        WiFiIndex++;
        DisplayUpdate = true;
        if (WiFiIndex > WiFiCount - 1) {
          WiFiIndex = WiFiCount - 1;
        }
      }

      if (DisplayUpdate) {
        display.clear();
        display.setTextAlignment(TEXT_ALIGN_LEFT);
        display.setFont(ArialMT_Plain_10);
        display.drawString(0, 0, "Networks: " + String(WiFiCount));
        display.drawString(0, 10, String(WiFiIndex + 1) + ": " + WiFi.SSID(WiFiIndex));
        display.drawString(0, 20, "Channel: " + String(WiFi.channel(WiFiIndex)));
        display.drawString(0, 30, "Strength: " + String(WiFi.RSSI(WiFiIndex)));
        display.drawString(0, 40, "Encryption: " + GetWiFiEncryption(WiFi.encryptionType(WiFiIndex)));
        display.display();
        DisplayUpdate = false;
        delay(200);
      }
    }
  }
  else {
    if (digitalRead(ESC) == LOW) {
      WiFi.disconnect();
      WiFiScanned = false;
      WiFiIndex = 0;
      DisplayUpdate = true;
    }  
  }
}
/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 by Daniel Eichhorn
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */
