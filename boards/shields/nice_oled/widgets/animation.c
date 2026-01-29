#include "animation.h"
#if !IS_ENABLED(CONFIG_NICE_OLED_WIDGET_ANIMATION_PERIPHERAL_SMART_BATTERY)
#include <stdlib.h>
#include <zephyr/kernel.h>

#if IS_ENABLED(CONFIG_NICE_OLED_WIDGET_ANIMATION_PERIPHERAL)
#if IS_ENABLED(CONFIG_NICE_OLED_WIDGET_ANIMATION_PERIPHERAL_HEAD)

LV_IMG_DECLARE(wario_00);
LV_IMG_DECLARE(wario_01);
LV_IMG_DECLARE(wario_02);
LV_IMG_DECLARE(wario_03);
LV_IMG_DECLARE(wario_04);
LV_IMG_DECLARE(wario_05);
/* LV_IMG_DECLARE(wario_06); */
/* LV_IMG_DECLARE(wario_07); */
/* LV_IMG_DECLARE(wario_08); */
/* LV_IMG_DECLARE(wario_09); */
/* LV_IMG_DECLARE(wario_10); */
/* LV_IMG_DECLARE(wario_11); */

const lv_img_dsc_t * const wario_imgs[] = {
    &wario_00, &wario_01, &wario_02, &wario_03, &wario_04, &wario_05,
    /* &wario_06, &wario_07, &wario_08, &wario_09, &wario_10, &wario_11, */
};

#elif IS_ENABLED(CONFIG_NICE_OLED_WIDGET_ANIMATION_PERIPHERAL_CAT)
LV_IMG_DECLARE(cat_0);
LV_IMG_DECLARE(cat_1);
LV_IMG_DECLARE(cat_2);
LV_IMG_DECLARE(cat_3);
LV_IMG_DECLARE(cat_4);
LV_IMG_DECLARE(cat_5);
LV_IMG_DECLARE(cat_6);
LV_IMG_DECLARE(cat_7);

const lv_img_dsc_t *cat_imgs[] = {&cat_0, &cat_1, &cat_2, &cat_3, &cat_4, &cat_5, &cat_6, &cat_7};

#endif
#else // IS_ENABLED(CONFIG_NICE_OLED_WIDGET_ANIMATION_PERIPHERAL)
      // IS_ENABLED(CONFIG_NICE_OLED_WIDGET_STATIC_IMAGE_PERIPHERAL)

#if IS_ENABLED(CONFIG_NICE_OLED_WIDGET_STATIC_IMAGE_PERIPHERAL_VIM)
LV_IMG_DECLARE(vim);
#define FIXED_IMAGE_VIM &vim

#elif IS_ENABLED(CONFIG_NICE_OLED_WIDGET_STATIC_IMAGE_PERIPHERAL_VIP_MARCOS)
LV_IMG_DECLARE(vip_marcos);
#define FIXED_IMAGE_VIP_MARCOS &vip_marcos

#else

LV_IMG_DECLARE(vim);
#define FIXED_IMAGE_1 &vim

#endif

#endif // IS_ENABLED(CONFIG_NICE_OLED_WIDGET_ANIMATION_PERIPHERAL)
       // IS_ENABLED(CONFIG_NICE_OLED_WIDGET_STATIC_IMAGE_PERIPHERAL)

void draw_animation(lv_obj_t *canvas, struct zmk_widget_screen *widget) {

    lv_obj_t *art = lv_animimg_create(canvas);
    /* lv_obj_set_size(art, 69, 32); */
    lv_obj_set_size(art, 48, 32);

#if IS_ENABLED(CONFIG_NICE_OLED_WIDGET_ANIMATION_PERIPHERAL)
    lv_obj_center(art);

#if IS_ENABLED(CONFIG_NICE_OLED_WIDGET_ANIMATION_PERIPHERAL_HEAD)
    lv_animimg_set_src(art, (const void **)wario_imgs, 6);
#elif IS_ENABLED(CONFIG_NICE_OLED_WIDGET_ANIMATION_PERIPHERAL_CAT)
    lv_animimg_set_src(art, (const void **)cat_imgs, 8);
#elif IS_ENABLED(CONFIG_NICE_OLED_WIDGET_ANIMATION_PERIPHERAL_SPACEMAN)
    lv_animimg_set_src(art, (const void **)spaceman_imgs, 20);
#elif IS_ENABLED(CONFIG_NICE_OLED_WIDGET_ANIMATION_PERIPHERAL_POKEMON)
    lv_animimg_set_src(art, (const void **)pokemon_imgs, 48);
#else
    lv_animimg_set_src(art, (const void **)crystal_imgs, 16);
#endif
    lv_animimg_set_duration(art, CONFIG_NICE_OLED_WIDGET_ANIMATION_PERIPHERAL_MS);
    lv_animimg_set_repeat_count(art, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(art);

#else // IS_ENABLED(CONFIG_NICE_OLED_WIDGET_ANIMATION_PERIPHERAL)
      // IS_ENABLED(CONFIG_NICE_OLED_WIDGET_STATIC_IMAGE_PERIPHERAL)

    /* #if IS_ENABLED(CONFIG_NICE_OLED_WIDGET_STATIC_IMAGE_PERIPHERAL_VIM) */
    /*     lv_img_set_src(art, FIXED_IMAGE_VIM); */
    /* #elif IS_ENABLED(CONFIG_NICE_OLED_WIDGET_STATIC_IMAGE_PERIPHERAL_VIP_MARCOS) */
    /*     lv_img_set_src(art, FIXED_IMAGE_VIP_MARCOS); */
    /* #else */
    /*     int length = sizeof(crystal_imgs) / sizeof(crystal_imgs[0]); */
    /*     srand(k_uptime_get_32()); */
    /*     int random_index = rand() % length; */

    /*     lv_img_set_src(art, crystal_imgs[random_index]); */
    /* #endif */

#endif // IS_ENABLED(CONFIG_NICE_OLED_WIDGET_ANIMATION_PERIPHERAL)
    // IS_ENABLED(CONFIG_NICE_OLED_WIDGET_STATIC_IMAGE_PERIPHERAL)

    lv_obj_align(art,
                 LV_ALIGN_TOP_LEFT,
                 CONFIG_NICE_OLED_WIDGET_ANIMATION_PERIPHERAL_CUSTOM_X,
                 CONFIG_NICE_OLED_WIDGET_ANIMATION_PERIPHERAL_CUSTOM_Y);
}
#endif
