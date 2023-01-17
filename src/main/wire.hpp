#pragma once

#include <cstring>

#include "driver/i2c.h"
#include "esp_log.h"

class Wire {
  private:
    bool initialized;
    static constexpr char const* TAG = "Wire";
    static SemaphoreHandle_t mutex;
    static StaticSemaphore_t mutex_buffer;
  public:
    Wire() : initialized(false) {}
    bool setup() {
      if (initialized) return true;

      ESP_LOGD(TAG, "Initializing...");
      // FIXME(Ryan): Why is a semaphore required?
      mutex = xSemaphoreCreateMutexStatic(&mutex_buffer);

      i2c_config_t config;

      memset(&config, 0, sizeof(i2c_config_t));

      config.mode             = I2C_MODE_MASTER;
      config.scl_io_num       = GPIO_NUM_22;
      config.scl_pullup_en    = GPIO_PULLUP_DISABLE;
      config.sda_io_num       = GPIO_NUM_21;
      config.sda_pullup_en    = GPIO_PULLUP_DISABLE;
      config.master.clk_speed = 1E5;

      ESP_ERROR_CHECK(i2c_param_config(I2C_NUM_0, &config));
      ESP_ERROR_CHECK(i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER, 0, 0, 0));

      initialized = true;
      return true;
    }
};

SemaphoreHandle_t Wire::mutex = nullptr;
StaticSemaphore_t Wire::mutex_buffer;
