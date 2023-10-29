#include<iostream>
#include<cstdlib>
using namespace std;
class Node{
    public:
        Node *prev;
        int value;
        Node *next;
        Node(){
            prev=NULL;
            value=0;
            next=NULL;
        }
};
class DoublyLL{
    private:
        Node *head;
        int size;
    public:
        DoublyLL(){
            head=NULL;
            size=0;
        }
        void insertAtBegin(int v){
            Node *temp=new Node();
            if(temp==NULL){
                cout<<"Memory not allocated....!!!!"<<endl;
                exit(0);
            }
            temp->value=v;
            if(head!=NULL){
                temp->next=head;
                head->prev=temp;
            }
            head=temp;
            size++;
            cout<<"Element inserted....!!!!"<<endl;
        }
        void insertAtMiddle(int v,int position){
            if(position>size || position<=0){
                cout<<"Position not exist....!!!!"<<endl;
                return;
            }
            Node *temp=new Node();
            if(temp==NULL){
                cout<<"Memory not allocation....!!!!"<<endl;
                exit(0);
            }
            temp->value=v;
            Node *t=head;
            if(t==NULL)
                head=temp;
            else{
                while(position>1){
                    position--;
                    t=t->next;
                }
                if(t->next!=NULL){
                    temp->next=t->next;
                    t->next->prev=temp;
                }
                t->next=temp;
                temp->prev=t;
            }
            size++;
            cout<<"Element inserted....!!!!"<<endl;
        }
        void insertAtEnd(int v){
            Node *temp=new Node();
            if(temp==NULL){
                cout<<"Memory not allocated....!!!!"<<endl;
                exit(0);
            }
            temp->value=v;
            Node *t=head;
            if(t==NULL)
                head=temp;
            else{
                while(t->next!=NULL)
                    t=t->next;
                t->next=temp;
                temp->prev=t;
            }
            size++;
            cout<<"Element inserted....!!!!"<<endl;
        }
        void deleteElementAt(int position){
            Node *t=head;
            if(t==NULL){
                cout<<"List is empty....!!!!"<<endl;
                return;
            }
            else{
                if(position>size || position<=0){
                    cout<<"Position does not exist....!!!!"<<endl;
                    return;
                }
                while(position>1){
                    position--;
                    t=t->next;
                }
                if(t->prev==NULL)
                    head=t->next;
                else{
                    if(t->next!=NULL)
                        t->next->prev=t->prev;
                    t->prev->next=t->next;
                }
                delete t;
                cout<<"Element deleted....!!!!"<<endl;
                size--;
            }
        }
        void search(int v){
            Node *t=head;
            int position=0;
            while(t!=NULL){
                position++;
                if(t->value==v){
                    cout<<"Element found at position "<<position<<endl;
                    return;
                }
                t=t->next;
            }
            cout<<"Element not found....!!!!"<<endl;
        }
        int getSize() {
            return size; 
        }
        void printElement(){
            Node *t=head;
            if(t==NULL){
                cout<<"List is empty....!!!!"<<endl;
                return;
            }
            cout<<"Elements are: ";
            while(t!=NULL){
                cout<<t->value<<" <=> ";
                t=t->next;
            }
            cout<<endl;
        }
};
int main(){
    DoublyLL d;
    int choice,value,position;
    while(1){
        cout<<"\n\n=====================================================\n\n";
        cout<<"1. InsertAtBegin"<<endl;
        cout<<"2. InsertAtMiddle"<<endl;
        cout<<"3. InsertAtEnd"<<endl;
        cout<<"4. DeleteElementAt"<<endl;
        cout<<"5. Search"<<endl;
        cout<<"6. GetSize"<<endl;
        cout<<"7. PrintElement"<<endl;
        cout<<"8. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Enter the element:";
                cin>>value;
                d.insertAtBegin(value);
                break;
            }
            case 2:{
                cout<<"Enter the element and position:";
                cin>>value>>position;
                d.insertAtMiddle(value,position);
                break;
            }
            case 3:{
                cout<<"Enter the element:";
                cin>>value;
                d.insertAtEnd(value);
                break;
            }
            case 4:{
                cout<<"Enter the position:";
                cin>>position;
                d.deleteElementAt(position);
                break;
            }
            case 5:{
                cout<<"Enter the element:";
                cin>>value;
                d.search(value);
                break;
            }
            case 6:{
                cout<<"Size="<<d.getSize();
                break;
            }
            case 7:{
                d.printElement();
                break;
            }
            case 8:
                exit(0);
            default:
                cout<<"Invalid Choice....!!!!"<<endl;
        }
    }
    return 0;
}
