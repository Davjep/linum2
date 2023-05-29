// Programmed by Sven Rönnbäck

#include "libresistance.h"
#include <ctype.h>
#include <math.h>

float fCalcResistance(char cType, unsigned int uCount, float *pfArray)
{
	float fOhm = -1.0f;
	if(pfArray && uCount>0){
		fOhm=0.0f;
		switch( toupper(cType))
		{
			case 'S':
				while(uCount-- >0){
					fOhm += *(pfArray++);
				}
				break;
			
			case 'P':
				while(uCount-->0){
					float f= *(pfArray++);
					if(f==0.0){
						fOhm = 0.0f;
						break;
					}
					else if(f<0.0f){
						fOhm = -1.0f;
						break;
					}
					fOhm += 1.0f/f;
				}
				if(fOhm>0.0f){
					fOhm = 1.0f/fOhm;
				}
				break;
				
			default:
				fOhm = -1.0f;
				break;
		}
	}
	return fOhm;
}



