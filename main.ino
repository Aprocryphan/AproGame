// An 8-bit game for my Arduino UNO Mini LE
// int8_t is one instruction, 16 is split into two instructions
#include <EEPROM.h> // Persistant value storage 1Kb max
#include "textures.h" // Textures and font data
#include "dialogue.h"

uint8_t frame_buffer[1024]; // 128 * 64 / 8

void setPixel(int16_t x, int16_t y) {
  if (x < 0 || x >= 128 || y < 0 || y >= 64) return; // Bounds checking
  frame_buffer[x + (y/8)*128] |= (1 << (y%8));
}

uint16_t omega = 256; // omega, how many frames one cycle takes
uint16_t phi = 0; // phi, the offset that the wave starts void setup()


void setup() {

}

void loop() {

}