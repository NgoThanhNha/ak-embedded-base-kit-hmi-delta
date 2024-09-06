 #include "scr_motor.h"
#include "task_hmi.h"

static void view_scr_motor();

view_dynamic_t dyn_view_motor = {
	{
		.item_type = ITEM_TYPE_DYNAMIC,
	},
	view_scr_motor
};

view_screen_t scr_motor = {
	&dyn_view_motor,
	ITEM_NULL,
	ITEM_NULL,

	.focus_item = 0,
};

void view_scr_motor() {
	/* draw frame */
	view_render.clear();
	view_render.drawRect(0, 0, 128, 64, WHITE);
	view_render.fillRoundRect(0, 0, 42, 14, 1, WHITE);
	view_render.setTextSize(1);
	view_render.setTextColor(BLACK);
	view_render.setCursor(5, 4);
	view_render.print("MOTOR");

	/* draw icon */
	view_render.drawBitmap(20, 20, motor_icon_50x35px, 50, 35, 1);

	if (hmi_reg_rev.motor) {
		view_render.fillRect(85, 30, 24, 16, WHITE);
		view_render.setTextSize(1);
		view_render.setTextColor(BLACK);
		view_render.setCursor(91, 34);
		view_render.print("ON");
	}
	else {
		view_render.drawRect(85, 30, 24, 16, WHITE);
		view_render.setTextSize(1);
		view_render.setTextColor(WHITE);
		view_render.setCursor(89, 34);
		view_render.print("OFF");
	}
	view_render.update();
}

void scr_motor_handle(ak_msg_t* msg) {
	switch (msg->sig) {
	case SCREEN_ENTRY: {
		APP_DBG_SIG("SCREEN_MOTOR_ENTRY\n");
	}
		break;

	case AC_DISPLAY_BUTON_MODE_PRESSED: {
		APP_DBG_SIG("AC_DISPLAY_BUTON_MODE_PRESSED\n");
		SCREEN_TRAN(scr_pump_handle, &scr_pump);
	}
		break;

	default:
		break;
	}
}