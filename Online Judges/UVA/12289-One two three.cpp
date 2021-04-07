//not submitted
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int main()
{
    char word[6];

    int i,t,one,two,three,l;

    while(cin>>t)
    {
        while(t--)
        {
            cin>>word;
            one=0;
            two=0;
            three=0;
            if((l=strlen(word))<=3)
            {
                for(i=0;word[i]!='\0';i++)
                {
                    if((i==0&&word[i]=='o')||(i==1&&word[i]=='n')||(i==2&&word[i]=='e'))
                        one++;
                    if((i==0&&word[i]=='t')||(i==1&&word[i]=='w')||(i==2&&word[i]=='o'))
                        two++;
                }
            }
            else
            {
               for(i=0;word[i]!='\0';i++)
              {
                  if((i==0&&word[i]=='t')||(i==1&&word[i]=='h')||(i==2&&word[i]=='r')||(i==3&&word[i]=='e')||(i==4&&word[i]=='e'))
                        three++;
               }
          }

                if(one>=2)
                    cout<<"1"<<endl;
                else if(two>=2)
                    cout<<"2"<<endl;
                else if(three>=4)
                    cout<<"3"<<endl;
        }
    }
    return 0;
}
