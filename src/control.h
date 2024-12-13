#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "string.h"

#define pinMaju 16   //RX2
#define pinMundur 17 //TX2
#define pinKiri 5    //D5
#define pinKanan 18  //D18
#define pinStart 19  //D19
#define pinStop 21   //D21


#define CONTROL_TAG "Control"

void receive_control(uint8_t* data , uint16_t len);