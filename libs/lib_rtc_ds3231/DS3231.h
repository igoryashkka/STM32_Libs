// DS3231 LIB H file

// Add erorr handling to ALL

#ifndef DS3231
#define DS3231

#include <stdint.h>
#include <stdbool.h>
#include "stm32h7xx_hal.h"

extern I2C_HandleTypeDef hi2c1;

#define I2C_HANDLER hi2c1

#define MAX_DELAY 0xFFFFFFFFU

#define DS3231_ADDRESS 0xD0
#define I2C_MEMADD_SIZE 1U
// ----- REG FOR TIMING INFO
#define DS3231_REG_SECONDS 0x00
#define DS3231_REG_MINUTES 0x01
#define DS3231_REG_HOURS 0x02
#define DS3231_REG_DAY 0x03
#define DS3231_REG_DATE 0x04
#define DS3231_REG_MONTH 0x05   // its the same as century
#define DS3231_REG_CENTURY 0x05 // its the same as month
#define DS3231_REG_YEAR 0x06

// ----- REG FOR ALARM 1 INFO
#define DS3231_REG_ALARM1_SECONDS 0x07
#define DS3231_REG_ALARM1_MINUTES 0x08
#define DS3231_REG_ALARM1_HOURS 0x09
#define DS3231_REG_ALARM1_DAY_DATE 0xA // its the same as DS3231_REG_ALARM1_DATE

// ----- REG FOR ALARM 2 INFO
#define DS3231_REG_ALARM2_MINUTES 0xB
#define DS3231_REG_ALARM2_HOURS 0xC
#define DS3231_REG_ALARM1_HOURS 0x09
// #define DS3231_REG_ALARM1_DAY_DATE 0xD // conflting with dev addr

// ----- REG FOR GANAREL INFO

#define DS3231_REG_CONTROL 0xE
#define DS3231_REG_STATUS 0xF
#define DS3231_REG_AGING 0x10
#define DS3231_REG_MSB_TEMP 0x11
#define DS3231_REG_LSB_TEMP 0x12

void DS3231_WriteReg(uint8_t DS3231_Reg, uint8_t *RegValue);
void DS3231_ReadReg(uint8_t DS3231_Reg, uint8_t *RegValue);

void DS3231_Init(void);

uint8_t DS3231_GetSeconds(void);
uint8_t DS3231_GetMinutes(void);
uint8_t DS3231_GetHours(void);
void DS3231_SetSeconds(uint8_t seconds);
void DS3231_SetMinutes(uint8_t minutes);
void DS3231_SetHours(uint8_t hours);
void DS3231_SetAlrm1(uint8_t date, uint8_t hours, uint8_t minutes, uint8_t seconds, uint8_t MASK_ALARM1);

#endif
