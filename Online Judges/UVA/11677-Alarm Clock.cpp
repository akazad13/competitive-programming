#include<iostream>

using namespace std;

int main(){
    int h1,m1,h2,m2;

    while(cin>>h1>>m1>>h2>>m2,h1|m1|h2|m2){
        int alarm=h2*60+m2;
        int current=h1*60+m1;

        if(alarm>=current){
            cout<<alarm-current<<endl;
        }
        else{
            cout<<(alarm+1440)-current<<endl;
        }
    }
    return 0;
}
