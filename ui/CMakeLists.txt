SET(SOURCES components/ui_comp_panel1.c
    components/ui_comp.c
    screens/ui_Screen2.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    images/ui_img_116455110.c
    images/ui_img_rectangle_3_png.c
    fonts/ui_font_speed14.c
    fonts/ui_font_speed15.c)

add_library(ui ${SOURCES})
