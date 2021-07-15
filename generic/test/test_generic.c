#include "unity.h"
#include "generic.h"
#include <stdbool.h>
#include <string.h>


uint8_t next_led(uint8_t current);

/**
 * @brief empty rx buffer
 */
void test_next_led_is_less_than_four()
{
    TEST_ASSERT_EQUAL_INT(0, next_led(3));
}

void test_next_led_handles_a_large_number()
{
    TEST_ASSERT_EQUAL_INT(1, next_led(64));
}
