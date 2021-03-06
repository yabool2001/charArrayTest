#include "mbed.h"

// SERIAL PINS
static BufferedSerial dbg ( PA_9 , NC , 115200 ) ;

// main() runs in its own thread in the OS
int main()
{
    //DBG configuration
    dbg.set_format( 8 , BufferedSerial::None , 1 ) ;

    char* p = new char[11] ;
    //char p[11] = {0} ; works also with //dbg.write ( p , sizeof ( p ) ) ;
    char c = 'c' ;

    for ( int i = 0 ; i < 10 ; i++ )
    {
        p [ i ] = c ;
        p [ i + 1 ] = '\0' ;
        
        dbg.write ( "\r\n" , sizeof ( "\r\n" ) ) ;
        // dbg.write ( p , sizeof ( p ) ) ; // doesn't work with // char* p = new char[11] ;
        dbg.write ( p , strlen ( p ) ) ;

    }
}

