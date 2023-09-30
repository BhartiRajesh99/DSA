#include<iostream>
#include<cstdlib>
using namespace std;
class stack
{
    private:
        stack *topNode;
        int value,size;
        stack *next;
        stack *prev;
    public:
        stack()
        {
            topNode=NULL;
            value=size=0;
            next=prev=NULL;
        }
        stack(int data)
        {
            topNode=NULL;
            value=data;
            size=0;
            next=prev=NULL;
        }
        int top() 
        { 
            if(isEmptyStack())
            {
                cout<<"Stack is empty....!!!!"<<endl;
                return -1;
            }
            return topNode->value; 
        }
        int getSize() { return size; }
        int isEmptyStack()
        {
            if(topNode==NULL)
                return 1;
            else
                return 0;
        }
        void push(int data)
        {
            stack *temp=new stack(data);
            if(temp==NULL)
            {
                cout<<"Memeory not allocated....!!!!"<<endl;
                exit(0);
            }
            if(isEmptyStack())
                topNode=temp;
            else
            {
                topNode->next=temp;
                temp->prev=topNode;
                topNode=temp;
            }
            size++;
        }
        void pop()
        {
            if(this->isEmptyStack())
            {
                cout<<"Stack is empty....!!!!"<<endl;
                return;
            }
            cout<<"Top element "<<this->top()<<" deleted....!!!!"<<endl;
            stack *ptr=topNode;
            topNode=ptr->prev;
            if(size!=1)
                topNode->next=ptr->next;
            delete ptr;
            size--;
        }
        void print()
        {
            stack *it=topNode;
            if(isEmptyStack())
            {
                cout<<"Stack is empty....!!!!"<<endl;
                return;
            }
            cout<<"Elements are:";
            while(it!=NULL)
            {
                cout<<it->value<<" ";
                it=it->prev;
            }
            cout<<endl;
        }
        void search(int data)
        {
            stack *y=topNode;
            while(y!=NULL)
            {
                if(y->value==data)
                {
                    cout<<"Element Found....!!!!"<<endl;
                    return;
                }
                y=y->prev;
            }
            cout<<"Element not found....!!!!"<<endl;
        }
        ~stack()
        {
            while(topNode!=NULL)
                pop();
        }
};
int main()
{
    stack s;
    int choice,value;
    while(1)
    {
        cout<<"\n\n========================================================\n\n";
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. EmptyStack"<<endl;
        cout<<"4. GetSize"<<endl;
        cout<<"5. TopElement"<<endl;
        cout<<"6. Search"<<endl;
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
                s.push(value);
                break;
            }
            case 2:
            {
                s.pop();
                break;
            }
            case 3:
            {
                if(s.isEmptyStack())
                    cout<<"Stack is empty....!!!!"<<endl;
                else
                    cout<<"Stsck is not empty....!!!!"<<endl;
                break;
            }
            case 4:
            {
                cout<<"Size="<<s.getSize()<<endl;
                break;
            }
            case 5:
            {
                if(s.top()!=-1)
                    cout<<"Top Element="<<s.top()<<endl;
                break;
            }
            case 6:
            {
                cout<<"Enter the element you want to search:";
                cin>>value;
                s.search(value);
                break;
            }
            case 7:
            {
                s.print();
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