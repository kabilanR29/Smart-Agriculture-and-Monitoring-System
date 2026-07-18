#ifndef GSM1_HEADER_H
#define GSM1_HEADER_H

void gsm_config(void);
void gsm_msgse(char *msg);
void receive_gsm(void);
void gsm_receive_sms(char *buffer);

#endif