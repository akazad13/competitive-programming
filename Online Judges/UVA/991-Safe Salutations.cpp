#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long int factorial(int p,int q)
{
    if(p==q)
        return 1;
    return (p*factorial(p-1,q));
}

int main()
{
    long long int N=-1,n;
    int pairs=-1;
    while(cin>>pairs)
    {
        if(N!=-1)
            cout<<"\n";
        N=factorial((2*pairs),(pairs+1));
        n=factorial(pairs,1);

        cout<<(N/n)<<endl;
    }
    return 0;
}
