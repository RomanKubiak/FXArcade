/*
* Define a REAL printf since Arduino doesn't have one
*
* SerialPrintf() will automatically put the format string in AVR program space
* 
* You can simple change/rename "SerialPrintf" in the macro below to be "printf" if you like.
* instead of the using the additional macro for printf.
* Using the printf() macro below allows easily changing were printf is directed in the case
* you have multiple places. Either way works.
*/
#include "constants.h"

extern "C"
{
	int serialputc(char c, FILE *fp)
 	{ 
    	if(c == '\n')
       		Serial.write('\r'); 
   		Serial.write(c); 

   		return (1);
 	}
}


void _SerialPrintf(const char *fmt, ...)
{
	FILE stdiostr;
	va_list ap;

 	fdev_setup_stream(&stdiostr, serialputc, NULL, _FDEV_SETUP_WRITE);
 	va_start(ap, fmt);
 	vfprintf_P(&stdiostr, fmt, ap);
 	va_end(ap);
}