#include<iostream>
#include<cstdlib>
using namespace std;
class Node
{
    public:
        Node *next;
        int value;
        Node()
        {
            next=NULL;
            value=0;
        }
};
class SinglyLL
{
    private:
        Node *head;
        int size;
    public:
        SinglyLL()
        {
            head=NULL;
            size=0;
        }
        void insertAtBegin(int v)
        {
            Node *temp=new Node();
            if(temp==NULL)
            {
                cout<<"Memory not allocated....!!!!"<<endl;
                exit(0);
            }
            temp->value=v;
            if(head==NULL)
                head=temp;
            else
            {
                temp->next=head;
                head=temp;
            }
            size++;
            cout<<"Element inserted....!!!!"<<endl;

        }
        void insertAtMiddle(int data,int position)
        {
            Node *temp=new Node();
            if(temp==NULL)
            {
                cout<<"Memory not allocated....!!!!"<<endl;
                exit(0);
            }
            temp->value=data;
            Node *iterator=head;
            if(iterator==NULL)
            {
                head=temp;
                cout<<"Element inserted....!!!!"<<endl;
            }
            else
            {
                if(position>size || position<0)
                {
                    cout<<"Position not exist in list....!!!!"<<endl;
                    return;
                }
                else
                {
                    while(position>1)
                    {
                        position--;
                        iterator=iterator->next;
                    }
                    if(iterator!=NULL)
                    {
                        temp->next=iterator->next;
                        iterator->next=temp;
                    }
                    else
                    {
                        temp->next=head;
                        head=temp;
                    }
                    cout<<"Element inserted....!!!!"<<endl;
                }
            }
            size++;
        }
        void insertAtEnd(int v)
        {
            Node *temp=new Node();
            if(temp==NULL)
            {
                cout<<"Memory not allocated....!!!!"<<endl;
                exit(0);
            }
            temp->value=v;
            if(head==NULL)
                head=temp;
            else
            {
                Node *iterator=head;
                while(iterator->next!=NULL)
                {
                    iterator=iterator->next;
                }
                iterator->next=temp;
            }
            size++;
            cout<<"Element inserted....!!!!"<<endl;
        }
        int getSize() { return size; }
        void printElements()
        {
            if(head==NULL)
            {
                cout<<"List is Empty....!!!!"<<endl;
                return;
            }
            Node *iterator=head;
            cout<<"Elements are: ";
            while(iterator!=NULL)
            {
                cout<<iterator->value<<" -> ";
                iterator=iterator->next;
            }
            cout<<endl;
        }
        void deleteAt(int position)
        {
            if(position>size || position<0)
            {
                cout<<"Position not exist in list....!!!!"<<endl;
                return;
            }
            else
            {
                Node *iterator=head;
                if(iterator==NULL)
                {
                    cout<<"List is empty....!!!!"<<endl;
                    return;
                }
                else
                {
                    while(position>2)
                    {
                        position--;
                        iterator=iterator->next;
                    }
                    if(position==1)
                    {
                        head=iterator->next;
                        delete iterator;
                    }
                    else
                    {
                        Node *t=iterator->next;
                        iterator->next=t->next;
                        delete t;
                    }
                    size--;
                    cout<<"Element Deleted....!!!!"<<endl;
                }
            }
        }
        void search(int v)
        {
            Node *iterator=head;
            int count=0;
            while(iterator!=NULL)
            {
                count++;
                if(iterator->value==v)
                {
                    cout<<"Element found at position "<<count<<endl;
                    return;
                }
                iterator=iterator->next;
            }
            cout<<"Element not found....!!!!"<<endl;
        }
};
int main()
{
    SinglyLL s;
    int choice,value,position;
    while(1)
    {
        cout<<"\n\n======================================================\n\n";
        cout<<"1. InsertAtBegin."<<endl;
        cout<<"2. InsertAtMiddle."<<endl;
        cout<<"3. InsertAtEnd."<<endl;
        cout<<"4. Search."<<endl;
        cout<<"5. DeleteElement."<<endl;
        cout<<"6. GetSize."<<endl;
        cout<<"7. PrintElement."<<endl;
        cout<<"8. Exit."<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter the element: ";
                cin>>value;
                s.insertAtBegin(value);
                break;
            }
            case 2:
            {
                cout<<"Enter the element and index: ";
                cin>>value>>position;
                s.insertAtMiddle(value,position);
                break;
            }
            case 3:
            {
                cout<<"Enter the element: ";
                cin>>value;
                s.insertAtEnd(value);
                break;
            }
            case 4:
            {
                cout<<"Enter the element you want to search: ";
                cin>>value;
                s.search(value);
                break;
            }
            case 5:
            {
                cout<<"Enter the position you want to delete: ";
                cin>>position;
                s.deleteAt(position);
                break;
            }
            case 6:
            {
                cout<<"Size= "<<s.getSize()<<endl;
                break;
            }
            case 7:
            {
                s.printElements();
                break;
            }
            case 8:
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