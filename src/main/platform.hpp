#pragma once

#include "esp_log.h"

class Platform {
  public:
    Platform() { }
    inline bool setup(bool sd_card_init) {
      printf("[HFramework] Platform setup...\n");
      printf("[HFramework] Platform setup done.\n");
      return true;
    }
};
