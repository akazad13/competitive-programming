#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test,num;


    cin>>test;

    while(test--)
    {
        cin>>num;
        int arr[10]={0};

        for(int i=num;i>=1;i--)
        {
            int temp=i;
            while(temp!=0)
            {
                arr[temp%10]++;
                temp/=10;
            }
        }

        cout<<arr[0];

        for(int i=1;i<10;i++)
        {
            cout<<" "<<arr[i];
        }

        cout<<"\n";
    }

    return 0;
}
