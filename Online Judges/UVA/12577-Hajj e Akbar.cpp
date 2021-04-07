#include<iostream>

using namespace std;

int main()
{
    char haj[6];
    int i=1;
    cin>>haj;
    while(haj[0]!='*')
    {
        if(haj[0]=='H')
            cout<<"Case "<<i<<": Hajj-e-Akbar"<<endl;
        else
            cout<<"Case "<<i<<": Hajj-e-Asghar"<<endl;
        i++;
        cin>>haj;
    }
    return 0;
}


