#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

#define max 1000000
#define lld long long int
bool prime[max+10];


void sieve()
{
    int i,j;
    for(i=4;i<=max;i+=2)
        prime[i]=1;

    long long int s=sqrt(max);
    for(i=3;i<=s;i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=max;j+=2*i)
            {
                prime[j]=1;
            }
        }
    }
    prime[1]=prime[0]=1;
}

int main()
{
    sieve();

    lld num;

    while(cin>>num)
    {
        if(num==0)
            continue;
        lld n = (2<<(num-1))-1;

        int sqt = sqrt(n);
       // cout<<n<<endl;

       int flag=1;
       if(n%2==0)
        flag=0;
       else
       {
           for(int i=3;i<=sqt;i+=2)
           {
                if(prime[i]==0)
                {
                    if(n%i==0)
                    {
                          flag=0;
                          break;
                    }
                }
           }
       }



       if(flag)
       {
           lld res = (2<<(num-2));
           res*=n;
          // cout<<"Perfect: "<<((2<<(num-2))*n)<<"!\n";
          cout<<"Perfect: "<<res<<"!\n";
       }
       else
       {
           if(prime[num]==0)
            printf("Given number is prime. But, NO perfect number is available.\n");
           else
            printf("Given number is NOT prime! NO perfect number is available.\n");
       }
    }

    return 0;
}
