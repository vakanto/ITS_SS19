#define LED_PIN 13
#define LED_BLUE A0
#define LED_GREEN A1
#define LED_YELLOW A2
#define LED_HZ  1

//ITS-R-1
void setup() {
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  Serial.begin(9600);
}
int number=1;
int direct = 0;

void loop() {
  if(number==1){
    direct = 0;
    } else {
      if(number==4){
        direct = 1;
      }
    }

    if (direct == 0){
      number = number << 1;
    } else{
      number = number >> 1;
    }
  
  activate_led(number);
  delay(1000.0/LED_HZ);
}

void activate_led(int number){
    digitalWrite(LED_BLUE, (number&4)>>2);
    digitalWrite(LED_GREEN, (number&2)>>1);
    digitalWrite(LED_YELLOW, (number&1));  
}
