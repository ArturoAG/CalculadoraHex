#include <stdio.h>
#include <stdlib.h>


int main(){
     unsigned int wps_pin_checksum(unsigned int pin);
    int PIN = 0;
    printf("ComputePIN-C83A35\n");
    printf("Description:\n");
    printf("If your wireless router MAC address start with \"C83A35\",\n");
    printf("type the other six digits, you might be able to get the \n");
    printf("WPS-PIN of this equipment.\n");
    printf("Input MAC Address(HEX):c83a35");
    scanf("%x",&PIN);
    printf("MAC Address(HEX) is: C83A35%X\n",PIN);
    printf("WPS PIN is: %07d%d\n",PIN%10000000,wps_pin_checksum(PIN%10000000));
    return 0;
}
    
unsigned int wps_pin_checksum(unsigned int pin){
    unsigned int accum = 0;
    while (pin){
        accum += 3 * (pin % 10);
        pin /= 10;
        accum += pin % 10;
        pin /= 10;
    }
    return (10 - accum % 10) % 10;
}
