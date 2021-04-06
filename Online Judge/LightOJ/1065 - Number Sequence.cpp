#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

#define rn 2  //number of rows in matrix
#define cn 2  //number of column in matrix

ll mod;

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
	ll a,b,n;
    base.mat[0][0] = 1;
    base.mat[0][1] = 1;
    base.mat[1][0] = 1;
    base.mat[1][1] = 0;

	scanf("%d",&test);

	for(int Case=1;Case<=test;Case++)
    {

        scanf("%lld %lld %lld %lld",&a,&b,&n,&mod);

        printf("Case %d: ",Case);

        mod = round(pow(10,mod));

        a%=mod;
        b%=mod;
        if(n==0)
        {
            printf("%lld\n",a);
            continue;
        }
        if(n==1)
        {
            printf("%lld\n",b);
            continue;
        }

        matrix res = expo(base,n-1);

        printf("%lld\n",((res.mat[0][0]*b)%mod+(res.mat[0][1]*a)%mod)%mod);
	}

    return 0;
}

