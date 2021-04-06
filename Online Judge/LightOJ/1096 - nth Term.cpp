#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

#define rn 4  //number of rows in matrix
#define cn 4  //number of column in matrix

#define mod 10007

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
	ll a,b,c,n;

	scanf("%d",&test);


	for(int Case=1;Case<=test;Case++)
    {

        scanf("%lld %lld %lld %lld",&n,&a,&b,&c);

        base.mat[0][0] = a;
        base.mat[0][1] = 0;
        base.mat[0][2] = b;
        base.mat[0][3] = c;
        base.mat[1][0] = 1;
        base.mat[1][1] = 0;
        base.mat[1][2] = 0;
        base.mat[1][3] = 0;
        base.mat[2][0] = 0;
        base.mat[2][1] = 1;
        base.mat[2][2] = 0;
        base.mat[2][3] = 0;
        base.mat[3][0] = 0;
        base.mat[3][1] = 0;
        base.mat[3][2] = 0;
        base.mat[3][3] = 1;

        printf("Case %d: ",Case);

        if(n<=2)
        {
            printf("0\n");
            continue ;
        }
        matrix res = expo(base,n-2);

        printf("%lld\n",(res.mat[0][3])%mod);
	}
    return 0;
}
