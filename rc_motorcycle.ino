#include <RCSwitch.h>


RCSwitch mySwitch = RCSwitch();

int k_1 = "fhfhfhfh";
int k_2 = "fhfhfhfh";
int k_3 = "fhfhfhfhh";
int radio_value;
int left_signal = 3;
int right_signal = 4;
int front_light = 5;
int back_light = 6;
int beam_light = 7;// selektör
int starter = 8;// marş düğmesi
int ignition_r = 9;// anahtar kontak
int ignition_b = 10;// kontak düğmesi
int reflector = 0;
int ignition = 0;
int engine_start = 0;
int lock;
unsigned long old_time = 0;
void setup() {
  mySwitch.enableReceive(0);  // Receiver input on interrupt 0 (D2)
  pinMode(left_signal, OUTPUT);
  pinMode(right_signal, OUTPUT);
  pinMode(front_light, OUTPUT);
  pinMode(back_light, OUTPUT);
  pinMode(beam_light, OUTPUT);
  pinMode(starter, OUTPUT);
  pinMode(ignition_r, OUTPUT);
  pinMode(ignition_b, OUTPUT);
  digitalWrite(ignition_r, LOW);

}

void loop() {
  if (mySwitch.available()) {
    radio_value = mySwitch.getReceivedValue();
    if (radio_value == k_3) {
      if (lock == 0 && engine_start == 0) {
        lock = 1;
        ignition = 1;
        digitalWrite(ignition_r, HIGH);
        digitalWrite(ignition_b, HIGH);

      }
      if (lock == 1 && engine_start == 0) {
        engine_start = 1;
        digitalWrite(starter, HIGH);
        delay(300);
        digitalWrite(starter, LOW);
        delay(400);
      }

    }
    if (radio_value == k_1) {
      if (engine_start == 1 ) {
        engine_start = 0;
        ignition = 0;
        digitalWrite(ignition_b, LOW);


      }
      if (engine_start == 0 && lock == 1) {
        lock = 0;
        digitalWrite(ignition_b, LOW);
      }
    }
    if (radio_value == k_2) {
      if (reflector == 0) {
        reflector = 1;
      }
      if (reflector == 1) {
        reflector = 0;
      }
    }

    mySwitch.resetAvailable();
  }
  if (millis - old_time > 0) {
    if (reflector == 1) {
      digitalWrite(left_signal, HIGH);
      delay(50);
      digitalWrite(left_signal, LOW);
      delay(50);
      digitalWrite(left_signal, HIGH);
      delay(50);
      digitalWrite(left_signal, LOW);
      delay(300);
      digitalWrite(right_signal, HIGH);
      delay(50);
      digitalWrite(right_signal, LOW);
      delay(50);
      digitalWrite(right_signal, HIGH);
      delay(50);
      digitalWrite(right_signal, LOW);
      delay(300);

    }
  }
}
