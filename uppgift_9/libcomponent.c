// Programmed by Sven Rönnbäck

#include "libresistance.h"

int nFindE12resistances( float fOrigResistance, int nMaxResistances, float *pfResArray)
{
	int nResistances=0;
	if(fOrigResistance>0.0f && pfResArray){
		const float afRES[]={100.0f, 120.0f, 150.0f, 180.0f, 220.0f, 270.0f, 330.0f, 390.0f, 470.0f, 560.0f, 680.0f, 820.0f};
	
		float fExp=1000000.0f;
		while((nResistances<nMaxResistances) && (fExp>=0.001f)){
			for (int n=11;n>=0 && nResistances<nMaxResistances;n--){
				float fR = fExp*afRES[n];
				//printf("Test: %f %d\n",fR,nResistances);
				if(fOrigResistance - fR>=0.0f){
					*(pfResArray++) = fR;
					fOrigResistance -= fR;
					nResistances++;
					n++;
				}
			}
			fExp *=0.1f;	
		}
	}
	return nResistances;
}

