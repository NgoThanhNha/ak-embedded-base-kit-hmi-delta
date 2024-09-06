 #include "scr_pump.h"
#include "task_hmi.h"

static void view_scr_pump();

view_dynamic_t dyn_view_pump = {
	{
		.item_type = ITEM_TYPE_DYNAMIC,
	},
	view_scr_pump
};

view_screen_t scr_pump = {
	&dyn_view_pump,
	ITEM_NULL,
	ITEM_NULL,

	.focus_item = 0,
};

void view_scr_pump() {
	/* draw frame */
	view_render.clear();
	view_render.drawRect(0, 0, 128, 64, WHITE);
	view_render.fillRoundRect(0, 0, 42, 14, 1, WHITE);
	view_render.setTextSize(1);
	view_render.setTextColor(BLACK);
	view_render.setCursor(9, 4);
	view_render.print("PUMP");

	/* draw icon */
	view_render.drawBitmap(25, 18, pump_icon_40x37px, 40, 37, 1);

	if (hmi_reg_rev.pump) {
		view_render.fillRect(80, 25, 24, 16, WHITE);
		view_render.setTextSize(1);
		view_render.setTextColor(BLACK);
		view_render.setCursor(86, 29);
		view_render.print("ON");
	}
	else {
		view_render.drawRect(80, 25, 24, 16, WHITE);
		view_render.setTextSize(1);
		view_render.setTextColor(WHITE);
		view_render.setCursor(84, 29);
		view_render.print("OFF");
	}
	view_render.update();
}

void scr_pump_handle(ak_msg_t* msg) {
	switch (msg->sig) {
	case SCREEN_ENTRY: {
		APP_DBG_SIG("SCREEN_PUMP_ENTRY\n");
	}
		break;

	case AC_DISPLAY_BUTON_MODE_PRESSED: {
		APP_DBG_SIG("AC_DISPLAY_BUTON_MODE_PRESSED\n");
		SCREEN_TRAN(scr_light_handle, &scr_light);
	}
		break;

	default:
		break;
	}
}