#include <stdio.h>
#include <stdlib.h>

#include "libresistance.h"
#include "libpower.h"
#include "libcomponent.h"


int main(int argc, char** argv)
{
    char input_buf[8];
    char* input;

    printf("Ange spänningskälla i V: ");
    float volt = atof( fgets(input_buf, 8, stdin) );

    printf("Ange koppling[S | P]: ");
    char conn = fgets(input_buf, 8, stdin)[0];

    printf("Antal komponenter: ");
    int count = atoi( fgets(input_buf, 8, stdin) );
    float* res_array = (float*) calloc(count, sizeof(float));
    for (int i = 0; i < count; ++i) {
        printf("Komponent %d i ohm: ", i + 1);
        res_array[i] = atof( fgets(input_buf, 8, stdin) );
    }

    float resistance = calc_resistance(count, conn, res_array);
    printf("Ersättningsresistans:\n%.1f ohm\n", resistance);

    free(res_array);

    float p = calc_power_r(volt, resistance);
    printf("Effekt: %.2f W\n", p);

    printf("Ersättningsresistanser i E12-serien kopplade i serie:\n");

    res_array = (float*) calloc(3, sizeof(float));

    int num_of_res = e_resistance(resistance, res_array);
    for(int i = 0; i < num_of_res; i++) {
      printf("%.0f\n", res_array[i]);
    }

    free(res_array);

    return 0;
}
