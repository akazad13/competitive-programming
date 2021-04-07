#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int L[10002];
int I[10002];

void LisNlogK(vector<int> Sequence, int n)
{
    //cout<<"Ok"<<endl;

   // cout<<Sequence[0]<<endl;
    for(int i=1;i<=n+1;i++)
        I[i] = INT_MAX;
    I[0] = INT_MIN;

    //cout<<I[0]<<endl;
    int LisLength = 0;

    for(int i=0;i<n;i++)
    {
        int low,high,mid;

        low=0;
        high = LisLength;

        while(low<=high)
        {
            mid = (low+high)/2;
            //cout<<"Ok"<<endl;
            if(I[mid]<Sequence[i])
                low = mid+1;
            else
                high = mid-1;
        }

        I[low] = Sequence[i];

        if(i==0)
            L[i] = low;
        else
            L[i] = max(low,L[i-1]);

        if(LisLength<low)
        {
            LisLength=low;
        }
    }

  /*  for(int i=0;i<n;i++)
        cout<<L[i]<<" ";
    cout<<endl;*/

  //  return LisLength;
 // return L;
}


int main()
{
    //freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int n,test,p;
    vector<int> Sequence;
    //Sequence.reserve(10002);
    int LIS[10002],LDS[10002];

    while(scanf("%d",&n)==1)
    {
        Sequence.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d",&p);
            Sequence.push_back(p);
        }
        //cout<<"ok"<<endl;
        LisNlogK(Sequence,n);

        for(int i=0;i<n;i++)
            LIS[i]=L[i];

        reverse(Sequence.begin(),Sequence.end());

        LisNlogK(Sequence,n);

        for(int i=0;i<n;i++)
            LDS[i]=L[i];

        reverse(LDS,LDS+n);

        int Max = 0;

        for(int i=0;i<n;i++)
        {
            //cout<<LIS[i]<<" "<<LDS[i]<<endl;

            Max = max(Max,LDS[i]+LIS[i]-1);
        }

        printf("%d\n",Max);
    }




    return 0;
}


