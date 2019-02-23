void setup()
{
  setupBlink();
  Serial.begin(9600);
}

void loop()
{
  blink();

  Serial.print("blinked - ");
  Serial.print("with interval ");
  Serial.println(interval);
}