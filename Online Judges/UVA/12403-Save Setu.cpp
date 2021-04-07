#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{


    long long int donate,total;
    char a[6];

    int i,t;

    while(cin>>t)
    {
         total=0;
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
