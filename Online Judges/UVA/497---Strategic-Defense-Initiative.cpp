#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int Sequence[100002];
int I[100002];
int L[100002];
int sol[100002];


void findSequence(int n)
{
    int i,j;
    int Max=0;

    for(int j=0;j<n;j++)
    {
        if(L[j]>Max)
        {
            i = j;
            Max = L[j];
        }
    }

    int top = L[i]-1;

    sol[top] = Sequence[i];
    top--;

   // cout<<"Ok"<<endl;

    for(int j=i-1;j>=0;j--)
    {
        if(Sequence[i]>Sequence[j] && L[j]==L[i]-1)
        {
            i=j;
            sol[top]=Sequence[i];
            top--;
        }
    }

   // cout<<"ok"<<endl;

    for(int i=0;i<Max;i++)
        printf("%d\n",sol[i]);
}

int LisNlogK(int n)
{
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

            if(I[mid]<Sequence[i])
                low = mid+1;
            else
                high = mid-1;
        }

        I[low] = Sequence[i];
      //  cout<<low<<endl;
        L[i] = low;

        if(LisLength<low)
        {
            LisLength=low;
        }
    }

    return LisLength;
}

int main()
{
   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,test;
    int cnt=0;

    scanf("%d",&test);
    char ch = getchar();

    char str[10];

    gets(str);

    for(int Case=1;Case<=test;Case++)
    {
        cnt=0;
        while(gets(str))
        {
            int len = strlen(str);
            if(len==0)
                break;
            n=0;
            for(int i=0;i<len;i++)
            {
                n = 10*n+str[i]-'0';
            }

            Sequence[cnt++] = n;
        }

        n = cnt;

        if(Case>1)
            printf("\n");

        printf("Max hits: %d\n",LisNlogK(n));

       // printf("-\n");

        findSequence(n);
    }




    return 0;
}

