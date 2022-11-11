#ifndef API_H
#define API_H
#include<stdint.h>
// --- for my simplicity, generate example code will be UGLY hardcode. ><  --- 
int32_t bossPoint = 1055;
struct gridInfo{
    int32_t artifactType;
    int32_t artifactAttributeID1;
    int32_t artifactAttributeID2;
};
struct gridInfo MapInfo[5][5]={
    {{0,0,0},{3,1,2},{1,1,3},{2,1,4},{6,1,4}},
    {{1,7,6},{5,2,1},{1,1,6},{4,2,1},{7,1,3}},
    {{4,5,6},{1,1,2},{6,1,7},{1,3,1},{4,5,2}},
    {{7,5,3},{6,4,6},{1,3,5},{7,4,1},{2,1,4}},
    {{6,1,4},{4,1,7},{4,5,2},{1,4,6},{8,0,0}}
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