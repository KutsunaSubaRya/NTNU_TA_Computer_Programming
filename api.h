#ifndef API_H
#define API_H
#include<stdint.h>
// --- for my simplicity, generate example code will be UGLY hardcode. ><  --- 
int32_t bossPoint = 1075;
struct gridInfo{
    int32_t artifactType;
    int32_t artifactAttributeID1;
    int32_t artifactAttributeID2;
};
struct gridInfo MapInfo[5][5]={
    {{0,0,0},{1,1,2},{2,1,2},{3,1,2},{4,1,2}},
    {{1,3,2},{1,3,2},{1,3,2},{1,3,2},{1,3,2}},
    {{1,4,2},{1,4,2},{1,4,2},{1,4,2},{1,4,2}},
    {{1,6,2},{1,6,2},{1,6,2},{1,6,2},{1,6,2}},
    {{1,1,2},{1,1,2},{1,1,2},{1,1,2},{8,0,0}}
};
// ---------------------------------------------------------------------------
int32_t getBossRequiringPoint(void){
    return bossPoint;
}
int32_t getTypeOfAttributeByCoord(int32_t x, int32_t y){
    return MapInfo[x][y].artifactType;
}
int32_t getIDOfAttributeByCoord1(int32_t x, int32_t y){
    return MapInfo[x][y].artifactAttributeID1;
}
int32_t getIDOfAttributeByCoord2(int32_t x, int32_t y){
    return MapInfo[x][y].artifactAttributeID2;
}
#endif