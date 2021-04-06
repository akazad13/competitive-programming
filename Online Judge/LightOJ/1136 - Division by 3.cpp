#include<iostream>
#include<iostream>

using namespace std;

int div3(int n)
{
    if(n==0)
        return 0;
    int res=(n/3)*2;

    if((n%3)>1)
        res=res+1;
    return res;
}

int main()
{
    int test,upper_bound,lower_bound;
    cin>>test;

    for(int i=1;i<=test;i++)
    {
        cin>>lower_bound>>upper_bound;

        cout<<"Case "<<i<<": "<<div3(upper_bound)-div3(lower_bound-1)<<endl;
    }
    return 0;
}
