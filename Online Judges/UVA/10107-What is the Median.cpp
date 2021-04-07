#include<bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    vector<long int> List;

    long int num;

    while(cin>>num)
    {
        List.push_back(num);
        sort(List.begin(),List.end());
        long int length=List.size();

        if(length%2==1)
            cout<<(List[(length-1)/2])<<endl;
        else
        {
            cout<<((List[length/2]+List[length/2-1])/2)<<endl;
        }
    }
}
