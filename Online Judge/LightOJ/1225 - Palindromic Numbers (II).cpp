#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    cin>>test;

    for(int i=1;i<=test;i++)
    {
        char str[12];
        scanf(" %s",str);

        int flag=1;

        int l=strlen(str);

        for(int k=0;k<=(l/2);k++)
        {
            if(str[k]!=str[l-k-1])
            {
                flag=0;
                break;
            }
        }

        if(flag)
            printf("Case %d: Yes\n",i);
        else
            printf("Case %d: No\n",i);
    }
    return 0;
}
