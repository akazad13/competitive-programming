#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ui unsigned int

int rn;  //number of rows in matrix
int cn;  //number of column in matrix

ui dp[55][55];

ui nCr(int n, int r)
{
    if(r==0)
        return 1;
    if(r==1)
        return n;
    if(n==r)
        return 1;
    if(dp[n][r]!=-1) return dp[n][r];

    dp[n][r] = nCr(n-1,r)+nCr(n-1,r-1);

    return dp[n][r];

}

struct matrix
{
    ui mat[54][54];

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
    ui s;

    matrix res;

    for (i = 0; i < rn; i++)
        for (j = 0; j < cn; j++)
        {
            s = 0;
            for (k = 0; k < rn; k++)
                s = (s + (A.mat[i][k]*B.mat[k][j]));
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
	int test,k;
	ll n;

	memset(dp,-1,sizeof(dp));

	scanf("%d",&test);

	for(int Case=1;Case<=test;Case++)
    {
		scanf("%lld %d",&n,&k);

		rn = cn = k+2;

		base.mat[0][0]=1;
		for(int i=1;i<k+2;i++)
            base.mat[0][i] = nCr(k,i-1);

        for(int i=1;i<k+2;i++)
        {
            int p=0;
            for(int j=i;j<k+2;j++)
            {
                base.mat[i][j] = nCr(k-i+1,p++);
            }
        }
		matrix res = expo(base,n-1);

        ui sum = 0;

        for(int i=0;i<k+2;i++)
            sum+=res.mat[0][i];
		printf("Case %d: %lu\n",Case,sum);
	}

    return 0;
}

