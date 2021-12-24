
void setup() {
   Serial.begin(9600);     // запускаем монитор порта
   pinMode(A7, INPUT); // к входу A1 подключаем потенциометр
}

void loop() {
   int st_distance = analogRead(A7); // считываем данные с порта A1
   // ставим задержку для удобства
}
