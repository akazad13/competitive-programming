#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>up;
    vector<int>low;

    int count=1,n,i;

    while(1)
    {
        if(count%2!=0)
        {
            for(i=count;i>=1;i--)
            {
                up.push_back(i);

            }

            for(i=1;i<=count;i++)
            {
                low.push_back(i);
            }
            if(up.size()>10000000)
                    break;
        }
        else
        {
            for(i=count;i>=1;i--)
            {
                low.push_back(i);
            }

            for(i=1;i<=count;i++)
            {
                up.push_back(i);

            }
            if(up.size()>10000000)
                    break;
        }

        count++;
    }

    while(cin>>n)
    {
        cout<<"TERM "<<n<<" IS "<<up[n-1]<<"/"<<low[n-1]<<endl;
    }
    return 0;
}
