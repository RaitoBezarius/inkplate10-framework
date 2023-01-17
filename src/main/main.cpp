#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

// hackENS framework includes
#include "platform.hpp"

extern "C" void app_main(void)
{
  Platform platform;
  platform.setup(false);
  vTaskDelay(3000 / portTICK_PERIOD_MS);
  fflush(stdout);
  esp_restart();
}
