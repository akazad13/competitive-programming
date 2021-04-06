#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()

{
    //freopen("out.txt","r",stdin);
    int temp1,temp2;
    int arr[105];

    vector<int> vec1;
    vector<int> vec2;

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                temp1 = (arr[i]*arr[j])+arr[k];
                if(arr[i]!=0)
                {
                    temp2 = arr[i]*(arr[j]+arr[k]);
                    vec2.push_back(temp2);
                }
                vec1.push_back(temp1);


            }
        }
    }

    int S1 = vec1.size();
    int S2 = vec2.size();

    sort(vec2.begin(),vec2.end());

    int p;
    int res =0;

    for(int i=0;i<S1;i++)
    {
        temp1 = vec1[i];

        p = upper_bound(vec2.begin(),vec2.end(),temp1) - lower_bound(vec2.begin(),vec2.end(),temp1);
        //cout<<p<<" "<<q<<endl;
        res+=p;

    }

    printf("%d\n",res);
}
