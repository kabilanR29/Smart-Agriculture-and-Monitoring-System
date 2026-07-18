#include<lpc21xx.h>
#include "Motor.h"
//#include "delay_header.h"

#define motorin  (1<<8)
#define motorout (1<<9)

void MOTOR_ON(void)
{
    IODIR0 |= motorin|motorout;
    IOSET0 = motorin;
    IOCLR0 = motorout;      // Motor ON
    delay_milliseconds(500);
	IOSET0=motorin;
}

void MOTOR_OFF(void)
{
    IOCLR0 = motorin;
    IOCLR0 = motorout;
}

