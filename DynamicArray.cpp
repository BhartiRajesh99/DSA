#include<iostream>
#include<cstdlib>
using namespace std;
class DynamicArray
{
    private:
        int *a=NULL;
        int size,capacity;
        void resize()
        {
            if(size==capacity)
            {
                int *temp=new int[2*capacity];
                if(temp==NULL)
                {
                    cout<<"Memory not allocated....!!!!"<<endl;
                    exit(0);
                }
                for(int i=0;i<size;i++)
                    temp[i]=a[i];
                delete []a;
                a=temp;
                capacity=2*capacity;
            }
        }
    public:
        DynamicArray()
        {
            a=new int[1];
            if(a==NULL)
            {
                cout<<"Memory not allocated....!!!!"<<endl;
                exit(0);
            }
            size=0;
            capacity=1;
        }
        void insertElement(int value)
        {
            resize();
            a[size++]=value;
        }
        void insertElementAt(int value,int index)
        {
            if(index>size || index<0)
            {
                cout<<"Index not exist....!!!!"<<endl;
                return;
            }   
            if(size==capacity)
                resize();
            for(int i=size;i>index;i--)
                a[i]=a[i-1];
            a[index]=value;
            size++;
        }
        int getSize() { return size; }
        int getCapacity() { return capacity; }
        void ShrinkToFit()
        {
            int *temp=new int[size];
            if(temp==NULL)
            {
                cout<<"Memory not allocated....!!!!"<<endl;
                exit(0);
            }
            for(int i=0;i<size;i++)
                temp[i]=a[i];
            delete []a;
            a=temp;
            capacity=size;
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
        void search(int value)
        {
            int flag=-1;
            for(int i=0;i<size;i++)
            {
                if(a[i]==value)
                {
                    flag=i;
                    break;
                }
            }
            if(flag!=-1)
                cout<<"Element found at index "<<flag<<endl;
            else
                cout<<"Element not found...!!!!"<<endl;
        }
        void deleteElement(int index)
        {
            if(index>=size || index<0)
            {
                cout<<"Index not exist....!!!!"<<endl;
                return;
            }
            for(int i=index;i<size-1;i++)
                a[i]=a[i+1];
            size--;
            cout<<"Element Deleted....!!!!"<<endl;
        }
        ~DynamicArray()
        {
            delete []a;
            size=capacity=0;
        }
};
int main()
{
    DynamicArray d;
    int choice,value,index;
    while(1)
    {
        cout<<"\n\n=======================================================\n\n";
        cout<<"1. InsertElement"<<endl;
        cout<<"2. InsertElementAt"<<endl;
        cout<<"3. Search"<<endl;
        cout<<"4. DeleteElement"<<endl;
        cout<<"5. ShrinkToFit"<<endl;
        cout<<"6. Getsize"<<endl;
        cout<<"7. GetCapacity"<<endl;
        cout<<"8. PrintELements"<<endl;
        cout<<"9. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter the value: ";
                cin>>value;
                d.insertElement(value);
                cout<<"ELement inserted....!!!!";
                break;
            }
            case 2:
            {
                cout<<"Enter the value and index: ";
                cin>>value>>index;
                d.insertElementAt(value,index);
                cout<<"ELement inserted....!!!!";
                break;
            }
            case 3:
            {
                cout<<"Enter the value you want to search: ";
                cin>>value;
                d.search(value);
                break;
            }
            case 4:
            {
                cout<<"Enter the index you want to delete: ";
                cin>>index;
                d.deleteElement(index);
                break;
            }
            case 5:
            {
                d.ShrinkToFit();
                cout<<"Capacity= "<<d.getCapacity();
                cout<<"Size= "<<d.getSize();
                break;
            }
            case 6:
            {
                cout<<"Size= "<<d.getSize();
                break;
            }
            case 7:
            {
                cout<<"Capacity= "<<d.getCapacity();
                break;
            }
            case 8:
            {
                d.printElements();
                break;
            }
            case 9:
            {
                exit(0);
            }
            default:
            {
                cout<<"Invalid choice....!!!!"<<endl;
            }
        }
    }
    return 0;
}