
/*

lcd_init();

  lcd_send_cmd(0x40);
  for (int i=0; i<64; i++) lcd_send_data(cc[i]);
  lcd_clear();

  while (1)
  {

	  static int counter_dino = 1;
	  static int counter_tree = 1;
	  static int c = 20;
	  static int state_dino = 0;
	  static int position_tree = 18;

	  //lcd_put_cur(0,0);
	  //lcd_send_data(c);
	  lcd_put_cur(2,0);
	    for(int i = 0; i < 19;i++){


			  if (i == position_tree) {

				  if (position_tree == 3){
					  if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_3) == 0){
						  lcd_send_data(2);
					  }else {
						  lcd_put_cur(0,0);
						  lcd_send_string("loose");
						  lcd_put_cur(2,3);
					  }

				  }
				  if(i == 0){
					  position_tree = 18;
				  }
				   if( counter_tree % 2 == 0){
					   position_tree -=1;
				    }
			  lcd_send_data(2);
			  counter_tree++;
			  }



	    		  if(i == 3){// ____________________________________________________________-

	    			  if(counter_dino %2 == 0){state_dino = 0;}else{state_dino = 1;}
	    			  counter_dino++;
	    			  if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_3)== 0){
	    				  //if pressed
	    				  lcd_put_cur(2,3);
	    				  lcd_send_data(7);
	    				  lcd_put_cur(1,3);
	    			 	  lcd_send_data(state_dino);
	    			 	  lcd_put_cur(2,3);
	    			  }else {
	    				  //if not pressed
	    				  lcd_put_cur(1,3);
	    				  lcd_send_data(4);
	    				  lcd_put_cur(2,3);
	    			  }

	    			  if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_3)== 1){
	    			  lcd_put_cur(2,3);
	    			  lcd_send_data(state_dino);
	    			  }


	    			    continue;
	    		  } // ____________________________________________________________-




	  	  HAL_Delay(25);
	      lcd_send_data(7);

	    	}

	 // for(int i = 0; i < 10;i++){

		//  if(i == 1){continue;}
		  //lcd_send_data(7);
	 // }
	  //HAL_Delay(400);
	  //lcd_put_cur(2,1);
	  //lcd_send_data(0);
	 // HAL_Delay(400);
	  //lcd_clear();

	  //lcd_put_cur(2,1);
	  //lcd_send_data(1);
	 // HAL_Delay(400);
	  //lcd_clear();


  }

*/
//
/// Example Code
