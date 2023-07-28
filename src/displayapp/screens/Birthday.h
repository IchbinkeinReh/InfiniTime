#pragma once

#include "displayapp/screens/Screen.h"
#include "displayapp/screens/FileView.h"
#include "displayapp/DisplayApp.h"
#include <lvgl/lvgl.h>

namespace Pinetime {
  namespace Applications {
    namespace Screens {
      class Birthday : public Screen {
      public:
        Birthday(DisplayApp* app);
        ~Birthday() override;
        void Refresh() override;

      private:
        DisplayApp* app;
        lv_task_t* taskRefresh;
        lv_obj_t* label1;
        lv_obj_t* label2;
        lv_obj_t* label3;
        int32_t time;
        char *buf1;
        char *buf2;
        char *buf3;
      };
    }
  }
}
