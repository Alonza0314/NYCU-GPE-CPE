#include<iostream>
using namespace std;

int num,answer,*arr=nullptr,*dp=nullptr;

int main(){
    while(cin>>num){
        arr=new int[num];
        dp=new int[num];
        for(int i=0;i<num;i++){
            cin>>arr[i];
            dp[i]=0;
        }
        answer=0;
        for(int i=0;i<num;i++){
            for(int j=i-1;j>=0;j--){
                if(arr[i]>arr[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                    answer=max(answer,dp[i]);
                }
            }
        }
        cout<<answer+1<<"\n";
    }

    return 0;
}