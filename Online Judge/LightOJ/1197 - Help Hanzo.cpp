
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros

#define READ(a) scanf("%d",&a)
#define write(a) printf("%d\n",a)
#define Cwrite(i,a) printf("Case %d: %d\n",i,a)
#define CLEAR(a,b) memset(a,b,sizeof(a))
#define VI(a) vector<a>
#define MA(a,b) map<a,b>

#define lld long long
#define PI acos(-1.0)

#define MAX 1000010
bool prime[MAX+10];

void seive()
{
    for(int i=4;i<=MAX;i+=2)
        prime[i]=1;
    int srt = sqrt(MAX);
    for(int i=3;i<=srt;i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=MAX;j+=2*i)
            {
                prime[j]=1;
            }
        }
    }
    prime[0]=prime[1]=1;
}

bool seg_seive[100010];

lld first(lld lo,lld i)
{
    if(lo%i==0)
            return (lld)max(lo,i*i);
    else
        return (lld)max(lo + (i-lo%i),i*i);
}


void segment_seive(lld a, lld b)
{
    CLEAR(seg_seive,0);
        if(a==1)
        {
            seg_seive[a]=1;
        }

        for(lld k=first(a,2);k>=a&&k<=b;k=k+2)
            seg_seive[k-a+1]=1;

        int max1 = sqrt(b);
        for(int j=3;j<=max1;j+=2)
        {
            if(prime[j]==0)
            {
                for(lld k=first(a,j);k>=a&&k<=b;k=k+j)
                    seg_seive[k-a+1]=1;
            }

        }
}

int main()
{
    seive();

    int test;
    long long int low,up,count;

    READ(test);

    for(int i=1;i<=test;i++)
    {
        scanf("%lld %lld",&low,&up);
        segment_seive(low,up);

        count=0;

        for(int j=low;j<=up;j++)
        {
            if(seg_seive[j-low+1]==0)
            {
                count++;
            }
        }

        printf("Case %d: %lld\n",i,count);

    }

    return 0;

}
