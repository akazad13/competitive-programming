#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros
#define read(a) scanf("%d",&a)
#define CLEAR(a,b) memset(a,b,sizeof(a))
#define VI(a) vector<a>

#define lld long long int
#define ulld unsigned long long int
#define PI acos(-1.0)
#define Gamma 0.5772156649015328606065120900824024310421

int main()
{
    //freopen("outt.txt","w",stdout);
    int test,m,n;

    read(test);

    for(int Case = 1; Case<=test; Case++)
    {
        read(m);read(n);

        printf("Case %d: ",Case);

        if(m*n==1)
            printf("1\n");
        else if(m*n==2)
            printf("2\n");
        else if(m*n==4)
            printf("4\n");
        else if(n==1)
            printf("%d\n",m);
        else if(m==1)
            printf("%d\n",n);
        else if(m*n==6)
            printf("4\n");
        else if(m==2 || n==2)
        {
            if(m==2)
            {
                int res = n/4;
                int rem = n%4;
                res=res*2;
                if(rem==1)
                    res++;
                else if(rem==2 || rem==3)
                    res+=2;
                res=res*2;
                printf("%d\n",res);
            }
            else
            {
                int res = m/4;
                int rem = m%4;
                res=res*2;
                if(rem==1)
                    res++;
                else if(rem==2 || rem==3)
                    res+=2;
                res=res*2;
                printf("%d\n",res);
            }
        }
        else
        {
            int cal1 = n/2;
            int rem1 = n%2;
            int temp = 2*cal1+rem1;

            int cal2 = m/2;
            int rem2 = m%2;

            temp = temp*(cal2)+rem2*(cal1+rem1);
            printf("%d\n",temp);
        }
    }
    return 0;
}


