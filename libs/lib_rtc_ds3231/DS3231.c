// DS3231 LIB C file

// --------------------- // ------------------- //
// Registers Functions
// --------------------- // ------------------- //
void DS3231_WriteReg(uint8_t DS3231_Reg, uint8_t *RegValue){
    if(HAL_I2C_Mem_Write(&I2C_HANDLER, DS3231_ADDRESS,DS3231_Reg, I2C_MEMADD_SIZE, *RegValue, sizeof(*RegValue), MAX_DELAY) != HAL_OK){
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
void DS3231_SetAlrm1(/*define args for setting diff alarms*/){
    /*diiff masks & for diff alarmns*/
    /*Example code for setting alarm for 1st mask*/
    DS3231_WriteReg(DS3231_REG_ALARM1_SECONDS,decimalToBCD(10));
    DS3231_WriteReg(DS3231_REG_ALARM1_MINUTES, 0b10000000);
    DS3231_WriteReg(DS3231_REG_ALARM1_HOURS, 0b10000000);
    DS3231_WriteReg(DS3231_REG_ALARM1_DAY, 0b10000000);
    /*it can be imroved by using start addr for trasnmitting*/

}
// ------------------- // ------------------- //
