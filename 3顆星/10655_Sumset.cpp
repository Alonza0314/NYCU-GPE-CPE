#include<iostream>
#include<set>
using namespace std;

int s,temp,*arr=nullptr,**record=nullptr;
bool flag;
set<int> setting;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin>>s&&s!=0){
        arr=new int[s];
        record=new int*[s];
        for(int i=0;i<s;i++){
            record[i]=new int[s];
        }
        for(int i=0;i<s;i++){
            cin>>arr[i];
            setting.insert(arr[i]);
        }
        for(int i=s-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                record[i][j]=arr[i]+arr[j];
            }
        }
        flag=true;
        for(int i=s-2;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                for(int k=j-1;k>=0;k--){
                    if(setting.count(arr[i]+record[j][k])){
                        cout<<arr[i]+record[j][k]<<"\n";
                        flag=false;
                        break;
                    }
                }
                if(!flag){
                    break;
                }
            }
            if(!flag){
                break;
            }
        }
        if(flag){
            cout<<"no solution\n";
        }
        setting.clear();
    }

    return 0;
}
