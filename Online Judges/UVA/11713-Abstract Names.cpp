#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    char name1[21],name2[21];

    int n,i,p;

    while(cin>>n)
    {
        while(n--)
        {
            p=1;
            cin>>name1;
            cin>>name2;
            if(strlen(name1)==strlen(name2))
            {
                for(i=0;name1[i]!='\0';i++)
                {
                    if(name1[i]!='a'&&name1[i]!='e'&&name1[i]!='i'&&name1[i]!='o'&&name1[i]!='u')
                    {
                        if(name1[i]!=name2[i])
                            {p=0;
                            break;}
                    }
                }
            }
            else
                p=0;

            if(p)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;

}
