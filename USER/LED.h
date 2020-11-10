#ifndef _LED_
#define _LED_

#include "stm8s.h"
#include "stm8s_conf.h"
#include "Delay.h"
#include "stm8s_tim2.h"
#include "stm8s_clk.h"

#define LED_ON_OFF_PORT  (GPIOD)
#define LED_MODE_PORT    (GPIOD)
#define LED_HCL_PORT     (GPIOC)
#define LED_TOMATO_PORT  (GPIOC)

#define LED_BAR_1_7_PORT (GPIOB)
#define LED_BAR_8_9_PORT (GPIOE)
#define LED_BAR_10_PORT  (GPIOC)

#define LED_ON_OFF_PIN  (GPIO_PIN_2)
#define LED_MODE_PIN    (GPIO_PIN_3)
#define LED_HCL_PIN     (GPIO_PIN_2)
#define LED_TOMATO_PIN  (GPIO_PIN_3)

#define LED_BAR_1_PIN   (GPIO_PIN_6)
#define LED_BAR_2_PIN   (GPIO_PIN_5)
#define LED_BAR_3_PIN   (GPIO_PIN_4)
#define LED_BAR_4_PIN   (GPIO_PIN_3)
#define LED_BAR_5_PIN   (GPIO_PIN_2)
#define LED_BAR_6_PIN   (GPIO_PIN_1)
#define LED_BAR_7_PIN   (GPIO_PIN_0)
#define LED_BAR_8_PIN   (GPIO_PIN_7)
#define LED_BAR_9_PIN   (GPIO_PIN_6)
#define LED_BAR_10_PIN  (GPIO_PIN_1)

#define LED_PWM_C_PORT  (GPIOD)
#define LED_PWM_W_PORT  (GPIOA)

#define LED_PWM_C_PIN   (GPIO_PIN_4) 
#define LED_PWM_W_PIN   (GPIO_PIN_3)

void LED_Init(void);
void LED_tonggle(void);
void LED_PWM_Config(void);
#endif