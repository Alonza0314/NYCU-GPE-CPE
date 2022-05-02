#include<iostream>
#include<string>
using namespace std;

string input,inverse,output;
int input_length;
int input_index,inverse_index;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(getline(cin,input)&&input!="0"){
        inverse="";
        input_length=input.length();
        for(int i=input_length-1;i>=0;i--){
            inverse+=input[i];
        }
        input_index=0;
        inverse_index=0;
        while(input_index<input_length){
            if(input[input_index]==inverse[inverse_index]){
                inverse_index++;
            }
            else{
                inverse_index=0;
            }
            input_index++;
        }
        output=inverse.substr(inverse_index,inverse.length()-inverse_index+1);
        cout<<input<<output<<"\n";
    }

    return 0;
}