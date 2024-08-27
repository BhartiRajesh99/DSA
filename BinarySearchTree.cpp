#include<iostream>
using namespace std;
class BST{
    public:
        int data;
        BST* left;
        BST* right;

        BST(){
            this->data=0;
            this->left=nullptr;
            this->right=nullptr;
        }

        BST(int v){
            this->data=v;
            this->left=nullptr;
            this->right=nullptr;
        }

        BST* search(int key){
            if(!this || this->data == key)
                return this;
            else if(key > this->data)
                return this->right->search(key);
            else
                return this->left->search(key);
        }

        void preorder(){
            if(this != nullptr){
                cout<<this->data<<" ";
                this->left->preorder();
                this->right->preorder();
            }
        }
        
        void inorder(){
            if(this != nullptr){
                this->left->inorder();
                cout<<this->data<<" ";
                this->right->inorder();
            }
        }

        void postorder(){
            if(this != nullptr){
                this->left->postorder();
                this->right->postorder();
                cout<<this->data<<" ";
            }
        }

        // Recursive Approach for Maximum and Minimum value for BST
        BST* maximumNode(){
            if(!this || !this->right)
                return this;
            else
                return this->right->maximumNode();
        }
        
        BST* minimumNode(){
            if(!this || !this->left)
                return this;
            else
                return this->left->minimumNode();
        }

        // Non-Recursive Approach for Maximum and Minimum value for BST
        BST* MaximumNode(){
            if(this == nullptr)
                return this;
            BST* temp=this;
            while(temp->right != nullptr){
                temp = temp->right;
            }
            return temp;
        }

        BST* MinimumNode(){
            if(this == nullptr)
                return nullptr;
            BST* temp=this;
            while(temp->left != nullptr){
                temp = temp->left;
            }
            return temp;
        }

        int height(){
            if(!this)
                return 0;
            int lheight = left->height();
            int rheight = right->height();
            return (rheight>lheight ? rheight+1 : lheight+1);
        }

        BST* inorderSuccessor(){
            if(!this)
                return nullptr;
            return this->right->minimumNode();
        }

        BST* inorderPredecessor(){
            if(!this)
                return nullptr;
            return this->left->maximumNode();
        }

        BST* insertNode(int v){
            if(!this)
                return new BST(v);
            else if(this->data > v)
                this->left = this->left->insertNode(v);
            else
                this->right = this->right->insertNode(v);
            return this;
        }

        BST* deleteNode(int v){
            if(!this)
                return this;
            else if(this->data > v)
                this->left = this->left->deleteNode(v);
            else if(this->data < v)
                this->right = this->right->deleteNode(v);
            else{
                //  if zero child exists
                if(this->left == nullptr && this->right == nullptr){
                    delete this;
                    return nullptr;
                }
                // if one child exists
                else if(this->left == nullptr){
                    BST* temp = this->right;
                    delete this;
                    return temp;
                }
                else if(this->right == nullptr){
                    BST* temp = this->left;
                    delete this;
                    return temp;
                }
                //if two child exists
                else{
                    BST* temp = this->inorderSuccessor();
                    this->data = temp->data;
                    this->right = this->right->deleteNode(temp->data);
                }
            }
            return this;
        }
};

int main(int argc,char *argv[]){
    // BST* root = new BST(10);
    // root->left = new BST(5);
    // root->left->left = new BST(3);
    // root->left->right = new BST(7);
    // root->right = new BST(15);
    // root->right->left = new BST(13);
    // root->right->right = new BST(16);


    BST* root = nullptr;
    root = root->insertNode(10);
    root->insertNode(15);
    root->insertNode(8);
    root->insertNode(13);
    root->insertNode(21);
    root->insertNode(16);
    root->insertNode(2);
    root->insertNode(5);

    cout<<"Before Deletion: ";
    root->inorder();
    cout<<endl;

    root->deleteNode(16);

    cout<<"After Deletion: ";
    root->inorder();
    cout<<endl;

    cout<<(root->search(3) != nullptr ? "Found" : "Not found")<<endl;
    cout<<"Recursive:"<<endl;
    cout<<"Maximun value: "<<root->maximumNode()->data<<endl;
    cout<<"Minimum value: "<<root->minimumNode()->data<<endl;
    cout<<"Non-Recursive:"<<endl;
    cout<<"Maximun value: "<<root->MaximumNode()->data<<endl;
    cout<<"Minimum value: "<<root->minimumNode()->data<<endl;

    return 0;
}