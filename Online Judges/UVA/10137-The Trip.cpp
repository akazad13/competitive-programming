#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{


    int n;

    while(cin>>n,n)
    {
        double str_enp[1020];
        double sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>str_enp[i];
            sum+=str_enp[i];
        }

        double avg = sum/n;

        double sum1=0.0,sum2=0.0,diff;
       // cout<<avg<<endl;

        for(int i=0;i<n;i++)
        {
            diff=(double)(long)((str_enp[i] - avg) * 100) / 100.0;
           // cout<<diff<<endl;

            if(diff>0)
                sum1+=diff;
            else
                sum2-=diff;
        }

        if(sum2>sum1)
        {
            printf("$%.2f\n",sum2);
        }

        else
        {
            printf("$%.2f\n",sum1);
        }

    }

    return 0;
}
