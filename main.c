#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "api.h"
int main (void){
    char b = getTypeOfAttributeByCoord(1,3);
    int32_t a = getIDOfAttributeByCoord1(1,3);
    int32_t c = getIDOfAttributeByCoord2(1,3);
    printf("%c %d %d\n", b,a,c);
    return 0;
}