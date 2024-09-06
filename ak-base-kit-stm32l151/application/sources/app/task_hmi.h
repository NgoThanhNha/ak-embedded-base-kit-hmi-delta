#ifndef __TASK_HMI_H__
#define __TASK_HMI_H__

#include <stdio.h>
#include <stdint.h>
#include "xprintf.h"

#define HMI_LOG

#if defined (HMI_LOG)
#define HMI_LOG(fmt, ...)       xprintf(fmt, ##__VA_ARGS__)
#else
#define HMI_LOG(fmt, ...)
#endif

typedef struct {
    uint16_t light[4];
    uint16_t motor;
    uint16_t pump;
} hmi_reg_t;

extern hmi_reg_t hmi_reg_rev;

#endif /* __TASK_HMI_H__ */