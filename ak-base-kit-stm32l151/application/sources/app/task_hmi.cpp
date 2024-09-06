#include <string.h>

#include "ak.h"
#include "port.h"
#include "message.h"
#include "timer.h"

#include "sys_dbg.h"
#include "sys_ctrl.h"
#include "sys_boot.h"
#include "sys_io.h"

#include "flash.h"
#include "led.h"

#include "app.h"
#include "app_if.h"
#include "app_dbg.h"
#include "app_data.h"
#include "app_flash.h"
#include "app_modbus_pull.h"

#include "task_if.h"
#include "task_list.h"
#include "task_list_if.h"
#include "task_fw.h"
#include "task_life.h"
#include "task_hmi.h"
#include "task_display.h"

hmi_reg_t hmi_reg_rev;
hmi_reg_t hmi_reg_prev;

void task_hmi_handler(ak_msg_t* msg) {
	switch (msg->sig) {
	case AC_HMI_MOBUS_REQ: {
        updateDataModbusDevice(&HMI_Delta);
        for (uint8_t i = 0; i < 4; i++) {
            hmi_reg_rev.light[i] = (HMI_Delta.listRegDevice[i].regValue * HMI_Delta.listRegDevice[i].ratio);
        }
        hmi_reg_rev.motor = (HMI_Delta.listRegDevice[4].regValue * HMI_Delta.listRegDevice[4].ratio);
        hmi_reg_rev.pump = (HMI_Delta.listRegDevice[5].regValue * HMI_Delta.listRegDevice[5].ratio);
        HMI_LOG("--- HMI register value ---\n");
        for (uint8_t i = 0; i < 4; i++) {
            HMI_LOG("light[%d]: %d\n", i, hmi_reg_rev.light[i]);
        }
        HMI_LOG("motor: %d\n", hmi_reg_rev.motor);
        HMI_LOG("pump: %d\n", hmi_reg_rev.pump);
        memcpy((hmi_reg_t*)&hmi_reg_prev, (hmi_reg_t*)&hmi_reg_rev, sizeof(hmi_reg_t));

        /* screen update */
        task_post_pure_msg(AC_TASK_DISPLAY_ID, AC_HMI_SCREEN_UPDATE);
	}
		break;

	default:
		break;
	}
}

