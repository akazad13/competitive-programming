#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define rn 4  //number of rows in matrix
#define cn 4  //number of column in matrix
#define mod 10007 //modulo

struct matrix
{
    ll mat[rn][cn];

    matrix() //initializing to 0
    {
        for (ll i = 0; i < rn; i++)
            for (ll j = 0; j < cn; j++)
                mat[i][j] = 0;
    }
} base;

matrix mul(matrix A, matrix B)
{
    ll i, j, k, s;

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
	ll test,a,b,n,p;
        base.mat[0][0] = 1;
		base.mat[0][1] = 1;
		base.mat[0][2] = 1;
		base.mat[0][3] = 1;
		base.mat[1][0] = 1;
		base.mat[1][1] = 0;
		base.mat[1][2] = 0;
		base.mat[1][3] = 0;
		base.mat[2][0] = 0;
		base.mat[2][1] = 1;
		base.mat[2][2] = 0;
		base.mat[2][3] = 1;
		base.mat[3][0] = 0;
		base.mat[3][1] = 1;
		base.mat[3][2] = 1;
		base.mat[3][3] = 0;

	scanf("%lld",&test);

	for(int Case=1;Case<=test;Case++)
    {
		scanf("%lld",&n);
        if(n == 1)
        {
			printf("Case %d: 1\n",Case);
			continue;
		}
		if(n==2)
        {
			printf("Case %d: 2\n",Case);
			continue;
		}
		matrix res = expo(base,n-2);

		printf("Case %d: %lld\n",Case, ((res.mat[0][0]*2)%mod + (res.mat[0][1]) % mod + (res.mat[0][2]) % mod + (res.mat[0][3] % mod)) % mod);
	}
    return 0;
}

