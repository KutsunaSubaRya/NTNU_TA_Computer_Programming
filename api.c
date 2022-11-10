#include "basic.h"
#include "api.h"
int32_t getBossRequiringPoint(void){
    return bossPoint;
}
char getTypeOfAttributeByCoord(int32_t x, int32_t y){
    return MapInfo[x][y].artifactType;
}
int32_t getIDOfAttributeByCoord1(int32_t x, int32_t y){
    return MapInfo[x][y].artifactAttributeID1;
}
int32_t getIDOfAttributeByCoord2(int32_t x, int32_t y){
    return MapInfo[x][y].artifactAttributeID2;
}