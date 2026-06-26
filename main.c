
/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
#define _DEFAULT_SOURCE /* needed for usleep() */
#include <stdlib.h>
#include <unistd.h>
#include "lvgl/lvgl.h"
#include "ui/ui.h" 
#include "stdio.h" 
#include  "string.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void hal_init(void); 


/**********************
 *  STATIC VARIABLES
 **********************/ 
uint16_t value = 0; 
static bool speed_flage=true;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/ 
void speed_update(uint16_t value);

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *      VARIABLES
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/   


 static void hr_timer(lv_timer_t * timer)  
{   
   
   speed_update(value);

    // value++;

    // if(value >= 92)
    // {
        
    // }  
    if(speed_flage==true) 
    {  
          value++; 
            if(value>93) 
            { 
                speed_flage=false;
            }
        
    } 
    else 
    { 

        value--;

        if(value == 0)
        {
            speed_flage = true;
        }
    }
   
}  
void speed_update(uint16_t value)
{
    lv_arc_set_value(ui_Arc2, value);

    int32_t angle;

    angle = value * 27;

    lv_image_set_rotation(ui_Image3, angle);  
    char buf[20];  
    sprintf(buf,"%d KM/H",value);
    lv_label_set_text(ui_Label10,buf);
} 



int main(int argc, char **argv) {
    (void)argc; /*Unused*/
    (void)argv; /*Unused*/

    /*Initialize LVGL*/
    lv_init();

    /*Initialize the HAL (display, input devices, tick) for LVGL*/
    hal_init();

    ui_init();  
    //  speed_update(value);
   
  lv_timer_create(hr_timer,100,NULL); 
    while(1) 
    {
        /* Periodically call the lv_task handler.
        * It could be done in a timer interrupt or an OS task too.*/ 
   

    // lv_timer_handler();
    // usleep(50 * 1000);
        lv_timer_handler();
        usleep(5 * 1000);
    }

    lv_deinit();
    return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the LVGL graphics
 * library
 */
static void hal_init(void) {

    /*Create a display*/
    static lv_display_t *disp;
    disp = lv_sdl_window_create( 480, 480 );

    /*Add the mouse as input device*/
    static lv_indev_t *mouse;
    mouse = lv_sdl_mouse_create();

    /*Add the keyboard as an input device*/
    static lv_indev_t *keyboard;
    keyboard = lv_sdl_keyboard_create();

    lv_theme_t * th = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), LV_THEME_DEFAULT_DARK, LV_FONT_DEFAULT);
    lv_disp_set_theme(disp, th);
}
