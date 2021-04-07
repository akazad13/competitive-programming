#include<iostream>
#include <iomanip>

using namespace std;

int main()
{
    long int num,i;
    double fact;

    while(cin>>num)
    {
        if(num<0)
        {
            if(num%2==0)
                cout<<"Underflow!"<<endl;
            else
                cout<<"Overflow!"<<endl;
        }
        else if(num<8&&num>=0)
        {
            cout<<"Underflow!"<<endl;
        }
        else if(num>13)
        {
            cout<<"Overflow!"<<endl;
        }
        else
        {
            i=2;
            fact=1;
            while(i<=num)
            {
                fact=fact*i;
                i++;
            }
            cout<<fixed<<setprecision(0)<<fact<<endl;
        }

    }

    return 0;
}
