/**
 * @file main.cpp
 * @brief Minimal example to initialize and print text on an SSD1306 I2C OLED using Arduino.
 *
 * This sketch demonstrates basic initialization of a 128x64 SSD1306 OLED
 * using the Adafruit_SSD1306 and Adafruit_GFX libraries. It sets up the
 * display over I2C, configures text properties, and prints sample lines.
 *
 * The example is intended for educational/demo purposes on Arduino UNO R4
 * or compatible boards.
 *
 * @author Himanshu
 * @date 2026-02-11
 * @version 1.0
 * @note Requires Adafruit_GFX and Adafruit_SSD1306 libraries.
 */

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/**
 * @brief OLED display width in pixels.
 *
 * Used to construct the Adafruit_SSD1306 display object.
 */
#define SCREEN_WIDTH 128 // OLED display width, in pixels

/**
 * @brief OLED display height in pixels.
 */
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

/**
 * @brief I2C address of the OLED display (commonly 0x3C or 0x3D).
 */
#define OLED_ADDR  0x3C // I2C address for the OLED display

/**
 * @brief Global SSD1306 display instance.
 *
 * Constructed with the configured screen width and height. Use this
 * object to draw graphics and text to the OLED.
 */
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);

/**
 * @brief Arduino setup() function.
 *
 * Initializes Serial (for debug output), initializes the SSD1306 display
 * via I2C, performs basic display configuration (clear, text size, color,
 * and cursor), and prints a few sample lines to the screen.
 *
 * If the display initialization fails, an error message is printed to
 * Serial and the program halts.
 *
 * @return void
 */
void setup() {
// write your initialization code here
    Serial.begin(9600);
    if (!display.begin(SSD1306_SWITCHCAPVCC,OLED_ADDR)) {
        Serial.println("OLED not found");
        while (true);
    }
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Arduino UNO R4");
    display.println("OLED with I2C");
    display.println("Hello Himanshu Ji");
    display.display();

}

/**
 * @brief Arduino loop() function.
 *
 * This example does not perform ongoing work in loop(). Add recurring
 * tasks, input polling, or animation updates here as needed.
 *
 * @return void
 */
void loop() {

// write your code here
}