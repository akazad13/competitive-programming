#include<iostream>

using namespace std;

int main()
{
    int test;

    int e,found,c,num;

    cin>>test;

    while(test--)
    {
        cin>>e>>found>>c;
        e=e+found;
        num=0;
        while(e>=c)
        {
            num+=e/c;
            e=e/c+e%c;
        }

        cout<<num<<endl;
    }
}
