#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    
    if(root==NULL)
    {
        return NULL;
    }
    
    if(!root->children.empty())
    {
        TreeNode<int>* temp= maxSumNode(root->children[0]);
        
     int maxSum=temp->data;
    
    for(int i=0;i<temp->children.size();i++)
        {
            maxSum+=temp->children[i]->data;
        }
    
    for(int i=1;i<root->children.size();i++)
    {
        TreeNode<int>* temp2= maxSumNode(root->children[i]);
        
        int maxSum2=temp2->data;
        
        for(int i=0;i<temp2->children.size();i++)
        {
            maxSum2+=temp2->children[i]->data;
        }
        
        if(maxSum<maxSum2)
        {
            temp=temp2;
            maxSum=maxSum2;
        }
        
    }
        
        int maxSum3=root->data;
        
        for(int i=0;i<root->children.size();i++)
        {
            maxSum3+=root->children[i]->data;
        }
        
        if(maxSum3>maxSum)
        {
            return root;
        }else
        {
            return temp;
        }
        
    }else
    {
        return root;
    }
    
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}
