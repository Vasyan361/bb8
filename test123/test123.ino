#define in1 44
#define in2 46

void setup() {
    pinMode( in1, OUTPUT );
    pinMode( in2, OUTPUT );
}
void loop() {
    // выставляем 100% мощность на моторе А - 255 из 255
    // выставляем режим мотора - вращение по часовой
    digitalWrite( in1, HIGH );
    digitalWrite( in2, LOW );
    delay(3000); // пауза 3сек

    // режим мотора - вращение против часовой
    digitalWrite( in1, LOW );
    digitalWrite( in2, HIGH );
    delay(3000); // пауза 3сек
}