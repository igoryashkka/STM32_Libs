
/// Example Code
/*
static uint8_t sec = 0;
    static uint8_t min = 0;
    static uint8_t h = 0;

    DS3231_SetSeconds(58);
    DS3231_SetMinutes(32);
    DS3231_SetHours(11);

    DS3231_SetAlrm1(0,12,33,33,3);
    uint8_t data = 0;
    uint8_t buff = 0;
  // Null the control|status reg
     HAL_I2C_Mem_Write(&hi2c1, DS3231_ADDRESS, 0x0F, I2C_MEMADD_SIZE_8BIT,&buff, sizeof(buff), HAL_MAX_DELAY);
  // Infinite loop
  for(;;)
  {
      // Check the control|status reg
      uint8_t ret = HAL_I2C_Mem_Read(&hi2c1, DS3231_ADDRESS, 0x0F, I2C_MEMADD_SIZE_8BIT, &data, sizeof(data), HAL_MAX_DELAY);
      sec = DS3231_GetSeconds();
      min = DS3231_GetMinutes();
      h = DS3231_GetHours();

  }
*/
//
/// Example Code
