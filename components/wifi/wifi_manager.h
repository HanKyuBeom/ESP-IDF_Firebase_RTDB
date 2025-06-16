#pragma once

#include "esp_err.h"
#include "esp_wifi.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief WiFi configuration structure
 */
typedef struct {
    const char* ssid;        ///< WiFi SSID
    const char* password;    ///< WiFi password
} wifi_config_sta_t;

/**
 * @brief Initialize WiFi in station mode
 * 
 * @param config WiFi station configuration
 * @return esp_err_t ESP_OK on success
 */
esp_err_t wifi_init_sta(const wifi_config_sta_t *config);

/**
 * @brief Check if WiFi is connected
 * 
 * @return true if connected, false otherwise
 */
bool wifi_is_connected(void);

/**
 * @brief Wait for WiFi connection
 * 
 * @param timeout_ms Timeout in milliseconds
 * @return esp_err_t ESP_OK on success
 */
esp_err_t wifi_wait_connection(uint32_t timeout_ms);

#ifdef __cplusplus
}
#endif 