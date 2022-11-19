#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
double Gregory_Leibniz(int32_t num){
    double ans = 4.0;
    bool status = false; // false: negative, true: positive
    if(num == 1) return ans;
    for(int i=2;i<=num;i++){
        double tmp = (double) i*2-1;
        if(status){
            ans += (4.0/tmp);
            status = false;
        }
        else {
            ans -= (4.0/tmp);
            status = true;
        }
        
    }
    return ans;
}
double Nilakantha(int32_t num){
    double ans = 3.0;
    bool status = true; // false: negative, true: positive
    if(num == 1) return ans;
    for(int i=2;i<=num;i++){
        int32_t tmp_idx=i*2;
        int32_t value=(tmp_idx-2)*(tmp_idx-1)*(tmp_idx);
        if(status){
            ans += (4.0/(double)value);
            status = false;
        }
        else {
            ans -= (4.0/(double)value);
            status = true;
        }
    }
    return ans;
}
int main(){
    int32_t num;
    printf("Please enter n (16-bits unsigned): ");
    scanf("%d",&num);
    double ans1 = Gregory_Leibniz(num),ans1_abs=ans1-3.14159265358979323846;
    if(ans1_abs<0) ans1_abs *= -1.0;
    double ans2 = Nilakantha(num),ans2_abs=ans2-3.14159265358979323846;
    if(ans2_abs<0) ans2_abs *= -1.0;
    
    printf("Gregory – Leibniz series: %lf (%lf)\n",ans1,ans1_abs);
    printf("Nilakantha series: %lf (%lf)\n",ans2,ans2_abs);
    
    return 0;
}