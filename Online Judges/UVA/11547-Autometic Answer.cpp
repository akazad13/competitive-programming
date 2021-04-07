#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long int num;
    int test;

    cin>>test;

    while(test--)
    {
        cin>>num;

        num=num*567;
        num=num/9;
        num=num+7492;
        num=num*235;
        num=num/47;
        num=num-498;

        cout<<abs((num/10)%10)<<endl;
    }

    return 0;
}
