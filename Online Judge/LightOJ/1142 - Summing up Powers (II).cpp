#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll int
int n;  //number of rows in matrix
 //number of column in matrix
#define mod 10 //modulo

struct matrix
{
    ll mat[30][30];

    matrix() //initializing to 0
    {
        for (ll i = 0; i < 30; i++)
            for (ll j = 0; j < 30; j++)
                mat[i][j] = 0;
    }
} base,unit;

matrix mul(matrix A, matrix B)
{
    ll i, j, k, s;

    matrix res;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            s = 0;
            for (k = 0; k < n; k++)
                s = (s + (A.mat[i][k]*B.mat[k][j])%mod)%mod;
            res.mat[i][j] = s;
        }
    return res;
}

matrix add(matrix A, matrix B)
{
    ll i, j, k, s;

    matrix res;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            res.mat[i][j] = (A.mat[i][j]+B.mat[i][j])%mod;
        }
    return res;
}

matrix expo(matrix b, int p)
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


matrix bigMod(matrix b, int k)
{
    if(k==1)
    {
        return b;
    }

    if(k%2==1)
    {
        return add(bigMod(b,k-1),expo(b,k));
    }
    else
    {
        return mul(bigMod(b,k/2),add(unit,expo(b,k/2)));
    }
}

int main()
{

	int test,k;

	scanf("%d",&test);


	for(int Case=1;Case<=test;Case++)
    {
        scanf("%d %d",&n,&k);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&base.mat[i][j]);
                if(i==j)
                unit.mat[i][j]=1;
            }
        }

        matrix res = bigMod(base,k);

        printf("Case %d:\n",Case);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d",res.mat[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}


