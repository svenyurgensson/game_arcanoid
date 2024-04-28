#pragma once

// Furduino Joystick
#define PIN_START_BUTTON 24
#define PIN_RIGHT_BUTTON 29
#define PIN_LEFT_BUTTON 1
#define PIN_UP_BUTTON 24

#define JOYPAD_LEFT (digitalRead(PIN_LEFT_BUTTON))
#define JOYPAD_RIGHT (digitalRead(PIN_RIGHT_BUTTON))
#define JOYPAD_UP (digitalRead(PIN_START_BUTTON))

#define JOYPAD_UP_PRESSED (digitalRead(PIN_START_BUTTON) == 0)
#define JOYPAD_UP_UNPRESSED (digitalRead(PIN_START_BUTTON) == 1)
#define START_PRESSED (digitalRead(PIN_START_BUTTON) == 0)
#define START_UNPRESSED (digitalRead(PIN_START_BUTTON) == 1)
#define JOY_BOTH_LEFT_RIGHT_PRESSED (digitalRead(PIN_LEFT_BUTTON) == 0 && digitalRead(PIN_RIGHT_BUTTON) == 0)

class Joystick
{
public:
    uint8_t up = 1, left = 1, right = 1, start = 1;

    Joystick()
    {
        init();
    }

    void init()
    {
        pinMode(PIN_START_BUTTON, INPUT_PULLUP);
        //pinMode(PIN_UP_BUTTON, INPUT_PULLUP);
        pinMode(PIN_RIGHT_BUTTON, INPUT_PULLUP);
        pinMode(PIN_LEFT_BUTTON, INPUT_PULLUP);        
    }

    bool read()
    {
        bool changed = false;
        uint8_t tmp;
        uint16_t tmp16;

        tmp = JOYPAD_LEFT;
        if (tmp != left)
        {
            left = tmp;
            changed = true;
        }

        tmp = JOYPAD_RIGHT;
        if (tmp != right)
        {
            right = tmp;
            changed = true;
        }

        tmp = JOYPAD_UP;
        if (tmp != up)
        {
            up = tmp;
            start = tmp;
            changed = true;
        }

        return changed;
    }
};

static Joystick control;

static void log_joystick_state()
{
    if (control.read())
    {
        Serial.print("UP="), Serial.print(control.up);
        Serial.print("\tLEFT="), Serial.print(control.left);
        Serial.print("\tRIGHT="), Serial.print(control.right);
        Serial.println(" ");
    }
}