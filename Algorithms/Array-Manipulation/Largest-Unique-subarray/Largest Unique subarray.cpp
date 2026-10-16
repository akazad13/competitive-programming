/**
 * @file Largest Unique subarray.cpp
 * @brief Longest Contiguous Subarray with Unique Elements
 * 
 * Uses a sliding window (two pointers) and hash map to find the maximum length
 * of a contiguous subarray consisting of all distinct values.
 * 
 * Time Complexity:  O(n) with unordered_map / O(n log n) with map
 * Space Complexity: O(n)
 */

#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

long long int arr[1000010];

int main()
{
    int n,test;
    scanf("%d",&test);

    while(test--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        map<int,int>myMap;

        int large=0,count=0;
        int j=1;

        for(int i=1;i<=n;i++)
        {
            if(i==n&&myMap[arr[i]]==0)
            {
                count= (i+1)-j;
            }
            else if(myMap[arr[i]]==0)
            {
                myMap[arr[i]]++;
               //count++;
            }

            else
            {
                count = (i-j);

                for(int k=j;k<=n;k++)
                {
                    if(arr[k]==arr[i])
                    {
                       // cout<<"left : "<<k<<"Right: "<<i<<"\n"<<endl;
                        j=k+1;
                        //cout<<"left : "<<j<<"Right: "<<i<<endl;
                        break;
                    }
                    else
                    {
                        myMap[arr[k]]=0;
                    }
                }

            }
            if(i==j&&count==0)
                large=1;
            else if(count>large)
                large=count;
        }

        cout<<large<<endl;
    }

    return 0;
}
