#include<iostream>

using namespace std;

int total,num;
int *arr=nullptr;
bool *dp=nullptr;

int main(){
    while(cin>>total>>num){
        arr=new int[num];
        dp=new bool[total+1];
        for(int*itt=&arr[0];itt<=&arr[num-1];itt++){
            cin>>*itt;
        }
        dp[0]=false;
        for(int i=1;i<=total;i++){
            dp[i]=false;
            for(int j=0;j<num;j++){
                if(i>=arr[j]&&!dp[i-arr[j]]){
                    dp[i]=true;
                    break;
                }
            }
        }
        cout<<(dp[total] ? "Stan wins\n\n":"Ollie wins\n\n");
    }
    return 0;
}