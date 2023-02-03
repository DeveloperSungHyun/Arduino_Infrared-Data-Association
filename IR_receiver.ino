char IR_Pin = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(IR_Pin, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int i = IR_Data(IR_Pin);
 
  if (i == 15) {
    digitalWrite(13, true);
  } else {
    digitalWrite(13, false);
  }
}

int IR_Data(char pin) {
  char time_count = 0;
  char Data = 0;
  char shift = 0;
  if (digitalRead(pin) == false) { //9ms의 시작 신호 가 감지되면
    while (true) {
      //다음 4.5ms 의 true의 신호가 들어올때까지 반복
      if (digitalRead(pin) == true) {
        while (true) {
          if (digitalRead(pin) == true) {
            time_count++;
          } else if (time_count == 5) {
            // 신호가 4~5정도가 입력되면 데이터 입력 시작
            time_count = 0;//카운트 리셋
            while (true) { //실질적인 데이터 입력부
              if (digitalRead(pin) == true) {
                time_count++;
              } else if (time_count == 2) { //2ms 가 들어오면
                Data++;
                if(shift != 4) Data = Data << 1;//1bit shift
                shift++;
                time_count = 0;
              } else if (time_count = 1) { //1ms 가 들어오면
                if(shift != 4) Data = Data << 1;//1bit shift
                shift++;
                time_count = 0;
              }
              if (shift >= 5) {
                delay(1);
                return Data;//입력이 끝나면 입력받은 값 반환
              }
              delay(1);
            }
          } else {
            return -1;//start 입력신호가 아니라면 종료
          }
          delay(1);//1ms 간격으로 측정
        }
      }
    }
  }
  
}
