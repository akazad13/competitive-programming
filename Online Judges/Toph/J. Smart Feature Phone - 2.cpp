#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define ll long long int

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
//istringstream is()

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

template <class T> inline T bigmod(T p,T e,T M){
    ll ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}

template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

template<typename T>inline T POW(T B,T P)
{
    if(P==0) return 1;
    if(P&1) return B*POW(B,P-1);
    else return SQR(POW(B,P/2));
}


template<typename T>inline T Dis(T x1,T y1,T x2, T y2)
{
    return sqrt( SQR(x1-x2) + SQR(y1-y2) );
}

template<typename T>inline T Angle(T x1,T y1,T x2, T y2)
{
    return atan( double(y1-y2) / double(x1-x2));
}
template<typename T>inline T DIFF(T a,T b)
{
    T d = a-b;
    if(d<0)return -d;
    else return d;
}
template<typename T>inline T ABS(T a)
{
    if(a<0)return -a;
    else return a;
}

template<typename T>inline T euclide(T a,T b,T &x,T &y)
{
    if(a<0)
    {
        T d=euclide(-a,b,x,y);
        x=-x;
        return d;
    }
    if(b<0)
    {
        T d=euclide(a,-b,x,y);
        y=-y;
        return d;
    }
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        T d=euclide(b,a%b,x,y);
        T t=x;
        x=y;
        y=t-(a/b)*y;
        return d;
    }
}

inline int Set(int N, int pos)
{
    return N= N|(1<<pos);
}

inline int Reset(int N, int pos)
{
    return N= N & ~(1<<pos);
}

inline bool check(int N, int pos)
{
    return (bool) (N&(1<<pos));
}
/************************************************************************************/
char str[100010];

struct node
{
    char ch;
    int cnt;
};

node arr[30];

bool cmp(node a, node b)
{
    if(a.cnt==b.cnt)
        return a.ch<b.ch;
    return a.cnt>b.cnt;
}

vector<char> res[10];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    //ios_base::sync_with_stdio(false); cin.tie(0);

    int test,i,j,Case,n,m;
    read(test);
    rep(Case,1,test+1)
    {
        gets(str);
        int len = strlen(str);

        for(int i =0 ;i<26;i++)
        {
            arr[i].ch = 'a'+i;
            arr[i].cnt=0;

           // cout<<arr[i].ch<<endl;
        }

        for(int i=0;i<len;i++)
        {
            arr[str[i]-'a'].cnt++;
        }

        sort(arr,arr+26,cmp);

        if(arr[0].cnt>=arr[1].cnt && arr[0].cnt!=0)
        {
            res[0].push_back(arr[0].ch);
        }
        else
        {
            for(int i=1;i<3;i++)
                res[0].push_back(arr[i].ch);
            for(int i=3;i<6;i++)
            {
                res[1].push_back(arr[i].ch);
            }

             for(int i=6;i<9;i++)
            {
                res[2].push_back(arr[i].ch);
            }

             for(int i=9;i<12;i++)
            {
                res[3].push_back(arr[i].ch);
            }
             for(int i=12;i<15;i++)
            {
                res[4].push_back(arr[i].ch);
            }
             for(int i=15;i<19;i++)
            {
                res[5].push_back(arr[i].ch);
            }

             for(int i=19;i<22;i++)
            {
                res[6].push_back(arr[i].ch);
            }
             for(int i=22;i<26;i++)
            {
                res[7].push_back(arr[i].ch);
            }

             printf("Case %d:\n",Case);

        printf("###############\n#....#%c%c%c#%c%c%c.#\n###############\n#%c%c%c.#%c%c%c#%c%c%c.#\n###############\n#%c%c%c%c#%c%c%c#%c%c%c%c#\n###############\n",res[0][0],res[0][1],res[0][2],res[1][0],res[1][1],res[1][2],res[2][0],res[2][1],res[2][2], res[3][0],res[3][1],res[3][2], res[4][0],res[4][1],res[4][2], res[5][0],res[5][1],res[5][2], res[5][3], res[6][0],res[6][1],res[6][2], res[7][0],res[7][1],res[7][2],res[7][3]);

            continue ;
        }

        if(arr[1].cnt>=arr[2].cnt && arr[1].cnt!=0)
        {
            res[1].push_back(arr[0].ch);
        }
        else
        {
            for(int i=1;i<3;i++)
                res[0].push_back(arr[i].ch);
            for(int i=3;i<6;i++)
            {
                res[1].push_back(arr[i].ch);
            }

             for(int i=6;i<9;i++)
            {
                res[2].push_back(arr[i].ch);
            }

             for(int i=9;i<12;i++)
            {
                res[3].push_back(arr[i].ch);
            }
             for(int i=12;i<15;i++)
            {
                res[4].push_back(arr[i].ch);
            }
             for(int i=15;i<19;i++)
            {
                res[5].push_back(arr[i].ch);
            }

             for(int i=19;i<22;i++)
            {
                res[6].push_back(arr[i].ch);
            }
             for(int i=22;i<26;i++)
            {
                res[7].push_back(arr[i].ch);
            }

             printf("Case %d:\n",Case);

        printf("###############\n#....#%c%c%c#%c%c%c.#\n###############\n#%c%c%c.#%c%c%c#%c%c%c.#\n###############\n#%c%c%c%c#%c%c%c#%c%c%c%c#\n###############\n",res[0][0],res[0][1],res[0][2],res[1][0],res[1][1],res[1][2],res[2][0],res[2][1],res[2][2], res[3][0],res[3][1],res[3][2], res[4][0],res[4][1],res[4][2], res[5][0],res[5][1],res[5][2], res[5][3], res[6][0],res[6][1],res[6][2], res[7][0],res[7][1],res[7][2],res[7][3]);
        continue ;
        }





    }

    return 0;
}


