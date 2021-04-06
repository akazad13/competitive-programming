#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

#define rn 2  //number of rows in matrix
#define cn 2  //number of column in matrix

#define mod 1000000007

struct matrix
{
    ll mat[rn][cn];

    matrix() //initializing to 0
    {
        for (int i = 0; i < rn; i++)
            for (int j = 0; j < cn; j++)
                mat[i][j] = 0;
    }
} base;

matrix mul(matrix A, matrix B)
{
    int i, j, k;
    ll s;

    matrix res;

    for (i = 0; i < rn; i++)
        for (j = 0; j < cn; j++)
        {
            s = 0;
            for (k = 0; k < rn; k++)
                s = (s + (A.mat[i][k]*B.mat[k][j])%mod)%mod;
            res.mat[i][j] = s;
        }
    return res;
}

matrix expo(matrix b, ll p)
{
    if (p==1)
    {
        return b;
    }

    matrix x = expo(b, p/2);

    if (p%2 == 0)
    {
        return mul(x, x);
    }
    else
    {
        return mul(b, mul(x, x));
    }
}


int main()
{

	int test;
	ll a,b;
	ll n,m,len1,len2,k;
    base.mat[0][0] = 1;
    base.mat[0][1] = 1;
    base.mat[1][0] = 1;
    base.mat[1][1] = 0;

	scanf("%d",&test);


	for(int Case=1;Case<=test;Case++)
    {

        scanf("%lld %lld %lld %lld %lld",&n,&len1,&m,&len2,&k);

        matrix res1 = expo(base,n);
        matrix res2 = expo(base,m);

        ll p = res1.mat[0][0]*res2.mat[0][1]-res2.mat[0][0]*res1.mat[0][1];


        printf("Case %d: ",Case);

        if(p==0 || res1.mat[0][0]==0)
        {
            printf("Impossible\n");
            continue ;
        }


        ll q = res1.mat[0][0]*len2-res2.mat[0][0]*len1;

        if(q%p || q/p<0)
        {
            printf("Impossible\n");
            continue ;
        }

        b = q/p;

        if((len1-b*res1.mat[0][1])%res1.mat[0][0])
        {
            printf("Impossible\n");
            continue ;
        }

        a = (len1-b*res1.mat[0][1])/res1.mat[0][0];

        if(a<0)
        {
            printf("Impossible\n");
            continue ;
        }

        matrix res = expo(base,k);

        printf("%lld\n",((res.mat[0][0]*a)%mod+(res.mat[0][1]*b)%mod)%mod);
	}

    return 0;
}
