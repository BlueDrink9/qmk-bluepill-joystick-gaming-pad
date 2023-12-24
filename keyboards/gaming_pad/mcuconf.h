#pragma once

#include_next <mcuconf.h>

#undef STM32_ADC_USE_ADC9
#define STM32_ADC_USE_ADC9 TRUE
#undef STM32_ADC_USE_ADC8
#define STM32_ADC_USE_ADC8 TRUE
#undef STM32_ADC_USE_ADC1
#define STM32_ADC_USE_ADC1 TRUE
