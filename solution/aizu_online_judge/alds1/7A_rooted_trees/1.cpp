#include <cstdio>
#include <string>
#define NODE_MAX_SIZE 100000
#define NULL_INDEX -1

// 文字列は素直にchar str[]でなくstd::stringを使ったほうが良い。

struct Node {
  int parent_index;
  int left_child_index;
  int right_sibling_index;
  int depth;
};

void init_tree(Node tree[], int size) {
  for(int i = 0; i < size; i++) {
    tree[i].parent_index = tree[i].left_child_index = tree[i].right_sibling_index = NULL_INDEX;
  }
}

int get_root_index(Node tree[], int size) {
  for(int i = 0; i < size; i++) {
    if(tree[i].parent_index == NULL_INDEX) {
      return i;
    }
  }

  return NULL_INDEX;
}

void set_depth(Node tree[], int root_node_index, int currentDepth) {
  tree[root_node_index].depth = currentDepth;

  if(tree[root_node_index].left_child_index != NULL_INDEX) {
    set_depth(tree, tree[root_node_index].left_child_index, currentDepth + 1);
  }
  if(tree[root_node_index].right_sibling_index != NULL_INDEX) {
    set_depth(tree, tree[root_node_index].right_sibling_index, currentDepth);
  }
}

std::string get_node_type(Node node) {
  if(node.parent_index == NULL_INDEX) {
    return "root";
  }
  if (node.left_child_index == NULL_INDEX) {
    return "leaf";
  }

  return "internal node";
}

void print_tree(Node tree[], int size) {
  for(int node_index = 0; node_index < size; node_index++) {
    Node node = tree[node_index];
    std::string node_type = get_node_type(node);

    printf("node %d: parent = %d, depth = %d, %s, ", node_index, node.parent_index, node.depth, node_type.c_str());

    printf("[");
    for(int child_node_index = node.left_child_index; child_node_index != NULL_INDEX; child_node_index = tree[child_node_index].right_sibling_index) {
      printf("%d", child_node_index);

      if(tree[child_node_index].right_sibling_index != NULL_INDEX) {
        printf(", ");
      }
    }
    printf("]");

    printf("\n");
  }
}

int main() {
  Node tree[NODE_MAX_SIZE];
  int node_size;

  scanf("%d%*c", &node_size);
  init_tree(tree, node_size);

  for(int i = 0; i < node_size; i++) {
    int node_index, child_num;
    scanf("%d %d", &node_index, &child_num);
    int previous_child_index;
    for(int j = 0; j < child_num; j++) {
      int child_index;
      scanf("%d", &child_index);

      tree[child_index].parent_index = node_index;
      if (j == 0) {
        tree[node_index].left_child_index = child_index;
      } else {
        tree[previous_child_index].right_sibling_index = child_index;
      }

      previous_child_index = child_index;
    }
  }

  int root_index = get_root_index(tree, node_size);
  set_depth(tree, root_index, 0);

  print_tree(tree, node_size);
}
