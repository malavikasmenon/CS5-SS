#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 11

char l[10];
int count = 0;
struct symb
{
    int add;
    char label[10];
}sy[11];

int create(int num)
{
    int key;
    key = num % MAX;
    return key;
}

void lprob(int a[MAX], int key, int num)
{
    int flag = 0;
    int i;
    if(count == MAX)
    {
        printf("Hash Table is full...\nExiting...\n");
        exit(1);
    }

    else
    {
        count++;
        flag = 0;
        for(i = key; i < MAX; i++)
        {
            if(a[i] == 0)
            {   a[i] = num;
                flag = 1;
                sy[i].add = num;
                strcpy(sy[i].label, l);
                break;
            }
        }
        if(flag == 0)
        {
            for(i = 0; i < MAX; i++)
                {
                    if(a[i] == 0)
                    {   a[i] = num;
                        flag = 1;
                        sy[i].add = num;
                        strcpy(sy[i].label, l);
                        break;

                    }

                }

        }

    }

}

void display(int a[MAX])
{
    int i;
    printf("\nThe Symbol Table");
    printf("\n*******");
    printf("\nHash Values\tAddress\tLabel");
    for(i=0;i<MAX;i++)
    {
        printf("\n%d\t %d\t %s",i,sy[i].add,sy[i].label);
    }
}

void search()
{
    char la[10];
    int i,flag = 0, address;
    printf("Enter Label:");
    scanf("%s", la);
    for(i=0;i<MAX;i++)
    {
        if(strcmp(la, sy[i].label)==0)
            {
                address = sy[i].add;
                flag = 1;
                break;
            }

    }
    if(flag==1)
        {
            printf("The label was found at address %d.\n", address);
        }
        else
        {
            printf("The label was not found in the symbol table.\n");
        }
}
 
void modify()
{
    int address, flag=0, i;
    char la[10], str[100];
    printf("Enter address:");
    scanf("%d", &address);
    printf("Enter new label:");
    scanf("%s", la);
    for(i=0; i<MAX; i++)
    {
        if(sy[i].add == address)
        {
                    strcpy(sy[i].label, la);
                    flag = 1;
                    printf("Modification complete.\n");
                    break;
        }
    }
    if(flag==0)
    {
        printf("Address not found.\n");
    } 
}

void main()
{
    int a[MAX],num,key,i,ch;
    char ans='y';
    for(i=0;i<MAX;i++)
        a[i]=0;
    do
    {
        printf("\nSymbol Table Menu\n1.Create a Symbol Table\n2.Display\n3.Search in the Symbol Table\n4.Modify Symbol\n5.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: while(ans=='y')
                    {
                        printf("\nEnter the Address:");
                        scanf("%d",&num);
                        key=create(num);
                        printf("\nEnter The Label:");
                        scanf("%s",l);
                        lprob(a,key,num);
                        printf("\nDo you want to Continue(y/n)?");
                        scanf(" %c",&ans);
                    }
                    // display(a);
                    ans = 'y';
                    break;
            case 2: display(a);
                    break;
            case 3: search();
                    break;
            case 4: modify();
                    break;
           case 5: exit(0);
        }
    }while(ch<=5 && ch!= 0);

}
