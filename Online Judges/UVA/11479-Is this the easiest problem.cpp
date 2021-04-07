#include<iostream>
#include<bits/stdc++.h>


using namespace std;
int main()

{
    int test,i;

    double A,B,C;

    cin>>test;

    for(i=1;i<=test;i++)
    {
        cin>>A>>B>>C;
        if((A+B)<=C||(A+C)<=B||(B+C)<=A)
            cout<<"Case "<<i<<": Invalid"<<endl;
        else if(A==B&&B==C)
            cout<<"Case "<<i<<": Equilateral"<<endl;
        else if(A==B||B==C||A==C)
            cout<<"Case "<<i<<": Isosceles"<<endl;
        else
            cout<<"Case "<<i<<": Scalene"<<endl;
    }
    return 0;
}
