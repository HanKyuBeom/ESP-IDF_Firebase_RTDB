/*
 * Firebase Realtime Database CRUD Example (Lightweight)
 */

#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "wifi_manager.h"
#include "firebase_client.h"

static const char *TAG = "firebase_crud";

void app_main(void)
{
    // NVS 초기화
    ESP_ERROR_CHECK(nvs_flash_init());
    
    // WiFi 연결
    wifi_config_sta_t wifi_config = {
        .ssid = "your_wifi_ssid",
        .password = "your_wifi_password"
    };
    ESP_ERROR_CHECK(wifi_init_sta(&wifi_config));
    ESP_ERROR_CHECK(wifi_wait_connection(30000));
    
    // Firebase 초기화
    firebase_config_t firebase_config = {
        .host = "your-project.firebasedatabase.app",
        .api_key = "your_api_key"
    };
    ESP_ERROR_CHECK(firebase_init(&firebase_config));
    
    // CRUD 테스트
    ESP_LOGI(TAG, "=== CREATE ===");
    firebase_set_data("/test/temp", "25");
    
    ESP_LOGI(TAG, "=== READ ===");
    firebase_get_data("/test/temp");
    
    ESP_LOGI(TAG, "=== UPDATE ===");
    firebase_set_data("/test/temp", "30");
    
    ESP_LOGI(TAG, "=== DELETE ===");
    firebase_delete_data("/test/temp");
    
    ESP_LOGI(TAG, "CRUD test complete");
} 