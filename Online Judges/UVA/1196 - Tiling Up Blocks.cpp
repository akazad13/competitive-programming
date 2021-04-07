#include<iostream>
#include<bits/stdc++.h>


using namespace std;

struct node
{
    int p,q;
};

node Sequence[10002];
node I[10002];

int LisNlogK(int n)
{
    for(int i=1;i<=n+1;i++)
    {
        I[i].p = INT_MAX;
        I[i].q = INT_MAX;
    }
    I[0].p = INT_MIN;
    I[0].q = INT_MIN;

    int LisLength = 0;

    for(int i=0;i<n;i++)
    {
        int low,high,mid;

        low=0;
        high = LisLength;

        while(low<=high)
        {
            mid = (low+high)/2;

            if(I[mid].p<=Sequence[i].p && I[mid].q <= Sequence[i].q)
                low = mid+1;
            else
                high = mid-1;
        }

        I[low].p = Sequence[i].p;
        I[low].q = Sequence[i].q;

        if(LisLength<low)
        {
            LisLength=low;
        }
    }

    return LisLength;
}

bool cmp(node a, node b)
{
    if(a.p==b.p)
    {
        return a.q<b.q;
    }

    return a.p<b.p;
}

int main()
{
    int n;

    while(scanf("%d",&n)==1)
    {

        if(n==0)
            break;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&Sequence[i].p,&Sequence[i].q);
        }

        sort(Sequence,Sequence+n,cmp);

        //cout<<Sequence[0].p<<" "<<Sequence[0].q<<endl;
        printf("%d\n",LisNlogK(n));
    }

    printf("*\n");




    return 0;
}

