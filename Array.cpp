#include<iostream>
#include<cstdlib>
#define SIZE 10
using namespace std;
class Array
{
    private:
        int a[SIZE]={0};
        int size;
    public:
        Array()
        {
            size=0;
        }
        void search(int value)
        {
            int flag=-1;
            for(int i=0;i<size;i++)
                if(a[i]==value)
                {
                    flag=i;
                    break;
                }
            if(flag!=-1)
                cout<<"Element found at index "<<flag<<"."<<endl;
            else
                cout<<"Element not found.....!!!!!!"<<endl;
        }
        void insertElement(int value)
        {
            if(size==SIZE)
            {
                cout<<"Array is full.....!!!! , Can't insert "<<value<<endl;
                return;
            }
            else
            {
                cout<<"Element Inserted at index "<<size<<endl;
                a[size++]=value;

            }
        }
        void insertAtMiddle(int value,int index)
        {
            if(index>size || index<0)
            {
                cout<<"Index not exist....!!!!"<<endl;
                return;
            }
            if(size==SIZE)
            {
                cout<<"Array is full.....!!!! , Can't insert "<<value<<endl;
            }
            else
            {
                cout<<"Element Inserted at index "<<index<<endl;
                for(int i=size;i>=index;i--)
                {
                    a[i+1]=a[i];
                }
                a[index]=value;
                size++;
            }
        }
        int getSize()
        {
            return size;
        }
        void printElements()
        {
            if(size==0)
            {
                cout<<"Array is empty....!!!!"<<endl;
                return;
            }
            cout<<"Elements are: ";
            for(int i=0;i<size;i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }
        void deleteElementAt(int index)
        {
            if(index>=size || index<0)
            {
                cout<<"Index not exist....!!!!"<<endl;
            }
            else
            {
                cout<<"Element "<<a[index]<<" deleted....!!!!"<<endl;
                for(int i=index;i<size;i++)
                    a[i]=a[i+1];
                --size;
            }
        }
};
int main()
{
    Array ar;
    int choice,value,index;
    cout<<endl<<endl<<"==================================================  "<<endl<<endl;
    while(1)
    {
        cout<<"1. InsertElement"<<endl;
        cout<<"2. InsertAtMiddle"<<endl;
        cout<<"3. Search"<<endl;
        cout<<"4. DeleteElement"<<endl;
        cout<<"5. PrintElements"<<endl;
        cout<<"6. GetSize"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter your chioce: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter Element:";
                cin>>value;
                ar.insertElement(value);
                break;
            }
            case 2:
            {
                cout<<"Enter Element and index:";
                cin>>value>>index;
                ar.insertAtMiddle(value,index);
                break;
            }
            case 3:
            {
                cout<<"Enter the element you want to search:";
                cin>>value;
                ar.search(value);
                break;
            }
            case 4:
            {
                cout<<"Enter index:";
                cin>>index;
                ar.deleteElementAt(index);
                break;
            }
            case 5:
            {
                ar.printElements();
                break;
            }
            case 6:
            {
                cout<<"Size="<<ar.getSize()<<endl;
                break;
            }
            case 7:
            {
                exit(1);
            }
            default:
            {
                cout<<"Invalid Choice....!!!!";
            }
        }
        cout<<endl<<endl<<"==================================================  "<<endl;
    }
    return 0;
}
