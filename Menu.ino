void Menu()
{
  // get the reading from the encoder and the switches 

  int Select = digitalRead(selectPin);
  int zero_num;// the number used to zero the menu each time 

  // read the position of the rotary encoder
      encoder.tick();
      newPos = encoder.getPosition();
// if the encoder is turned change the number used to scroll through the menu interface        
if (oldPos!= newPos or newPos == 0 or Select == LOW ){      
// convert the encoder position number to an integer with in the length of the        
      Menu_num = (abs(newPos)-zero_num )% Menu_len;

switch(menuArray[0]){
  case 0:// Materials Menu 
          //temporary code 
          material = "Wol";
          menuArray[0]  = 1;

          //normal code
          Menu_len = textile_len;
          lcd.setCursor(0,0);
          lcd.print(F("Select Material"));
             lcd.setCursor(0,1);
          lcd.print(F(">"));
          lcd.print(textiles[Menu_num]);
          lcd.print(F("   "));
          
          lcd.print(textiles[Menu_num+1]);
          if (Select == LOW){
            delay(1000);
             material = textiles[Menu_num];
             menuArray[0]  = 1;
             lcd.setCursor(0, 0);
            lcd.print("                ");
            lcd.setCursor(0, 1);
            lcd.print("                ");
          
             Select = HIGH;
            }
          break;
  
  case 1: //Color MEnu 
        
        Menu_len =color_list_len;
          lcd.setCursor(0,0);
          lcd.print(F("Select Color:  "));
             lcd.setCursor(0,1);
          lcd.print(F(">"));
          lcd.print(colors_types[Menu_num]);
          lcd.print(F("   "));
          
          lcd.print(colors_types[Menu_num+1]);
          
          if (Select == LOW){
            delay(1000);
             color = colors_types[Menu_num];
             menuArray[0]  = 3;
             zero_num = abs(newPos);
             lcd.setCursor(0, 0);
            lcd.print("                ");
            lcd.setCursor(0, 1);
            lcd.print("                ");
          
             Select = HIGH;
            }
          break;
    break;
 
  case 2: //Color MEnu#2 
        
        Menu_len =color_list_len;
          lcd.setCursor(0,0);
          lcd.print(F("Select Color2:  "));
             lcd.setCursor(0,1);
          lcd.print(F(">"));
          lcd.print(colors_types[Menu_num]);
          lcd.print(F("   "));
          
          lcd.print(colors_types[Menu_num+1]);
          
          if (Select == LOW){
            delay(1000);
             color2 = colors_types[Menu_num];
             menuArray[0]  = 3;
             zero_num = abs(newPos);
             lcd.setCursor(0, 0);
            lcd.print("                ");
            lcd.setCursor(0, 1);
            lcd.print("                ");
          
             Select = HIGH;
            }
          break;
    break;
 
 
 /*   
  case 2://opacity menu  
        Menu_len = 10;
           lcd.setCursor(0, 0);
         // print the number of seconds since reset:
          lcd.print("0=clear 10=opaqu");
          
          lcd.setCursor(0, 1);
          lcd.print(">" );
          lcd.print(Menu_num );
          lcd.print("               " );

          if (Select == LOW){
            delay(1000);
            opacity = Menu_num;
            menuArray[0] = 3;
            zero_num = abs(newPos);
            lcd.setCursor(0, 0);
            lcd.print("                ");
            lcd.setCursor(0, 1);
            lcd.print("                ");
          
            Select = HIGH;
          }
          break;*/
    case 3://list settings
        lcd.setCursor(0, 0);
         // print the number of seconds since reset:
          
          lcd.print("Mater:");
          lcd.print(material);
          lcd.print(" R#");
          lcd.print(record_count);
          lcd.setCursor(0, 1);
          lcd.print("HUE:" );
          lcd.print(color );
          lcd.print(" Hue2:" );
          lcd.print( color2);
          if (Select == LOW){
            delay(1000);
            
            menuArray[0] = 0;
            zero_num = abs(newPos);
            lcd.setCursor(0, 0);
            lcd.print("                ");
            lcd.setCursor(0, 1);
            lcd.print("                ");
          
            Select = HIGH;
          }
          break;
    
  if (Select == HIGH){Select = LOW;}
  else{}
}
  }
  else{}
   
//write the menu on the screen 


    
  


  
  
  
  
  
  
  }


/*
switch(menuNum[0]){
  case 0:// main menu 
      int Main_Menu_Len = 5;
      String  Menu_strings[6] = {"Take Reading","Material:   ","Color:      ","Opacity:    ","OFF         "};
        Menu_len = Main_Menu_Len;
          lcd.setCursor(0, 0);
         // print the number of seconds since reset:
          lcd.print(">");
          lcd.print(Menu_strings[Menu_num] );
          lcd.setCursor(0, 1);
         // print the number of seconds since reset:
          lcd.print(" " );
          lcd.print(Menu_strings[Menu_num+1] );
          if (Select == LOW){
            delay(100);
            menuNum[0] =  Menu_num;
            pos_holder = newPos;
            }
          else{}
          //oldPos = newPos;

          break;
  /*
  case 1: //Take Reading 
        Take_Reading();
        menuNum[0] = 0 ;
    break;
  case 3://Color Menu 
        Menu_len = Main_Menu_Len;
           lcd.setCursor(0, 0);
         // print the number of seconds since reset:
          lcd.print(">");
          lcd.print(colors_types[Menu_num] );
          lcd.setCursor(0, 1);
         // print the number of seconds since reset:
          lcd.print(" " );
          lcd.print(colors_types[Menu_num+1] );
          if (Select == LOW){
            delay(100);
            color = colors_types[Menu_num];
            menuNum[0] = 0;
          }
          break;
  case 4:// Opacity Menu
          Menu_len = 10;
          lcd.setCursor(0, 0);
         // print the number of seconds since reset:
          lcd.print(F("0=Clear,10=Opaqu"));
          lcd.setCursor(0, 1);
         // print the number of seconds since reset:
          lcd.print( Menu_num );
          if (Select == LOW){
            delay(100);
            menuNum[0] =  Menu_num;
            opacity = Menu_num;
            }
          else{}
    break;
  case 2://Materials Menu
        Menu_len = material_menu_len;
           lcd.setCursor(0, 0);
         // print the number of seconds since reset:
          lcd.print(">");
          lcd.print(Materail_strings[Menu_num] );
          lcd.setCursor(0, 1);
         // print the number of seconds since reset:
          lcd.print(" " );
          lcd.print(Materail_strings[Menu_num+1] );
          if (Select == LOW){
            delay(100);
            menuNum[1] =  Menu_num;
            
            }
          else{}
          break;

}
*/
