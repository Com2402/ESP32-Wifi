// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.4
// Project name: QR_code_2_8

#include "../ui.h"

void ui_DynamicQR_screen_init(void)
{
    ui_DynamicQR = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_DynamicQR, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DynamicQR, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DynamicQR, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DynamicQR, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LogoVietQR = lv_img_create(ui_DynamicQR);
    lv_img_set_src(ui_LogoVietQR, &ui_img_vietqr_h35_png);
    lv_obj_set_width(ui_LogoVietQR, LV_SIZE_CONTENT);   /// 230
    lv_obj_set_height(ui_LogoVietQR, LV_SIZE_CONTENT);    /// 74
    lv_obj_set_x(ui_LogoVietQR, 20);
    lv_obj_set_y(ui_LogoVietQR, 1);
    lv_obj_add_flag(ui_LogoVietQR, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_LogoVietQR, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_LogoVietQR, 240);

    ui_LogoBankUser1 = lv_img_create(ui_DynamicQR);
    lv_img_set_src(ui_LogoBankUser1, &ui_img_logo_mb_he_mau_resize_png);
    lv_obj_set_width(ui_LogoBankUser1, LV_SIZE_CONTENT);   /// 100
    lv_obj_set_height(ui_LogoBankUser1, LV_SIZE_CONTENT);    /// 45
    lv_obj_set_x(ui_LogoBankUser1, -27);
    lv_obj_set_y(ui_LogoBankUser1, -140);
    lv_obj_set_align(ui_LogoBankUser1, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_LogoBankUser1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_LogoBankUser1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ContainerQRD = lv_obj_create(ui_DynamicQR);
    lv_obj_remove_style_all(ui_ContainerQRD);
    lv_obj_set_width(ui_ContainerQRD, 190);
    lv_obj_set_height(ui_ContainerQRD, 190);
    lv_obj_set_x(ui_ContainerQRD, 0);
    lv_obj_set_y(ui_ContainerQRD, -30);
    lv_obj_set_align(ui_ContainerQRD, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ContainerQRD, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ContainerQRD, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ContainerQRD, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ContainerQRD, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ContainerQRD, lv_color_hex(0x2303FA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ContainerQRD, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ContainerQRD, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ContainerQRD, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ContainerQRD, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ContainerQRD, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ContainerQRD, 3, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ContainerLogoBank = lv_obj_create(ui_DynamicQR);
    lv_obj_remove_style_all(ui_ContainerLogoBank);
    lv_obj_set_width(ui_ContainerLogoBank, 240);
    lv_obj_set_height(ui_ContainerLogoBank, 42);
    lv_obj_set_x(ui_ContainerLogoBank, 0);
    lv_obj_set_y(ui_ContainerLogoBank, 82);
    lv_obj_set_align(ui_ContainerLogoBank, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ContainerLogoBank, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Napas247 = lv_img_create(ui_ContainerLogoBank);
    lv_img_set_src(ui_Napas247, &ui_img_napas247_png);
    lv_obj_set_width(ui_Napas247, LV_SIZE_CONTENT);   /// 121
    lv_obj_set_height(ui_Napas247, LV_SIZE_CONTENT);    /// 45
    lv_obj_set_x(ui_Napas247, 0);
    lv_obj_set_y(ui_Napas247, -5);
    lv_obj_set_align(ui_Napas247, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Napas247, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Napas247, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Footer2 = lv_obj_create(ui_DynamicQR);
    lv_obj_remove_style_all(ui_Footer2);
    lv_obj_set_width(ui_Footer2, 240);
    lv_obj_set_height(ui_Footer2, 63);
    lv_obj_set_align(ui_Footer2, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(ui_Footer2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ChuTaiKhoanDynamicQR = lv_label_create(ui_Footer2);
    lv_obj_set_width(ui_ChuTaiKhoanDynamicQR, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChuTaiKhoanDynamicQR, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ChuTaiKhoanDynamicQR, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_ChuTaiKhoanDynamicQR, "PHAM DUC TUAN");
    lv_obj_set_style_text_color(ui_ChuTaiKhoanDynamicQR, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChuTaiKhoanDynamicQR, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui_ChuTaiKhoanDynamicQR, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_ChuTaiKhoanDynamicQR, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ChuTaiKhoanDynamicQR, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChuTaiKhoanDynamicQR, &ui_font_Bold_Font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SoTaiKhoanDynamicQR = lv_label_create(ui_Footer2);
    lv_obj_set_width(ui_SoTaiKhoanDynamicQR, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SoTaiKhoanDynamicQR, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SoTaiKhoanDynamicQR, 0);
    lv_obj_set_y(ui_SoTaiKhoanDynamicQR, -5);
    lv_obj_set_align(ui_SoTaiKhoanDynamicQR, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SoTaiKhoanDynamicQR, "9000006789");
    lv_obj_set_style_text_color(ui_SoTaiKhoanDynamicQR, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SoTaiKhoanDynamicQR, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui_SoTaiKhoanDynamicQR, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_SoTaiKhoanDynamicQR, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SoTaiKhoanDynamicQR, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SoTaiKhoanDynamicQR, &ui_font_arial16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ContainerPayMent = lv_obj_create(ui_Footer2);
    lv_obj_remove_style_all(ui_ContainerPayMent);
    lv_obj_set_width(ui_ContainerPayMent, 240);
    lv_obj_set_height(ui_ContainerPayMent, 26);
    lv_obj_set_align(ui_ContainerPayMent, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(ui_ContainerPayMent, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ContainerPayMent, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ContainerPayMent, lv_color_hex(0xE6B400), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ContainerPayMent, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ContainerPayMent, lv_color_hex(0x433030), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ContainerPayMent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ContainerPayMent, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AmountTitle = lv_label_create(ui_ContainerPayMent);
    lv_obj_set_width(ui_AmountTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_AmountTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_AmountTitle, 8);
    lv_obj_set_y(ui_AmountTitle, 0);
    lv_obj_set_align(ui_AmountTitle, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_AmountTitle, "Số tiền:");
    lv_obj_set_style_text_font(ui_AmountTitle, &ui_font_arialbold14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AmountValue = lv_label_create(ui_ContainerPayMent);
    lv_obj_set_width(ui_AmountValue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_AmountValue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_AmountValue, -10);
    lv_obj_set_y(ui_AmountValue, 0);
    lv_obj_set_align(ui_AmountValue, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_AmountValue, "790.000.000 VND");
    lv_obj_set_style_text_color(ui_AmountValue, lv_color_hex(0xD729B2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AmountValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AmountValue, &ui_font_ariallbi20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageVietQR1 = lv_img_create(ui_DynamicQR);
    lv_img_set_src(ui_ImageVietQR1, &ui_img_481985369);
    lv_obj_set_width(ui_ImageVietQR1, LV_SIZE_CONTENT);   /// 25
    lv_obj_set_height(ui_ImageVietQR1, LV_SIZE_CONTENT);    /// 25
    lv_obj_set_x(ui_ImageVietQR1, 0);
    lv_obj_set_y(ui_ImageVietQR1, -30);
    lv_obj_set_align(ui_ImageVietQR1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageVietQR1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageVietQR1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ImageVietQR1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ImageVietQR1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_DynamicQR, ui_event_DynamicQR, LV_EVENT_ALL, NULL);

}
