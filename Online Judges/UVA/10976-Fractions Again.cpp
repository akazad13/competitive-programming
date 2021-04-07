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

struct node
{
    char name[100];
    int low, high;
};

int main()
{
    //freopen("uvain.txt","r",stdin);
    //freopen("uvaout.txt","w",stdout);
    bool flag=0;
    int n;
    node data[10010];

    vector< pair<int, int > > vec;

    while(scanf("%d",&n)==1)
    {
        vec.clear();
        for(int i=n+1;i<=2*n;i++)
        {
            if((n*i) %(i-n)==0)
            {
                vec.push_back(mp(((n*i)/(i-n)),i));
            }
        }

        printf("%d\n",vec.size());

        for(int i=0;i<vec.size();i++)
        {
            printf("1/%d = 1/%d + 1/%d\n",n,vec[i].first,vec[i].second);
        }
    }

    return 0;

}





