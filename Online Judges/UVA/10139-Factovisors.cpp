#include<iostream>
#include<cmath>

using namespace std;

bool prime[3000006];
int primeList[220000];

//int fact[220000];

void sieve()
{
    int i,j;
    for(i=4;i<=3000000;i+=2)
    {
        prime[i]=1;
    }
    for(i=3;i<=sqrt(3000000);i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=3000000;j+=2*i)
                prime[j]=1;
        }
    }

    prime[1]=1;
}

long long int get_pow(long long int n,int p)
{
    long long int res=0;
    //cout<<p<<endl;
    long long int pow;
    for(pow=p;pow<=n;pow*=p)
        {
            res=res+(n/pow);
           // cout<<res<<" "<<pow<<endl;
        }
    //cout<<"Res: "<<res<<endl;
    return res;
}

int main()
{
    sieve();
    int i,j=0;
    for(i=2;i<=3000000;i++)
    {
        if(prime[i]==0)
            primeList[j++]=i;
    }
    //cout<<primeList[j-1]<<endl;
    long long int m,n,k,count1,count2,count;
    double R;

    while(cin>>n>>m)
    {
        int p=1;
        k=m;
        //cout<<m<<endl;

        for(i=0;primeList[i]<=sqrt(k);i++)
        {

            count1=0;
            count2=0;
            while(k%primeList[i]==0)
            {
                count1++;
                k/=primeList[i];
                //cout<<k<<endl;
            }

           // cout<<"PRIME: "<<primeList[i]<<" count1: "<<count1<<endl;

            if(count1>0){
                    count2=get_pow(n,primeList[i]);
            }

          // cout<<"count2 : "<<count2<<endl;
          //cout<<"count1: "<<count1<<" count2: "<<count2<<endl;

            if(count1>count2)
            {
                p=0;
                break;
            }



        }

        if(k>1)
        {
            count=get_pow(n,k);
            if(count==0)
                p=0;
        }

        if(p)
            cout<<m<<" divides "<<n<<"!"<<endl;
        else
            cout<<m<<" does not divide "<<n<<"!"<<endl;

    }
    return 0;
}
