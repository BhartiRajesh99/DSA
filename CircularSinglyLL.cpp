#include<iostream>
#include<cstdlib>
using namespace std;
class node
{
    public:
        int value;
        node *next;
        node()
        {
            value=0;
            next=NULL;
        }
};
class CircularSLL
{
    private:
        node *head;
        int size;
    public:
        CircularSLL()
        {
            head=NULL;
            size=0;
        }
        void insertAtBegin(int v)
        {
            node *temp=new node();
            if(temp==NULL)
            {
                cout<<"Memory not allocated....!!!!";
                exit(0);
            }
            temp->value=v;
            if(head==NULL)
            {
                head=temp;
                temp->next=head;
            }
            else
            {
                node *t=head;
                temp->next=head;
                while(t->next!=head)
                    t=t->next;
                head=temp;
                t->next=temp;
            }
            size++;
            cout<<"Element inserted....!!!!"<<endl;
        }
        void insertAtEnd(int v)
        {
            node *temp=new node();
            if(temp==NULL)
            {
                cout<<"Memory not allocated....!!!!";
                exit(0);
            }
            temp->value=v;
            node *t=head;
            if(t==NULL)
            {
                head=temp;
                temp->next=head;
            }
            else
            {
                while(t->next!=head)
                    t=t->next;
                t->next=temp;
                temp->next=head;
            }
            size++;
            cout<<"Element inserted....!!!!"<<endl;
        }
        void insertAtMiddle(int v,int position)
        {
            node *temp=new node();
            if(temp==NULL)
            {
                cout<<"Memory not allocated....!!!!";
                exit(0);
            }
            temp->value=v;
            if(position>size || position<0)
                cout<<"Position not exist....!!!!"<<endl;
            else
            {
                node *t=head;
                while(position>1)
                {
                    position--;
                    t=t->next;
                }
                temp->next=t->next;
                t->next=temp;
                size++;
                cout<<"Element inserted....!!!!"<<endl;
            }
        }
        int getSize() { return size; }
        void deleteELement(int position)
        {
            node *t=head;
            if(t==NULL)
                cout<<"List is empty....!!!!"<<endl;
            else
            {
                if(position==1)
                {
                    node *j=head;
                    head=j->next;
                    while(t->next!=j)
                        t=t->next;
                    t->next=head;
                    delete j;
                }
                else
                {
                    while(position>2)
                    {
                        position--;
                        t=t->next;
                    }
                    node *it=t->next;
                    t->next=it->next;
                    delete it;
                }
                size--;
                cout<<"Element deleted....!!!!"<<endl;
            }
        }
        void printElement()
        {
            node *t=head;
            if(t==NULL)
            {
                cout<<"List is empty....!!!!"<<endl;
                return;
            }
            cout<<"Elemnets are: ";
            while(t->next!=head)
            {
                cout<<t->value<<" ";
                t=t->next;
            }
            cout<<t->value<<endl;
        }
};
int main()
{
    CircularSLL sl;
    int choice,value,position;
    while(1)
    {
        cout<<"\n\n========================================================\n\n";
        cout<<"1. InsertAtBEgin"<<endl;
        cout<<"2. InsertAtMiddle"<<endl;
        cout<<"3. InsertAtEnd"<<endl;
        cout<<"4. GetSize"<<endl;
        cout<<"5. DeleteElement"<<endl;
        cout<<"6. PrintElement"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter the element:";
                cin>>value;
                sl.insertAtBegin(value);
                break;
            }
            case 2:
            {
                cout<<"Enter the element and position:";
                cin>>value>>position;
                sl.insertAtMiddle(value,position);
                break;
            }
            case 3:
            {
                cout<<"Enter the element:";
                cin>>value;
                sl.insertAtEnd(value);
                break;
            }
            case 4:
            {
                cout<<"Size="<<sl.getSize()<<endl;
                break;
            }
            case 5:
            {
                cout<<"Enter the position:";
                cin>>position;
                sl.deleteELement(position);
                break;
            }
            case 6:
            {
                sl.printElement();
                break;
            }
            case 7:
            {
                exit(0);
            }
            default:
            {
                cout<<"Invalid Choice....!!!!"<<endl;
            }
        }
    }
    return 0;
}