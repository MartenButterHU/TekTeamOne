#include "hwlib.hpp"

int main( void ){	
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
      // wait for the PC console to start
   hwlib::wait_ms( 500 );   
   
   namespace target = hwlib::target;
   
   auto scl = target::pin_oc( target::pins::sda );
   auto sda = target::pin_oc( target::pins::scl );
   
   // The OLED display is connected in a very funny way:
   // the I2C pins are reversed, and two GPIO pins are
   // (mis-) used as ground and power for the display.
   // This works, and makes it very easy to connect the LCD,
   // but don't take this as an advice to connect peripherals is this way
   // unless you know very well what you are doing.
   auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
   auto pin_gnd = target::pin_out( target::pins::d18 );
   pin_gnd.set( 0 );
   auto pin_vcc = target::pin_out( target::pins::d19 );
   pin_vcc.set( 1 );
   
   // use the buffered version
   auto oled = hwlib::glcd_oled_buffered( i2c_bus, 0x3c );  

   // won't work because it doesn't call flush()     
   // hwlib::graphics_random_circles( oled );
   
   auto w1 = hwlib::window_part( 
      oled, 
      hwlib::location( 0, 0 ),
      hwlib::location( 128, 32));
   auto w2 = hwlib::window_part( 
      oled, 
      hwlib::location( 0, 32 ),
      hwlib::location( 128, 32));
      
   auto f1 = hwlib::font_default_16x16();
   auto d1 = hwlib::window_ostream( w1, f1 );
   
   auto f2 = hwlib::font_default_8x8();
   auto d2 = hwlib::window_ostream( w2, f2 );
   
   d1 << "\f"
      << "LASER \nshooter";   
   d2 << "\f"
      << "==============\n"
      << "user: Wouter\n"
      << "score: " << 42 << "\n"
      << "==============\n";
      
   auto t1 = hwlib::now_us(); 
   oled.flush();
   auto t2 = hwlib::now_us();
   HWLIB_TRACE << "oled.fluhs() took " << t2 - t1 << " us";
      
   int n = 0;   
   for(;;){
      hwlib::wait_ms(1000);
      d1 << "\f" << ++n;
      d2 << "\t0502" << ": " << n + 42;
      oled.flush();
   }      
      
}

