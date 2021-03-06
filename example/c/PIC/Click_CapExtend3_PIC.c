/*
Example for CapExtend3 Click

    Date          : Jan 2018.
    Author        : MikroE Team

Test configuration PIC :
    
    MCU             : P18F87K22
    Dev. Board      : EasyPIC PRO v7
    PIC Compiler ver : v7.1.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initialize AN, RST, CS, PWM, INT pin as INPUT
- Application Initialization -  Initialize GPIO Driver
- Application Task - (code snippet) - In depending witch button will be touched the usb uart
  will show number of button witch is touched.

*/

#include "Click_CapExtend3_types.h"
#include "Click_CapExtend3_config.h"

uint8_t touch_0;
uint8_t touch_1;
uint8_t touch_3;
uint8_t touch_4;

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_logInit( _LOG_USBUART, 9600 );

    Delay_ms( 100 );
}

void applicationInit()
{
    capextend3_gpioDriverInit( (T_CAPEXTEND3_P)&_MIKROBUS1_GPIO );
     mikrobus_logWrite("---- Init ----",_LOG_LINE);
}

void applicationTask()
{
   touch_1 = capextend3_Touch_1();
   touch_0 = capextend3_Touch_0();
   touch_3 = capextend3_Touch_3();
   touch_4 = capextend3_Touch_4();

   if( touch_0 == 0 )
      mikrobus_logWrite("Touch 0 ",_LOG_LINE);

   if( touch_1 == 0 )
      mikrobus_logWrite("Touch 1 ",_LOG_LINE);

   if( touch_3 == 0 )
      mikrobus_logWrite("Touch 3 ",_LOG_LINE);

   if( touch_4 == 0 )
      mikrobus_logWrite("Touch 4 ",_LOG_LINE);

   Delay_ms( 100 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}
