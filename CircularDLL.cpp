#include<iostream>
#include<cstdlib>
using namespace std;
class CircularDLL
{
    private:
        CircularDLL *head;
        CircularDLL *prev;
        int value;
        CircularDLL *next;
        int size;
    public:
        CircularDLL()
        {
            head=NULL;
            size=0;
            prev=NULL;
            value=0;
            next=NULL;
        }
        CircularDLL(int v)
        {
            head=NULL;
            size=0;
            prev=NULL;
            value=v;
            next=NULL;
        }
        void insertAtBegin(int v)
        {
            CircularDLL *temp=new CircularDLL(v);
            if(temp==NULL)
            {
                cout<<"Memory not allocated....!!!!"<<endl;
                exit(0);
            }
            if(this->head==NULL)
            {
                this->head=temp;
                temp->next=this->head;
                temp->prev=this->head;
            }
            else
            {
                temp->next=this->head;
                temp->prev=this->head->prev;
                this->head->prev->next=temp;
                this->head->prev=temp;
                this->head=temp;
            }
            cout<<"Element inserted....!!!!"<<endl;
            this->size++;
        }
        void insertAtEnd(int v)
        {
            CircularDLL *temp=new CircularDLL(v);
            if(temp==NULL)
            {
                cout<<"Memory not allocated....!!!!"<<endl;
                exit(0);
            }
            if(this->head==NULL)
            {
                this->head=temp;
                temp->next=this->head;
                temp->prev=this->head;
            }
            else
            {
                temp->prev=this->head->prev;
                temp->next=this->head;
                this->head->prev->next=temp;
                this->head->prev=temp;
            }
            cout<<"Element inserted....!!!!"<<endl;
            this->size++;
        }
        void insertAtMiddle(int v,int position)
        {
            CircularDLL *temp=new CircularDLL(v);
            if(temp==NULL)
            {
                cout<<"Memory not allocated....!!!!"<<endl;
                exit(0);
            }
            if(position>this->size || position<0)
            {
                cout<<"Position not exist....!!!!"<<endl;
                return;
            }
            CircularDLL *it=this->head;
            if(position==this->size)
            {
                temp->prev=this->head->prev;
                temp->next=this->head;
                this->head->prev->next=temp;
                this->head->prev=temp;
            }
            else
            {
                while(position>1)
                {
                    position--;
                    it=it->next;
                }
                temp->prev=it;
                temp->next=it->next;
                it->next->prev=temp;
                it->next=temp;
            }
            cout<<"Element inserted....!!!!"<<endl;
            (this->size)++;
        }
        int getSize() { return this->size; }
        void deleteElement(int position)
        {
            if(head==NULL)
            {
                cout<<"List is empty....!!!!"<<endl;
                return;
            }
            else if(position>size || position<0)
            {
                cout<<"Position not exist....!!!!"<<endl;
                return;
            }
            else if(position==1)
            {
                CircularDLL *it=this->head;
                it->next->prev=this->head->prev;
                it->prev->next=this->head->next;
                this->head=it->next;
                delete it;
            }
            else if(position==size)
            {
                CircularDLL *temp=this->head->prev;
                temp->prev->next=this->head;
                this->head->prev=temp->prev;
                delete temp;
            }
            else
            {
                CircularDLL *t=this->head;
                while(position>1)
                {
                    position--;
                    t=t->next;
                }
                t->prev->next=t->next;
                t->next->prev=t->prev;
                delete t;
            }
            this->size--;
            cout<<"Element deleted....!!!!"<<endl;
        }
        void search(int v)
        {
            CircularDLL *it=this->head;
            int flag=0;
            while(it->next!=this->head)
            {
                if(it->value==v)
                {
                    flag=1;
                    break;
                }
                it=it->next;
            }
            if(it->value==v || flag==1)
                cout<<"Element found....!!!!"<<endl;
            else
                cout<<"Element not found....!!!!"<<endl;
        }
        void printElement()
        {
            CircularDLL *it=this->head;
            if(head==NULL)
            {
                cout<<"List is empty....!!!!"<<endl;
                return;
            }
            cout<<"ELements are:";
            while(it->next!=this->head)
            {
                cout<<it->value<<" ";
                it=it->next;
            }
            cout<<it->value<<endl;
        }
};
int main()
{
    CircularDLL dl;
    int choice,value,position;
    while(1)
    {
        cout<<"\n\n========================================================\n\n";
        cout<<"1. InsertAtBEgin"<<endl;
        cout<<"2. InsertAtMiddle"<<endl;
        cout<<"3. InsertAtEnd"<<endl;
        cout<<"4. GetSize"<<endl;
        cout<<"5. DeleteElement"<<endl;
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
                dl.insertAtBegin(value);
                break;
            }
            case 2:
            {
                cout<<"Enter the element and position:";
                cin>>value>>position;
                dl.insertAtMiddle(value,position);
                break;
            }
            case 3:
            {
                cout<<"Enter the element:";
                cin>>value;
                dl.insertAtEnd(value);
                break;
            }
            case 4:
            {
                cout<<"Size="<<dl.getSize()<<endl;
                break;
            }
            case 5:
            {
                cout<<"Enter the position:";
                cin>>position;
                dl.deleteElement(position);
                break;
            }
            case 6:
            {
                cout<<"Enter the element:";
                cin>>value;
                dl.search(value);
                break;
            }
            case 7:
            {
                dl.printElement();
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