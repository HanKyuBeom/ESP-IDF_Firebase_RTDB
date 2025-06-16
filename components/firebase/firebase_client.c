#include "firebase_client.h"
#include "esp_log.h"
#include "esp_http_client.h"
#include "esp_crt_bundle.h"
#include <string.h>

static const char *TAG = "firebase";
static firebase_config_t firebase_config;
static char http_response[1024];
static int response_len = 0;

static esp_err_t http_event_handler(esp_http_client_event_t *evt)
{
    switch(evt->event_id) {
        case HTTP_EVENT_ON_DATA:
            if (evt->data_len < sizeof(http_response) - response_len) {
                memcpy(http_response + response_len, evt->data, evt->data_len);
                response_len += evt->data_len;
                http_response[response_len] = 0;
            }
            break;
        case HTTP_EVENT_ON_FINISH:
            ESP_LOGI(TAG, "Response: %s", http_response);
            break;
        default:
            break;
    }
    return ESP_OK;
}

esp_err_t firebase_init(const firebase_config_t *config)
{
    firebase_config = *config;
    ESP_LOGI(TAG, "Firebase initialized");
    return ESP_OK;
}

static esp_err_t firebase_request(const char* method, const char* path, const char* data)
{
    char url[512];
    snprintf(url, sizeof(url), "https://%s%s.json?auth=%s", 
             firebase_config.host, path, firebase_config.api_key);
    
    response_len = 0;
    memset(http_response, 0, sizeof(http_response));
    
    esp_http_client_config_t config = {
        .url = url,
        .event_handler = http_event_handler,
        .crt_bundle_attach = esp_crt_bundle_attach,
        .timeout_ms = 5000,
    };
    
    if (strcmp(method, "PUT") == 0) {
        config.method = HTTP_METHOD_PUT;
    } else if (strcmp(method, "DELETE") == 0) {
        config.method = HTTP_METHOD_DELETE;
    } else {
        config.method = HTTP_METHOD_GET;
    }
    
    esp_http_client_handle_t client = esp_http_client_init(&config);
    
    if (data && (strcmp(method, "PUT") == 0)) {
        esp_http_client_set_header(client, "Content-Type", "application/json");
        esp_http_client_set_post_field(client, data, strlen(data));
    }
    
    esp_err_t err = esp_http_client_perform(client);
    int status_code = esp_http_client_get_status_code(client);
    
    esp_http_client_cleanup(client);
    
    return (err == ESP_OK && status_code == 200) ? ESP_OK : ESP_FAIL;
}

esp_err_t firebase_set_data(const char* path, const char* json_data)
{
    return firebase_request("PUT", path, json_data);
}

esp_err_t firebase_get_data(const char* path)
{
    return firebase_request("GET", path, NULL);
}

esp_err_t firebase_delete_data(const char* path)
{
    return firebase_request("DELETE", path, NULL);
} 