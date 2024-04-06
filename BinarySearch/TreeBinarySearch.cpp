#include <bits/stdc++.h>
using namespace std;
class Node {
	int value;
	vector<Node*> children;
	Node(int value) : value(value) {}
};
void preorder_traversal(Node* root, const vector<int>& Queries , vector<int>& weight_array){
	weight_array.push_back(root->value);
	for (Node* child : root->children) {
		preorder_traversal(child, Queries, weight_array);
	};
	// backtrack and process queries using binary search (lower bound)
	for (int query: queries){
		if(query <= root->value || query >= weight_array.end()){
			continue;
		};
		auto it = lower_bound(weight_array.begin(),weight_array.end() , query );
		if (it != weight_array.begin()){
			cout<< *it << endl;
		};
	};
	weight_array.pop_back();
}
int main() {
  Node* root = new Node(3);


  vector<int> queries = {4, 7, 9, 6, 15};
  solve(root, queries);

  return 0;
}