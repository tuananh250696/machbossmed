int led_pin = 6;         //LED được nối với chân số 6 của Arduino
int pot_pin = A0;      //Chân giữa của biến trở được kết nối với chân tương tự A0 của Arduino
int output;
int led_value;

void setup() {
pinMode(led_pin, OUTPUT);
}

void loop() {
//Đọc giá trị từ biến trở
output = analogRead(pot_pin);
//Ánh xạ các giá trị từ 0 đến 255 vì chúng ta có thể đưa ra ngõ ra
//giá trị từ 0 -255 bằng cách sử dụng hàm analogwrite
led_value = map(output, 0, 1023, 0, 255);
analogWrite(led_pin, led_value);
delay(1);
}
