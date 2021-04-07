#include<iostream>

using namespace std;

int main()
{
    int test,n,m,x,y;

    while(cin>>test,test!=0)
    {
        cin>>n>>m;
        while(test--)
        {
            cin>>x>>y;
            if(n==x||m==y)
                cout<<"divisa"<<endl;
            else if(x>n&&y>m)
                cout<<"NE"<<endl;
            else if(x<n&&y>m)
                cout<<"NO"<<endl;
            else if(x>n&&y<m)
                cout<<"SE"<<endl;
            else if(x<n&&y<m)
                cout<<"SO"<<endl;
        }
    }
    return 0;
}
