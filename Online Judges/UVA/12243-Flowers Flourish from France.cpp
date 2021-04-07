#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctype.h>
using namespace std;

int main()
{
    //freopen("D:\\23.txt","r",stdin);
    string p;
    char q,r;
    int pp,i;
    getline(cin,p);
    while(p[0]!='*')
    {
        r=tolower(p[0]);
        pp=1;
        for(i=1;p[i]!='\0';i++)
        {
            if(p[i]==' ')
            {
                q=tolower(p[i+1]);
                //cout<<"q="<<q<<endl;
                //cout<<"r="<<r<<endl;
                if(q!=r)
                {pp=0;
                break;}
            }
        }
        if(pp)
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;
        getline(cin,p);
    }
    return 0;

}
