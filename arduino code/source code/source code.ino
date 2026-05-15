int trig_pins[] = {2, 4, 6};
int echo_pins[] = {7, 8, 9};

int threshold = 30; // cm

int direction_frequencies[] = {262, 523, 784};

int startup_frequencies[] = {523, 659, 784, 1046};
int startup_frequency_durations[] = {200, 200, 200, 400}; 

int buzzer_pin = 11;

int distances[3];

void setup() {
  for (int pin : trig_pins)
    pinMode(pin, OUTPUT);
  for (int pin: echo_pins)
    pinMode(pin, INPUT);

  pinMode(buzzer_pin, OUTPUT);

  for (int i = 0; i < 4; i++)
  {
    int freq = startup_frequencies[i];
    int duration = startup_frequency_durations[i];
    tone(buzzer_pin, freq);
    delay(duration);
  }
  noTone(buzzer_pin);

  Serial.begin(115200);
}

void loop() {
  for (int i = 0; i < 3; i++)
    distances[i] = calc_dist(trig_pins[i], echo_pins[i]);

 int min_val = distances[0];
 int min_index = 0;
  for (int i = 0; i < 3; i++)
  {
    if (distances[i] < min_val)
    {
      min_val = distances[i];
      min_index = i;
    }
  }

  if (min_val < threshold)
    tone(buzzer_pin, direction_frequencies[min_index]);
  else
    noTone(buzzer_pin);

  for (int distance : distances)
  {
    Serial.print(distance);
    Serial.print(" ");
  }
  Serial.println();
}

long calc_dist(int trig_pin, int echo_pin)
{
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  long time = pulseIn(echo_pin, HIGH, 100000);
  if (time == 0)
    return 400;

  long distance = time * 0.017;
  return distance;
}
