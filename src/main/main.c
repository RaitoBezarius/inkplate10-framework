#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

void app_main(void)
{
  printf("This is a test\n");
  vTaskDelay(3000 / portTICK_PERIOD_MS);
  fflush(stdout);
  esp_restart();
}
