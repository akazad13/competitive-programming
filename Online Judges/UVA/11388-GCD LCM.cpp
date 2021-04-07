#include<iostream>

using namespace std;

int main()
{
    int test;
    long int GCD,LCM;

    cin>>test;

    while(test--)
    {
        cin>>GCD>>LCM;

        if(LCM%GCD==0)
            cout<<GCD<<" "<<LCM<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
