#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

bool sieve[46350];
int primeList[4800];

void prime()
{
    int i,j;
    for(i=4;i<=46345;i+=2)
        sieve[i]=1;
    for(i=3;i<=215;i+=2)
    {
        if(sieve[i]==0)
        {
            for(j=i*i;j<=46345;j+=2*i)
            {
                sieve[j]=1;
            }
        }
    }
    sieve[1]=1;
}


int main()
{
   // freopen("test.txt","w",stdout);
    prime();
    int j=0,i;
    for(i=1;i<=46345;i++)
    {
        if(sieve[i]==0)
        {
            primeList[j++]=i;
        }

    }


    long long int num;
    int p;

    while(cin>>num,num)
    {
        p=0;
        cout<<num<<" =";
        if(num<0)
        {
            cout<<" -1";
            p=1;
            num=abs(num);
        }
        for(i=0;i<j&&num!=1&&(primeList[i]*primeList[i])<=num;i++){
            if(num%primeList[i]==0)
            {

                if(p==0)
                {
                    cout<<" "<<primeList[i];
                    p++;
                }
                else
                {
                    cout<<" x "<<primeList[i];
                }

                num=num/primeList[i];
                i=-1;
                //cout<<"\n9num= "<<num<<" "<<endl;

            }
        }
        if(p>0&&num>1)
            cout<<" x "<<num;
        else if(p==0&&num>1)
            cout<<" "<<num;
        cout<<"\n";
    }
    return 0;
}
