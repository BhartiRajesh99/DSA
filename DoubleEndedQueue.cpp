#include<iostream>
#include<cstdlib>
using namespace std;
class DoubleEndedQueue
{
    private:
        class node
        {
            public:
                node *prev;
                int value;
                node *next;
                node(int v)
                {
                    prev=next=NULL;
                    value=v;
                }
        }*front,*rear;
        int size;
    public:
        DoubleEndedQueue()
        {
            front=rear=NULL;
            size=0;
        }
        void EnqueueAtBegin(int data)
        {
            node *temp=new node(data);
            if(temp==NULL)
            {
                cout<<"Memory not allocated....!!!!"<<endl;
                return;
            }
            if(front==NULL)
            {
                front=rear=temp;
            }
            else
            {
                front->prev=temp;
                temp->next=front;
                front=temp;
            }
            size++;
            cout<<"Element inserted....!!!!"<<endl;
        }
        void EnqueueAtEnd(int data)
        {
            node *temp=new node(data);
            if(temp==NULL)
            {
                cout<<"Memory not allocated....!!!!"<<endl;
                return;
            }
            if(rear==NULL)
            {
                front=rear=temp;
            }
            else
            {
                rear->next=temp;
                temp->prev=rear;
                rear=temp;
            }
            size++;
            cout<<"Element inserted....!!!!"<<endl;
        }
        void search(int data)
        {
            node *traverse=front;
            while(traverse!=NULL)
            {
                if(traverse->value==data)
                {
                    cout<<"Element found....!!!!"<<endl;
                    return;
                }
                traverse=traverse->next;            
            }
            cout<<"Element not found....!!!!"<<endl;
        }
        void print()
        {
            if(front==NULL && rear==NULL)
            {
                cout<<"Queue is empty....!!!!"<<endl;
                return;
            }
            node *traverse=front;
            cout<<"Elements are: ";
            while(traverse!=NULL)
            {
                cout<<traverse->value<<" ";
                traverse=traverse->next;            
            }
            cout<<endl;
        }
        int getSize() { return size; }
        void DequeueAtBegin()
        {
            if(front==NULL)
            {
                cout<<"Queue is empty....!!!!"<<endl;
                return;
            }
            node *it=front;
            front=it->next;
            if(front!=NULL)
                front->prev=it->prev;
            else
                rear==NULL;
            delete it;
            size--;
            cout<<"Element deleted....!!!!"<<endl;
        }
        void DequeueAtEnd()
        {
            if(rear==NULL)
            {
                cout<<"Queue is empty....!!!!"<<endl;
                return;
            }
            node *it=rear;
            rear=it->prev;
            if(rear!=NULL)
                rear->next=it->next;
            else
                front==NULL;
            delete it;
            size--;
            cout<<"Element deleted....!!!!"<<endl;
        }
        /*~DoubleEndedQueue()
        {
            while(front!=NULL&&rear!=NULL)
                DequeueAtBegin();
        }*/
};
int main()
{
    DoubleEndedQueue de;
    int choice,value;
    while(1)
    {
        cout<<"\n\n========================================================\n\n";
        cout<<"1. EnqueueAtBegin"<<endl;
        cout<<"2. EnqueueAtEnd"<<endl;
        cout<<"3. Search"<<endl;
        cout<<"4. GetSize"<<endl;
        cout<<"5. DequeueAtBegin"<<endl;
        cout<<"6. DequeueAtEnd"<<endl;
        cout<<"7. PrintElement"<<endl;
        cout<<"8. Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter the element:";
                cin>>value;
                de.EnqueueAtBegin(value);
                break;
            }
            case 2:
            {
                cout<<"Enter the element:";
                cin>>value;
                de.EnqueueAtEnd(value);
                break;
            }
            case 3:
            {
                cout<<"Enter the element:";
                cin>>value;
                de.search(value);
                break;
            }
            case 4:
            {
                cout<<"Size="<<de.getSize()<<endl;
                break;
            }
            case 5:
            {
                de.DequeueAtBegin();
                break;
            }
            case 6:
            {
                de.DequeueAtEnd();
                break;
            }
            case 7:
            {
                de.print();
                break;
            }
            case 8:
            {
                return 0;
            }
            default:
            {
                cout<<"Invalid Choice....!!!!"<<endl;
            }
        }
    }
    return 0;
}