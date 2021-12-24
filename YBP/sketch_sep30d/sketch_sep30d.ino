#include <NewPing.h>

//const int PIN_TRIG = 53;
//const int PIN_ECHO = 52;

#define PIN_TRIG  53
#define PIN_ECHO  52

#define MAX_DISTANCE 200 // Константа для определения максимального расстояния, которое мы будем считать корректным.

// Создаем объект, методами которого будем затем пользоваться для получения расстояния.
// В качестве параметров передаем номера пинов, к которым подключены выходы ECHO и TRIG датчика

NewPing sonar(PIN_TRIG, PIN_ECHO, MAX_DISTANCE);

//NewPing sonarR(PIN_TRIG_R, PIN_ECHO_R, MAX_DISTANCE);

//NewPing sonarL(PIN_TRIG_L, PIN_ECHO_L, MAX_DISTANCE);

void setup() {
  // Инициализируем взаимодействие по последовательному порту на скорости 9600
  Serial.begin(9600);
}

void loop() {

  // Стартовая задержка, необходимая для корректной работы.
  delay(50);

  // Получаем значение от датчика расстояния и сохраняем его в переменную
  unsigned int distance = sonar.ping_cm();

  // Печатаем расстояние в мониторе порта
  Serial.print(distance);
  Serial.println("см");

}
