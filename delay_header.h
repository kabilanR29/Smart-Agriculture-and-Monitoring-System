#ifndef	__DELAY_HEADER_H__
#define __DELAY_HEADER_H__

//void delay_seconds(unsigned int);
//void delay_milliseconds(unsigned int);

void delay_seconds(unsigned seconds)
{
T0PR=15000000-1;
T0TCR=0X01;
while(T0TC<seconds);
T0TCR=0X03;
T0TCR=0X00;
}
void delay_milliseconds(unsigned milliseconds)
{
T0PR=15000-1;
T0TCR=0X01;
while(T0TC<milliseconds);
T0TCR=0X03;
T0TCR=0X00;
}
#endif