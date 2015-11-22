#include <boost/shared_ptr.hpp>

struct Node;
typedef boost::shared_ptr<Node> NodeSP;

struct Node {
  NodeSP parent;
  NodeSP left_child;
  NodeSP right_child;
};

void add_children(NodeSP n) {
  NodeSP left(new Node);
  n->left_child = left;
  n->left_child->parent = n;

  NodeSP right(new Node);
  n->right_child = right;
  n->right_child->parent = n;
}

int main() {
  NodeSP root(new Node);
  
  add_children(root);
  add_children(root->left_child);
  add_children(root->right_child);
  
  return 0;
}
