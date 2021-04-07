#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

struct node{

    char cdata;

    node *LC;
    node *RC;

};

node* insertData(node *par, char data)
{
    node *NN;

    if(par==NULL)
    {
        NN=new node;
        NN->cdata=data;
        NN->LC=NULL;
        NN->RC=NULL;
        par=NN;
        return par;
    }
    else if(data<par->cdata)
    {
        if(par->LC==NULL)
        {
            NN=new node;
            NN->cdata=data;
            NN->LC=NULL;
            NN->RC=NULL;
            par->LC=NN;
        }

        else
        {
            insertData(par->LC,data);
        }
    }

     else if(data>par->cdata)
    {
        if(par->RC==NULL)
        {
            NN=new node;
            NN->cdata=data;
            NN->LC=NULL;
            NN->RC=NULL;
            par->RC=NN;
        }

        else
        {
            insertData(par->RC,data);
        }
    }


}

node* print(node *par)
{
    if(par==NULL)
        return par;
    printf("%c",par->cdata);
    print(par->LC);
    print(par->RC);
}

int main()
{
    char a[100];
    char ch;
    int i;


    while(cin>>ch)
    {
        i=0;
        while(ch!='*'&&ch!='$')
        {
            if(ch!=' ')
                a[i++]=ch;
            cin>>ch;
        }
        a[i]='\0';
        node *root;
        root=NULL;
        root=insertData(NULL,a[i-1]);

        for(int j=i-2;j>=0;j--)
        {
            insertData(root,a[j]);
        }

        print(root);

        printf("\n");

        if(ch=='$')
            break;

    }
    return 0;
}
