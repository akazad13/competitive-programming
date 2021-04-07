#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define max 1000010
bool prime[max+10];
vector<int>vec;
int Vsize;

long long int DP[max];


void seive()
{
    for(int i=4;i<=max;i+=2)
        prime[i]=1;
    int srt = sqrt(max);
    for(int i=3;i<=srt;i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=max;j+=2*i)
            {
                prime[j]=1;
            }
        }
    }
    prime[0]=prime[1]=1;

    for(int i=2;i<=max;i++)
    {
        if(prime[i]==0)
        {
            vec.push_back(i);
        }
    }

    Vsize = vec.size();

    //cout<<"seive OK"<<endl;
}

int PI_fun(int n)
{
    if(prime[n]==0)
    {
        //cout<<n-1;
        return n-1;
    }
    int count;
    int res=1;
    for(int i=0;i<=Vsize;i++)
    {
        count=0;
        while(n%vec[i]==0 && n!=1)
        {
            n/=vec[i];
            count++;
        }
        if(count>=1)
            res*=((pow(vec[i],count))-(pow(vec[i],count-1)));

        if(n<=1)
            break;

        if(prime[n]==0)
        {
            res*=(n-1);
            break;
        }
    }
   // cout<<res;

    return res;

}

int main()
{
    //freopen("out.txt","w",stdout);
    seive();

    DP[0]=0;
    DP[1]=0;
    DP[2]=1;

   // cout<<vec[0]<<endl;


    for(int i=3;i<=max-9;i++)
    {
       // cout<<i<<": ";
       DP[i]=DP[i-1]+PI_fun(i);

      // cout<<"\n";


    }

    int n;
    while(cin>>n,n)
    {
        cout<<DP[n]<<endl;
    }




    return 0;
}
