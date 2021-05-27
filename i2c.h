#include <16F1459.h>
#device ADC=10

#FUSES NOWDT                    //No Watch Dog Timer

#use delay(internal=16MHz,USB_FULL)

#define USB_CONFIG_BUS_POWER 500
#include <usb_cdc.h>

#use i2c(Master,Fast,sda=PIN_B4,scl=PIN_B6,force_sw)
