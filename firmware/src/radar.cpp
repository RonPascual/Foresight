#include <Arduino.h>
#include "foresight_types.h"
#include "radar.h"
// Radar Frame Parser
// Things to know about the frame format:
// - Each frame starts with 0xAA 0xAA and ends with 0x55 0x55
// - The third byte is the number of targets in the frame
// - Each target is 10 bytes long (the 10 bytes are the target's information)

// CONSTANTS
const int RX_PIN = 16;   
const int TX_PIN = 17;
const long BAUD_RATE = 115200;

const uint8_t FRAME_START = 0xAA;
const uint8_t FRAME_END = 0x55;

const size_t TARGET_SIZE = 10; // each target is 10 bytes long

// Byte Positions inside one 10-byte target record
const int OFFSET_ID = 0;
const int OFFSET_DIRECTION = 1;
const int OFFSET_DISTANCE = 2;     // 2 bytes
const int OFFSET_SPEED = 4;        // 2 bytes
const int OFFSET_FLAGS = 6;        // high-speed and association flags
const int OFFSET_FRAMES = 7;
const int OFFSET_ANGLE = 8;        // 2 bytes, signed


// Global Variables
uint8_t frameBuffer[256]; // buffer to store the incoming frame
size_t pos = 0;           // current position in the buffer
uint8_t numTargets = 0;   // number of targets in the current frame
size_t expectedLength = 0; // expected length of the current frame

// Function Declarations
void resetFrame();
bool isFrameValid(const uint8_t* buf, size_t len);
void parseFrame(const uint8_t* buf, size_t len);
uint16_t combineBytes(const uint8_t* p);
Target decodeTarget(const uint8_t* r);
void printTarget(const Target& t);


void setup() {
  Serial.begin(115200);
  Serial1.begin(BAUD_RATE, SERIAL_8N1, RX_PIN, TX_PIN);
}


// loop runs forever
void loop() {
  readRadarBytes();
}


void readRadarBytes() {
  while (Serial1.available()) {
    uint8_t b = Serial1.read();   // read ONE byte

    if (pos == 0) {
      // Still looking for the first start byte
      // if b == 0xAA: add it to the buffer
      // else: discard it
      
    }
    else if (pos == 1) {
      // Need the second start byte right after the first
      // if b == 0xAA: add it to the buffer
      // else: not a real frame start, reset pos to 0 and discard
    }
    else {
      // A frame is in progress: add every byte to the buffer
      // if we just received the 3rd byte (pos == 3 after adding):
      //   numTargets = that byte
      //   expected length = 5 + 10 * numTargets
      // if we have collected the expected length:
      //   check the last two bytes are 0x55 0x55
      //   if valid: parse the frame
      //   reset pos to 0 to look for the next frame
    }
  }
}


void resetFrame() {
  // set pos = 0, numTargets = 0, expectedLength = 0
}


bool isFrameValid(const uint8_t* buf, size_t len) {
  // Check the frame is valid (start bytes, end bytes, length)
  // Return true if valid, false if not
  return false; // placeholder
}


// Need to combine bytes since distance, speed, and angle are sent as 2 byte values 
uint16_t combineBytes(const uint8_t* p) {
  // Combine two bytes into 1 number (low byte first: 6A 02 -> 618)
  return 0; // placeholder
}


Target decodeTarget(const uint8_t* r) {
  // Decode the 10-byte record into a Target struct
  // use combineBytes() to read the 2-byte values for distance, speed, and angle
  // divide distance and speed by 100 to convert to meters and km/h
  // read angle as signed value (since it can be negative)
  Target t = {};
  return t; // placeholder
}


void printTarget(const Target& t) {
  // Print the target's information in a readable format to verify during testing
}




// The example frame from the manual (3 targets, 35 bytes total)
const uint8_t exampleFrame[] = {
  0xAA, 0xAA, 0x03,                                           // start marker + 3 targets
  0x0D, 0x02, 0x6A, 0x02, 0xD7, 0x0B, 0x02, 0x0F, 0x23, 0x00, // target 1
  0x0E, 0x02, 0x80, 0x00, 0x2A, 0x07, 0x00, 0x0F, 0x11, 0x00, // target 2
  0x1F, 0x01, 0x1D, 0x02, 0x87, 0x1A, 0x01, 0x0B, 0xEE, 0xFF, // target 3
  0x55, 0x55                                                  // end marker
};
