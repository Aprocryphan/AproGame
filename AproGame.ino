// An 8-bit game for my Arduino UNO Mini LE
// int8_t is one instruction, 16 is split into two instructions
#include <EEPROM.h> // Even this can be done manually
#include <Wire.h>
#include "textures.h" // Textures and font data
#include "dialogue.h"
#define OLED_ADDRESS 0x3C

uint8_t frame_buffer[1024]; // 128 * 64 / 8
uint8_t psudorandom;

void setPixel(int16_t x, int16_t y) {
  if (x < 0 || x >= 128 || y < 0 || y >= 64) return; // Bounds checking
  frame_buffer[x + (y/8)*128] |= (1 << (y%8));
}

void drawBuffer() {
  
}

void clearBuffer() {
  for (uint16_t i = 0; i < sizeof(frame_buffer); i++) {
    frame_buffer[i] = 0;
  }
}

uint16_t omega = 256; // omega, how many frames one cycle takes
uint16_t phi = 0; // phi, the offset that the wave starts
uint16_t sintime = 0;

uint8_t thickness = 2; // Makes a line 5 pixels thick (centre + 2 up + 2 down)
void thickenSin(uint8_t x, uint8_t y_center) {
  for (int8_t i = -thickness; i <= thickness; i++) {
    setPixel(x, y_center + i); 
  }
}

void drawDynamicWave() {
  uint16_t phase_accumulator = 0;
  uint16_t phi = sintime * 100;
  for (uint8_t x = 0; x < 128; x++) {
    uint16_t current_phase = phase_accumulator + phi;
    uint8_t lut_index = (uint8_t)(current_phase >> 8); // calculate the correct index needed for this slice of the wave
    uint8_t y_raw = pgm_read_byte(&sine_lut_256[lut_index]); // get the value from the LUT with the index calculated
    uint8_t y_center = 32 + (y_raw - 128) / 8;
    thickenSin(x, y_center); // draw the pixel
    phase_accumulator += omega;
  }
}

void setup() {
  Wire.begin();
  psudorandom = analogRead(A0);
}

void loop() {

}