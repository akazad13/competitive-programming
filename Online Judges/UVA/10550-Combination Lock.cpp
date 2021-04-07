#include<iostream>

using namespace std;

int main()
{
    int initia, p,q,r;

    while(cin>>initia>>p>>q>>r,initia|p|q|r)
    {
        int ans=1080+((initia-p)>0?((initia-p)*9):((40+(initia-p))*9))+((q-p)>=0?((q-p)*9):((40+(q-p))*9))+((q-r)>=0?((q-r)*9):((40+(q-r))*9));
        cout<<ans<<endl;
    }

    return 0;
}
