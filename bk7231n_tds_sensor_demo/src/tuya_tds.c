/**
 * @File: tuya_tds.c 
 * @Author: hunaling.zhang@tuya.com 
 * @Last Modified time: 2021-03-13 
 * @Description:TDS detection demo 
 */

#include "tuya_dp_process.h"
#include "tuya_tds.h"
#include "tuya_iot_com_api.h"
#include "uni_log.h"

#include "FreeRTOS.h"
#include "task.h"
#include "uni_thread.h"
#include "soc_adc.h"

#define TEMP_ADC_DATA_LEN       (4)

tuya_adc_dev_t tuya_adc;


INT_T adc_value_get(VOID)
{   
    USHORT_T value = 0;
    INT_T ret;

    tuya_adc.priv.pData = Malloc(TEMP_ADC_DATA_LEN * sizeof(USHORT_T));
    memset(tuya_adc.priv.pData, 0, TEMP_ADC_DATA_LEN * sizeof(USHORT_T));
    tuya_adc.priv.data_buff_size = TEMP_ADC_DATA_LEN; //设置数据缓存个数
    tuya_hal_adc_init(&tuya_adc); 
    ret = tuya_hal_adc_value_get(TEMP_ADC_DATA_LEN, &value);
    
    if(-1 == ret) {
        PR_ERR("get adc value failed");
    }
    else {
        PR_NOTICE("vcc_value = %d", value);
    }
    tuya_hal_adc_finalize(&tuya_adc); 
    Free(&tuya_adc);

    return value;
}

VOID tds_sensor_init(VOID)
{

    tuya_hal_thread_create(NULL, "check_water_quality", 512 * 4, TRD_PRIO_2, check_water_quality_task, NULL);
}

VOID check_water_quality_task(VOID)
{   
    while(1) { 

        updata_dp_all();
        tuya_hal_system_sleep(1000);
    }
}



