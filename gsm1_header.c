#include<lpc21xx.h>
#include "gsm1_header.h"
#include "uart_header.h"
//#include "delay_header.h"

#define FARMER_NUMBER "+919344975732"

void gsm_config(void)
{
   
    delay_milliseconds(2000);          // let GSM module power up/register

    UART0_STR("AT");
    UART0_STR("\r");
    UART0_STR("\n");
    delay_milliseconds(100);

    UART0_STR("AT+CMGF=1");
    UART0_STR("\r");
    UART0_STR("\n");
    delay_milliseconds(100);

	
   /*0_STR("AT+CNMI=2,2,0,0,0");
    UART0_STR("\r");
    UART0_STR("\n");
    delay_milliseconds(100); */
}

void gsm_msgse(char *msg)
{
    UART0_STR("AT+CMGS=\"");
    UART0_STR(FARMER_NUMBER);
    UART0_STR("\"");
    UART0_STR("\r");
    UART0_STR("\n");
   delay_milliseconds(2000);

    UART0_STR(msg);
    UART0_STR("\r");
    UART0_STR("\n");
    UART0_TX(0x1A);                    // Ctrl+Z, sends the message
    delay_milliseconds(5000);
}

void receive_gsm(void)
{
    UART0_STR("AT+CNMI=2,2,0,0,0");
    UART0_STR("\r");
    UART0_STR("\n");
    delay_milliseconds(2000);
}

/* same '*' ... '#' framing loop as the first attached file, just pulled into a function */
void gsm_receive_sms(char *buffer)
{
    unsigned char ch;
    unsigned int i;

    do
    {
        ch = UART0_RX();
    } while(ch != '*');

    i = 0;
    do
    {
        buffer[i++] = UART0_RX();
    } while(buffer[i-1] != '#');
    buffer[i-1] = '\0';
}

