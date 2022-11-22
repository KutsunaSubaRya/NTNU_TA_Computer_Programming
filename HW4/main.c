#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "basic.h"
int32_t twoPieceSetPointList[8] = {0,10,20,35,50,60,75,100};
int32_t fourPieceSetPointList[8] = {0,160,150,75,135,125,95,110};
int32_t attributeIDList[8] = {0,125,100,75,50,50,25,10};
int32_t tmpCombinationType[7],tmpCombinationID1[7],tmpCombinationID2[7];
int32_t combinationListType[70][7],combinationListID1[70][7],combinationListID2[70][7];
int32_t idList[1500][3][5],tmpidList[3][7],flagOfIdList=0;
int32_t _num = 0;
int32_t idxIdList = 0;
// equip[0] = {Type}
// equip[1] = {ID1}
// equip[2] = {ID2}
void setUp(int32_t mapType[5][5], int32_t mapID1[5][5], int32_t mapID2[5][5]){
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            mapType[i][j] = TypeOfAttribute[i][j];
            mapID1[i][j] = AttributeID1[i][j];
            mapID2[i][j] = AttributeID2[i][j];
        }
    }
}
int32_t calculateTwoPieceSetPoint(int32_t arr[5]){
    int32_t list[8]={0}, twoPieceSetPoint=0;
    for(int32_t i=0;i<5;++i){
        ++list[arr[i]];
    }
    for(int32_t i=1;i<=7;++i){
        if(list[i]>=4 || list[i]<2){
            continue;
        }
        else{
            twoPieceSetPoint+=twoPieceSetPointList[i];
        }
    }
    return twoPieceSetPoint;
}
int32_t calculateFourPieceSetPoint(int32_t arr[5]){
    int32_t list[8]={0}, fourPieceSetPoint=0;
    for(int32_t i=0;i<5;++i){
        ++list[arr[i]-1];
    }
    for(int32_t i=1;i<=7;++i){
        if(list[i]>=4){
            fourPieceSetPoint+=fourPieceSetPointList[i];
        }
    }
    return fourPieceSetPoint;
}
int32_t calculateTotalPoint(int32_t equip[3][5]){
    int32_t totalPoint = calculateTwoPieceSetPoint(equip[0]) + calculateFourPieceSetPoint(equip[0]);
    for(int i=0;i<5;++i){
        totalPoint += (attributeIDList[equip[1][i]]+attributeIDList[equip[2][i]]);
    }
    return totalPoint;
}
void storeTotalPointList(int32_t totalPointList[1500], int32_t totalPoint){
    totalPointList[idxIdList]=totalPoint;
}
void cpy2DArray(int32_t tmp[3][5], int32_t equip[3][5]){
    for(int32_t i=0;i<3;++i){
        for(int32_t j=0;j<5;++j){
            tmp[i][j]=equip[i][j];
        }
    }
}
void enumerateAllPath(int32_t x, int32_t y, int32_t idx, int32_t mapType[5][5], int32_t mapID1[5][5], int32_t mapID2[5][5]){
    if(x==y && x==4){ // Boss point
        for(int i=0;i<7;i++){
            combinationListType[_num][i] = tmpCombinationType[i];
            combinationListID1[_num][i] = tmpCombinationID1[i];
            combinationListID2[_num][i] = tmpCombinationID2[i];
        }
        ++_num;
        return;
    }
    if(x==5 || y==5){ // 撞牆
        return;
    }
    if(mapType[x][y]!=0){
        tmpCombinationType[idx]=mapType[x][y];
        tmpCombinationID1[idx]=mapID1[x][y];
        tmpCombinationID2[idx]=mapID2[x][y];
        ++idx;
    }
    // move right
    enumerateAllPath(x,y+1,idx,mapType,mapID1,mapID2);
    // move down
    enumerateAllPath(x+1,y,idx,mapType,mapID1,mapID2);
}
void getAllCombination(int32_t idx, int32_t _start,int32_t x){
    if(idx == 5){
        for(int32_t i=0;i<5;i++){
            idList[flagOfIdList][0][i]=tmpidList[0][i];
            idList[flagOfIdList][1][i]=tmpidList[1][i];
            idList[flagOfIdList][2][i]=tmpidList[2][i];
        }
        flagOfIdList++;
        return;
    }
    for(int32_t i=_start;i<7;++i){
        
        tmpidList[0][idx]=combinationListType[x][i];
        tmpidList[1][idx]=combinationListID1[x][i];
        tmpidList[2][idx]=combinationListID2[x][i];
        // printf("A: %d ",combinationListType[x][i]);
        // printf("%d ",combinationListID1[x][i]);
        // printf("%d \n",combinationListID2[x][i]);
        getAllCombination(idx+1, i+1, x);
        tmpidList[0][idx]=0;
        tmpidList[1][idx]=0;
        tmpidList[2][idx]=0;
    }
}
int main (void){
    int32_t mapType[5][5],mapID1[5][5],mapID2[5][5],totalPointList[1500];
    setUp(mapType,mapID1,mapID2);
    enumerateAllPath(0,0,0,mapType,mapID1,mapID2);
    for(int32_t x=0;x<70;x++){
        getAllCombination(0,0,x);
    }
    for(int32_t i=0;i<flagOfIdList;++i){
        totalPointList[i] = calculateTotalPoint(idList[i]);
    }
    for(int32_t i=0;i<flagOfIdList;++i){
        for(int32_t j=0;j<flagOfIdList-1-i;++j){
            if(totalPointList[j]<totalPointList[j+1]){
                // swap Total Point
                int tmp = totalPointList[j];
                totalPointList[j]=totalPointList[j+1];
                totalPointList[j+1]=tmp;
                // swap five
                for(int k=0;k<5;++k){
                    // swap type, ID1, ID2
                    for(int32_t m=0;m<3;++m){
                        int tmp1 = idList[j][m][k];
                        idList[j][m][k] = idList[j+1][m][k];
                        idList[j+1][m][k] = tmp1;
                    }
                }
            }
        }
    }
    
    // for(int32_t i=0;i<flagOfIdList;++i){
    //     int32_t flag=0;
    //     printf("Total Point: %d. Five equipment: %d %d %d %d %d.\n",totalPointList[i], idList[i][0][0], idList[i][0][1], idList[i][0][2], idList[i][0][3], idList[i][0][4]);
        // for(int32_t j=0;j<5;j++)
        //     printf("artifact attribute %d: %d %d\n", ++flag, idList[i][1][j], idList[i][2][j]);
    // }

    printf("1st Top Total Point: %d. Type of five Artifacts: %d %d %d %d %d.\n",totalPointList[0], idList[0][0][0], idList[0][0][1], idList[0][0][2], idList[0][0][3], idList[0][0][4]);
    printf("2nd Top Total Point: %d. Type of five Artifacts: %d %d %d %d %d.\n",totalPointList[1], idList[1][0][0], idList[1][0][1], idList[1][0][2], idList[1][0][3], idList[1][0][4]);
    printf("3rd Top Total Point: %d. Type of five Artifacts: %d %d %d %d %d.\n",totalPointList[2], idList[2][0][0], idList[2][0][1], idList[2][0][2], idList[2][0][3], idList[2][0][4]);
    int requiredPoint = bossPoint;
    printf("Target Boss required point: %d\n",requiredPoint);
    if(totalPointList[2] >= requiredPoint){
        printf("Ready Perfectly!\n");
    }
    else{
        printf("Gonna be OK.\n");
    }
    return 0;
}