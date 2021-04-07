#include<iostream>
#include<bits/stdc++.h>

#define lld long long int

using namespace std;

lld GCD(lld a, lld b)
{
    if(a%b==0)
        return b;
    return GCD(b,a%b);
}

int main()
{
    lld num;

    while(cin>>num,num)
    {
        lld div[1000];

        lld n=sqrt(num);
        int k=0;

        for(int i=1;i<=n;i++)
        {
            if(num%i==0)
            {
                div[k++]=i;
                if(i!=(num/i))
                    div[k++]=(num/i);
            }
        }
        //int res=k+2;
        int res=0;

        for(int i=0;i<k;i++)
        {
            for(int j=i;j<k;j++)
            {
                if(num== ((div[i]*div[j])/GCD(div[i],div[j])))
                   {
                       res++;
                   }
            }
        }
        cout<<num<<" "<<res<<"\n";
    }
    return 0;
}
