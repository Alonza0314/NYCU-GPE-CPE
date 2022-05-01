#include<iostream>

using namespace std;

int regions,counting;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin>>regions&&regions!=0){
        regions--;
        for(int i=1;i<regions;i++){
            counting=0;
            for(int j=1;j<=regions;j++){
                counting=(counting+i)%j;
            }
            if(counting==11){
                cout<<i<<"\n";
                break;
            }
        }
    }
    return 0;
}