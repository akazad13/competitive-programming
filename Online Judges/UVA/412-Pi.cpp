#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int GCD(int a , int b)
{
    if(a%b==0)
        return b;
    return GCD(b,a%b);
}

int main()
{
    int arr[52];
    int n;

    while(cin>>n,n)
    {
        int count=0;
        int pair=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                pair++;
                if(GCD(arr[i],arr[j])==1)
                {
                    count++;
                }
            }
        }

        if(count>0)

       {
           double res = sqrt((6*(double)pair)/(double)count);

            printf("%.6f\n",res);
       }
       else
       {
           printf("No estimate for this data set.\n");
       }


    }

    return 0;
}

