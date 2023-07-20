#include "GCU.h"


// Device Parameters
const unsigned char device_number = 0x02;
const unsigned char device_frequency = 50;
// #define sample_delayms 100

// Sensor Numbers
const unsigned char sensors_rows_num = 1;
const unsigned char sensors_columns_num = 1;

// Data Format Function
const bool start_flag = 1;
const bool device_num_flag = 1;
const bool sensors_num_flag = 1;
const bool timestamp_flag = 1;
const bool data_validation_flag = 1;
const bool end_flag = 1;

// WiFi Parameters
// #define SSID "GCU-wifi"
// #define password "12345678"
const char* SSID       = "GCU-wifi";
const char* password   = "12345678";
const char* SeverIP = "192.168.1.101";
const uint16_t port = 1337;
const bool TCP_UDP_Flag = UDP;


// Times Setting
const int UTC = 9;
const char* ntpServer1 = "pool.ntp.org";
const char* ntpServer2 = "time.nist.gov";
const int  gmtOffset_sec = 3600 * UTC;
const int  daylightOffset_sec = 0;


// Define ADIO(sensor_rows) and SelectIO(sensor_columns)
const int analogReadIO[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
const int SelectIO[]={20, 21, 35, 36, 37, 39, 40, 41, 42, 45};


// Data Array Size = (start_flag + sensors_num  + data_validation_flag +end_flag ) * 2 + device_num_flag + sensors_num_flag + timestamp_flag * 6
const unsigned char sensors_num = sensors_rows_num * sensors_columns_num;
const int data_num = (start_flag + sensors_num  + data_validation_flag +end_flag ) * 2 + device_num_flag + sensors_num_flag + timestamp_flag * 6;

bool working_flag = 0;
unsigned char data[data_num];
unsigned char * data_p = data;
uint32_t check_sum = 0;


Ticker data_receiver;
WiFiMulti WiFiMulti;
ESP32Time rtc(0*3600);


void setup() {

  neopixelWrite38(RGB_BRIGHTNESS-50,0,0); // Red
  delay(300);
  neopixelWrite38(0,RGB_BRIGHTNESS-50,0); // Green
  delay(300);
  neopixelWrite38(0,0,RGB_BRIGHTNESS-50); // Blue
  delay(300);
  neopixelWrite38(0,0,0); // Off / black
  delay(300);
  
  
  for(int i=0;i < sizeof(SelectIO)/sizeof(SelectIO[0]);i++){
    pinMode(SelectIO[i],INPUT);
  }

  Serial.begin(115200);
  delay(10);
  Wire.begin(GCU_SDA,GCU_SCL);
  delay(10);

  //set the resolution to 12 bits (0-4096)
  analogReadResolution(12);

  neopixelWrite38(RGB_BRIGHTNESS-50,0,0); // Red
  WiFiMulti.addAP(SSID, password);
  

  Serial.println();
  Serial.println();
  Serial.print("Waiting for WiFi... ");
  while(WiFiMulti.run() != WL_CONNECTED){
    Serial.print(".");
  }
  neopixelWrite38(0,0,0);

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  delay(500);

  neopixelWrite38(0,RGB_BRIGHTNESS-50,RGB_BRIGHTNESS-50);


  if(!init_RTC_from_net()){
    for(int i = 0; i < 3; i++){
      neopixelWrite38(0,RGB_BRIGHTNESS-50,RGB_BRIGHTNESS-50);
      delay(500);
      neopixelWrite38(0,0,0);
      delay(500);
    }
    if(!init_RTC_from_bq32002()){
      RTC_error();
    }
  }

  if(start_flag){
    data[0] = 0x5a;
    data[1] = 0x5a;
    data_p += 2;
  }

  if(device_num_flag){
    data[2] = device_number;
    data_p += 1;
  }

  if(sensors_num_flag){
    data[3] = sensors_num;
    data_p += 1;
  }


  if(end_flag){
    data[data_num - 2] = 0xa5;
    data[data_num - 1] = 0xa5;
  }

  //Enable Timer Interrupt
  neopixelWrite38(RGB_BRIGHTNESS-50,RGB_BRIGHTNESS-50,0);
  data_receiver.attach_ms(1000/device_frequency, data_receive);

}

void loop() {

  Serial.print(".");
  delay(10);

}

