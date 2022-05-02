#include<iostream>

int input,level,step,sum,counting,indexi,direct_counting,direct,x,y;
struct unit{
    int x_;
    int y_;
    bool exist=false;
}*arr=new unit[100000];

void zuoxia(){
    x--;
    y++;
}
void zuoshang(){
    x--;
}
void shang(){
    y--;
}
void youshang(){
    x++;
    y--;
}
void youxia(){
    x++;
}
void xia(){
    y++;
}

int main(){
    while(std::cin>>input){
        input--;
        if(input==0){
            std::cout<<"0 0\n";
            continue;
        }
        if(arr[input].exist){
            std::cout<<arr[input].x_<<" "<<arr[input].y_<<"\n";
            continue;
        }
        counting=0;
        sum=0;
        while(sum<input){
            sum+=6*counting;
            counting++;
        }
        level=counting-1;
        counting=0;
        while(counting<level){
            input-=6*counting;
            counting++;
        }
        step=input%(6*level);
        x=level;
        y=0;
        counting=0;
        direct_counting=0;
        direct=0;
        indexi=6*(level-1)+1;
        while(counting<step){
            switch(direct){
                case 0:{
                    zuoxia();
                    break;
                }
                case 1:{
                    zuoshang();
                    break;
                }
                case 2:{
                    shang();
                    break;
                }
                case 3:{
                    youshang();
                    break;
                }
                case 4:{
                    youxia();
                    break;
                }
                case 5:{
                    xia();
                    break;
                }
                default:{}
            }
            direct_counting=(direct_counting+1)%level;
            if(direct_counting==0){
                direct=(direct+1)%6;
            }
            counting++;
            arr[indexi].exist=true;
            arr[indexi].x_=x;
            arr[indexi].y_=y;
            indexi++;
        }
        std::cout<<x<<" "<<y<<"\n";
    }
    return 0;
}