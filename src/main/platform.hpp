#pragma once

#include "esp_log.h"
#include "wire.hpp"

class Platform {
  public:
    Platform() { }
    inline bool setup(bool sd_card_init) {
      Wire wire;
      printf("[HFramework] Platform setup...\n");
      if (!wire.setup()) return false;
      printf("[HFramework] Platform setup done.\n");
      return true;
    }
};
