#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int b1,b2,b3,g1,g2,g3,c1,c2,c3;

    long long int arr[10];
    string str[]={
        "BCG","BGC","CBG","CGB","GBC","GCB"
    };

    while(scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3)==9)
    {
        arr[0]=b2+b3+c1+c3+g1+g2;
        arr[1]=b2+b3+g1+g3+c1+c2;
        arr[2]=c2+c3+b1+b3+g1+g2;
        arr[3]=c2+c3+g1+g3+b1+b2;
        arr[4]=g2+g3+b1+b3+c1+c2;
        arr[5]=g2+g3+c1+c3+b1+b2;

        long long int min=99999999999999999;

        for(int i=0;i<6;i++)
        {
            if(min>arr[i])
                    min=arr[i];
        }

        for(int i=0;i<6;i++)
        {
            if(min==arr[i])
            {
                cout<<str[i]<<" "<<min<<"\n";
                break;

            }
        }

    }
    return 0;
}
