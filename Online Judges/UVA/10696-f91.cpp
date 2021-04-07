#include<iostream>
using namespace std;

int main()
{
    long int n;
    cin>>n;
    while(n!=0)
    {
        if(n>=101)
            cout<<"f91("<<n<<") = "<<n-10<<endl;
        else
            cout<<"f91("<<n<<") = "<<91<<endl;
        cin>>n;
    }
    return 0;
}
