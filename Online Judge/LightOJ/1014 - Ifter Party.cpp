#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int i=1;i<=test;i++)
    {
        long long int prepare,left;
        cin>>prepare>>left;

        vector<long long int> list1;
        int max,diff;

        diff=prepare-left;
        printf("Case %d:",i);
        if(diff<=left)
        {
            printf(" impossible\n");
            continue;
        }
        max=sqrt(diff);

        int k;

        for( k=1;k<=max;k++)
        {
            if(diff%k==0)
            {
                list1.push_back(k);
                list1.push_back((diff/k));
            }
        }
        sort(list1.begin(),list1.end());
        list1.resize(distance( list1.begin(), unique(list1.begin(),list1.end())) );
        for(int k = 0; k< list1.size(); ++k)
        {
            if(list1[k] > left)
                {
                        cout<<" "<<list1[k];
                }
        }

        printf("\n");

        list1.empty();
    }
    return 0;
}

