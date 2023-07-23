#include <Arduino.h>
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

void setup()
{
  Serial.begin(115200);
  pinMode(13, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);

  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

void loop()
{
  if (bleKeyboard.isConnected())
  {
    if (digitalRead(13) == LOW)
    {
      delay(100);
      // really ugly code
      if (digitalRead(13) == LOW)
      {
        bleKeyboard.write(KEY_MEDIA_CONSUMER_CONTROL_CONFIGURATION);
        // bleKeyboard.print("Hello world");
        delay(500);
      }
    }
    if (digitalRead(12) == LOW)
    {
      delay(100);
      if (digitalRead(12) == LOW)
      {
        bleKeyboard.write(KEY_MEDIA_NEXT_TRACK);
        delay(500);
      }
    }
    if (digitalRead(14) == LOW)
    {
      delay(100);

      if (digitalRead(14) == LOW)
      {
        bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
        delay(500);
      }
    }
    if (digitalRead(27) == LOW)
    {
      delay(100);
      if (digitalRead(27) == LOW)
      {
        bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
        delay(500);
      }
    }
  }
}