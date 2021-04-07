#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int num;

    int arr[500004];

    arr[1]=1;
    arr[2]=2;

    int temp=2;
    for(int i=3;i<=500000;i++)
    {
        if(i<temp)
        {
            temp=2;
        }
        arr[i]=temp;
        temp+=2;
    }

    while(cin>>num,num)
    {
        cout<<arr[num]<<"\n";
    }




    return 0;
}

