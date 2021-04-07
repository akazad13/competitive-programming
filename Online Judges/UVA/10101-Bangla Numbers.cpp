#include<iostream>
#include<bits/stdc++.h>

#define lld long long int
using namespace std;

int main()
{
    lld num;
    int serial=1;

    while(cin>>num)
    {
        printf("%4d.",serial++);
        if(num==0)
        {
            cout<<" 0\n";
           // serial++;
            continue;
        }
        int n;
        bool flag=0;
        //memset(arr,0,sizeof(arr));
        n=num/100000000000000;
        num=num%100000000000000;

        if(n>0)
            {
                cout<<" "<<n<<" kuti";
                flag=1;
            }

        n=num/1000000000000;
        num=num%1000000000000;

        if(n>0)
            {
                cout<<" "<<n<<" lakh";
                flag=1;
            }

        n=num/10000000000;
        num= num%10000000000;

        if(n>0)
            {
                cout<<" "<<n<<" hajar";
                flag=1;
            }

        n=num/1000000000;
        num = num%1000000000;

        if(n>0)
            {
                cout<<" "<<n<<" shata";
                flag=1;
            }

        n= num/10000000;
        num  =num%10000000;

        if(n>0)
            cout<<" "<<n<<" kuti";
        else if(n==0 && flag==1)
            cout<<" kuti";

        n = num/100000;
        num = num%100000;

        if(n>0)
            cout<<" "<<n<<" lakh";

        n= num/1000;
        num = num%1000;

        if(n>0)
            cout<<" "<<n<<" hajar";

        n= num/100;
        num =  num%100;

        if(n>0)
            cout<<" "<<n<<" shata";

        n=num;

        if(n>0)
            cout<<" "<<n;

        cout<<"\n";
        //serial++;
    }

    return 0;
}
