//submitted
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
   //freopen("D:\\Programing Code\\ONLINE\\doc\\10082.txt","r",stdin);
    char line[1000];
    int i,l;

    while(gets(line))
    {
        l=strlen(line);
        for(i=0;i<l;i++)
        {
            switch(line[i])
            {
            case '=':
                line[i]='-';
                break;
            case '-':
                line[i]='0';
                break;
            case '0':
                line[i]='9';
                break;
            case '9':
                line[i]='8';
                break;
            case '8':
                line[i]='7';
                break;
            case '7':
                line[i]='6';
                break;
            case '6':
                line[i]='5';
                break;
            case '5':
                line[i]='4';
                break;
            case '4':
                line[i]='3';
                break;
            case '3':
                line[i]='2';
                break;;
            case '2':
                line[i]='1';
                break;
            case '1':
                line[i]='`';
                break;
            case '\\':
                line[i]=']';
                break;
            case ']':
                line[i]='[';
                break;
            case '[':
                line[i]='P';
                break;
            case '\'':
                line[i]=';';
                break;
            case ';':
                line[i]='L';
                break;
            case '/':
                line[i]='.';
                break;
            case '.':
                line[i]=',';
                break;
            case ',':
                line[i]='M';
                break;
            case 'P':
                line[i]='O';
                break;
            case 'O':
                line[i]='I';
                break;
            case 'I':
                line[i]='U';
                break;
            case 'U':
                line[i]='Y';
                break;
            case 'Y':
                line[i]='T';
                break;
             case 'T':
                line[i]='R';
                break;
            case 'R':
                line[i]='E';
                break;
            case 'E':
                line[i]='W';
                break;
            case 'W':
                line[i]='Q';
                break;
            case 'L':
                line[i]='K';
                break;
            case 'K':
                line[i]='J';
                break;
            case 'J':
                line[i]='H';
                break;
            case 'H':
                line[i]='G';
                break;
             case 'G':
                line[i]='F';
                break;
            case 'F':
                line[i]='D';
                break;
            case 'D':
                line[i]='S';
                break;
            case 'S':
                line[i]='A';
                break;
            case 'M':
                line[i]='N';
                break;
            case 'N':
                line[i]='B';
                break;
            case 'B':
                line[i]='V';
                break;
            case 'V':
                line[i]='C';
                break;
             case 'C':
                line[i]='X';
                break;
            case 'X':
                line[i]='Z';
                break;
            }
        }
        cout<<line<<endl;
    }
    return 0;
}
