#include<iostream>
#include<bits/stdc++.h>



using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define ll long long int
#define lu unsigned long long int

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define VD vector<double>

#define pi pair<int,int>
#define mp(a,b) make_pair(a,b)
#define eps 1e-9
#define PI 2.0*acos(0.0) //#define PI acos(-1.0)

#define MOD 1000000007
#define INF (1<<28)

#define Clear(a,b) memset(a,b,sizeof(a))

template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}


/*********************************************************/

#define Max 200

bool prime[Max+10];
VI pList;
int Vsize;

void sieve()
{
    Clear(prime,0);
    prime[0] = prime[1]=1;
    for(int i=4;i<=Max;i+=2)
    {
        prime[i]=1;
    }

    int sqr = sqrt(Max);

    for(int i=3;i<=sqr;i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=Max;j = 2*i+j)
            {
                prime[j]=1;
            }
        }

    }

    for(int i=2;i<=Max;i++)
    {
        if(prime[i]==0)
        {
            pList.pb(i);
        }
    }

    Vsize = pList.size();
}

/*************************************/
int a;
int num_fact(int n)
{
    int res = 0;

    for(int p =n; p<=a;p = p*n)
    {
        res+=(a/p);
    }
    //cout<<res<<endl;
    return res;
}

int arr[110];

int main()
{
    sieve();

    int test,Case;
    read(test);

    rep(Case,1,test+1)
    {
        read(a);
        Clear(arr,0);
        for(int i=0;pList[i]<=a;i++)
        {
            arr[pList[i]]=num_fact(pList[i]);
        }

        bool flag=0;

        printf("Case %d: %d",Case,a);

        for(int i=2;i<=a;i++)
        {
            if(prime[i]==0 && arr[i])
            {
                if(flag==0)
                    printf(" = %d (%d)",i,arr[i]);
                else
                    printf(" * %d (%d)",i,arr[i]);
                flag=1;
            }
        }
        printf("\n");
    }



    return 0;
}






