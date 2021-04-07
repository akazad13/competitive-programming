#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    bool flag;
    int test;
    scanf("%d",&test);

    for(int i=1;i<=test;i++)
    {
        flag=1;
        for(int j=0;j<13;j++)
        {
            cin>>n;
            if(n==0)
                flag=0;
        }

        printf("Set #%d: ",i);
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
