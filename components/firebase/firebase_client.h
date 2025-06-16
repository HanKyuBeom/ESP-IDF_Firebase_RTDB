#pragma once

#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Firebase configuration structure
 */
typedef struct {
    const char* host;       ///< Firebase host URL
    const char* api_key;    ///< Firebase API key
} firebase_config_t;

/**
 * @brief Initialize Firebase client
 * 
 * @param config Firebase configuration
 * @return esp_err_t ESP_OK on success
 */
esp_err_t firebase_init(const firebase_config_t *config);

/**
 * @brief Set data to Firebase Realtime Database
 * 
 * @param path Database path
 * @param json_data JSON data to set
 * @return esp_err_t ESP_OK on success
 */
esp_err_t firebase_set_data(const char* path, const char* json_data);

/**
 * @brief Get data from Firebase Realtime Database
 * 
 * @param path Database path
 * @return esp_err_t ESP_OK on success
 */
esp_err_t firebase_get_data(const char* path);

/**
 * @brief Delete data from Firebase Realtime Database
 * 
 * @param path Database path
 * @return esp_err_t ESP_OK on success
 */
esp_err_t firebase_delete_data(const char* path);

#ifdef __cplusplus
}
#endif 