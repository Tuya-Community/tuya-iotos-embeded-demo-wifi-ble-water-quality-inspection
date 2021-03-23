/**
 * @File: tuya_dp_process.h 
 * @Author: huanling.zhang@tuya.com 
 * @Last Modified time: 2021-03-13 
 * @Description: TDS detection demo 
 */

#ifndef __TUYA_DP_PROCESS_H_
#define __TUYA_DP_PROCESS_H_

#include "tuya_cloud_com_defs.h"
#include "tuya_cloud_types.h"

#define        GOOD        0
#define        COMMON      1
#define        POOR        2


//typedef enum {
//    good = 0,
//    common,
//    poor
//}WATER_STA_E;


//设备状态结构体
typedef struct {
    UCHAR_T water_quality;
}tds_detection_S;

extern tds_detection_S  tds_sensor_status;

VOID updata_dp_all(VOID);
VOID dp_process(IN CONST TY_OBJ_DP_S *root);


#endif




