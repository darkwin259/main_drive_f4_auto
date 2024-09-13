
#ifndef INC_KEYPAD_LCD_H_
#define INC_KEYPAD_LCD_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "main.h"
extern char button[4];

void key_pad_gpio(void);

char read_1(void);
char read_2(void);
char read_3(void);
char read_4(void);


char read_keypad();
#ifdef __cplusplus
}
#endif
#endif /* INC_KEYPAD_LCD_H_ */
