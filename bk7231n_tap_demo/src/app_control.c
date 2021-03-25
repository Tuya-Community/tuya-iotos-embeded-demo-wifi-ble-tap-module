/*
 * @Author: zgw
 * @email: liang.zhang@tuya.com
 * @LastEditors: zgw
 * @file name: sht21.h
 * @Description: SHT21 IIC drive src file
 * @Copyright: HANGZHOU TUYA INFORMATION TECHNOLOGY CO.,LTD
 * @Company: http://www.tuya.com
 * @Date: 2020-12-16 18:51:29
 * @LastEditTime: 2021-03-23 14:55:30
 */

#include "app_control.h"
#include "tuya_gpio.h"
#include "tuya_uart.h"
#include "BkDriverUart.h"
#include "sys_timer.h"
#include "uni_time.h"
/***********************************************************
*************************types define***********************
***********************************************************/
typedef enum
{
    LOW = 0,
    HIGH,
}default_level;

APP_CTRL_DATA_T app_ctrl_data = {0};

/***********************************************************
*************************IO control device define***********
***********************************************************/
#define SWITCH_IO                           (6)
/***********************************************************
*************************about adc init*********************
***********************************************************/

/***********************************************************
*************************about iic init*********************
***********************************************************/

/***********************************************************
*************************function***************************
***********************************************************/

STATIC VOID __ctrl_gpio_init(CONST TY_GPIO_PORT_E port, CONST BOOL_T high)
{   
    //Set IO port as output mode
    tuya_gpio_inout_set(port, FALSE);
    //Set IO port level
    tuya_gpio_write(port, high);
}


VOID app_device_init(VOID)
{
    tuya_gpio_inout_set(SWITCH_IO, TRUE);
}



VOID app_ctrl_handle(VOID)
{   
    app_ctrl_data.sensor_state = tuya_gpio_read(SWITCH_IO);
    if(!app_ctrl_data.sensor_state) {
        app_report_all_dp_status();
        PR_NOTICE("--------------io = %d------------",app_ctrl_data.sensor_state);
    }
}

VOID app_ctrl_all_off(VOID)
{   

}

 