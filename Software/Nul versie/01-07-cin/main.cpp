#include "hwlib.hpp"

int main( void ){	
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   // wait for the PC console to start
   hwlib::wait_ms( 500 );
   
   auto t1 = hwlib::now_ticks();
   auto t2 = hwlib::now_ticks();
   HWLIB_TRACE << t1 << " " << t2 << " " << t2 - t1;
   
   for(;;){
      auto c = hwlib::cin.getc();
      hwlib::cout << "[" << c << "]\n";
   }
}
