#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#define MAX_NODE_SIZE 100
#define NULL_INDEX -1
using namespace std;

struct Node {
  int parent_index, left_child_index, right_child_index;
  int key;
};

struct Tree {
  int root_index;
  vector<Node> nodes;
};

// *************************
// * Memory Limit Exeeded  *
// *************************

// 配列を使うと削除処理が書きにくい。
// insert, delete 処理があるものはポインタで連結するのが吉!?

void insert(Tree *tree, int key) {
  int current_node_index = tree->root_index;
  int previous_node_index = NULL_INDEX;
  while(true) {
    if(current_node_index == NULL_INDEX) {
      break;
    }

    previous_node_index = current_node_index;
    if(key < tree->nodes[current_node_index].key) {
      current_node_index = tree->nodes[current_node_index].left_child_index;
    } else {
      current_node_index = tree->nodes[current_node_index].right_child_index;
    }
  }

  Node new_node;
  new_node.key = key;
  new_node.left_child_index = new_node.right_child_index = NULL_INDEX;
  new_node.parent_index = previous_node_index;

  if(previous_node_index == NULL_INDEX) {
    tree->root_index = 0;
  } else {
    if(new_node.key < tree->nodes[previous_node_index].key) {
      tree->nodes[previous_node_index].left_child_index = tree->nodes.size();
    } else {
      tree->nodes[previous_node_index].right_child_index = tree->nodes.size();
    }
  }

  tree->nodes.push_back(new_node);
};

void walk_inorder(Tree tree, int current_index) {
  if(current_index == NULL_INDEX) {
    return;
  }

  walk_inorder(tree, tree.nodes[current_index].left_child_index);
  printf(" %d", tree.nodes[current_index].key);
  walk_inorder(tree, tree.nodes[current_index].right_child_index);
}

void walk_preorder(Tree tree, int current_index) {
  if(current_index == NULL_INDEX) {
    return;
  }

  printf(" %d", tree.nodes[current_index].key);
  walk_preorder(tree, tree.nodes[current_index].left_child_index);
  walk_preorder(tree, tree.nodes[current_index].right_child_index);
}

int main() {
  Tree tree = {NULL_INDEX};
  int operation_num;
  char operation[7];

  scanf("%d%*c", &operation_num);


  for(int i = 0; i < operation_num; i++) {
    int key;

    scanf("%s", operation);

    if(0 == strncmp(operation, "insert", 6)) {
      scanf("%d%*c", &key);

      insert(&tree, key);
    } else if (0 == strncmp(operation, "print", 6)) {
      walk_inorder(tree, tree.root_index);
      printf("\n");
      walk_preorder(tree, tree.root_index);
      printf("\n");
    }
  }
}
