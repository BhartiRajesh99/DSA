#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int v;
    struct Node *next;
    struct Node *prev;
}Node;
// typedef Node Node; -> Another way of changing struct Node to Node
void insertAtEnd(Node **head,int v)
{
    Node *temp=(Node*)malloc(sizeof(Node));
    if(temp==NULL)
    {
        printf("Memory not allocated....!!!!\n");
        return;
    }
    temp->prev=temp->next=NULL;
    temp->v=v;
    if(*head==NULL)
        *head=temp;
    else
    {
        Node *it=*head;
        while(it->next)
            it=it->next;
        it->next=temp;
        temp->prev=it;
    }
    printf("Node inserted....!!!!\n");
}
void insertAtMiddle(Node **head,int v,int position)
{
    Node *temp=(Node*)malloc(sizeof(Node));
    if(temp==NULL)
    {
        printf("Memory not allocated....!!!!\n");
        return;
    }
    temp->next=temp->prev=NULL;
    temp->v=v;
    Node *it=*head;
    if(position==1)
    {
        if(*head!=NULL)
        {
            temp->next=*head;
            (*head)->prev=temp;
        }
        *head=temp;
    }
    else if(position<=0){
        printf("Position doesn't exist....!!!!\n");
        return;
    }
    else
    {
        int flag=0;
        while(position-2)
        {
            it=it->next;
            if(!it)
            {
                flag=1;
                break;
            }
            --position;
        }
        if(flag || !(it->next))
        {
            printf("Position doesn't exist....!!!!\n");
            return;
        }
        temp->next=it->next;
        temp->prev=it;
        it->next=temp;
        temp->next->prev=temp;
    }
    printf("Node inserted....!!!!\n");
}
void insertAtBegin(Node **head,int v)
{
    Node *temp=(Node*)malloc(sizeof(Node));
    if(temp==NULL)
    {
        printf("Memory not allocated....!!!!\n");
        return;
    }
    temp->next=temp->prev=NULL;
    temp->v=v;
    if(*head!=NULL)
    {
        temp->next=*head;
        (*head)->prev=temp;
    }
    *head=temp;
    printf("Node inserted....!!!!\n");
}
void Delete(Node **head,int position)
{
    if(*head==NULL)
    {
        printf("List is empty....!!!!\n");
        return;
    }
    Node *it=*head;
    if(position==1)
    {
        *head=it->next;
        if(it->next)
            (*head)->prev=it->prev;
        free(it);
    }
    else
    {
        int flag=0;
        while(position-2)
        {
            it=it->next;
            if(!it)
            {
                flag=1;
                break;
            }
            --position;
        }
        if(flag || !(it->next))
        {
            printf("Position doesn't exist....!!!!\n");
            return;
        }
        Node *t=it->next;
        it->next=t->next;
        if(t->next)
            t->next->prev=it;
        free(t);
    }
    printf("Node deleted....!!!!\n");
}
void display(Node *head)
{
    Node *it=head;
    if(head==NULL)
    {
        printf("List is empty....!!!!\n");
        return;
    }
    printf("List is:");
    while(it)
    {
        printf("%d->",it->v);
        it=it->next;
    }
    printf("\n");
}
int main()
{
    Node *head=NULL;
    int choice,v,pos;
    while(1)
    {
        printf("\n==========================================================\n\n");
        printf("1.InsertAtBegin\n");
        printf("2.InsertAtMiddle\n");
        printf("3.InsertAtEnd\n");
        printf("4.Delete\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter element:");
                scanf("%d",&v);
                insertAtBegin(&head,v);
                break;
            case 2:
                printf("Enter element and position:");
                scanf("%d%d",&v,&pos);
                insertAtMiddle(&head,v,pos);
                break;
            case 3:
                printf("Enter element:");
                scanf("%d",&v);
                insertAtEnd(&head,v);
                break;
            case 4:
                printf("Enter position:");
                scanf("%d",&pos);
                Delete(&head,pos);
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice....!!!!\n");
        }
    }
    return 0;
}
