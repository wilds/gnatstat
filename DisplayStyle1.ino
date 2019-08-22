/*
   ___ ___ ___ ___ _      ___   __  ___  ___ ___ ___ ___ _  _   _
  |   \_ _/ __| _ \ |    /_\ \ / / / __|/ __| _ \ __| __| \| | / |
  | |) | |\__ \  _/ |__ / _ \ V /  \__ \ (__|   / _|| _|| .` | | |
  |___/___|___/_| |____/_/ \_\_|   |___/\___|_|_\___|___|_|\_| |_|
*/
void DisplayStyle1 () {

  //--------------------------------------- Display Background ----------------------------------------------------

  /* OLED Background */
  display.setTextSize(2); //set background txt font size
  display.setCursor(1, 12);
  display.println("CPU");
  display.setCursor(1, 38);
  display.println("GPU");
  display.setTextSize(1); //set background txt font size
  display.setCursor(1, 56);
  display.println("SYSRAM");


  //display.display();
  //oledDraw = 1;

  /*CPU/GPU/RAM  Clearing Boxes, eg: display.fillRect(<X>, ^Y^, W, H, Color);*/
  display.fillRect(38, 11, 90, 16, BLACK); // fill CPU live stats section only
  display.fillRect(38, 37, 90, 16, BLACK); // fill GPU live stats section only
  display.fillRect(38, 54, 36, 10, BLACK); // fill RAM live stats section only
  /* Position Test*/
  //display.drawRect(38, 11, 90, 16, WHITE); // fill CPU live stats section only
  //display.drawRect(38, 37, 90, 16, WHITE); // fill GPU live stats section only
  //display.drawRect(38, 54, 36, 10, WHITE); // fill RAM live stats section only
  //display.drawRect(68, 54, 58, 10, WHITE); // Flash bottom right corner when updating

  //---------------------------------------CPU & GPU Hardware ID----------------------------------------------------

  /*CPU & GPU Hardware ID*/
  /*CPU Manual Position Test*/
#ifdef DEBUG
  //display.setTextSize(0);
  //display.setCursor(-35, 1);// Negative spacing so, CPU ID doesn't cause a rollover, on the next line
  //String cpuName = "Intel Core i7-5820K"; // Name spacing test
  strcpy(packet.cpuName, "Intel Core i7-5820K");
#endif

  /*CPU & GPU Hardware ID*/
  display.setTextSize(1); // string font size
  display.setCursor(0, 1);
  display.println(strlen(packet.cpuName) <= 20 ? packet.cpuName : removeWordsFromLeft(packet.cpuName, 1));

  /* GPU Manual Position Test*/
#ifdef DEBUG
  //display.setTextSize(0);
  //display.setCursor(-42, 28); // Negative spacing so, GPU ID doesn't cause a rollover, on the next line
  //String gpuName = "Nvidia GeForce GTX 1080"; // Name spacing test
  strcpy(packet.gpuName, "Nvidia GeForce GTX 1080");
#endif

  display.setTextSize(1); // string font size
  display.setCursor(0, 28);
  display.println(strlen(packet.gpuName) <= 20 ? packet.gpuName : removeWordsFromLeft(packet.gpuName, 1));


  //------------------------------------------ CPU Load/Temp -------------------------------------------------

  /*CPU Display String*/


  /*CPU TEMPERATURE*/
  display.setTextSize(2);
  display.setCursor(42, 12);
  display.print(round(packet.cpuTemp));
  display.setTextSize(1);
  
  #ifdef noDegree
display.print("C");       // Centigrade Symbol
#else
display.print((char)247); //Degrees Symbol
display.print("C");       // Centigrade Symbol
#endif

  /*CPU LOAD, ALL CORES*/
  display.setTextSize(2);
  display.setCursor(85, 12);
  display.print(round(packet.cpuLoad));
  display.setTextSize(1);
  display.println("%");    // Small Percent Symbol



  //------------------------------------------ GPU Load/Temp -------------------------------------------------

  /*GPU Display String*/

  /*GPU TEMPERATURE*/
  display.setTextSize(2);
  display.setCursor(42, 38);
  display.print(round(packet.gpuTemp));
  display.setTextSize(1);
  
 #ifdef noDegree
display.print("C");       // Centigrade Symbol
#else
display.print((char)247); //Degrees Symbol
display.print("C");       // Centigrade Symbol
#endif

  /*GPU LOAD*/
  display.setTextSize(2);
  display.setCursor(85, 38);
  display.print(round(packet.gpuLoad));
  display.setTextSize(1);
  display.println("%");      // Small Percent Symbol


  //----------------------------------------SYSTEM RAM USAGE---------------------------------------------------

  /*SYSTEM RAM String*/

  /*RAM USAGE*/
  display.setTextSize(1); //set background txt font size
  display.setCursor(42, 56);
  display.println(packet.ramLoad);

  
  //--------------------------Trigger an event when CPU or GPU threshold is met ---------------------------------


#ifdef uVol_enableThesholdtriggers

  //uVol_TriggerCPU_temp( cpuString1.toInt() ); // Neopixel CPU  Temperature
  uVol_TriggerCPU_load( cpuString2.toInt() ); // Neopixel CPU  Load

  //uVol_TriggerGPU_temp( gpuString1.toInt() ); // Neopixel GPU  Temperature
  uVol_TriggerGPU_load( gpuString2.toInt() ); // Neopixel GPU  Load

#endif

#ifdef enableCustomThesholdtriggers

  CustomTriggerCPU_temp( cpuString1.toInt() ); // Neopixel CPU  Temperature
  CustomTriggerCPU_load( cpuString2.toInt() ); // Neopixel CPU  Load

  CustomTriggerGPU_temp( gpuString1.toInt() ); // Neopixel GPU  Temperature
  CustomTriggerGPU_load( gpuString2.toInt() ); // Neopixel GPU  Load

#endif

#ifdef enableNeopixelGauges

  CPU_loadGauge( cpuString2.toInt() ); // Neopixel Ring Gauge  CPU  Load
  //CPU_tempGauge( cpuString1.toInt() ); // Neopixel Ring Gauge  CPU  Temperature

  GPU_loadGauge( gpuString2.toInt() ); // Neopixel Ring Gauge  GPU  Load
  //GPU_tempGauge( gpuString1.toInt() ); // Neopixel Ring Gauge  GPU  Temperature

#endif


  //display.setTextSize(1);
  //display.setCursor(115, 1);
  //display.println("D1");
  display.display();

  displayDraw = 1;

}
