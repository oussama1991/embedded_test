#include "unity.h"
#include "tempSensor.h"
#include "mock_i2c.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_tempSensor_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement tempSensor");
}

void test_whenTempRegisterReadsMaxValue_thenTheTempIsTheMaxValue(void)
{
    uint8_t tempRegisterAddress = 0x03;
    float expectedTemperature = 104.6f;
    float tolerance = 0.1f;

    //When
    i2c_readRegister_ExpectAndReturn(tempRegisterAddress, 0x3ff);

    //Then
    float actualTemperature = tempSensor_getTemperature();
    TEST_ASSERT_FLOAT_WITHIN(tolerance, expectedTemperature, 
        actualTemperature);
}
