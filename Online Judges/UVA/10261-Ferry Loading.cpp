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
#define mp make_pair

//End Macros

int n,len;
int arr[205];
map< pair< pair <int, int> , int > ,int > Map, RES;

int solve(int ind, int port, int starbort)
{
    if(ind>=n)
    {
        return 0;
    }
    pair<int, int > p;
    p = mp(ind,port);

    int ret = Map[mp(p,starbort)];

    if(ret!=0) return ret;

    int ret1=0;
    int ret2=0;
    int ret3=0;

    if(port+arr[ind]<=len)
    {
        ret1 = solve(ind+1, port+arr[ind], starbort)+1;
    }
    if(starbort+arr[ind]<=len)
    {
        ret2 = solve(ind+1, port, starbort+arr[ind])+1;
    }

   // cout<<ret1<<" "<<ret2<<" "<<ind<<endl;

    if(ret1!=0 || ret2!=0){
         //   cout<<"un "<<" "<<ret1<<" "<<ret2<<" "<<ind<<endl;
    if(ret1>=ret2)
    {
        //res[ind][port][starbort]=1;
       // cout<<ind<<endl;
        RES[mp(p,starbort)] = 1;
    }
    else
    {
        //res[ind][port][starbort]=2;
        RES[mp(p,starbort)] = 2;
    }
    }

    ret =  max(ret1,max(ret2,ret3));
    Map[mp(p,starbort)] = ret;

    return ret;
}

void printSol()
{
    int i,j,k;
    i=0;j=0;k=0;

    vector<string> sol;

    while(i<n && j<=len && k<=len)
    {
       // cout<<res[i][j][k]<<" "<<res[i][j][k]<<" "<<i<<endl;

       int ret = RES[mp(mp(i,j),k)];

      // cout<<i<<" "<<j<<" "<<k<<" "<<ret<<endl;
        if(ret==1)
        {
            //cout<<i<<endl;
            sol.push_back("port");
            j+= arr[i];
            i++;
        }
        else if(ret==2)
        {
           // cout<<"st  "<<i<<endl;
            sol.push_back("starboard");
            k+= arr[i];
            i++;
        }
        else if(ret==0)
        {
            break;
        }
    }

    //printf("%d\n",sol.size());

    for(int i=0;i<sol.size();i++)
    {
        cout<<sol[i]<<"\n";
    }

    return ;
}



int main()
{
    //freopen("uvain.txt","r",stdin);
    //freopen("uvaout.txt","w",stdout);
    bool flag=0;
    int test,a;
    scanf("%d",&test);

    while(test--)
    {
        scanf("%d",&len);
        len = len*100;
        n=0;

        while(scanf("%d",&a)==1)
        {
            if(a==0)
                break;
            if(n<=200)
                arr[n++] = a;

        }

        Map.clear();
        RES.clear();
        if(flag)
            printf("\n");
        flag=1;

        int ret = solve(0,0,0);

        printf("%d\n",ret);
        printSol();


    }

    return 0;

}



