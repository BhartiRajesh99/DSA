#include<iostream>
using namespace std;
class AVLTree{
    public:
        int data;
        int height;
        AVLTree* left;
        AVLTree* right;

        AVLTree(){
            data=0;
            left=nullptr;
            right=nullptr;
        }

        AVLTree(int v){
            data=v;
            left=nullptr;
            right=nullptr;
        }

        void preorder(){
            if(this){
                cout<<this->data<<" ";
                this->left->preorder();
                this->right->preorder();
            }
        }

        void inorder(){
            if(this){
                this->left->inorder();
                cout<<this->data<<" ";
                this->right->inorder();
            }
        }

        void postorder(){
            if(this){
                this->left->postorder();
                this->right->postorder();
                cout<<this->data<<" ";
            }
        }

        int balanceFactor(){
            return (this->left->calculateHeight() - this->right->calculateHeight());
        }

        AVLTree* rightRotation(){
            if(!this)
                return nullptr;
            AVLTree* newRootNode = this->left;
            AVLTree* temp = newRootNode->right;
            newRootNode->right = this;
            this->left = temp;

            return newRootNode;
        }

        AVLTree* leftRotation(){
            if(!this)
                return nullptr;
            AVLTree* newRootNode = this->right;
            AVLTree* temp = newRootNode->left;
            newRootNode->left = this;
            this->right = temp;
            
            return newRootNode;
        }

        int calculateHeight(){
            if(!this)
                return 0;
            int lheight = this->left->calculateHeight();
            int rheight = this->right->calculateHeight();
            return (rheight>lheight ? rheight+1 : lheight+1);
        }

        AVLTree* insertNode(int v){
            if(!this)
                return new AVLTree(v);
            else if(this->data > v)
                this->left = this->left->insertNode(v);
            else
                this->right = this->right->insertNode(v);

            int balFac = this->balanceFactor();
            //for LL/LR rotation
            if(balFac > 1){
                if(this->left->data < v)
                    this->left = this->left->leftRotation();
                return this->rightRotation();
            }

            //for RR/RL rotation
            if(balFac < -1){
                if(this->right->data > v)
                    this->right = this->right->rightRotation();
                return this->leftRotation();
            }
            return this;
        }

        AVLTree* maximumNode(){
            if(!this->right)
                return this;
            return this->right->minimumNode();
        }

        AVLTree* minimumNode(){
            if(!this->left)
                return this;
            return this->left->minimumNode();
        }

        AVLTree* inorderPredecessor(){
            if(!this)
                return nullptr;
            return this->left->maximumNode();
        }

        AVLTree* inorderSuccessor(){
            if(!this)
                return nullptr;
            return this->right->minimumNode();
        }

        AVLTree* deleteNode(int v){
            if(!this)
                return nullptr;
            //if element is greater than root then go to right
            else if(this->data < v)
                this->right = this->right->deleteNode(v);
            //if element is less than root then go to left
            else if(this->data > v)
                this->left = this->left->deleteNode(v);
            //element found
            else{
                //if zero child 
                if(!this->left && !this->right){
                    delete this;
                    return nullptr;
                } else if(this->left) {  //if one child exists
                    AVLTree* temp = this->left;
                    delete this;
                    return temp;
                } else if(this->right) {
                    AVLTree* temp = this->right;
                    delete this;
                    return temp;
                } else {      // if two child exists
                    AVLTree* temp = this->inorderSuccessor();
                    this->data = temp->data;
                    this->right = this->right->deleteNode(v);
                }
            }

            int balFac = this->balanceFactor();
            // checking balance factor for find rotation
            //for LL/LR rotation
            if(balFac > 1){
                //if balance factor is less than 0 then LR rotation else LL rotation
                if(this->left->balanceFactor() < 0)
                    this->left = this->left->leftRotation();
                return this->rightRotation();
            }

            //for RR/RL rotation 
            if(balFac < -1){
                //if balance factor is greater than 0 then RL rotation else RR rotation
                if(this->right->balanceFactor() > 0)
                    this->right = this->right->rightRotation();
                return this->leftRotation();
            }

            return this;
        }
};

//Driver Code
int main(int argc, char* argv[]){
    AVLTree* root = nullptr;
    root = root->insertNode(4);
    root = root->insertNode(6);
    root = root->insertNode(23);
    root = root->insertNode(13);
    root = root->insertNode(30);
    root = root->insertNode(15);
    root = root->insertNode(33);
    root->inorder();
    cout<<endl;
    root = root->deleteNode(30);
    root = root->deleteNode(15);
    root->inorder();
    cout<<endl<<root->minimumNode()->data;
    return 0;
}