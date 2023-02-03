bool data[4];

byte Signal_Pin = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(Signal_Pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  data[0] = false;
  data[1] = false;
  data[2] = false;
  data[3] = false;
  IR_remote(data);//데이터 전송

  delay(5000);

  data[0] = true;
  data[1] = true;
  data[2] = false;
  data[3] = false;
  IR_remote(data);//데이터 전송

  delay(5000);

  data[0] = false;
  data[1] = false;
  data[2] = true;
  data[3] = true;
  IR_remote(data);//데이터 전송

  delay(5000);

  data[0] = true;
  data[1] = true;
  data[2] = true;
  data[3] = true;
  IR_remote(data);//데이터 전송

  delay(5000);

}


void IR_remote(bool data[]) {
  for (int i = 0; i < (38 * 9) + 5; i++) {  //9ms  start signal
    digitalWrite(Signal_Pin, true);
    delayMicroseconds(11);
    digitalWrite(Signal_Pin, false);
    delayMicroseconds(11);
  }
  delayMicroseconds(4500);

  for (int bit_shift = 0; bit_shift < 4; bit_shift++) {
    for (int i = 0; i < 38; i++) {  //1ms click
      digitalWrite(Signal_Pin, true);
      delayMicroseconds(11);
      digitalWrite(Signal_Pin, false);
      delayMicroseconds(11);
    }

    delay(data[bit_shift] + 1);//data_1
  }
  for (int i = 0; i < 38; i++) {  //1ms click
    digitalWrite(Signal_Pin, true);
    delayMicroseconds(11);
    digitalWrite(Signal_Pin, false);
    delayMicroseconds(11);
  }
  delay(4);//finish
}
