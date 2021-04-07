#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int GrCD(int a, int b)
{
    int rem;
    while(b!=0)
    {
        rem=a%b;
        a=b;
        b=rem;
    }

    return a;
}

int main()
{
    int N,i,j,GCD;

    while(cin>>N,N){
            GCD=N-1;

        for(i=2;i<N;i++)
        {
            for(j=i+1;j<=N;j++)
            {
                GCD+=GrCD(i,j);
            }
        }

        cout<<GCD<<endl;
    }

    return 0;
}
