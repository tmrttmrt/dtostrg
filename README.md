<h1>dtostrg</h1>

The dtostrg(...) function converts the double value passed in val into an ASCII representation that will be stored at s. The caller is responsible for providing sufficient storage at s.

char * dtostrg(
	double __val,
	signed char __width,
	unsigned char __prec,
	char * __s)  

Similar to dtostrf. The output format is either "[-]d.ddd" (%f format) or "[-]d.ddde[-]d" (%e format) depending on width and prec. 

The maximum output field is width and the requested number of significant digits printed is prec.
 
The %f format is prefered if prec and width can be satisfied else %e format is output with no more than prec significant digits.
 	
A negative width results in left aligned output.

For ESP8266 also dtostre(...) is implemented.
The dtostre() function converts the double value passed in val into an ASCII representation that will be stored under s. The caller is responsible for providing sufficient storage in s.

char * dtostre(
	double __val,
	char * __s,
	unsigned char __prec,
	unsigned char __flags)
	

Conversion is done in the format "[-]d.ddde±dd" where there is one digit before the decimal-point character and the number of digits after it is equal to the precision prec; if the precision is zero, no decimal-point character appears.

flags functionality is not implemented but is there for compatibility.
