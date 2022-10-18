#include <nrf_log.h>
#include "displayapp/screens/ImageView.h"
#include "displayapp/DisplayApp.h"

using namespace Pinetime::Applications::Screens;

ImageView::ImageView(DisplayApp* app, const char *path)
    : Screen(app)
{
  label = nullptr;

  lv_obj_t* image = lv_img_create(lv_scr_act(), nullptr);
  lv_img_set_src(image, path);
  lv_obj_align(image, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);

  const char *c = strrchr(path, '/') + 1;
  if (c == nullptr)
    c = path;

  strncpy(name, c, LFS_NAME_MAX-1);
  char *pchar = strchr(name, '_');
  while (pchar != nullptr) {
    *pchar = ' ';
    pchar = strchr(pchar + 1, '_');
  }

  ShowInfo();
}

void ImageView::ShowInfo() {
  if(label != nullptr) {
    return;
  }
  label = lv_btn_create(lv_scr_act(), nullptr);
  label->user_data = this;

  lv_obj_set_height(label, 20);
  lv_obj_set_width(label, LV_HOR_RES);
  lv_obj_align(label, lv_scr_act(), LV_ALIGN_IN_BOTTOM_MID, 0, 0);

  lv_obj_t *txtMessage = lv_label_create(label, nullptr);
  lv_obj_set_style_local_bg_color(label, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_NAVY);
  lv_label_set_text_static(txtMessage, name);
}

void ImageView::HideInfo() {
  lv_obj_del(label);
  label = nullptr;
}

void ImageView::ToggleInfo() {
  if (label == nullptr)
    ShowInfo();
  else
    HideInfo();
}

ImageView::~ImageView() {
  lv_obj_clean(lv_scr_act());
}
