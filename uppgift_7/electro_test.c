#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include <stdio.h>
#include <math.h>

#include "electrotest/libcomponent.h"
#include "electrotest/libpower.h"
#include "electrotest/libresistance.h"

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

void test_component()
{
    float array[3] = {10.0, 20.0, 30.0};
    float result = calc_resistance(3, 'S', array);
    CU_ASSERT_DOUBLE_EQUAL(result, 60.0, 0.0001);

    array[0] = 10.0;
    array[1] = 20.0;
    array[2] = 0.0;
    result = calc_resistance(3, 'P', array);
    CU_ASSERT_DOUBLE_EQUAL(result, 0.0, 0.0001);

    result = calc_resistance(3, 'X', array);
    CU_ASSERT_DOUBLE_EQUAL(result, -1.0, 0.0001);

    result = calc_resistance(3, 'S', NULL);
    CU_ASSERT_DOUBLE_EQUAL(result, -1.0, 0.0001);
}

void test_power()
{

    // Test with positive volt and current values
    float expected = 500.0;
    float result = calc_power_i(10.0, 50.0);
    CU_ASSERT_EQUAL(result, expected);

    // Test with negative volt and current values
    expected = 125.0;
    result = calc_power_i(-5.0, -25.0);
    CU_ASSERT_EQUAL(result, expected);

    // Test with zero current value
    expected = 0.0;
    result = calc_power_i(10.0, 0.0);
    CU_ASSERT_EQUAL(result, expected);

    // Test with zero volt value
    expected = 0.0;
    result = calc_power_i(0.0, 10.0);
    CU_ASSERT_EQUAL(result, expected);

    // Test with positive volt and current values
    expected = 500.0;
    result = calc_power_i(10.0, 50.0);
    CU_ASSERT_EQUAL(result, expected);

    // Test with negative volt and current values
    expected = 125.0;
    result = calc_power_i(-5.0, -25.0);
    CU_ASSERT_EQUAL(result, expected);

    expected = 500.0;
    result = calc_power_i(10.0, 50.0);
    CU_ASSERT_EQUAL(result, expected);

    // Test with NaN values
    result = calc_power_r(NAN, NAN);
    CU_ASSERT(isnan(result));

    // Test with infinity resistance value
    result = calc_power_r(10.0, INFINITY);
    CU_ASSERT_DOUBLE_EQUAL(result, INFINITY, 0.0001);

    result = calc_power_i(1.0e+100, 1.0e-100);
    CU_ASSERT_DOUBLE_EQUAL(result, INFINITY, 0.0001);
}

void test_resistance()
{
    float array1[] = {1.0, 2.0, 3.0};
    float result = calc_resistance(3, 'S', array1);
    CU_ASSERT_DOUBLE_EQUAL(result, 6.0, 0.0001);

    float array2[] = {1.0, 2.0, 3.0, 4.0};
    result = calc_resistance(4, 'S', array2);
    CU_ASSERT_DOUBLE_EQUAL(result, 10.0, 0.0001);

    float array3[] = {1.0, -2.0, 3.0};
    result = calc_resistance(3, 'S', array3);
    CU_ASSERT_DOUBLE_EQUAL(result, NAN, 0.0001);
}

int main()
{
    CU_pSuite pSuite = NULL;
    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }
    pSuite = CU_add_suite("electro_test_suite", init_suite, clean_suite);
    if (pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_add_test(pSuite, "component_test", test_component);
    CU_add_test(pSuite, "power_test", test_power);
    CU_add_test(pSuite, "resistance_test", test_resistance);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    printf("\n");

    CU_cleanup_registry();
    return CU_get_error();
}