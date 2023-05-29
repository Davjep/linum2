// Programmed by Sven Rönnbäck

#include "libcomponent.h"
#include "libpower.h"
#include "libresistance.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int nArgv, char *pvcArgc[])
{
	printf("Call with arguments <value> <resistors>");
	float fValue = 2020.0f;
	
	if(nArgv>1){
		fValue = atof(pvcArgc[1]);
	}
	int nResistors = 3;
	if(nArgv>2){
		int n = atoi(pvcArgc[2]);
		nResistors = (n>nResistors)?n:nResistors;
	}
	if(nResistors>=3){
		float af[nResistors];

		int nNr = nFindE12resistances(fValue,nResistors,&af[0]);
		if(nNr>0){
			printf("\n\nNumber of E12 resistances %d for %.0f.\n",nNr,fValue);
			float fSum =fCalcResistance('S',nNr,&af[0]);
			printf("Target value is %.0f Ohm.\n",fValue);
			printf("Resistance %.1f is reached with %d components (E12).\n",fSum, nNr);
			for(int n=0;n<nNr;n++){
				printf(" %.1f",af[n]);
			}
			printf("\n\n");
			
			float fVolt = 220.0f;
			printf("(220V AC)\n");
			printf("(U^2/R)=%.2f Watt\n",fCalcPowerR(fVolt,fSum));
			printf("(U*I)=%.2f Watt\n",fCalcPowerI(fVolt,fVolt/fSum));
		}
	}
}


