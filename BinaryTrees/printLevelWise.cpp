#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
    
    if(root==NULL)
    {
        return;
    }
    
    queue<BinaryTreeNode<int>*> pendingnodes;
    
    pendingnodes.push(root);
    
    while(!pendingnodes.empty())
    {
        BinaryTreeNode<int>* front= pendingnodes.front();
        pendingnodes.pop();
        
        cout<<front->data<<":";
        
        if(front->left!=NULL)
        {
            BinaryTreeNode<int>* leftchild= front->left;
            cout<<"L:"<<leftchild->data<<",";
            pendingnodes.push(leftchild);
        }else
        {
            cout<<"L:-1,";
        }
        
        if(front->right!=NULL)
        {
            BinaryTreeNode<int>* rightchild= front->right;
            cout<<"R:"<<rightchild->data;
            pendingnodes.push(rightchild);
        }else
        {
            cout<<"R:-1";
        }
        
        cout<<endl;
    }
    
}

BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
}
