#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros

#define READ(a) scanf("%d",&a)
#define CLEAR(a,b) memset(a,b,sizeof(a))

#define lld long long
#define PI acos(-1.0)

lld x, y;
void extendedEulid(lld a, lld b)
{
    if(b==0)
    {
        x=1; y=0;
        return ;
    }
    extendedEulid(b, a%b);
    lld x1 = y;
    lld y1 = x - (a/b) *y;
    x = x1;
    y = y1;
}

lld chinese_remainder(int m[], int a[], int len)
{
	lld M = 1,sum = 0;

	for (int i=0;i<len;i++)
    {
        M*= m[i];
    }

	for (int i=0; i<len;i++) {
		lld p = M/m[i];
		extendedEulid(p,m[i]);
		if(x<0)
            x+=m[i];
		sum+= a[i]*x*p;
	}

	return sum%M;
}

int main()
{
	int m[20],a[20];
	int test;
	READ(test);
	for(int i=1;i<=test;i++)
    {
        int n;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>m[j];
            cin>>a[j];
        }

	printf("Case %d: %lld\n",i,chinese_remainder(m,a,n));
    }

	return 0;
}


