#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define Max  2010
#define ll long long int

char str[Max];
int arr[Max];
int test,n,m;
stack<int> stk;

int histoSolve()
{
        int maxArea=0, curInd=0;

        int i=0;

        for(;i<m;i++)
        {
            if(stk.empty())
            {
                stk.push(i);
            }
            else
            {
                while(!stk.empty() && arr[stk.top()]>arr[i] )
                {
                    curInd = stk.top();
                    stk.pop();

                    if(stk.empty())
                    {
                        maxArea = max( maxArea, (i)*arr[curInd]);
                    }
                    else
                        maxArea = max( maxArea, (i-stk.top()-1)*arr[curInd]);
                   // cout<<maxArea<<" "<<i<<" "<<curInd<<endl;
                }

                stk.push(i);
            }

        }

        if(!stk.empty())
        {
            while(!stk.empty())
            {
                    curInd = stk.top();
                    stk.pop();

                    if(stk.empty())
                    {
                        maxArea = max( maxArea, (i)*arr[curInd]);
                    }
                    else
                        maxArea = max( maxArea, (i-stk.top()-1)*arr[curInd]);
                  //  cout<<maxArea<<" "<<i<<" "<<curInd<<endl;
            }
        }

        return maxArea;

}

int main()
{

    si(test);

    for(int Case=1;Case<=test;Case++)
    {
        si(n); si(m);

        memset(arr,0,sizeof(arr));

        int res=0;

        for(int i=0;i<n;i++)
        {
            scanf(" %s",str);

            for(int j=0;j<m;j++)
            {
                if(str[j]=='0')
                    arr[j+1]++;
                else
                    arr[j+1]=0;
            }

            res = max(res,histoSolve());

        }

        printf("Case %d: %d\n",Case,res);

    }

    return 0;
}

