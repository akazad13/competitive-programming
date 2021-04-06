#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int i,j,t,k;

    long long int arr[30],n;

    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    arr[3]=6;
    for(i=4;i<=20;i++)
    {
        arr[i]=arr[i-1]*i;
    }

    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        int a[30];
        for(j=0;j<30;j++)
            a[j]=0;
        k=1;
        scanf("%lld",&n);

        for(j=20;j>=0;j--)
        {
            if(n>=arr[j])
            {
                a[j]++;
                n-=arr[j];
            }
        }

        printf("Case %d: ",i);

        if(n==0)
        {

            for(j=0;j<=20;j++)
            {
                if(a[j]==1)
                {
                    if(k==1)
                    {
                        printf("%d!",j);
                        k=0;
                    }
                    else
                        printf("+%d!",j);
                }
            }
        }

        else
            printf("impossible");

        printf("\n");
    }

    return 0;
}

