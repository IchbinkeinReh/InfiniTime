#include <nrf_log.h>
#include "displayapp/screens/Birthday.h"
#include "displayapp/DisplayApp.h"

using namespace Pinetime::Applications::Screens;

Birthday::Birthday(DisplayApp* app) : app {app} {
  label1 = lv_label_create(lv_scr_act(), nullptr);
  lv_label_set_recolor(label1, true);
  lv_obj_align(label1, lv_scr_act(), LV_ALIGN_IN_LEFT_MID, 0, 0);

  label2 = lv_label_create(lv_scr_act(), nullptr);
  lv_label_set_recolor(label2, true);
  lv_obj_align(label2, lv_scr_act(), LV_ALIGN_IN_LEFT_MID, 0, 0);

  label3 = lv_label_create(lv_scr_act(), nullptr);
  lv_label_set_recolor(label3, true);
  lv_obj_align(label3, lv_scr_act(), LV_ALIGN_IN_LEFT_MID, 0, 0);

  time = 0;
  buf1 = (char*) lv_mem_alloc(30);
  buf2 = (char*) lv_mem_alloc(30);
  buf3 = (char*) lv_mem_alloc(30);
  //TODO:
  //https://www.w3schools.com/cpp/cpp_strings_concat.asp
  //https://stackoverflow.com/questions/1211705/paint-me-a-rainbow
  //https://stackoverflow.com/questions/20034297/decimal-to-hex-conversion-c-built-in-function
  //https://www.google.com/search?q=itoa&rlz=1C1ONGR_deDE977DE978&oq=itoa&aqs=chrome..69i57j0i512j0i67j0i512l7.599j0j7&sourceid=chrome&ie=UTF-8

  taskRefresh = lv_task_create(RefreshTaskCallback, 100, LV_TASK_PRIO_MID, this);
}

Birthday::~Birthday() {
  if (buf1 != nullptr)
    lv_mem_free(buf1);
  if (buf2 != nullptr)
    lv_mem_free(buf2);
  if (buf3 != nullptr)
    lv_mem_free(buf3);
  lv_obj_clean(lv_scr_act());
}

void Birthday::Refresh() {
  time = time + 1;

  /*buf1[0] = '#';
  for (unsigned i = 0; i < 3; ++i) {
    const float h = hue + i / 3.f;
    rgb[i] = std::clamp(6.f * std::fabs(h - std::floor(h) - 0.5f) - 1.f, 0.f, 1.f);
  }

  char hexString[20];
  itoa(value, buf1, 16);

  lv_label_set_text_fmt(label_love, "A + P = #ffa500 \xEF\x80\x84#");*/
}

/*std::array<float, 3> HueToRGB(float hue) {
  std::array<float, 3> rgb;
  for (unsigned i = 0; i < 3; ++i) {
    const float h = hue + i / 3.f;
    rgb[i] = std::clamp(6.f * std::fabs(h - std::floor(h) - 0.5f) - 1.f, 0.f, 1.f);
  }
  return rgb;
}*/