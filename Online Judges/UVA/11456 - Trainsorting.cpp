#include<iostream>
#include<bits/stdc++.h>


using namespace std;


int main()
{
   // freopen("in.txt","r",stdin);
    //freopen("out1.txt","w",stdout);
    int n,test,p;
    int Sequence[2001];
    int T1[2001],T2[2001];

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&Sequence[i]);
        }

        for(int i=n-1;i>=0;i--)
        {
            T1[i]=1;

            for(int j=i+1;j<n;j++)
            {
                if(Sequence[i]<Sequence[j])
                {
                    T1[i] = max(T1[j]+1,T1[i]);
                }
            }
        }

        for(int i=n-1;i>=0;i--)
        {
            T2[i]=1;

            for(int j=i+1;j<n;j++)
            {
                if(Sequence[i]>Sequence[j])
                {
                    T2[i] = max(T2[j]+1,T2[i]);
                }
            }
        }

        int Max = 0;

        for(int i=0;i<n;i++)
        {
            //cout<<LIS[i]<<" "<<LDS[i]<<endl;
            //if(min(LDS[i],LIS[i])>Max)
            //{

                Max = max(Max,T1[i]+T2[i]-1);
            //}
        }

        printf("%d\n",Max);
    }

    return 0;
}



