#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "sensor.h"
#include "display.h"
#include "led.h"

static const char *TAG = "LAB8";

void app_main(void)
{
    ESP_LOGI(TAG, "🚀 Lab 8: Sensor + Display + LED Demo Started");

    sensor_init();
    display_init();
    led_init();

    int reading_count = 0;

    while (1) {
        reading_count++;
        ESP_LOGI(TAG, "📋 Reading #%d", reading_count);

        sensor_read_data();     
        sensor_check_status();

        int fake_value = rand() % 100;

        if (fake_value > 50) {
            led_on();
            ESP_LOGI(TAG, "💡 LED ON (fake_value > 50)");
        } else {
            led_off();
            ESP_LOGI(TAG, "💡 LED OFF (fake_value <= 50)");
        }

        ESP_LOGI(TAG, "==========================================");

        vTaskDelay(pdMS_TO_TICKS(4000));
    }
}