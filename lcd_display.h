#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

int flagForParams = 1;
String messageParamsLCD;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  


void setupLcd(){
  // initialize LCD
  lcd.begin();
  // turn on LCD backlight                      
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("SIMONAIR");
  delay(1000);
}


void showToLcd_temperature(int lcdRow, int MaxLcdColumns, float temperature_val){
  for (int cursorPos = 0; cursorPos < MaxLcdColumns; cursorPos++){
    lcd.setCursor(cursorPos, lcdRow);
    lcd.print(" ");
  }

  lcd.setCursor(0, lcdRow);
  messageParamsLCD = "Temp(Cel): " + String(temperature_val);
  lcd.print(messageParamsLCD);
}

void showToLcd_ph(int lcdRow, int MaxLcdColumns, float ph_val){
  for (int cursorPos = 0; cursorPos < MaxLcdColumns; cursorPos++){
    lcd.setCursor(cursorPos, lcdRow);
    lcd.print(" ");
  }

  lcd.setCursor(0, lcdRow);
  messageParamsLCD = "PH: " + String(ph_val);
  lcd.print(messageParamsLCD);
}

void showToLcd_tds(int lcdRow, int MaxLcdColumns, float tds_val){
  for (int cursorPos = 0; cursorPos < MaxLcdColumns; cursorPos++){
    lcd.setCursor(cursorPos, lcdRow);
    lcd.print(" ");
  }

  lcd.setCursor(0, lcdRow);
  messageParamsLCD = "TDS(ppm): " + String(tds_val);
  lcd.print(messageParamsLCD);

}

void showToLcd_tss(int lcdRow, int MaxLcdColumns, float tss_val){
  for (int cursorPos = 0; cursorPos < MaxLcdColumns; cursorPos++){
    lcd.setCursor(cursorPos, lcdRow);
    lcd.print(" ");
  }

  lcd.setCursor(0, lcdRow);
  messageParamsLCD = "TSS(Volt): " + String(tss_val);
  lcd.print(messageParamsLCD);
}

void showToLcd_salinity(int lcdRow, int MaxLcdColumns, float salinity_val){
  for (int cursorPos = 0; cursorPos < MaxLcdColumns; cursorPos++){
    lcd.setCursor(cursorPos, lcdRow);
    lcd.print(" ");
  }

  lcd.setCursor(0, lcdRow);
  messageParamsLCD = "Sal(ppm): " + String(salinity_val);
  lcd.print(messageParamsLCD);
}

void showToLcd_ammonia(int lcdRow, int MaxLcdColumns, float ammonia_val){
  for (int cursorPos = 0; cursorPos < MaxLcdColumns; cursorPos++){
    lcd.setCursor(cursorPos, lcdRow);
    lcd.print(" ");
  }

  lcd.setCursor(0, lcdRow);
  messageParamsLCD = "Ammo(ppm): " + String(ammonia_val);
  lcd.print(messageParamsLCD);
}

void statusParamsText(int lcdRow, int MaxLcdColumn, float temperature_val, float ph_val, float tds_val, float tss_val, float salinity_val, float ammonia_val) 
{
  if (flagForParams == 1){
    showToLcd_temperature(lcdRow, MaxLcdColumn, temperature_val);
    flagForParams += 1;

  } else if(flagForParams == 2){
    showToLcd_ph(lcdRow, MaxLcdColumn, ph_val);
    flagForParams += 1;

  } else if(flagForParams == 3){
    showToLcd_tds(lcdRow, MaxLcdColumn, tds_val);
    flagForParams += 1;

  } else if(flagForParams == 4){
    showToLcd_tss(lcdRow, MaxLcdColumn, tss_val);
    flagForParams += 1;

  } else if(flagForParams == 5){
    showToLcd_salinity(lcdRow, MaxLcdColumn, salinity_val);
    flagForParams += 1;

  } else if(flagForParams == 6){
    showToLcd_ammonia(lcdRow, MaxLcdColumn, ammonia_val);
    flagForParams = 1;

  }
}

