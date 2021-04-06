#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int i=1;i<=test;i++)
    {
        long int num;
        cin>>num;

        bool flag=1;

        if(num%2==1)
        {
            printf("Case %d: Impossible\n",i);
            continue;
        }

        for(int j=2;j<=(num/2);j*=2)
        {
            if((num/j)%2==1)
            {
                printf("Case %d: %ld %ld\n",i,(num/j),j);
                flag=0;
                break;
            }
        }
        if(flag)
            printf("Case %d: Impossible\n",i);
    }

    return 0;
}
