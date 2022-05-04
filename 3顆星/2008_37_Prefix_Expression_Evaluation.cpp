#include<iostream>
#include<string>
#include<stack>
#include<cctype>
using namespace std;

string input;
char opera,*temp;
int input_length,a,b,counting;
bool flag;
stack<int> st_int;

void func(char ope){
    a=st_int.top();st_int.pop();
    b=st_int.top();st_int.pop();
    if(ope=='+'){
        st_int.push(a+b);
        return;
    }
    if(ope=='-'){
        st_int.push(a-b);
        return;
    }
    if(ope=='*'){
        st_int.push(a*b);
        return;
    }
    if(ope=='/'){
        st_int.push(a/b);
        return;
    }
    if(ope=='%'){
        st_int.push(a%b);
        return;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(getline(cin,input)&&input!="."){
        input_length=input.length();
        flag=true;
        for(char *itt=&input[input_length-1];itt>=&input[0];itt--){
            if(isdigit(*itt)){
                temp=itt;
                while(!isspace(*temp)){
                    temp--;
                }
                temp++;
                counting=0;
                for(;temp<=itt;temp++){
                    counting=counting*10+(*temp-'0');
                }
                st_int.push(counting);
                while(!isspace(*itt)){
                    itt--;
                }
            }
            else if(ispunct(*itt)){
                if(st_int.size()<2){
                    flag=false;
                    break;
                }
                else{
                    func(*itt);
                }
            }
            else{
                continue;
            }
        }
        if(!flag){
            cout<<"illegal\n";
        }
        else{
            cout<<st_int.top()<<"\n";
            st_int.pop();
        }
    }
    return 0;
}