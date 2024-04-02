#pragma once

// Furduino Joystick
#define PIN_START_BUTTON 11
#define PIN_RIGHT_BUTTON 12
#define PIN_DOWN_BUTTON 13
#define PIN_LEFT_BUTTON 14
#define PIN_UP_BUTTON 15
#define JOYSTICK_AXIS_X 26
#define JOYSTICK_AXIS_Y 27

#define JOYPAD_LEFT (digitalRead(PIN_LEFT_BUTTON))
#define JOYPAD_RIGHT (digitalRead(PIN_RIGHT_BUTTON))
#define JOYPAD_DOWN (digitalRead(PIN_DOWN_BUTTON))
#define JOYPAD_UP (digitalRead(PIN_UP_BUTTON))
#define JOYPAD_CROSS (digitalRead(PIN_START_BUTTON))
#define JOYSTICK_X (analogRead(JOYSTICK_AXIS_X))
#define JOYSTICK_Y (analogRead(JOYSTICK_AXIS_Y))

#define JOYPAD_UP_PRESSED (JOYPAD_UP == 0)
#define JOYPAD_UP_UNPRESSED (JOYPAD_UP == 1)
#define JOYPAD_DOWN_PRESSED (JOYPAD_DOWN == 0)
#define JOYPAD_DOWN_UNPRESSED (JOYPAD_DOWN == 1)
#define START_PRESSED (digitalRead(PIN_START_BUTTON) == 0)
#define START_UNPRESSED (digitalRead(PIN_START_BUTTON) == 1)

class Joystick
{
public:
    uint8_t up = 1, down = 1, left = 1, right = 1, cross = 1;
    uint16_t x = 512, y = 512;

    const uint16_t epsilon = 16;

    Joystick()
    {
        init();
    }

    void init()
    {
        pinMode(PIN_START_BUTTON, INPUT_PULLUP);
        pinMode(PIN_RIGHT_BUTTON, INPUT_PULLUP);
        pinMode(PIN_DOWN_BUTTON, INPUT_PULLUP);
        pinMode(PIN_LEFT_BUTTON, INPUT_PULLUP);
        pinMode(PIN_UP_BUTTON, INPUT_PULLUP);
        pinMode(JOYSTICK_AXIS_X, INPUT_PULLUP); // analog
        pinMode(JOYSTICK_AXIS_Y, INPUT_PULLUP); // analog
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
            changed = true;
        }

        tmp = JOYPAD_DOWN;
        if (tmp != down)
        {
            down = tmp;
            changed = true;
        }

        tmp = JOYPAD_CROSS;
        if (tmp != cross)
        {
            cross = tmp;
            changed = true;
        }

        tmp16 = JOYSTICK_X;
        if (abs(tmp16 - x) >= epsilon)
        {
            if (tmp16 < x)
            {
                left = 0;
                right = 1;
            }
            else
            {
                right = 0;
                left = 1;
            }

            x = tmp16;
            changed = true;
        }

        tmp16 = JOYSTICK_Y;
        if (abs(tmp16 - y) >= epsilon)
        {
            // if (tmp16 < y) { down = 0; up = 1; }
            // else { up = 0; down = 1; }

            y = tmp16;
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
        Serial.print("\tDOWN="), Serial.print(control.down);
        Serial.print("\tLEFT="), Serial.print(control.left);
        Serial.print("\tRIGHT="), Serial.print(control.right);
        Serial.print("\tJCENTER="), Serial.print(control.cross);
        Serial.print("\tJ-X="), Serial.print(control.x);
        Serial.print("\tJ-Y="), Serial.println(control.y);
        Serial.println(" ");
    }
}