#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    cin>>test;

    vector< pair <int, string> > database;
    vector< pair <int, string> > :: iterator it;

    int count=0;

    string input_index;
    string input_float;

    char ch=getchar();


    while(test--)
    {
        count++;
        char ch=getchar();

        int index;

        string value;

        getline(cin, input_index);
        getline(cin, input_float);

        stringstream ss1(input_index), ss2(input_float);

        while(ss1>>index)
        {
            ss2>>value;
            database.push_back(pair<int, string> (index, value));
        }

        sort(database.begin(),database.end());

        if(count>1)
            cout<<"\n";

       /* for(int i=0;i<database.size();i++)
            cout<<database[i].second<<"\n";

            */

        for(it=database.begin();it!=database.end();it++)
            cout<<it->second<<"\n";

        database.clear();


    }

    return 0;
}
