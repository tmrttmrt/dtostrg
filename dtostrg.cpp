#include "Arduino.h"
#include "dtostrg.h"

int normalize(double *val) {
    int exponent = 0;
    double value = *val;

    while (value >= 10.0) {
        value /= 10.0;
        ++exponent;
    }

    while (value < 1.0) {
        value *= 10.0;
        --exponent;
    }
    *val = value;
    return exponent;
}


char *dtostrg(double value, signed char width, int prec, char *s){
	//Similar to dtostrf. The output format is either "[-]d.ddd" (%f format) or "[-]d.ddde[-]d" (%e format) depending on width and prec. 
	//The maximum output field is width and the requested number of significant digits printed is prec. 
	//The %f format is prefered if prec can be satisfied else %e format is output with no more than prec significant digits. 	
	//Negative width results in left aligned output
	int exponent,reqwidth;
	int ndigits=0,npad;
	bool negative = false;
	bool lalign = false;
	double dtmp;
	
	if (isnan(value)) {
        strcpy(s, "nan");
        return s;
    }
    if (isinf(value)) {
        strcpy(s, "inf");
        return s;
    }

    if (value == 0.0) {
        strcpy(s, "0");
        return s;
    }
	
	if(width<0){
		lalign=true;
		width=-width;
	}	
	
	// Handle negative numbers
    if (value < 0.0) {
        negative = true;
		ndigits=1;
    }
	
	dtmp=negative?-value:value;
	exponent=normalize(&dtmp);
	
	if(exponent>0){
		if(exponent<prec){
			ndigits+=prec+1;
			if(ndigits<=width){
				return dtostrf(value,lalign?-ndigits:ndigits,prec-exponent,s);
			}
		} else {
			ndigits+=exponent;
			if(ndigits<=width){
				return dtostrf(value,lalign?-ndigits:ndigits,0,s);
			}
		}
	} else {
		ndigits+=2-exponent+prec;
		if(ndigits<=width){
				return dtostrf(value,lalign?-ndigits:ndigits,-exponent+prec,s);
			}
	} 
	
	//%f format does not fit to width so we need %e format
		
    *s = 'e';
    itoa(exponent, s+1, 10);
	ndigits=strlen(s);
	String buff= String(s);
	reqwidth=prec+ndigits+1;
	reqwidth=width<reqwidth?width:reqwidth;
	npad=width-reqwidth;
	s=lalign?s:s+npad;
	dtostrf(negative?-dtmp:dtmp,reqwidth-ndigits,reqwidth-ndigits-2,s);
	while(npad-- > 0){
        *--s = ' ';
    }
	strcat(s,buff.c_str());


}
