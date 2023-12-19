// DS3231 LIB C file
#include "DS3231.h"
void Error_Handler(void);
// --------------------- // ------------------- //
// Registers Functions
// --------------------- // ------------------- //
void DS3231_WriteReg(uint8_t DS3231_Reg, uint8_t *RegValue)
{
    if(HAL_I2C_Mem_Write(&I2C_HANDLER, DS3231_ADDRESS,DS3231_Reg, I2C_MEMADD_SIZE, RegValue, sizeof(*RegValue), MAX_DELAY) != HAL_OK){
        Error_Handler();
    }
}

void DS3231_ReadReg(uint8_t DS3231_Reg, uint8_t *RegValue){ 
    if (HAL_I2C_Mem_Read(&I2C_HANDLER, DS3231_ADDRESS, DS3231_Reg, I2C_MEMADD_SIZE,RegValue, sizeof(*RegValue), MAX_DELAY) != HAL_OK){
        Error_Handler();
    }
}
// --------------------- // ------------------- //
uint8_t bcdToDecimal(uint8_t bcdValue){
    return ((bcdValue >> 4) * 10) + (bcdValue & 0x0F);
}
// --------------------- // ------------------- //
// General Functions
// --------------------- // ------------------- //
void decimalToBCD(uint8_t *decimalValue) {
    uint8_t tens = *decimalValue / 10;
    uint8_t units = *decimalValue % 10;
    uint8_t ret_value = (tens << 4) | units;
    *decimalValue = ret_value;
}
static uint8_t D2B(uint8_t decimal)
{
  return (((decimal / 10) << 4) | (decimal % 10));
}
// --------------------- // ------------------- //

// --------------------- // ------------------- //
// Init Functions
// --------------------- // ------------------- //
void DS3231_Init(void){
    uint8_t initSequence[] = {0x00};  // Set the control register to enable the oscillator
    DS3231_WriteReg(DS3231_REG_CONTROL, initSequence);
}
// ------------------- // ------------------- //

// ------------------- // ------------------- //
// Seconds Functions 
// ------------------- // ------------------- //
uint8_t DS3231_GetSeconds(void) {
    uint8_t seconds;
    DS3231_ReadReg(DS3231_REG_SECONDS,&seconds);
    return bcdToDecimal(seconds);
}

void DS3231_SetSeconds(uint8_t seconds) {
   decimalToBCD(&seconds);
   DS3231_WriteReg(DS3231_REG_SECONDS,&seconds);
}
// ------------------- // ------------------- //
// ------------------- // ------------------- //
// Minutes Functions 
// ------------------- // ------------------- //
uint8_t DS3231_GetMinutes(void) {
    uint8_t minutes;
    DS3231_ReadReg(DS3231_REG_MINUTES,&minutes);
    return bcdToDecimal(minutes);
}

void DS3231_SetMinutes(uint8_t minutes) {
   decimalToBCD(&minutes);
   DS3231_WriteReg(DS3231_REG_MINUTES,&minutes);
}
// ------------------- // ------------------- //
// ------------------- // ------------------- //
// Hours Functions 
// ------------------- // ------------------- //
uint8_t DS3231_GetHours(void) {
    uint8_t hours;
    DS3231_ReadReg(DS3231_REG_HOURS,&hours);
    return bcdToDecimal(hours);
}

void DS3231_SetHours(uint8_t hours) {
   decimalToBCD(&hours);
   DS3231_WriteReg(DS3231_REG_HOURS,&hours);
}
// ------------------- // ------------------- //
// ------------------- // ------------------- //
// Alarms Functions 
// ------------------- // ------------------- //

#define MASK_ALARM 					0b10000000
#define MASK_ONCE_PER_SEC 			1
#define MASK_SEC_MACTH 				2
#define MASK_SEC_MIN_MACTH 			3
#define MASK_SEC_MIN_HOUR_MACTH 	4




void DS3231_SetAlrm1(uint8_t date,uint8_t hours,uint8_t minutes,uint8_t seconds,uint8_t MASK_ALARM1/*define args for setting diff alarms*/){


	uint8_t alarmSecond = D2B(seconds);
	uint8_t alarmMinute = D2B(minutes);
	uint8_t alarmHour = D2B(hours);
	uint8_t alarmDate = D2B(date);

	switch(MASK_ALARM1){
	case MASK_ONCE_PER_SEC:
		alarmSecond |= MASK_ALARM;
		alarmMinute |= MASK_ALARM;
		alarmHour 	|= MASK_ALARM;
		alarmDate 	|= MASK_ALARM;
	case MASK_SEC_MACTH:
		alarmMinute |= MASK_ALARM;
		alarmHour 	|= MASK_ALARM;
		alarmDate 	|= MASK_ALARM;
	case MASK_SEC_MIN_MACTH:
		alarmHour 	|= MASK_ALARM;
		alarmDate 	|= MASK_ALARM;
	case MASK_SEC_MIN_HOUR_MACTH:
		alarmDate 	|= MASK_ALARM;
	}

	 uint8_t startAddr = DS3231_REG_ALARM1_SECONDS;
	 uint8_t buffer[5] = {startAddr, alarmSecond, alarmMinute, alarmHour, alarmDate};
	 if(HAL_I2C_Master_Transmit(&I2C_HANDLER, DS3231_ADDRESS, buffer, sizeof(buffer), HAL_MAX_DELAY) != HAL_OK) return;


}

// ------------------- // ------------------- //

