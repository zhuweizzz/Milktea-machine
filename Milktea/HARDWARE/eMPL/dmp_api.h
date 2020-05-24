#ifndef DMP_API_H
#define DMP_API_H

#include "stm32f4xx.h"
#include "systick.h"

void gyro_data_ready_cb(void);

uint8_t mpu6050_init(void);

uint8_t dmp_get_data(void);

#endif
