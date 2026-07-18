#include<lpc21xx.h>
#include<string.h>
#include "delay_header.h"
#include "gsm1_header.h"
#include "gsm1_header.c"
#include "lcdheader.h"
#include "Motor.h"
#include "Motor.c"

#define D0   2
#define IR_S 3

int soilsensor_read(void);
int IRsensor_read(void);

int ML;
int IR_sensor;
char farmers_msg[100];

int main()
{
    //IODIR0 &= ~((1<<D0)|(1<<IR_S));   
    UART0_CONFIG();
    gsm_config();

    lcd_initialization();

    lcd_command(0x01);
    lcd_command(0x80);
    lcd_str("Smart Agriculture");
    delay_milliseconds(500);
    lcd_command(0xc0);
    lcd_str("Monitoring System");
    delay_milliseconds(500);
	IODIR0 |= motorin|motorout;
	MOTOR_OFF();

    while(1)
    {
        lcd_command(0x01);
        ML = soilsensor_read();
       // IR_sensor = IRsensor_read();

        if(ML==1)
        {
            lcd_command(0x80);
            lcd_str("Soil is Dry");
            delay_milliseconds(500);
            lcd_command(0x01);
            lcd_command(0x80);
            lcd_str("Please ON");
            lcd_command(0xc0);
            lcd_str("The Motor");
            delay_milliseconds(500);

            gsm_msgse("Soil is Dry,Please ON the Motor");
            receive_gsm();
            delay_milliseconds(200);

            gsm_receive_sms(farmers_msg);
            lcd_command(0x01);
            lcd_command(0x80);
            lcd_str(farmers_msg);
            delay_milliseconds(200);

            if((strstr(farmers_msg,"MOTOR ON")!= NULL))
            {
                lcd_command(0x01);
                lcd_command(0x80);
                lcd_str("MOTOR ON");
                delay_milliseconds(200);
                MOTOR_ON();
                MOTOR_OFF();
            }
        }
        else
        {
            lcd_command(0x01);
            lcd_command(0x80);
            lcd_str("Soil is Wet");
            delay_milliseconds(200);
            lcd_command(0x01);
            lcd_command(0x80);
            lcd_str("Don't ON");
            delay_milliseconds(500);
            lcd_str("the Motor");
            delay_milliseconds(500);

            gsm_msgse("Soil is Already Wet,So Don't ON the Motor");
            MOTOR_OFF();
        }

        if(IRsensor_read()==1)
        {
            lcd_command(0x01);
            lcd_command(0x80);
            lcd_str("object is Detected");
            delay_milliseconds(500);

            gsm_msgse("Object is Detected");
            receive_gsm();
            delay_milliseconds(500);

            gsm_receive_sms(farmers_msg);
            if(strstr(farmers_msg,"OK")!= NULL)
            {
                lcd_command(0x01);
                lcd_command(0x80);
                lcd_str("OK");
                delay_milliseconds(500);
            }
        }
    }
}

int soilsensor_read()
{
    if(((IOPIN0>>D0)&1)==0)
        return 0;
    else
        return 1;
}

int IRsensor_read()
{
    if(((IOPIN0>>IR_S)&1)==0)
        return 1;
    else
        return 0;
}
