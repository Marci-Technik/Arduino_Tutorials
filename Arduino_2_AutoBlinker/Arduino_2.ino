#define led_rechts 6
#define led_links 7
#define taster_rechts 2
#define taster_links 3

bool LED_AN_L = false;
bool LED_AN_R = false;
bool AN_AUS = false;

unsigned long Cooldown_Blinken = 0;
unsigned long ms_500 = 500;

void setup() {
  pinMode(led_rechts, OUTPUT);
  pinMode(led_links, OUTPUT);
  pinMode(taster_rechts, INPUT);
  pinMode(taster_links, INPUT);

  attachInterrupt(0, TasterInt_R, FALLING);
  attachInterrupt(1, TasterInt_L, FALLING);
}

void TasterInt_R()
{
  LED_AN_R = ! LED_AN_R;
}

void TasterInt_L()
{
  LED_AN_L = ! LED_AN_L;
}

void loop() {
  //Blinken
  if (Cooldown_Blinken <= millis())
  {
    Cooldown_Blinken = millis() + ms_500;
    if (AN_AUS == true)
    {
      digitalWrite(led_rechts, LED_AN_R);
      digitalWrite(led_links, LED_AN_L);
    }
    else
    {
      digitalWrite(led_rechts, false);
      digitalWrite(led_links, false);
    }
    AN_AUS = !AN_AUS;
  }
  
}
