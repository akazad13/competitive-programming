#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main()
{
    //freopen("D:\\12468.txt","r",stdin);
    int a,b;
    int temp1,temp2;
    cin>>a>>b;
    while(a!=-1||b!=-1)
    {
        if(a>b)
        {
            a=a+b;
            b=a-b;
            a=a-b;
        }
        temp1=abs(b-a);
        temp2=100-b+a;

        if(temp1<temp2)
            cout<<temp1<<endl;
        else
            cout<<temp2<<endl;
        cin>>a>>b;
    }
    return 0;
}
