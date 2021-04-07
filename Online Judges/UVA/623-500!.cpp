#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,i;
    int a[1001][20000];
        a[1][0]=1;
        int index = 0;
    for(int fact=1;fact<=1000;fact++)
    {

        for(;n>=2;n--)
        {
            int temp = 0;
            for(i=0;i<=index;i++)
            {
                temp = (a[fact][i]*n)+temp;
                a[fact][i] = temp%10;
                temp = temp/10;
            }
            while(temp>0)
            {
                a[fact][++index] = temp%10;
                temp/=10;
            }
        }
    }
    while(cin>>n)
    {
        printf("%d!\n",n);

        int len= strlen(a[n]);

        for(i=len-1;i>=0;i--)
        {
            printf("%d",a[n][i]);
        }

        printf("\n");
    }
return 0;
}

