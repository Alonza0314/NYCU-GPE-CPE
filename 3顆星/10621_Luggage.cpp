#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

int testcase,temp,sum;
string line;
vector<int> vec;
stringstream string_to_int;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>testcase;
    getline(cin,line);
    for(int t=0;t<testcase;t++){
        getline(cin,line);
        string_to_int<<line;
        sum=0;
        while(string_to_int>>temp){
            vec.push_back(temp);
            sum+=temp;
        }
        if(sum%2!=0){
            cout<<"No\n";
            continue;
        }
        vector<bool> dp(sum+1,false);
        dp[0]=true;
        for(int i=0;i<vec.size();i++){
            for(int j=sum;j>=vec[i];j--){
                if(dp[j-vec[i]]){
                    dp[j]=true;
                }
            }
        }
        cout<<(dp[sum/2] ? "YES":"NO")<<"\n";
    }

    return 0;
}