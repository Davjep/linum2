// Programmed by Sven Rönnbäck

#include "libpower.h"
#include <math.h>

float fCalcPowerR(float fVolt, float fResistance)
{
	float fPower = NAN;
	if(fResistance>0.0f){
		fPower=(fVolt*fVolt)/fResistance;
	}
	return fPower;
}


float fCalcPowerI(float fVolt, float fCurrent)
{
	float fPower = fVolt*fCurrent;
	fPower = fabs( fPower);
	return fPower;
}	

