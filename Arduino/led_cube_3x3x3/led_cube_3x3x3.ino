// =-=-=-=-=-=-=-=-=-=-=--=-=-=-=--=-=-=-=-=-=-=
// Led cube 3x3x3
// =-=-=-=-=-=-=-=-=-=-=--=-=-=-=--=-=-=-=-=-=-=

int layer_arr[] = {0, 0, 0};
int column_arr[] = {2, 3, 4, 5, 6, 7, 8, 10, 9};

int y = 0;
int x = 0;
uint32_t tmr;

void setup() {
  Serial.begin(9600);
  while (y < 3) {
    pinMode(layer_arr[y], OUTPUT);
    Serial.print(layer_arr[y], " ");
    ++y;
  }
  Serial.println(" ");
  while (x < 9) {
    pinMode(column_arr[x], OUTPUT);
    Serial.print(column_arr[x], " ");
    ++x;
  }
   delay(800);
}

void loop() {

  // check all leds
  for (int layer = 0; layer < sizeof(layer_arr); ++layer) {
    digitalWrite(layer_arr[layer], HIGH);
    for (int column = 0; column < sizeof(column_arr); ++column) {
      digitalWrite(column_arr[column], HIGH);
    }
  }

}

void random_led() {
  x = 0;
  y = 0;
  randomSeed(analogRead(0));
  x = random(0, 8);
  y = random(0, 2);
  digitalWrite(layer_arr[y], HIGH);
  digitalWrite(column_arr[x], HIGH);
}

void one_layer() {
  x = 0;
  y = 0;
  while (y < sizeof(layer_arr)) {
    if (millis() - tmr >= 1000) {  // ищем разницу
      tmr = millis(); // сброс таймера
      digitalWrite(layer_arr[y], HIGH);
      while (x < sizeof(column_arr)) {
        digitalWrite(column_arr[x], HIGH);
        ++x;
      }
      ++y;
    }
  }
}

// =-=-=-=-=-=-=-=-=-=-=--=-=-=-=--=-=-=-=-=-=-=
// End the program
// =-=-=-=-=-=-=-=-=-=-=--=-=-=-=--=-=-=-=-=-=-=
