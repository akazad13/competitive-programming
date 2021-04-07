#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    string STR="abcdefghijklmnopqrstuvwxyz";
//    str1++;

    string str1,str2,str3,str4,str5;

    //str2=str3=str4=str5=str1;

    //str  = str1 + str2 + str3 +str4+ str5;
   // str = ch+ch1+ch2;


   //cout<<str<<endl;
    string str;

   map<string,int> myMap;
   //map<string, int > :: iterator it;
   int count = 1;

   for(int i=0;i<26;i++)
    {
       str = STR[i];

        myMap[str]=count++;

   }


   for(int i=0;i<26;i++)
   {
       for(int j=i+1;j<26;j++)
       {
           //string str;
            str1 = STR[i];
            str2 = STR[j];
            str  = str1 + str2;
            //cout<<str<<endl;
           myMap[str]=count++;
       }
   }

   for(int i=0;i<26;i++)
   {
       for(int j=i+1;j<26;j++)
       {
           for(int k=j+1;k<26;k++)
           {

               str1 = STR[i];
               str2=STR[j];
               str3 =STR[k];

               str= str1+str2+str3;

               myMap[str] = count++;

           }

       }
   }

   for(int i=0;i<26;i++)
   {
       for(int j=i+1;j<26;j++)
       {
           for(int k=j+1;k<26;k++)
           {
               for(int l = k+1; l<26;l++)
               {
                   str1 = STR[i];
                    str2=STR[j];
                    str3 =STR[k];
                    str4 =STR[l];

                    str= str1+str2+str3+str4;
                    myMap[str] = count++;
               }
           }

       }
   }


   for(int i=0;i<26;i++)
   {
       for(int j=i+1;j<26;j++)
       {
           for(int k=j+1;k<26;k++)
           {
               for(int l = k+1; l<26;l++)
               {
                   for(int m=l+1;m<26;m++)
                   {
                        str1 = STR[i];
                        str2=STR[j];
                        str3 =STR[k];
                        str4 =STR[l];
                        str5= STR[m];

                    str= str1+str2+str3+str4+str5;
                        myMap[str] = count++;
                   }

               }
           }

       }
   }

   //string str;

   while(getline(cin,str))
   {
       if(myMap[str]>=1&&myMap[str]<=83681)
       {
           cout<<myMap[str]<<"\n";
       }
       else
        cout<<0<<"\n";
   }

    return 0;

}
