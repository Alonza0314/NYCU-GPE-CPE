#include<iostream>
#include<set>
using namespace std;

int testcase,num,answer;
struct unit{
    int x;
    int y;
};
unit*arr=nullptr;
set<float> xielv;
set<float> x_xian;
set<float> y_xian;
set<pair<float,float>> big_pool;
set<pair<float,float>> small_pool;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>testcase;
    for(int t=0;t<testcase;t++){
        cin>>num;
        arr=new unit[num];
        for(int n=0;n<num;n++){
            cin>>arr[n].x>>arr[n].y;
        }
        answer=0;
        for(int i=0;i<num;i++){
            float x1=arr[i].x;
            float y1=arr[i].y;
            if(big_pool.count(make_pair(x1,y1))){
                continue;
            }
            
            for(int j=i+1;j<num;j++){
                float x2=arr[j].x;
                float y2=arr[j].y;
                if(small_pool.count(make_pair(x2,y2))){
                    continue;
                }
                if(x2==x1){
                    if(y2==y1){
                        continue;
                    }
                    if(y_xian.count(x2)){
                        continue;
                    }
                    answer++;
                    y_xian.insert(x2);
                }
                else if(y2==y1){
                    if(x_xian.count(y2)){
                        continue;
                    }
                    answer++;
                    x_xian.insert(y2);
                }
                else{
                    float m=(y2-y1)/(x2-x1);
                    if(xielv.count(m)){
                        continue;
                    }
                    answer++;
                    xielv.insert(m);
                }
                small_pool.insert(make_pair(x2,y2));
            }
            big_pool.insert(make_pair(x1,y1));
            small_pool.clear();
        }
        cout<<answer<<"\n";
        x_xian.clear();
        y_xian.clear();
        xielv.clear();
        small_pool.clear();
        big_pool.clear();
    }

    return 0;
}