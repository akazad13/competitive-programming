#include<iostream>

using namespace std;

int main(){

    int a,b,c,l,count;
    long int divis;

    while(cin>>a>>b>>c>>divis>>l,a|b|c|divis|l){
        count=0;
        for(int i=0;i<=l;i++){

            long int sum=0;
            sum=((a*i*i)%divis)+((b*i)%divis)+(c%divis);

            if(sum%divis==0){
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
