#include "scr_light.h"
#include "task_hmi.h"

static void view_scr_light();

view_dynamic_t dyn_view_light = {
	{
		.item_type = ITEM_TYPE_DYNAMIC,
	},
	view_scr_light
};

view_screen_t scr_light = {
	&dyn_view_light,
	ITEM_NULL,
	ITEM_NULL,

	.focus_item = 0,
};

void view_scr_light() {
	view_render.clear();
	view_render.drawRect(0, 0, 128, 64, WHITE);
	view_render.fillRoundRect(0, 0, 42, 14, 1, WHITE);

	view_render.setTextSize(1);
	view_render.setTextColor(BLACK);
	view_render.setCursor(6, 4);
	view_render.print("LIGHT");
    view_render.setTextColor(WHITE);
    view_render.setCursor(11, 25);
    view_render.print("L1");
    view_render.setCursor(43, 25);
    view_render.print("L2");
    view_render.setCursor(74, 25);
    view_render.print("L3");
    view_render.setCursor(105, 25);
    view_render.print("L4");

	view_render.drawRect(4  , 36, 24, 16, WHITE);
	view_render.drawRect(36 , 36, 24, 16, WHITE);
	view_render.drawRect(68 , 36, 24, 16, WHITE);
	view_render.drawRect(100, 36, 24, 16, WHITE);

	for (uint16_t i = 0; i < 4; i++) {
		if ((hmi_reg_rev.light[i])) {
            /* fill light status */
            view_render.fillRect((4 + (i * 32)), 36, 24, 16, WHITE);

            view_render.setTextSize(1);
            view_render.setTextColor(BLACK);
			view_render.setCursor(10 + 32 * i, 40);
			view_render.print("ON");
		}
		else {
            view_render.setTextSize(1);
            view_render.setTextColor(WHITE);
			view_render.setCursor(8 + 32 * i, 40);
			view_render.print("OFF");
		}
	}
	view_render.update();
}

void scr_light_handle(ak_msg_t* msg) {
	switch (msg->sig) {
	case SCREEN_ENTRY: {
		APP_DBG_SIG("SCREEN_LIGHT_ENTRY\n");
	}
		break;

	case AC_DISPLAY_BUTON_MODE_PRESSED: {
		APP_DBG_SIG("AC_DISPLAY_BUTON_MODE_PRESSED\n");
		SCREEN_TRAN(scr_motor_handle, &scr_motor);
	}
		break;

	default:
		break;
	}
}