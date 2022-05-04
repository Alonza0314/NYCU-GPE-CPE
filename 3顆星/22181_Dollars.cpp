#include<iostream>
#include<string>
#include<cctype>
#define max 30000
using namespace std;

int money_1,money_2;
int arr[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};
long long dp[30000]={1};

int main(){
    for(int*itt=&arr[0];itt<=&arr[10];itt++){
        for(int i=*itt;i<=30000;i++){
            dp[i]+=dp[i-*itt];
        }
    }
    while(scanf("%d.%d",&money_1,&money_2)&&(money_1!=0||money_2!=0)){
        printf("%3d.%02d%17lld\n",money_1,money_2,dp[100*money_1+money_2]);
    }
    return 0;
}