#include<iostream>
#include<stack>
#include<string>
#include<cctype>
using namespace std;

string input;
stack<char> st_punct;
stack<int> st_int;
int num,counting,top_int,temp_1,temp_2,input_length,*arr=nullptr;
char top_punct;

void func(){
    top_punct=st_punct.top();st_punct.pop();
    top_int=st_int.top();st_int.pop();
    if(top_punct=='['){
        for(int *itt=&arr[0];itt<=&arr[num-1];itt++){
            *itt=top_int;
        }
        return;
    }
    if(top_punct=='+'){
        st_punct.pop();
        for(int *itt=&arr[0];itt<=&arr[num-1];itt++){
            if(itt==&arr[0]){
                temp_1=*itt;
                *itt=top_int;
            }
            else{
                temp_2=*(itt-1)+temp_1;
                temp_1=*itt;
                *itt=temp_2;
            }
        }
        return;
    }
    if(top_punct=='*'){
        st_punct.pop();
        for(int *itt=&arr[0];itt<=&arr[num-1];itt++){
            if(itt==&arr[0]){
                *itt=top_int*(*itt);
            }
            else{
                *itt=(*(itt-1))*(*itt);
            }
        }
        return;
    }
}

int main(){
    while(cin>>input>>num){
        input_length=input.length();
        arr=new int[num];
        for(int i=0;i<input_length;i++){
            if(ispunct(input[i])){
                if(input[i]=='['){
                    st_punct.push('[');
                }
                else if(input[i]==']'){
                    func();
                }
                else if(input[i]=='+'){
                    st_punct.push('+');
                }
                else if(input[i]=='*'){
                    st_punct.push('*');
                }
                else if(input[i]=='-'){
                    i++;
                    counting=0;
                    while(isdigit(input[i])){
                        counting=counting*10+input[i]-'0';
                        i++;
                    }
                    i--;
                    st_int.push(-counting);
                }
            }
            else{
                counting=0;
                while(isdigit(input[i])){
                    counting=counting*10+input[i]-'0';
                    i++;
                }
                i--;
                st_int.push(counting);
            }
        }
        for(int *it=&arr[0];it<=&arr[num-1];it++){
            cout<<*it<<" ";
        }
        cout<<"\n";
    }
    return 0;
}