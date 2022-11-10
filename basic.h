#ifndef BASIC_H
#define BASIC_H
#include<stdint.h>
#define A1 artifactAttributeID1
#define A2 artifactAttributeID2
#define AT artifactType
// for simplicity, my generate example code will be UGLY hardcode. >< 
int32_t bossPoint = 100;
struct gridInfo{
    char artifactType;
    int32_t artifactAttributeID1;
    int32_t artifactAttributeID2;
};

struct gridInfo MapInfo[7][7]={
    {{'A',1,2},{'A',1,2},{'A',1,2},{'A',1,2},{'A',1,2},{'A',1,2}},
    {{'A',1,2},{'A',1,2},{'A',1,2},{'A',1,2},{'A',1,2},{'A',1,2}},
    {{'A',1,2},{'A',1,2},{'A',1,2},{'A',1,2},{'A',1,2},{'A',1,2}},
    {{'A',1,2},{'A',1,2},{'A',1,2},{'A',1,2},{'A',1,2},{'A',1,2}},
    {{'A',1,2},{'A',1,2},{'A',1,2},{'A',1,2},{'A',1,2},{'A',1,2}},
    {{'A',1,2},{'A',1,2},{'A',1,2},{'A',1,2},{'A',1,2},{'A',1,2}}
};

#endif