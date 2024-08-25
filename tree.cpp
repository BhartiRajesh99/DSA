#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int v){
            this->data = v;
            this->left = nullptr;
            this->right = nullptr;
        }

        //Traversal functions
        void preorder(){
            if(this != nullptr){
                cout<<this->data<<" ";
                left->preorder();
                right->preorder();
            }
        }

        void inorder(){
            if(this != nullptr){
                left->inorder();
                cout<<this->data<<" ";
                right->inorder();
            }
        }

        void postorder(){
            if(this != nullptr){
                left->postorder();
                right->postorder();
                cout<<this->data<<" ";
            }
        }

        // No-recursive Level Order
        void levelOrder(){
            if(this == nullptr)
                return;
            queue<Node*> q;
            q.push(this);
            while(!q.empty()){
                cout<<q.front()->data<<" ";
                if(q.front()->left != nullptr)
                    q.push(q.front()->left);
                if(q.front()->right != nullptr)
                    q.push(q.front()->right);
                q.pop();
            }
        }
        
        // Recursive Level Order
        int height(){
            if(this == nullptr)
                return 0;
            int leftHeight = left->height();
            int rightHeight = right->height();
            return leftHeight > rightHeight ? leftHeight+1 : rightHeight+1;
        }

        void LevelOrder(){
            int h = this->height();
            for(int i=1; i<=h; i++){
                this->printCurrentLevel(i);
            }
        }

        void printCurrentLevel(int val){
            if(this == nullptr)
                return;
            if(val==1)
                cout<<this->data<<" ";
            else{
                left->printCurrentLevel(val-1);
                right->printCurrentLevel(val-1);
            }
        }
};

//Driver Code
int main(int argc, char *argv[]){
    Node* root = new Node(3);
    root->left = new Node(1);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(2);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);

    cout<<"\nPreorder: ";
    root->preorder();
    cout<<"\nInorder: ";
    root->inorder();
    cout<<"\nPostorder: ";
    root->postorder();
    cout<<"\nLevelorder Non-recursive: ";
    root->levelOrder();
    cout<<"\nLevelOrder Recursive: ";
    root->LevelOrder();

    return 0;
}