#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    cin>>test;
    bool flag=1;

    while(test--)
    {
        if(flag==0)
            cout<<"\n";
        int len;

        cin>>len;
        int l=len;

        vector<int> num1;
        vector<int> num2;
        list<int>result;

        list<int> :: iterator it;

        int a,b;
        while(l--)
        {
            cin>>a>>b;
            num1.push_back(a);
            num2.push_back(b);
            //cout<<l<<endl;
        }

        int rem=0;

        for(int i=len-1;i>=0;i--)
        {
            rem+= num1[i]+num2[i];

            result.push_front(rem%10);
            rem/=10;
        }

        for(it=result.begin();it!=result.end();it++)
        {
            cout<<(*it);
        }
        cout<<"\n";

        flag=0;


    }
    return 0;
}
