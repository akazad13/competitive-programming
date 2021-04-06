#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    int x1,y1,x2,y2,M;
    int lowX,upX,lowY,upY;

    cin>>test;

    for(int i=1;i<=test;i++)
    {
        cin>>x1>>y1;
        cin>>x2>>y2;

        cout<<"Case "<<i<<":"<<endl;

        cin>>M;

        int a,b;

        lowX=x1;
        upX=x2;
        lowY=y1;
        upY=y2;

        for(int k=0;k<M;k++)
        {
            cin>>a>>b;

            if(a>=lowX&&a<=upX&&b>=lowY&&b<=upY)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}
