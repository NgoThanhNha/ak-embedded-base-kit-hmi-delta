#ifndef __SCREEN_LIGHT_H__
#define __SCREEN_LIGHT_H__

#include "fsm.h"
#include "port.h"
#include "message.h"
#include "timer.h"

#include "sys_ctrl.h"
#include "sys_dbg.h"

#include "app.h"
#include "app_dbg.h"
#include "task_list.h"
#include "task_display.h"
#include "view_render.h"

#include "buzzer.h"

#include <math.h>
#include <vector>

extern view_dynamic_t dyn_view_light;
extern view_screen_t scr_light;
extern void scr_light_handle(ak_msg_t* msg);

#endif /* __SCREEN_LIGHT_H__*/