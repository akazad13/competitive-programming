#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{
   // freopen("10226.txt","r",stdin);

    int test;

    while(cin>>test,test)
    {

        map<string, int>myMap;
        map<string, int> :: iterator it;

        while(test--)
        {
           // char arr[10][10];

           string str1[6];

            string str;

            cin >> str1[0] >> str1[1] >> str1[2] >> str1[3] >> str1[4];
            sort(str1, str1+ 5);


            //cout<<strcmp(arr[1],arr[0])<<endl;


           /* for(int i=0;i<5-1;i++)
            {
                for(int j=i+1;j<5;j++)
                {
                    if(strcmp(arr[i],arr[j])==1)
                    {
                        char temp[10];
                        strcpy(temp,arr[i]);
                        strcpy(arr[i],arr[j]);
                        strcpy(arr[j],temp);
                    }
                }
            } */

            for(int i=0;i<5;i++)
            {
                str+=str1[i];
                //if(i!=4)
                    //str+=' ';
            }
            //str+='\0';

            //cout<<str<<"\n";



            myMap[str]++;

        }

        int max=0;

        for(it=myMap.begin();it!=myMap.end();it++)
        {
            if(max<it->second)
                max=it->second;
        }

        int count=0;

        for(it=myMap.begin();it!=myMap.end();it++)
        {
            if(max==it->second)
                count+=it->second;
        }

        //if(count>max)

            cout<<count<<"\n";

      //  else
          //  cout<<max<<"\n";





        myMap.clear();
    }

    return 0;
}

