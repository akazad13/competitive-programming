#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    int div,digit;
    cin>>test;

    for(int i=1;i<=test;i++)
    {
        scanf("%d %d",&div,&digit);

        int flag=1;
        int mod=0;
        int dgt=0;

        while(flag)
        {
            mod= (mod*10+digit)%div;
            dgt++;
            if(mod==0)
            {
                flag=0;
            }
        }

        printf("Case %d: %d\n",i,dgt);
    }

    return 0;
}
