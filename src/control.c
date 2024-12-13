#include "control.h"

void receive_control(uint8_t* data, uint16_t len ){

    if(strncmp("Maju",(char *)data,strlen("Maju"))==0){
        ESP_LOGI(CONTROL_TAG,"Maju");\
        gpio_set_level(pinMaju,0);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(pinMaju,1);
    }
    else if (strncmp("Mundur",(char *)data,strlen("Mundur"))==0){ 
        ESP_LOGI(CONTROL_TAG,"Mundur");
        gpio_set_level(pinMundur,0);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(pinMundur,1);
    }
    else if (strncmp("Kiri",(char *)data,strlen("Kiri"))==0){ 
        ESP_LOGI(CONTROL_TAG,"Kiri");
        gpio_set_level(pinKanan,1);
        gpio_set_level(pinKiri,!gpio_get_level(pinKiri));
    }
    else if (strncmp("Kanan",(char *)data,strlen("Kanan"))==0){ 
        ESP_LOGI(CONTROL_TAG,"Kanan");
        gpio_set_level(pinKiri,1);
        gpio_set_level(pinKanan,!gpio_get_level(pinKanan));
    }
    else if (strncmp("Start",(char *)data,strlen("Start"))==0){ 
        ESP_LOGI(CONTROL_TAG,"Start");
        gpio_set_level(pinStart,0);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(pinStart,1);
    }
    else if (strncmp("Stop",(char *)data,strlen("Stop"))==0){ 
        ESP_LOGI(CONTROL_TAG,"Stop");
        gpio_set_level(pinStop,0);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(pinStop,1);
    }
    else
    {
        ESP_LOGI(CONTROL_TAG,"Command Not found");
        ESP_LOGI(CONTROL_TAG,"get string |%s", (char *)data );
    }
    
}