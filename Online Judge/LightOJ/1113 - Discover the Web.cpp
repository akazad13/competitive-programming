#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    cin>>test;

    for(int i=1;i<=test;i++)
    {
        printf("Case %d:\n",i);
        char str1[10];
        string str2;
        string cur = "http://www.lightoj.com/";

        stack<string> Forword;
        stack<string> Backword;

        while( scanf(" %s",str1)!=EOF)
        {

            if(strcmp(str1,"QUIT")!=0)
            {
                if(strcmp(str1,"VISIT")==0)
                {
                    char ch=getchar();
                    getline(cin,str2);
                    Backword.push(cur);
                    cur=str2;
                    cout<<cur<<endl;

                   while(Forword.empty()==0)
                   {
                       Forword.pop();
                   }
                }

                else if(strcmp(str1,"BACK")==0)
                {
                    if(Backword.empty())
                    {
                        printf("Ignored\n");
                    }
                    else
                    {
                        Forword.push(cur);
                         cur = Backword.top();
                         cout<<cur<<"\n";
                         Backword.pop();
                    }
                }

                else if(strcmp(str1,"FORWARD")==0)
                {
                    if(Forword.empty())
                    {
                        printf("Ignored\n");
                    }
                    else
                    {
                        Backword.push(cur);
                        cur=Forword.top();
                        cout<<cur<<"\n";
                        Forword.pop();
                    }
                }
            }
            else
                break;
        }
    }
    return 0;
}
