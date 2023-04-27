#include "libcomponent.h"

const int sizeOfESeries = 12;
const float eSeries[12] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2};

int e_resistance(float orig_resistance, float *res_array){
	int count = 0;
	float valueResistor = 0;
	float resistance = orig_resistance;

	while((count < 3 )&&(resistance >= 1)){
		valueResistor = find_largest_res(resistance);
		res_array[count] = valueResistor;
		resistance -= valueResistor;
		count++;
	}
	return count;
}

float find_largest_res(float resistance){
	float largestResistor = 0;
	int tens = power_of_ten(resistance);
	resistance /= tens;
	for(int i = sizeOfESeries-1; i >= 0; i--){
		if(resistance / eSeries[i] >= 1){
			largestResistor = eSeries[i];
	      		break;
    		}
  	}
	return largestResistor * tens;
}

int power_of_ten(float resistance){
	int power = 0;
	int tens = 1;
	while(resistance >= 10){
		resistance /= 10;
		power += 1;
	}
	for(int i = 0;i < power; i++){
		tens *= 10;
	}
	return tens;
}