void statusQualityText(int quality_row, int lcdColumns, float temperature_val, float ph_val, float tds_val, float tss_val, float salinity_val, float mq_val) {
  
  String quality_message;
  int status_num_quality = 0;

  if (temperature_val >= 22 && temperature_val <= 27) {
    if(mq_val < 2 && (ph_val >= 6 || ph_val <= 9) && tds_val <= 400){
      status_num_quality = 1;
    } else{
      status_num_quality = 0;
    }
  }

  // if (mq_val < 1.0 && (ph_val >= 6 || ph_val <= 8) && tds_val < 1000) {
  //   if (temperature_val >= 25 && temperature_val <= 27) {
  //     status_num_quality = 1;
  //   }
  // }

  // if (mq_val < 1.0 && (ph_val >= 6 || ph_val <= 8) && tds_val < 1000) {
  //   if (temperature_val >= 25 && temperature_val <= 27) {
  //     status_num_quality = 1;
  //   }
  // }

  // if (mq_val < 0.1) {
  //   if (ph_val >= 6 && ph_val <= 8.5) {
  //     if (temperature_val >= 28 && temperature_val <= 32) {
  //       if (tds_val < 1000 and (tds_val > 3.8 || salinity_val >= 0 && salinity_val <= 0.4)) {
  //         status_num_quality = 1;
  //       }
  //     }
  //   }
  // }

  if (status_num_quality == 1){
    quality_message = "Kualitas: Baik";
  } else {
    quality_message = "Kualitas: Buruk";
  }

  lcd.setCursor(0, quality_row);
  lcd.print("                "); // Space sebanyak jumlah kolom LCD

  lcd.setCursor(0, quality_row);
  lcd.print(quality_message); 

}


// =================================================================================
// =================================================================================


// void statusQualityText(int quality_row, 
//                 float temperature_val,
//                 float ph_val, 
//                 float tds_val, 
//                 float tss_val, 
//                 float salinity_val, 
//                 float mq_val,
//                 int delayTime, 
//                 int lcdColumns) {
  

//   String quality_result;
//   String category_temperature, category_ph, category_tds, category_tss, category_salinity, category_mq;

//   // Kondisi untuk temperatur
//   if (temperature_val < 27) {
//       category_temperature = "Rendah";
//   } else if (temperature_val >= 27 && temperature_val <= 33) {
//       category_temperature = "Cukup";
//   } else {
//       category_temperature = "Tinggi";
//   }

//   // Kondisi untuk pH
//   if (ph_val < 6.6) {
//       category_ph = "Rendah";
//   } else if (ph_val >= 6.6 && ph_val <= 8.3) {
//       category_ph = "Cukup";
//   } else {
//       category_ph = "Tinggi";
//   }

//   // Kondisi untuk TDS
//   if (tds_val <= 1000) {
//       category_tds = "Cukup";
//   } else {
//       category_tds = "Tinggi";
//   }

//   // Kondisi untuk TSS
//   if (tss_val < 2.5) {
//       category_tss = "Keruh";
//   } else if (tss_val >= 2.5 && tss_val <= 3.5) {
//       category_tss = "Agak Keruh";
//   } else {
//       category_tss = "Jernih";
//   }

//   // Kondisi untuk salinitas
//   if (salinity_val <= 2.0) {
//       category_salinity = "Cukup";
//   } else {
//       category_salinity = "Tinggi";
//   }

//   // Kondisi untuk MQ
//   if (mq_val <= 1.0) {
//       category_mq = "Cukup";
//   } else {
//       category_mq = "Tinggi";
//   }


//   message_quality_1 = "Temp(Cel)=" + String(temperature_val) + " | " +
//                      "PH=" + String(ph_val) + " | " +
//                      "TDS(ppm)=" + String(tds_val) + " | " +
//                      "TSS(Volt)=" + String(tss_val) + " | " +
//                      "Salinitas(ppm)=" + String(salinity_val) + " | " +
//                      "Amonia(ppm)=" + String(mq_val) + " | ";

//   for (int i=0; i < lcdColumns; i++) {
//     message_quality_1 = " " + message_quality_1;  
//   } 
//   message_quality_1 = message_quality_1 + " "; 
//   for (int pos = 0; pos < message_quality_1.length(); pos++) {
//     lcd.setCursor(0, row);
//     lcd.print(message_quality_1.substring(pos, pos + lcdColumns));
//     delay(delayTime);
//   }

// }

