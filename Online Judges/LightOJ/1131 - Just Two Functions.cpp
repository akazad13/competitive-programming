#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

#define rn 6  //number of rows in matrix
#define cn 6  //number of column in matrix

ll mod;//modulo

struct matrix
{
    ll mat[rn][cn];

    matrix() //initializing to 0
    {
        for (ll i = 0; i < rn; i++)
            for (ll j = 0; j < cn; j++)
                mat[i][j] = 0;
    }
} base, unit;

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

	ll test,n, a[15];

	scanf("%lld",&test);

	for(ll Case=1;Case<=test;Case++)
    {
        for(int i=0;i<12;i++)
        {
            scanf("%lld",&a[i]);
        }

        scanf("%lld",&mod);

        for(int i=0;i<12;i++)
        {
            a[i]%=mod;
        }

		base.mat[0][0] = a[0];
		base.mat[0][1] = a[1];
		base.mat[0][5] = a[2];
		base.mat[1][0] = 1;
		base.mat[2][1] = 1;
		base.mat[3][2] = a[5];
		base.mat[3][3] = a[3];
		base.mat[3][4] = a[4];

		base.mat[4][3] = 1;
		base.mat[5][4] = 1;

        int q;
        scanf("%d",&q);

        printf("Case %lld:\n",Case);
		while(q--)
        {
            scanf("%lld",&n);
            if(n==0)
                printf("%lld %lld\n",a[6],a[9]);
            else if(n==1)
                printf("%lld %lld\n",a[7],a[10]);
            else if(n==2)
                printf("%lld %lld\n",a[8],a[11]);
            else
            {
                matrix res = expo(base,n-2);
                ll aa = (res.mat[0][0]*a[8]+res.mat[0][1]*a[7]+res.mat[0][2]*a[6]+res.mat[0][3]*a[11]+res.mat[0][4]*a[10]+res.mat[0][5]*a[9])%mod;
                ll bb = (res.mat[3][0]*a[8]+res.mat[3][1]*a[7]+res.mat[3][2]*a[6]+res.mat[3][3]*a[11]+res.mat[3][4]*a[10]+res.mat[3][5]*a[9])%mod;
                printf("%lld %lld\n",aa,bb);
            }
        }
	}

    return 0;
}

