#include<iostream>
#include<cstdio>
#include<cstring>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    

    string boy,girl;

    int i,j,a,b,temp;
    float pertge;
    while(getline(cin,boy))
    {
        getline(cin,girl);
        //put(cout,boy);
        //puts(girl);
        a=0;
        b=0;
        for(i=0;boy[i]!='\0';i++)
        {
            if(boy[i]>='a'&&boy[i]<='z')
            {
                a+=boy[i]-'a'+1;
            }
            else if(boy[i]>='A'&&boy[i]<='Z')
            {
                a+=boy[i]-'A'+1;
            }

        }
        while(a>9)
        {
            temp=a;
            a=0;
            while(temp!=0)
            {
                a+=temp%10;
                temp/=10;
            }
        }
       for(i=0;girl[i]!='\0';i++)
        {
            if(girl[i]>='a'&&girl[i]<='z')
            {
                b+=girl[i]-'a'+1;
            }
            else if(girl[i]>='A'&&girl[i]<='Z')
            {
                b+=girl[i]-'A'+1;
            }
        }
      //  cout<<a <<" " << b <<endl;

        while(b>9)
        {
            temp=b;
            b=0;
            while(temp!=0)
            {
                b+=temp%10;
                temp/=10;
            }
        }
        if(a>b)
        {
            pertge=(b/(float)a)*100;
        }
        else
        {
            pertge=(a/(float)b)*100;
        }

        printf("%.2f %%\n",pertge);
    }
    return 0;
}
