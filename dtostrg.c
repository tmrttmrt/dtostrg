#include "Arduino.h"
#include "dtostrg.h"

signed char normalize(double *val) {
	signed char exponent = 0;
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
	signed char exponent;
	char reqwidth;
	char ndigits=0,npad;
	bool negative = false;
	bool lalign = false;
	double dtmp;
	char buff[6];
	
	prec=prec<1?1:prec;
	
	if(width<0){
		lalign=true;
		width=-width;
	}	
	
	if (isnan(value)) {
		npad=lalign?0:width-3;
		s+=npad;
		strcpy(s, "nan");
		while(npad-- > 0){
			*--s = ' ';
		}
		return s;
	}
	if (isinf(value)) {
		npad=lalign?0:width-3;
		s+=npad;
		strcpy(s, "inf");
		while(npad-- > 0){
			*--s = ' ';
		}
		return s;
	}

	if (value == 0.0) {
		npad=lalign?0:width-1;
		s+=npad;
		strcpy(s, "0");
		while(npad-- > 0){
			*--s = ' ';
		}
		return s;
	}
	
	
	// Handle negative numbers
	if (value < 0.0) {
		negative = true;
		ndigits=1;
	}
	
	dtmp=negative?-value:value;
	exponent=normalize(&dtmp);
	
	//Try %f format
	
	if(exponent>0){
		if(exponent<prec){
			ndigits+=prec+1;
			if(ndigits<=width){
				npad=lalign?0:width-ndigits;
				s+=npad;
				dtostrf(value,-ndigits,prec-exponent-1,s);
				while(npad-- > 0){
					*--s = ' ';
				}
				return s;
			}
		} else {
			ndigits+=exponent+1;
			if(ndigits<=width){
				npad=lalign?0:width-ndigits;
				s+=npad;
				dtostrf(value,-ndigits,0,s);
				while(npad-- > 0){
					*--s = ' ';
				}
				return s;
			}
		}
	} else {
		ndigits+=1-exponent+prec;
		if(ndigits<=width){
			npad=lalign?0:width-ndigits;
			s+=npad;
			dtostrf(value,lalign?-ndigits:ndigits,-exponent+prec-1,s);
			while(npad-- > 0){
				*--s = ' ';
			}
			return s;
		}
	} 
	
	//%f format does not fit to width so we need %e format
	
	*buff='e';
	if(exponent<0){
		exponent=-exponent;
		buff[1]='-';
	} else{
		buff[1]='+';
	}
	if(exponent<10){
		buff[2]='0';
		itoa(exponent, buff+3, 10);
	} else{
		itoa(exponent, buff+2, 10);
	}
	ndigits=strlen(buff);
	reqwidth=prec+ndigits+1+(negative?1:0);
	reqwidth=width<reqwidth?width:reqwidth;
	npad=width-reqwidth;
	s=lalign?s:s+npad;
	dtostrf(negative?-dtmp:dtmp,reqwidth-ndigits,reqwidth-ndigits-2-(negative?1:0),s);
	while(npad-- > 0){
		*--s = ' ';
	}
	strcat(s,buff);
}
