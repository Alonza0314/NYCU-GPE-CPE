#include<iostream>
#include<cctype>
#include<string>
#include<vector>
using namespace std;

vector<string> vec;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string input;

    while(getline(cin,input)){
        if(input[0]=='0'){
            break;
        }
        int length=input.length();
        for(int i=0;i<length;i++){
            if(isalpha(input[i])){
                string output="";
                while(isalpha(input[i])){
                    output+=input[i];
                    i++;
                }
                i--;
                vec.insert(vec.begin(),output);
                cout<<output;
            }
            else if(isdigit(input[i])){
                int num=0;
                while(isdigit(input[i])){
                    num=num*10+input[i]-'0';
                    i++;
                }
                i--;
                string output=vec[num-1];
                vec.erase(vec.begin()+num-1);
                vec.insert(vec.begin(),output);
                cout<<output;
            }
            else{
                cout<<input[i];
            }
        }
        cout<<"\n";
    }

    return 0;
}