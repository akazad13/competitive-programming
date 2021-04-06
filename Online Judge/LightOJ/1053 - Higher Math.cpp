#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main()

{
    int test;
    int a,b,c;
    long long int M,N,P;

    cin>>test;

    for(int i=1;i<=test;i++)
    {
        cin>>a>>b>>c;
        M=a*a;
        N=b*b;
        P=c*c;

        if((M==N+P)||(N==P+M)||(P==M+N))
            cout<<"Case "<<i<<": yes"<<endl;
        else
            cout<<"Case "<<i<<": no"<<endl;
    }

    return 0;
}
