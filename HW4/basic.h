#ifndef BASIC_H
#define BASIC_H
#include<stdint.h>
static int32_t bossPoint = 1055;
static int32_t TypeOfAttribute[5][5]={
    {0,3,1,2,6},
    {1,5,1,4,7},
    {4,1,6,1,4},
    {7,6,1,7,2},
    {6,4,4,1,8}
};
static int32_t AttributeID1[5][5]={
    {0,1,1,1,1},
    {7,2,1,2,1},
    {5,1,1,3,5},
    {5,4,3,4,1},
    {1,1,5,4,0}
};
static int32_t AttributeID2[5][5]={
    {0,2,3,4,4},
    {6,1,6,1,3},
    {6,2,7,1,2},
    {3,6,5,1,4},
    {4,7,2,6,0}
};
#endif