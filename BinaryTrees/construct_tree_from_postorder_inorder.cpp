#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

int binary_search(int arr[], int l, int r, int k)
{
    int mid;
    
    while(l<=r)
    {
        mid= l+ (r-l)/2;
        
        if(arr[mid]==k)
        {
            return mid;
        }else if(arr[mid]<k)
        {
            l=mid+1;
        }else
        {
            r=mid-1;
        }
    }
    
    return -1;
    
}

BinaryTreeNode<int>* buildTreeUtil(int *postorder, int l1, int r1, int *inorder, int l2, int r2)
{
    if(l1>r1)
    {
        return NULL;
    }
    
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(postorder[r1]);
    
    int k= binary_search(inorder, l2, r2, postorder[r1]);
    
    int LpostS=l1;
    
    int LinS=l2;
    int LinE=k-1;
     int RpostE=r1-1;
    int RpostS=RpostE+1 - (r2-k);
    int LpostE=RpostS-1;
    int RinS=k+1;
    int RinE=r2;
    
    root->left = buildTreeUtil(postorder, LpostS, LpostE, inorder, LinS, LinE);
    root->right = buildTreeUtil(postorder, RpostS, RpostE, inorder, RinS, RinE);
    
    return root;
    
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    
   return buildTreeUtil(postorder, 0, postLength-1, inorder, 0, inLength-1);
}

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> post[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(post, size, in, size);
    printLevelATNewLine(root);
}
