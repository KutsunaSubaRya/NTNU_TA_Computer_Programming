#include<stdio.h>
#include<stdint.h>
int32_t parseNum(int32_t num){
    int32_t flag=0, arr[15];
    while(num>=10){
        arr[flag++] = num%10;
        num/=10;
    }
    int32_t total = 0;
    arr[flag++] = num;
    total += arr[flag-1];
    printf("%d",arr[flag-1]);
    for(int i=flag-2;i>=0;i--){
        total += arr[i];
        printf(" + %d",arr[i]);
    } printf(" = %d\n",total);
    return total;
}
int main(){
    printf("Please enter a number: ");
    int32_t num;
    if(scanf("%d",&num)){};
    if(!(num<10)){
        while(num>=10){
            num = parseNum(num);
        }
    }
    printf("Final: %d\n",num);
    return 0;
}