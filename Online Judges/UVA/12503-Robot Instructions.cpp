#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define for(n) for(int i=1;i<=n;i++)
#define for(m) for(int j=1;j<=m;j++)
#define print(n) printf("%d\n",n)
#define ma map<int,int>

int main()
{
    int test;
    char str1[10], str2[10];
    cin>>test;
    for(test)
    {
        int pos=0;
        ma myMap;
        int m,command;
        cin>>m;
        char ch = getchar();
        for(m)
        {
            //cout<<j<<endl;
            cin>>str1;
            if(strcmp(str1,"LEFT")==0)
            {
                myMap[j]=1;
                pos--;

            }
            else if(strcmp(str1,"RIGHT")==0)
            {
                myMap[j]=2;
                pos++;
            }
            else
            {
                scanf(" %s ",&str2);
                cin>>command;
                if(myMap[command]==1)
                {
                    myMap[j]=1;
                    pos--;
                }
                else
                {
                    myMap[j]=2;
                    pos++;
                }

            }
        }

        print(pos);
    }

    return 0;
}
