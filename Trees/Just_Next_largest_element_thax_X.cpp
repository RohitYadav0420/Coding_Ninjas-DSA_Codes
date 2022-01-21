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

TreeNode<int> *greaterElement(TreeNode<int> *root, int x)
{

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *temp = greaterElement(root->children[i], x);

        if (temp == NULL)
        {
            continue;
        }
        else
        {
            return temp;
        }
    }

    if (root->data > x)
    {
        return root;
    }
    else
    {
        return NULL;
    }
}

TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
{
    // Write your code here

    if (root == NULL)
    {
        return NULL;
    }

    if (!root->children.empty())
    {
        TreeNode<int> *temp_ans = greaterElement(root, x);
        TreeNode<int> *final_ans;
        if (temp_ans == NULL)
        {
            return NULL;
        }

        for (int i = 0; i < root->children.size(); i++)
        {
            final_ans = getNextLargerElement(root->children[i], x);
            if (final_ans != NULL)
            {
                if (final_ans->data > temp_ans->data)
                {
                    final_ans = temp_ans;
                }
            }
        }

        if (root->data > x && root->data < final_ans->data)
        {
            return root;
        }
        else
        {
            return final_ans;
        }
    }
    else
    {
        if (root->data > x)
        {
            return root;
        }
        else
        {
            return NULL;
        }
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
    int x;
    cin >> x;
    TreeNode<int>* ans = getNextLargerElement(root, x);

    if (ans != NULL) {
        cout << ans->data;
    }
}
