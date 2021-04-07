#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,taka,dis;
    char str[20];
    bool flag=0;
    while(cin>>n)
    {
        char ch = getchar();
        vector<string> vec;
        map<string,int> myMap;
        map<string,int> ::iterator it;
        for(int i=0;i<n;i++)
        {
            scanf("%s ",str);
            vec.push_back(str);
            myMap[str]=0;
        }
        for(int i=0;i<n;i++)
        {
            cin>>str;
            cin>>taka;
            cin>>dis;

            if(dis!=0)
            {
                myMap[str]+=(taka%dis)-taka;
                for(int j=0;j<dis;j++)
                {
                    scanf(" %s",str);
                    myMap[str]+=taka/dis;
                }
            }

        }
        if(flag)
            cout<<"\n";
        for(int i=0;i<n;i++)
        {
            cout<<vec[i]<< " "<<myMap[vec[i]]<<endl;
        }

        flag=true;


    }

    return 0;
}
