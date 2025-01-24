// C++ program to print postorder traversal 
// from preorder and inorder traversals
#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& arr, int x) {
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Prints postorder traversal from given inorder and
// preorder traversals
void printPostOrder(vector<int>& in, vector<int>& pre,
                    int inStart, int inEnd, int preStart) {
    // Base case
    if (inStart > inEnd) return;

    // The first element in pre[] is 
      // always root
    int rootIndex = search(in, pre[preStart]);

    // If left subtree is not empty, print left subtree
    if (rootIndex > inStart) {
        printPostOrder(in, pre, inStart, rootIndex - 1, preStart + 1);
    }

    // If right subtree is not empty, print 
      // right subtree
    if (rootIndex < inEnd) {
        printPostOrder(in, pre, rootIndex + 1, 
                       inEnd, preStart + rootIndex - inStart + 1);
    }

    cout << pre[preStart] << " ";
}

int main() {
  
    vector<int> in = { 9, 2 , 4 , 6, 8 ,7 ,3 ,1, 5, 10 };
    vector<int> pre = { 8, 2 , 9 , 6 , 4 , 1 , 3 , 7 , 5 , 10};
    int n = in.size();
    printPostOrder(in, pre, 0, n - 1, 0);
    return 0;
}