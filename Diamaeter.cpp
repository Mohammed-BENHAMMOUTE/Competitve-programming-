// C++ program to construct tree using inorder and
// postorder traversals
#include <bits/stdc++.h>

using namespace std;

class Node {
  public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

// Function to find index of value in arr[start...end]
// The function assumes that value is present in in[]
int search(vector<int> &arr, int strt, int end, int value) {
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            break;
    }
    return i;
}

// Recursive function to construct binary tree of size n
// from Inorder traversal in[] and Postorder traversal
// post[].  Initial values of inStrt and inEnd should
// be 0 and n - 1.
Node *buildUtil(vector<int> &inorder, vector<int> &postorder, 
                int inStrt, int inEnd, int &pIndex) {

    // if inStart is greater than inEnd return nullptr
    if (inStrt > inEnd)
        return nullptr;

    // Pick current node from Postorder traversal using
    //   postIndex and decrement postIndex
    Node *node = new Node(postorder[pIndex]);
    pIndex--;

    // If this node has no children then return
    if (inStrt == inEnd)
        return node;

    // Else find the index of this node in Inorder traversal
    int iIndex = search(inorder, inStrt, inEnd, node->data);

    // Using index in Inorder traversal, construct left and
    //   right subtrees
    node->right = buildUtil(inorder, postorder, iIndex + 1, inEnd, pIndex);
    node->left = buildUtil(inorder, postorder, inStrt, iIndex - 1, pIndex);

    return node;
}

// This function mainly initializes index of root
// and calls buildUtil()
Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int n = inorder.size();
    int pIndex = n - 1;
    return buildUtil(inorder, postorder, 0, n - 1, pIndex);
}

// Print the preorder traversal of a binary tree
void print(Node *curr) {
    if (curr == nullptr)
        return;
    cout << curr->data << " ";
    // if(curr->left == nullptr){

    // }
    print(curr->left);
    print(curr->right);
}
void printTree(Node* curr, string indent = "") {
    if (curr == nullptr)
        return;
        
    cout << indent << "Node: " << curr->data << endl;
    cout << indent << "├── Left: " << (curr->left ? to_string(curr->left->data) : "null") << endl;
    cout << indent << "└── Right: " << (curr->right ? to_string(curr->right->data) : "null") << endl;
    
    // Recursively print left and right subtrees with increased indentation
    printTree(curr->left, indent + "    ");
    printTree(curr->right, indent + "    ");
}
int height(Node* root) {
    if (root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}
int getDiameter(Node* root) {
    if (root == nullptr) return 0;
    
    // Get heights of left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    // Get diameters of left and right subtrees
    int leftDiameter = getDiameter(root->left);
    int rightDiameter = getDiameter(root->right);
    
    // Return maximum of:
    // 1) Diameter through root (left height + right height + 1)
    // 2) Diameter of left subtree
    // 3) Diameter of right subtree
    return max({leftHeight + rightHeight + 1, leftDiameter, rightDiameter});
}
struct DiameterInfo {
    int length;
    vector<int> path;
};

DiameterInfo getDiameterPath(Node* root) {
    if (root == nullptr) return {0, {}};
    
    DiameterInfo left = getDiameterPath(root->left);
    DiameterInfo right = getDiameterPath(root->right);
    
    // Calculate heights
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    // Path through root
    vector<int> pathThroughRoot;
    if (root->left) {
        Node* curr = root->left;
        while (curr != nullptr) {
            pathThroughRoot.insert(pathThroughRoot.begin(), curr->data);
            curr = (height(curr->left) > height(curr->right)) ? curr->left : curr->right;
        }
    }
    pathThroughRoot.push_back(root->data);
    if (root->right) {
        Node* curr = root->right;
        while (curr != nullptr) {
            pathThroughRoot.push_back(curr->data);
            curr = (height(curr->left) > height(curr->right)) ? curr->left : curr->right;
        }
    }
    
    // Compare three possibilities
    int throughRoot = leftHeight + rightHeight + 1;
    if (throughRoot >= left.length && throughRoot >= right.length) {
        return {throughRoot, pathThroughRoot};
    } else if (left.length >= right.length) {
        return left;
    } else {
        return right;
    }
}

int main() {
    vector<int> inorder = {10 , 3, 7 ,1 ,8 , 4, 5 , 9 ,2 , 6};
    vector<int> postorder = {10 , 7 , 1, 3 ,9 ,5 , 4, 8, 6, 2};

    Node *root = buildTree(inorder, postorder);
    
    print(root);
    cout << '\n';
    printTree(root);
    // cout << "Diameter of the tree is: " << getDiameter(root) << endl;
    DiameterInfo result = getDiameterPath(root);
    cout << "Diameter length: " << result.length << endl;
    cout << "Diameter path: ";
    for (int node : result.path) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}