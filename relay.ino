/**
 * 4 channel animation
 * LED Strip A - Pin 4
 * LED Strip B - Pin 5
 * LED Strip C - Pin 6
 * LED Strip D - Pin 7
 * All LEDs connected to common ground
 * 5v output - Unused pin
 * 3v Output - Unused pin
 */

const int pins[] = {4, 5, 6, 7};
const int total = sizeof(pins)/sizeof(int);

/**
 * LED and Relay work with different output pattern.
 * false: LED is connected
 * true: Relay is connected
 */
bool relay = false;

/**
 * Output status based on what is connected
 */
const bool ON = relay?LOW:HIGH;
const bool OFF = !ON;

void setup()
{
  int i;
  for(i=0; i<total; ++i)
  {
    pinMode(pins[i], OUTPUT);
  }

  all(OFF);
}

void loop()
{
  int t;
  int times = 4;

  for(t=0; t<times; ++t) walk();
  delay(100);
  
  for(t=0; t<times; ++t) flash();
  delay(100);
  
  for(t=0; t<times; ++t) walk_reverse();
  delay(100);
  
  for(t=0; t<times; ++t) flash();
  delay(100);
}

void walk()
{
  int i;
  for(i=0; i<total; ++i)
  {
    digitalWrite(pins[i], ON);
    delay(200);
    
    digitalWrite(pins[i], OFF);
  }
}

void walk_reverse()
{
  int i;
  for(i=total-1; i>=0; --i)
  {
    digitalWrite(pins[i], ON);
    delay(200);
    
    digitalWrite(pins[i], OFF);
  }
}

void all(bool PINMODE)
{
  int i;
  for(i=0; i<total; ++i)
  {
    digitalWrite(pins[i], PINMODE);
  }
}

void flash()
{
  all(ON);
  delay(80);

  all(OFF);
  delay(80);
}

