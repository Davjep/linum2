#include <stdio.h>
#include "libresistance.h"

float calc_resistance(int count, char conn, float *array)
{
    float r = 0.0;
    if (array == 0 || count < 0 || !(conn == 'S' || conn == 'P')) {
        return -1;
    }
    if (conn == 'S') {
        for (int i=0; i<count; ++i) {
            r += array[i];
        }
    }
    if (conn == 'P') {
        for (int i=0; i<count; ++i) {
            if (array[i] == 0) {
                return 0;
            }
            r += 1 / array[i];
        }
        r = 1 / r;
    }
    return r;
}
