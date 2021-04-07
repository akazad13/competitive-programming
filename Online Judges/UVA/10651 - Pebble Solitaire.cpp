#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define VD vector<double>

#define pi pair<int,int>
#define mp make_pair

#define Clear(a,b) memset(a,b,sizeof(a))

#define  inf -12200

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
 char str[20];

 int res;

int solve(int len)
{
    int ret1=0;
    int ret2=0,i;

   // char str[20];
    //strcpy(str,st);
    int cnt=0;
    rep(i,0,12)
    {
        if(str[i]=='o')
        {
                //cout<<i<<endl;
            cnt+=1;
        }
    }

    if(res>cnt)
        res=cnt;


   //cout<<"before: "<<str<<endl;


    for(int i=0;i<len-2;i++)
    {
        if(str[i]=='-' && str[i+1]=='o' && str[i+2]=='o')
        {
            str[i]='o'; str[i+1]='-' ; str[i+2]='-';
            ret1 = solve(len)+1;
            str[i]='-'; str[i+1]='o' ; str[i+2]='o';
           // flag=1;
        }
        else if(str[i]=='o' && str[i+1]=='o' && str[i+2]=='-')
        {
            str[i]='-'; str[i+1]='-' ; str[i+2]='o';
            ret2 = solve(len)+1;
            str[i]='o'; str[i+1]='o' ; str[i+2]='-';
            //flag=1;
        }
    }

   // cout<<"after: "<<str<<" "<<ret1<<" "<<ret2<<endl;

    return max(ret1,ret2);
}


int main()
{
    //freopen("inp.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int n,i;


    read(n);
    //char ch =getchar();

    while(n--)
    {
        int cnt=0;
        gets(str);

       // cout<<str<<endl;

        rep(i,0,12)
        {
             if(str[i]=='o')
            {
                //cout<<i<<endl;
                cnt+=1;
            }
        }

        //cout<<cnt<<endl;
        res=15;
        //cout<<"-----------------------------------------------"<<endl;
        solve(strlen(str));
        //cout<<ret<<endl;

        printf("%d\n",res);
    }
    return 0;
}




