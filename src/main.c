/*
 * SPDX-FileCopyrightText: 2021-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Unlicense OR CC0-1.0
 */

#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <inttypes.h>
#include "nvs.h"
#include "nvs_flash.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "spp_config.h"
#include "control.h"


void app_main(void)
{
    
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    if((ret = esp_bluetooth_stack_init()) != ESP_OK){
        ESP_LOGE("Bluetooth INIT", "%s Bluetooth stacks INIT failed : %s Please restart !", __func__, esp_err_to_name(ret));
        return;
    }

    gpio_config_t output_relay= {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_INPUT_OUTPUT,
        .pin_bit_mask = (uint64_t)( 0 | (1<<pinMaju) | (1<<pinMundur) | (1<<pinKiri) | (1<<pinKanan) | (1<<pinStart) | (1<<pinStop)),
    };

    if((ret = gpio_config(&output_relay)) != ESP_OK){
        ESP_LOGE("GPIO Init", "%s GPIO INIT failed : %s Please restart !", __func__, esp_err_to_name(ret));
        return;
    }
    gpio_set_level(pinMaju,1); 
    gpio_set_level(pinMundur,1);
    gpio_set_level(pinKiri,1);
    gpio_set_level(pinKanan,1);
    gpio_set_level(pinStart,1);
    gpio_set_level(pinStop,1);

}