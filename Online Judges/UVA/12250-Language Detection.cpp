#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
    //freopen("D:\\12250.txt","r",stdin);

    char a[15];
    int i=1;
    gets(a);
    while(a[0]!='#')
    {
        if(strcmp(a,"HELLO")==0)
        {
            cout<<"Case "<<i<<": ENGLISH"<<endl;
            i++;
        }
        else if(strcmp(a,"HOLA")==0)
        {
            cout<<"Case "<<i<<": SPANISH"<<endl;
            i++;
        }
        else if(strcmp(a,"HALLO")==0)
        {
            cout<<"Case "<<i<<": GERMAN"<<endl;
            i++;
        }
        else if(strcmp(a,"BONJOUR")==0)
        {
            cout<<"Case "<<i<<": FRENCH"<<endl;
            i++;
        }
        else if(strcmp(a,"CIAO")==0){
            cout<<"Case "<<i<<": ITALIAN"<<endl;
            i++;}
        else if(strcmp(a,"ZDRAVSTVUJTE")==0){
            cout<<"Case "<<i<<": RUSSIAN"<<endl;
            i++;}
        else
        {
            cout<<"Case "<<i<<": UNKNOWN"<<endl;
            i++;
        }
        gets(a);
    }
    return 0;
}
