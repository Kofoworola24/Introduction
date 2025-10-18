
int led_delay = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void greet(int iteration, int delay_ms){
  for(int j=0; j<=iteration; j++){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(delay_ms);
    digitalWrite(LED_BUILTIN, LOW);
    delay(delay_ms);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    String message = Serial.readString();
    if(message == "kofo"){
      greet(20, 200);
    }else if(message == "dubem"){
      greet(10, 500);
    }else{
      greet(60, 50);
    }
    // led_delay = value;
    // Serial.println(led_delay);
  }
  // digitalWrite(LED_BUILTIN, HIGH);
  // delay(led_delay);
  // digitalWrite(LED_BUILTIN, LOW);
  // delay(led_delay);
}
