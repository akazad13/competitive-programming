#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int Bank, query;

    while(cin>>Bank>>query,Bank|query)
    {
        int Bank_money[50],money;

        for(int i=1;i<=Bank;i++)
        {
            cin>>money;
            Bank_money[i]=money;
        }

        int D,C,V;

        for(int i=0;i<query;i++)
        {
            cin>>D>>C>>V;
            Bank_money[D]-=V;
            Bank_money[C]+=V;
        }

        int flag=1;

        for(int i=1;i<=Bank;i++)
        {
            if(Bank_money[i]<0)
            {
                flag=0;
                break;
            }
        }

        if(flag)
            printf("S\n");
        else
            printf("N\n");


    }
    return 0;
}
