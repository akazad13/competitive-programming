#include<iostream>
#include<cstdio>


using namespace std;

int main()
{
    int test;

    long int m,n,x,y;
    cin>>test;

    for(int i=1;i<=test;i++)
    {
        cin>>m;
        n=m;

        while(n>=10)
        {
            y=0;
            while(n>0)
            {
                x=n%10;
                y=y+x*x;
                n=n/10;
            }
            n=y;
        }
        if(n==1||n==7)
            printf("Case #%d: %ld is a Happy number.\n",i,m);
        else
            printf("Case #%d: %ld is an Unhappy number.\n",i,m);

    }
    return 0;
}
