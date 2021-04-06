#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
    long long int donate,total;
    char a[6];

    int i,test;
    cin>>test;

    for(int i=1;i<=test;i++)
    {
        cout<<"Case "<<i<<":"<<endl;
         total=0;
         int t;
         cin>>t;
        while(t--)
        {
            cin>>a;
            if(strcmp(a,"donate")==0)
            {
                cin>>donate;
                total+=donate;
            }
            else if(strcmp(a,"report")==0)
            {
                cout<<total<<endl;
            }
        }
    }
    return 0;
}

