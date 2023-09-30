#include<iostream>
#include<Cstdlib>
using namespace std;
class Queue
{
    private:
        class node
        {
            public:
                int value;
                node *next;
                node(int v)
                {
                    value=v;
                    next=NULL;
                }
        }*front,*rear;
        int size;
    public:
        Queue()
        {
            front=rear=NULL;
            size=0;
        }
        void Enqueue(int data)
        {
            node *temp=new node(data);
            if(temp==NULL)
            {
                cout<<"Memory not allocated....!!!!"<<endl;
                return;
            }
            if(front==NULL)
                front=rear=temp;
            else
            {
                rear->next=temp;
                rear=temp;
            }
            size++;
            cout<<"Element inserted....!!!!"<<endl;
        }
        void print()
        {
            node *it=front;
            if(it==NULL)
            {
                cout<<"Queue is empty....!!!!"<<endl;
                return;
            }
            cout<<"Queue elements are:";
            while(it!=NULL)
            {
                cout<<it->value<<" ";
                it=it->next;
            }
            cout<<endl;
        }
        int getSize() { return size; }
        void Dequeue()
        {
            if(front==NULL)
            {
                cout<<"Queue is empty....!!!!"<<endl;
                return;
            }
            node *it=front;
            front=it->next;
            cout<<"Element "<<it->value<<" deleted....!!!!"<<endl;
            delete it;
            size--;
        }
        ~Queue()
        {
            while(front!=NULL)
                Dequeue();
        }
};
int main()
{
    Queue q;
    int choice,value;
    while(1)
    {
        cout<<"\n\n================================================\n\n";
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. GetSize"<<endl;
        cout<<"4. PrintELement"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter the element:";
                cin>>value;
                q.Enqueue(value);
                break;
            }
            case 2:
            {
                q.Dequeue();
                break;
            }
            case 3:
            {
                cout<<"Size="<<q.getSize()<<endl;
                break;
            }
            case 4:
            {
                q.print();
                break;
            }
            case 5:
            {
                return 0;
            }
            default:
            {
                cout<<"Invalid choice....!!!!"<<endl;
            }
        }
    }
    return 0;
}