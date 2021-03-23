/**
 * @File: tuya_tds.h 
 * @Author: huanling.zhang@tuya.com 
 * @Last Modified time: 2021-03-13 
 * @Description:TDS detection demo 
 */
#ifndef __TUYA_TDS_H__
#define __TUYA_TDS_H__

#include "tuya_cloud_types.h"
#include "tuya_gpio.h"

VOID tds_sensor_init(VOID);
INT_T adc_value_get(VOID);
VOID check_water_quality_task(VOID);

#endif
