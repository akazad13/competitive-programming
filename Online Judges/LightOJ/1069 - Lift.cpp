#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main()

{
    int test;
    int liftPos, MyPos;

    cin>>test;

    for(int i=1;i<=test;i++)
    {
        cin>>MyPos>>liftPos;

        int res= ((abs(MyPos-liftPos))+abs(MyPos-0))*4+19;

        cout<<"Case "<<i<<": "<<res<<endl;
    }

    return 0;
}

