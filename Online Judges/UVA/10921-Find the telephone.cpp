#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main(){

    char line[32];

    while(gets(line)){
        for(int i=0; line[i]!='\0';i++){
                if(line[i]>='A'&&line[i]<='C')
                            line[i]='2';
                else if(line[i]>='D'&&line[i]<='F')
                            line[i]='3';
                else if(line[i]>='G'&&line[i]<='I')
                            line[i]='4';
                else if(line[i]>='J'&&line[i]<='L')
                            line[i]='5';
                else if(line[i]>='M'&&line[i]<='O')
                            line[i]='6';
                else if(line[i]>='P'&&line[i]<='S')
                            line[i]='7';
                else if(line[i]>='T'&&line[i]<='V')
                            line[i]='8';
                else if(line[i]>='W'&&line[i]<='Z')
                            line[i]='9';
        }

        puts(line);
    }

    return 0;
}
