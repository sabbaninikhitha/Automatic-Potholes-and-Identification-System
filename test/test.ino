#include <WiFi.h>
#include "esp_camera.h"
#include "esp_system.h"
hw_timer_t *timer = NULL;
void IRAM_ATTR resetModule(){
ets printf("reboot\n"); I
esp_restart();
}
#include <TridentTD_LineNotify.h>
#define SSID // WiFi name
#define PASSWORD "0894440818" // PASSWORD
#define LINE TOKEN "Bsw27xkrenos3csk8hf3BUwFOnlprrNzQ5fuaVJoaal"
// Pin definition for CAMERA_MODEL_AI_THINKER
#define PWDN_GPIO_NUM 32
##define define XCLK_GPIO_NUM RESET GPIO_NUM -1
0
#define SIOD GPIO NUM 26
#define SIOC_GPIO_NUM 27
#define Y9 GPIO_NUM 35
#define Y8_GPIO_NUM 34
#define Y7_GPIO_NUM 39
#define Y6 GPIO_NUM 36
#define Y5 GPIO_NUM 21
#define Y4 GPIO_NUM 19
#define Y3 GPIO_NUM 18
#define Y2_GPIO_NUM 5
#define VSYNC_GPIO_NUM 25
#define HREF_GPIO_NUM 23
#define PCLK GPIO_NUM 22
const int Led Flash = 4;
const int trigPin = 12;
const int echoPin = 13;
boolean startTimer = false;
unsigned long time now=0;
int time_capture=0;
long duration;
void int distance;
setup() {
Serial.begin(115200);
while (!Serial) ( ; )
pinMode(trigPin, OUTPUT) ; // Sets the trigPin as an Output
pinMode(echoPin, INPUT);
pinMode(Led Flash, OUTPUT);
WiFi.begin(SSID, PASSWORD);
Serial.printf("WiFi connecting to % s\n", SSID);
while(WiFi.status() != WL_CONNECTED) { Serial.print("."); delay(400); }
Serial.printf("\nWiFi connected\nIP : ");
Serial.println(WiFi.localIP());
LINE.setToken(LINE_TOKEN);
timer timerBegin(0, 80, true); // timer 0, div 80Mhz
timerAttachInterrupt(timer, & resetModule, true);
timerAlarmWrite(timer, 20000000, false); // set time in us 15s
timerAlarmEnable(timer); // enable interrupt
camera_config_t config;
config.ledc_channel = LEDC_CHANNEL_0;
config.ledc_timer = LEDC_TIMER_0;
config.pin_d0 = Y2_GPIO_NUM;
config.pin_d1 = Y3_GPIO_NUM;
config.pin_d2 = Y4_GPIO_NUM;
config.pin_d3 = Y5_GPIO_NUM;
config.pin_d4 = Y6_GPIO_NUM;
config.pin_d5 = Y7 GPIO_NUM;
config.pin_d6 = Y8_GPIO_NUM;
config.pin_d7 = Y9_GPIO_NUM;
config.pin_xclk = XCLK_GPIO_NUM;
config.pin_pclk = PCLK_GPIO_NUM;
config.pin_vsync = VSYNC_GPIO_NUM;
config.pin_href = HREF_GPIO_NUM;
config.pin_sscb_sda = SIOD_GPIO_NUM;
config.pin_ sscb_scl = SIOC_GPIO_NUM;
config.pin_pwdn = PWDN_GPIO_NUM;
config.pin_reset = RESET_GPIO_NUM;
config.xclk_freq_hz = 20000000;
config.pixel_format = PIXFORMAT_JPEG;
if(psramFound()){
// FRAMESIZE +
// QQVGA/160x120 // QQVGA2/128x160 // QCIF/176x144 // HQVGA/240x176
// QVGA/320x240 // CIF/400x296 // VGA/640x480 // SVGA/800x600 // XGA/1024x768
// sXGA/1280x1024 // UXGA/1600x1200 // QXGA/2048*1536
config.frame_size = FRAMESIZE_SXGA;
config.jpeg_quality -[10;
config.fb_count = 2;
} else {
config.frame_size = FRAMESIZE_QQVGA;
config.jpeg_quality = 12;
config.fb_count = 1;
}
// Init Camera
esp_err_t err = esp_camera_init(&config);
if (err = ESP_OK) {
Serial.printf("Camera init failed with error 0xx", err);
return;
}
void loop() {
timerWrite(timer, 0); // reset timer (feed watchdo
long tme millis();
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration pulseIn(echoPin, HIGH);
// Calculating the distance
distance duration 0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
if(distance <= 20){
  Camera_capture();
Serial.println("OR");
startTimer = true;
}
if(millis() > time now + 1000) (
time_now millis();
}
tme millis() - tme;
delay(200);
}
void Camera_capture() {
digitalWrite(Led Flash, HIGH);
delay(100);
digitalWrite(Led Flash, LOW);
delay(100);
digitalWrite(Led Flash, HIGH);
camera_fb_t * fb = NULL;
delay(200);
I/ Take Picture with Camera
fb esp_camera_fb_get();
if(!fb) (
Serial.println("Camera capture failed");
return;
}
digitalWrite(Led Flash, LOW);
Send_line(fp->buf, fb->len);
esp_camera_fb_return(fb);
// Serial.println("Going to sleep now");
// esp_deep_sleep_start();
// Serial.println("This will never be printed");
}
void Send_line(uint8_t *image_data, size_t image_size){
LINE.notifyPicture("DETECT !!", image_data, image_size);
}