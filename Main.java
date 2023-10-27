import java.util.Scanner;
class Node {
    public int v;
     public Node next;
     public Node prev;
     public Node(int v){
          this.v=v;
          next=null;
          prev=null;
     }
}
class DoublyLinkedList{
    private Node head;
    private int size;
    public DoublyLinkedList(){
        head=null;
        size=0;
    }
    public void insertAtBegin(int v){
        Node temp=new Node(v);
        if(head!=null)
        {
            temp.next=head;
            head.prev=temp;
        }
        head=temp;
        size++;
        System.out.println("Node inserted....!!!!");
    }
    public void insertAtMiddle(int v,int pos){
        Node temp=new Node(v);
        Node it=head;
        int flag=0;
        if(pos==1){
            if(it!=null){
                temp.next=head;
                head.prev=temp;
            }
            head=temp;
        }
        else if(pos<=0){
            System.out.println("Position doesn't exist....!!!!");
            return;
        }
        else{
            while((pos-2)!=0){
                it=it.next;
                if(it==null){
                    flag=1;
                    break;
                }
                --pos;
            }
            if (flag == 1 || it.next == null){
                System.out.println("Position doesn't exist....!!!!");
                return;
            }
            temp.next = it.next;
            temp.prev = it;
            it.next = temp;
            temp.next.prev = temp;
        }
        size++;
        System.out.println("Node inserted....!!!!");
    }
    public void insertAtEnd(int v){
        Node temp=new Node(v);
        if(head==null){
            head=temp;
        }
        else{
            Node it=head;
            while(it.next!=null)
                it=it.next;
            it.next=temp;
            temp.prev=it;
        }
        size++;
        System.out.println("Node inserted....!!!!");
    }
    public void deleteAtBegin(){
        if(head==null){
            System.out.println("List is empty....!!!!");
            return;
        }
        Node t=head;
        head=t.next;
        if(t.next!=null)
            head.prev=t.prev;
        System.out.println("Node deleted....!!!!");
        size--;
    }
    public void deleteAtMiddle(int pos){
        if(head==null){
            System.out.println("List is empty....!!!!");
            return;
        }
        Node it=head;
        int flag=0;
        if(pos==1){
            head=it.next;
            if(it.next!=null)
                head.prev=it.prev;
        }
        else{
            while((pos-2)!=0){
                it=it.next;
                if(it==null){
                    flag=1;
                    break;
                }
                --pos;
            }
            if(flag==1 || (it.next==null)){
                System.out.println("Position doesn't exist....!!!!");
                return;
            }
            Node t=it.next;
            it.next=t.next;
            if(t.next!=null)
                t.next.prev=it;
        }
        System.out.println("Node deleted....!!!!");
        size--;
    }
    public void deleteAtEnd(){
        if(head==null){
            System.out.println("List is empty....!!!!");
            return;
        }
        Node t=head;
        if(t.next==null)
            head=null;
        else{
            Node it=head;
            while(it.next!=null)
                it=it.next;
            it.prev.next= null;
        }
        System.out.println("Node deleted....!!!!");
        size--;
    }
    public void getSize(){
        System.out.println("Size of LL: "+size);
    }
    public void display(){
        Node it=head;
        if(head==null){
            System.out.println("List is empty....!!!!");
            return;
        }
        while(it!=null){
            System.out.print(it.v+"->");
            it=it.next;
        }
    }
}
public class Main{
     public static void main(String []args){
          Scanner sc=new Scanner(System.in);
          DoublyLinkedList D=new DoublyLinkedList();
          int choice,v,position;
          while(true){
               System.out.println("\n==================================================\n\n");
               System.out.println("1.InsertAtBegin");
               System.out.println("2.InsertAtMiddle");
               System.out.println("3.InsertAtEnd");
               System.out.println("4.DeleteAtBegin");
               System.out.println("5.DeleteAtMiddle");
               System.out.println("6.DeleteAtEnd");
               System.out.println("7.GetSize");
               System.out.println("8.Display");
               System.out.println("9.Exit");
               System.out.print("Enter your choice:");
               choice=sc.nextInt();
               switch(choice){
                    case 1-> {
                         System.out.print("Enter the Element:");
                         v = sc.nextInt();
                         D.insertAtBegin(v);
                    }
                    case 2->{
                         System.out.print("Enter the Element and position:");
                         v = sc.nextInt();
                         position=sc.nextInt();
                         D.insertAtMiddle(v,position);
                    }
                    case 3->{
                         System.out.print("Enter the Element:");
                         v = sc.nextInt();
                         D.insertAtEnd(v);
                    }
                    case 4-> D.deleteAtBegin();
                    case 5->{
                         System.out.print("Enter the position:");
                         position=sc.nextInt();
                         D.deleteAtMiddle(position);
                    }
                    case 6-> D.deleteAtEnd();
                    case 7-> D.getSize();
                    case 8-> D.display();
                    case 9-> System.exit(0);
                    default-> System.out.println("Invalid choice....!!!!");
               }
          }
    }
}
