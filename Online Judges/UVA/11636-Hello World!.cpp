#include<iostream>

using namespace std;

int main()
{
    int n,b,i,j=1;
    cin>>n;
    while(n>=0)
    {
        b=1;
        i=0;
        while(b<n)
        {
            b=b*2;
            i++;
        }
        cout<<"Case "<<j<<": "<<i<<endl;
        cin>>n;
        j++;
    }
    return 0;
}
