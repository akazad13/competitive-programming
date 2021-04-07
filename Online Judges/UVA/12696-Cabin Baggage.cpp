#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    double height,width,depth,weight;
    int test;

    int allowable=0;

    cin>>test;

    while(test--)
    {
        cin>>height>>width;
        cin>>depth>>weight;
        if(weight>7.00)
        {
            printf("0\n");
        }
        else if((height+width+depth)<=125 ||(height<=56&&width<=45&&depth<=25))
        {
            printf("1\n");
            allowable++;
        }
        else
        {
            printf("0\n");
        }
    }

    cout<<allowable<<"\n";

    return 0;
}
