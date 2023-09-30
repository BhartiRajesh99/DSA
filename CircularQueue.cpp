#include<iostream>
#define SIZE 5
using namespace std;
class CircularQueue
{
    private:
        int a[SIZE]={0},i,size;
        int front,rear;
    public:
        CircularQueue()
        {
            size=0;
            front=rear=-1;
        }
        void Enqueue(int data)
        {
            if((rear+1)%SIZE==front)
            {
                cout<<"Overflow....!!!!"<<endl;
                return;
            }
            if(rear==-1&&front==-1)
                front++;
            rear=(rear+1)%SIZE;
            a[rear]=data;
            size++;
            cout<<"Element inserted....!!!!"<<endl;
        }
        void Dequeue()
        {
            if(rear==-1 && front==-1)
            {
                cout<<"Underflow....!!!!"<<endl;
                return;
            }
            a[front]=0;
            if(front==rear)
                front=rear=-1;
            else  
                front=(front+1)%SIZE;
            size--;
            cout<<"Element deleted....!!!!"<<endl;
        }
        void print()
        {
            if(front==-1)
            {
                cout<<"Underflow....!!!!"<<endl;
                return;
            }
            cout<<"Elements are:";
            for (int i=front; ;i=(i+1)%SIZE)
            {
                cout<<a[i]<<" ";
                if(i==rear)
                    break;
            }
            cout<<endl;
        }
        int getSize() { return size; }
        ~CircularQueue()
        {
            size=0;
            while(front!=-1 && rear!=-1)
                Dequeue();
        }
};
int main()
{
    CircularQueue q;
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