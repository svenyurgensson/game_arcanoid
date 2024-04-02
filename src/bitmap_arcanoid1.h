#define ARCANOID1_HEIGHT 64
#define ARCANOID1_WIDTH 128

// array size is 1024
static const unsigned char arcanoid1[] PROGMEM  = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x8f, 
  0x47, 0x33, 0x11, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x8f, 0x47, 0x07, 0x0f, 0x1f, 0x0f, 0x0f, 
  0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0x7f, 0x3f, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x8f, 0xc7, 0x23, 0x11, 0x01, 0x03, 0x07, 0x0f, 
  0x1f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
  0x7f, 0x7f, 0x3f, 0x3f, 0x9f, 0x9f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x1f, 
  0x1f, 0x3f, 0x3f, 0x7f, 0x1f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x4f, 0x0f, 0x0f, 0x0f, 
  0x0f, 0x07, 0x27, 0x13, 0x08, 0x04, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x3f, 0x7f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x3f, 0x8f, 0x47, 0x33, 0x19, 0x0c, 0x06, 0x01, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x10, 0x08, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00, 0x01, 
  0x03, 0x8f, 0xc7, 0x23, 0x11, 0x08, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 
  0x0c, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xff, 
  0x9f, 0x0f, 0x27, 0x33, 0x78, 0xfc, 0xfe, 0xfd, 0xfc, 0x9c, 0x0c, 0x00, 0x00, 0xfc, 0xfc, 0xfc, 
  0xfc, 0xfc, 0x00, 0xfc, 0xfc, 0xfc, 0x7c, 0x3c, 0x7c, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 
  0x00, 0xfc, 0xfc, 0xfc, 0x7c, 0x3c, 0x7c, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0xa0, 0x70, 0xfc, 0xfe, 
  0xff, 0xfd, 0xdc, 0x8c, 0x04, 0x00, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0x00, 0x00, 0xfc, 0xfc, 0xfc, 
  0xfc, 0xf0, 0x00, 0x04, 0x0c, 0x1c, 0x7c, 0xfc, 0xf8, 0xfc, 0xfc, 0x7c, 0x3c, 0x1c, 0x00, 0x80, 
  0x04, 0x1c, 0x3c, 0x3c, 0x78, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 
  0x78, 0x7c, 0x3c, 0x1c, 0x0c, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0x7c, 0x3c, 0x00, 0xf8, 0xfc, 0xfc, 
  0x7c, 0x3c, 0x1c, 0x04, 0x80, 0xe0, 0xe0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0xfc, 0xf0, 0xe0, 0xc3, 0x87, 0x0f, 0x1f, 0x0f, 0x86, 0xc0, 0xe1, 0xf3, 0xf3, 
  0x03, 0x01, 0x80, 0xc3, 0xe1, 0xf0, 0xf8, 0xfc, 0xf8, 0xf0, 0xe1, 0xc3, 0x87, 0xc3, 0x01, 0x00, 
  0x80, 0xc1, 0xe1, 0xf0, 0xf8, 0xfc, 0xf8, 0xf0, 0xe1, 0xc3, 0x87, 0xc3, 0xe1, 0xf0, 0xf0, 0xe1, 
  0x83, 0x87, 0x1f, 0x0f, 0x86, 0x82, 0xc1, 0xf3, 0xf3, 0xf3, 0xf3, 0xf0, 0xf0, 0xf3, 0xf3, 0xf3, 
  0xf3, 0xf1, 0xf0, 0xf0, 0xfe, 0xfc, 0xf8, 0xf0, 0xe1, 0xe1, 0xe1, 0xf0, 0xfc, 0xfe, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xf9, 0xf9, 0xf9, 0xf8, 0xf8, 0xfc, 0xfc, 
  0xfc, 0xfc, 0xfe, 0xff, 0x80, 0x00, 0x00, 0x80, 0xc1, 0xf0, 0xf0, 0x00, 0x80, 0xc1, 0xc1, 0xf0, 
  0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};