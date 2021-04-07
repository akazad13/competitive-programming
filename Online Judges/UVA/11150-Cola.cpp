#include<iostream>

using namespace std;

int main()
{
    int n,r,s,p,q;
    while(cin>>n)
    {
        q=n;
        r=n+1;
        s=n;
        while((n/3)>0)
        {
            p=n/3;
            n=p+n%3;
            q+=p;
            //cout<<n<<endl;
        }
        while((r/3)>0)
        {
            p=r/3;
            r=p+r%3;
            s+=p;
        }
        if(q>s)
            cout<<q<<endl;
        else
            cout<<s<<endl;
    }
    return 0;
}

