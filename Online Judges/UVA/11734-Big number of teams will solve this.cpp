#include<iostream>
#include<cstring>
#include<cstdio>
#include<cctype>

using namespace std;

int main(){

    char judge[25],parti[25],a[25];

    int test;

    cin>>test;
    char ch=getchar();

    for(int i=1;i<=test;i++){
        gets(parti);
        gets(judge);

        if(strlen(parti)==strlen(judge)){
            if(strcmp(parti,judge)==0){
                cout<<"Case "<<i<<": Yes"<<endl;
            }
            else
                cout<<"Case "<<i<<": Wrong Answer"<<endl;
        }

        else{
                int k=0;
            for(int j=0;parti[j]!='\0';j++){

                if(isalpha(parti[j])){
                    a[k++]=parti[j];
                }

            }
            a[k]='\0';
            if(strcmp(a,judge)==0){
                cout<<"Case "<<i<<": Output Format Error"<<endl;
            }
            else
                cout<<"Case "<<i<<": Wrong Answer"<<endl;
        }
    }
    return 0;

}
