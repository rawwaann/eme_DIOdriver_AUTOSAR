#include "dio.h"
#include "std_types.h"

void portF_init(void)
{
    SYSCTL_RCGCGPIO_R  |= (1<<5);
    while(SYSCTL_RCGCGPIO_R&(1<<5)  ==0  ){}
    GPIO_PORTF_LOCK_R =0x4c4f434b;
    GPIO_PORTF_CR_R  =0x1f;
}

void configure_leds_switches(void) {
    GPIO_PORTF_DIR_R = 0x0E;
    GPIO_PORTF_PUR_R=0x11;
    GPIO_PORTF_DEN_R = 0x1f;
}

int main(void)
{
    portF_init();
    configure_leds_switches();
    while(1)
    {
        Dio_WriteChannel(40,STD_HIGH);  //blue
    }
    return 0;
}
