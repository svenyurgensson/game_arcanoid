#include "main.h"

// the setup routine runs once when you press reset:
void setup()
{
  Serial.begin(115200);
  delay(1000);

  // initialize the digital pin as an output.
  Serial.println(F("\nStarting\n"));
  init_display();
  game = new Game();
}

void loop()
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

  game->refresh();
  delay(20);
}
