/**
  *
  */
#include "generic.h"

uint8_t next_led(uint8_t current)
{
    return ++current % 4;
}