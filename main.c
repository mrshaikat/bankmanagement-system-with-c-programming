#include<stdio.h>
#include <stdlib.h>
#include<string.h>

struct node
{
    char fname[20];
    char lname[20];
    char phn[11];
    int acno;
    char pswrd[4];
    char rpswrd[4];
    double acb;
    struct node *next;
}*head;


void registration(int vr)
{
    struct node *current,*newnode;
    char fnam[20],lnam[20],ph[11];
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Unable to allocate memory\n");
    }
    else
    {
        char fnam[]="Amatul";
        char lnam[]="Bushra";
        char ph[]="01676436075";
        char ps[]="2020";
        strcpy(head->fname,fnam);
        strcpy(head->lname,lnam);
        strcpy(head->phn,ph);
        head->acno=1001;
        head->acb=0.0;
        strcpy(head->pswrd,ps);

        head->next=NULL;
        current=head;

        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)

        {
            printf("Unable to allocate memory\n");
            //break;
        }
        else
        {
            char fnam[]="Mazharul";
            char lnam[]="Islam";
            char ph[]="01515267787";
            char ps[]="3030";
            strcpy(newnode->fname,fnam);
            strcpy(newnode->lname,lnam);
            strcpy(newnode->phn,ph);
            newnode->acno=1002;
            newnode->acb=0.0;
            strcpy(newnode->pswrd,ps);

            newnode->next=NULL;
            current->next=newnode;
            current=current->next;
        }
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Unable to allocate memory\n");
            //break;
        }
        else
        {
            char fnam[]="Saikat";
            char lnam[]="Hossain";
            char ph[]="01737154982";
            char ps[]="4040";
            strcpy(newnode->fname,fnam);
            strcpy(newnode->lname,lnam);
            strcpy(newnode->phn,ph);
            newnode->acno=1003;
            newnode->acb=0.0;
            strcpy(newnode->pswrd,ps);

            newnode->next=NULL;
            current->next=newnode;
            current=current->next;
        }
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Unable to allocate memory\n");
            //break;
        }
        else
        {
            char fnam[]="Mohammad";
            char lnam[]="Sohel";
            char ph[]="01684546434";
            char ps[]="6374";
            strcpy(newnode->fname,fnam);
            strcpy(newnode->lname,lnam);
            strcpy(newnode->phn,ph);
            newnode->acno=1004;
            newnode->acb=0.0;
            strcpy(newnode->pswrd,ps);

            newnode->next=NULL;
            current->next=newnode;
            current=current->next;
        }

    }

    if(vr==0)
    {
        int more;
        do
        {
            int slct;
            printf("\nSelect what you want to do.\n\nPress '1' -->Open new account.\nPress '2' -->Edit any a/c information.\nPress '3' -->Delete any account.\nPress '4' -->Search any account.\nPress '5' -->Display all account information.\n");
            scanf("%d",&slct);
            switch(slct)
            {
            case 1:
                newac();
                break;
            case 2:
                editac();
                break;
            case 3:
                acdelete();
                break;
            case 4:
                search();
                break;
            case 5:
                dispaly();
                break;
            }
            printf("\nAre you want to do anymore operation?if want press -->'1':");
            scanf("%d",&more);
        }

        while(more==1);
    }
    else if(vr==1)
    {
        int more2;
        char paswrd[10], ch;
        int i,acn,cs;
        printf("\nEnter A/C no. : ");
        scanf("%d",&acn);
        printf("Enter password: ");

        for(i=0; i<4; i++)
        {
            ch = getch();
            paswrd[i] = ch;
            ch = '*' ;
            printf("%c",ch);
        }
        do
        {
            int a=0,wd,dp;
            char nps[4];
            current=head;

            while(current!=NULL)
            {
                if(acn==current->acno)
                {
                    printf("\nEnter your choise\n\nPress '1' for A/C balance inquiry\nPress '2' for balance withdraw\nPress '3' for deposite money\nPress '4' for change password\n\n");
                    scanf("%d",&cs);
                    switch(cs)
                    {
                    case 1:
                        printf("\nUser name: %s %s\n",current->fname,current->lname);
                        printf("User phone no: %s\n",current->phn);
                        printf("User a/c no: %d\n",current->acno);
                        printf("User a/c balance: %.2lf\n",current->acb);
                        break;
                    case 2:
                        printf("Enter the amount what you want withdraw <minimum 500,maximum 20000> : ");
                        scanf("%d",&wd);
                        current->acb=current->acb-wd;
                        break;
                    case 3:
                        printf("Enter the amount what you want deposit <minimum 500> :");
                        scanf("%d",&dp);
                        current->acb=current->acb+dp;
                        break;
                    case 4:printf("Enter new password : ");
                    scanf("%s",&nps);
                    strcpy(current->pswrd,nps);
                        break;
                    }


                    a=1;
                }
                current=current->next;
            }
            if(a==0)
            {
                printf("Do not match\n");
            }
            printf("\nAre you want to do anymore operation?if want press -->'1':");
            scanf("%d",&more2);
        }

        while(more2==1);
    }
}


