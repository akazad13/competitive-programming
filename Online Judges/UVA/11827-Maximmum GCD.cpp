#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int GrCD(int a , int b)
{
    if(a%b==0)
        return b;
    return GrCD(b,a%b);
}

int main()
{
    int test,maxGCD,i,j,k,GCD;
    //int a[99];
    char str[1000];
    int a[100];
    scanf("%d\n",&test);
    while(test--)
    {
        gets(str);
        i=0,j=0;
        while(str[i])
        {
            a[j] = 0;
            while(str[i] && str[i]!=' ')
                a[j] = a[j]*10 + str[i++]-'0';
            while(str[i]==' ')
                i++;
            j++;
        }
        maxGCD=0;
        for(i=0;i<j-1;i++)
        {
            for(k=i+1;k<j;k++)
            {
                GCD=GrCD(a[i],a[k]);

                if(GCD>maxGCD)
                    maxGCD=GCD;

            }
        }
        printf("%d\n",maxGCD);
    }
    return 0;
}

