int repeats;
int maxRepeats;
float interval;
bool isSpeedingUp;
float speedingRate;

// declare setup variables for blink
void setupBlink()
{
  interval = 1000;
  repeats = 0;
  maxRepeats = 10;
  isSpeedingUp = true;
  speedingRate = 1.3;

  pinMode(13, OUTPUT);
}

// update interval of blink according to isSpeedingUp
void updateInterval()
{
  if (isSpeedingUp)
  {
    interval = interval / speedingRate;
  }
  else
  {
    interval = interval * speedingRate;
  }
}

// reverse speed increase > decrease
void reverse()
{
  repeats = 0;
  isSpeedingUp = isSpeedingUp ? false : true;
}

// reverse after max repeats is reached
void reverseSpeedHandler()
{
  bool reachedMaxRepeats = repeats == maxRepeats;
  if (reachedMaxRepeats)
  {
    reverse();
  }
}

void blinkLed(int interval)
{
  ++repeats;
  digitalWrite(13, HIGH);
  delay(interval);
  digitalWrite(13, LOW);
  delay(interval);
}

void blink()
{
  reverseSpeedHandler();
  updateInterval();
  blinkLed(interval);
}