#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    int num;

    int bitVal[34];

    bitVal[1]=1;

    for(int i=2;i<=31;i++)
    {
        bitVal[i]=2*bitVal[i-1];
    }
    cin>>test;

    for(int i=1;i<=test;i++)
    {
        cin>>num;

        int arr[40]={-1};
        int n=num;
        int count=1;

        while(1)
        {
            arr[count]=num%2;
            num=num/2;

            if(arr[count]==0&&arr[count-1]==1)
            {
                break;
            }
            count++;
        }

        int diff=bitVal[count]-bitVal[count-1];

        int reDiff=0;

        int m=count-2;
        bool flag=0;

        for(int k=1;k<m;k++)
        {
            if(arr[k]==0)
            {
                for(int l=m;l>k;l--)
                {
                    if(arr[l]==1&&arr[k]==0)
                    {
                        int temp=bitVal[l]-bitVal[k];
                        arr[k]=1;
                        arr[l]=0;
                        if((temp+reDiff)<=diff)
                        {
                            reDiff+=temp;
                        }
                    }
                }
            }

        }
        diff=diff-reDiff;

        cout<<"Case "<<i<<": "<<(n+diff)<<endl;
    }

    return 0;
}
