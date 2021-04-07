#include<iostream>

using namespace std;

int main()
{
    int n,k,p,q;
    while(cin>>n>>k)
    {
        q=n;
        while((n/k)>0)
        {
            p=n/k;
            n=p+n%k;
            q+=p;
            //cout<<n<<endl;
        }

        cout<<q<<endl;
    }
    return 0;
}