void newac()
{
    struct node *newnode,*current;
    int a;
    newnode=(struct node*)malloc(sizeof(struct node));
    current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    printf("Enter user first Name:");
    scanf("%s",&newnode->fname);
    printf("Enter user last Name:");
    scanf("%s",&newnode->lname);
    printf("Enter user's phone no.:");
    scanf("%s",&newnode->phn);
    printf("Enter user's account no.:");
    scanf("%d",&newnode->acno);
    printf("Enter user's first account balance:");
    scanf("%lf",&newnode->acb);
    printf("Enter user's password <any 4 characters>:");
    scanf("%s",&newnode->pswrd);
    printf("Re-type password:");
    scanf("%s",&newnode->rpswrd);
    a=strcmp(newnode->pswrd,newnode->rpswrd);
    while(a!=0)
    {
        printf("Re-type password:");
        scanf("%s",&newnode->rpswrd);
        newnode->rpswrd[4]=newnode->rpswrd[4];
    }
    newnode->next=NULL;
    current->next=newnode;
}

void editac()
{
    struct node *current;
    int item,a=0,b;
    printf("Enter an a/c no. what you want to edit:");
    scanf("%d",&item);
    current=head;
    while(current!=NULL)
    {
        if(current->acno==item)
        {
            printf("Enter user new first Name:");
            scanf("%s",&current->fname);
            printf("Enter user new last Name:");
            scanf("%s",&current->lname);
            printf("Enter user's new phone no.:");
            scanf("%s",&current->phn);
            printf("Enter user's new account no.:");
            scanf("%d",&current->acno);
            printf("Enter user's new account balance:");
            scanf("%lf",&current->acb);
            printf("Enter user's new password <any 4 characters>:");
            scanf("%s",&current->pswrd);
            printf("Re-type password:");
            scanf("%s",&current->rpswrd);
            b=strcmp(current->pswrd,current->rpswrd);
            while(b!=0)
            {
                printf("Re-type password:");
                scanf("%s",&current->rpswrd);
                current->rpswrd[4]=current->rpswrd[4];
            }
            a=1;
            break;
        }
        current=current->next;
    }
    if(a==0)
    {
        printf("Does not match A/C\n");
    }
}



void acdelete()
{
    struct node *current,*prev;
    current=head;
    int acn;
    printf("Enter the a/c no. you want to delete:");
    scanf("%d",&acn);
    if(head->acno==acn)
    {
        head=current;
        head=head->next;
        free(current);
    }
    else
    {
        while(current!=NULL)
        {

            if(current->acno==acn)
            {
                prev->next=current->next;
                free(current);
                break;
            }
            prev=current;
            current=current->next;
        }
    }
}


void search()
{
    struct node *current;
    int item,a=0;
    printf("Enter an a/c no. what you want to searching:");
    scanf("%d",&item);
    current=head;
    while(current!=NULL)
    {
        if(current->acno==item)
        {
            printf("\nUser name: %s %s\n",current->fname,current->lname);
            printf("User phone no: %s\n",current->phn);
            printf("User a/c no: %d\n",current->acno);
            printf("User a/c balance: %.2lf\n",current->acb);
            a=1;
            break;
        }
        current=current->next;
    }
    if(a==0)
    {
        printf("Does not match A/C\n");
    }
}

void dispaly()
{
    struct node *current;
    current=head;
    while(current!=NULL)
    {
        printf("\nUser name: %s %s\n",current->fname,current->lname);
        printf("User phone no: %s\n",current->phn);
        printf("User a/c no: %d\n",current->acno);
        printf("User a/c balance: %.2lf\n",current->acb);
        current=current->next;
    }
}



int main()
{
    system("color 0A");
    printf("********\tWELCOME TO BANGLADESH BANK\t********\n\n\t\tFirst you need to log in\n\n");
    char id[10]="Admin",usr[10],ps[4]="1010",pw[4];
    int cm,cmp,vr;
    char pasword[10],usrname[10], ch;
    int i;
    printf("Press '0' -->Log in as Administration \nPress '1' -->Log in as Customer\n\n");
    int rg;
    scanf("%d",&rg);
    switch(rg)
    {
    case 1:
        vr=1;
        registration(vr);
        break;
    case 0:
        vr=0;

        printf("\nEnter admin name: ");
        scanf("%s",&usrname);
        printf("Enter password: ");

        for(i=0; i<4; i++)
        {
            ch = getch();
            pasword[i] = ch;
            ch = '*' ;
            printf("%c",ch);
        }
        cm=strcmp(id,usrname);
        if(cm==0&&ps[0]==pasword[0]&&ps[1]==pasword[1]&&ps[2]==pasword[2]&&ps[3]==pasword[3])
        {
            registration(vr);

        }
        else
        {
            printf("\nWrong username or password\n");
        }
        break;
    default:
        printf("\nWrong press\n");
        break;
    }
    return 0;
}
