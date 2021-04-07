#include<stdio.h>
#include<stdlib.h>

struct tree
{
    long int idata;
    struct tree *LC;
    struct tree *RC;
};



struct tree* insert(struct tree *par,long int data)
{
    struct tree *NN;
    if(par==NULL)
    {
        NN=(struct tree*) malloc(sizeof(struct tree));
        NN->idata=data;
        NN->LC=NULL;
        NN->RC=NULL;
        par=NN;
    }
    else if(data<par->idata)
    {
        if(par->LC==NULL)
        {
            NN=(struct tree*) malloc(sizeof(struct tree));
            NN->idata=data;
            NN->LC=NULL;
            NN->RC=NULL;
            par->LC=NN;
        }
        else
        {
            insert(par->LC,data);
        }
    }

    else if(data>par->idata)
    {
        if(par->RC==NULL)
        {
            NN=(struct tree*) malloc(sizeof(struct tree));
            NN->idata=data;
            NN->LC=NULL;
            NN->RC=NULL;
            par->RC=NN;
        }
        else
        {
            insert(par->RC,data);
        }
    }

    return par;
}

struct tree* postorder(struct tree *par)
{
    struct node *LC, *RC;
    if(par==NULL)
        return par;
    postorder(par->LC);
    postorder(par->RC);
    printf("%ld\n",par->idata);
}

int main()
{
    struct tree *root, *root1;
    long int data;
    root=NULL;
    root1=NULL;
    scanf("%ld",&data);
    root=insert(root1,data);
    while(scanf("%ld",&data)==1)
    {
        insert(root,data);
    }
    postorder(root);

    return 0;
}

