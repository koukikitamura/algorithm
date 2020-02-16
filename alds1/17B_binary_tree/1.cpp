#include <cstdio>
#include <algorithm>
#include <string>
#define MAX_NODE_SIZE 25
#define NULL_INDEX -1

// 配列の要素を超えてアクセスするとそのあとに宣言した変数の値を更新してしまう可能性がある。
// 再帰呼び出しは再起の終了条件を意識しながらかく。

struct Node {
  int parent_index;
  int left_child_index;
  int right_child_index;
  int depth;
  int height;
  int sibling;
  int degree;
};

void init_tree(Node tree[], int node_size) {
  for(int i = 0; i < node_size; i++) {
    tree[i].parent_index =
      tree[i].left_child_index =
      tree[i].right_child_index =
      tree[i].sibling = NULL_INDEX;

    tree[i].degree = 0;
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

void set_depth(Node tree[], int root_index, int root_depth) {
  tree[root_index].depth = root_depth;

  if(tree[root_index].left_child_index != NULL_INDEX) {
    set_depth(tree, tree[root_index].left_child_index, root_depth + 1);
  }
  if(tree[root_index].right_child_index != NULL_INDEX) {
    set_depth(tree, tree[root_index].right_child_index, root_depth + 1);
  }
}

int set_height(Node tree[], int root_index) {
  int left_child_height = 0, right_child_height = 0;

  if(tree[root_index].left_child_index == NULL_INDEX && tree[root_index].right_child_index == NULL_INDEX) {
    tree[root_index].height = 0;
    return tree[root_index].height;
  }

  if(tree[root_index].left_child_index != NULL_INDEX) {
    left_child_height = set_height(tree, tree[root_index].left_child_index);
  }
  if(tree[root_index].right_child_index != NULL_INDEX) {
    right_child_height = set_height(tree, tree[root_index].right_child_index);
  }

  tree[root_index].height = std::max(left_child_height, right_child_height) + 1;
  return tree[root_index].height;
}

std::string get_node_type(Node node) {
  if(node.parent_index == NULL_INDEX){
    return "root";
  }

  if(node.left_child_index == NULL_INDEX && node.right_child_index == NULL_INDEX) {
    return "leaf";
  }

  return "internal node";
}

void print_tree(Node tree[], int size) {
  for(int i = 0; i < size; i++ ) {
    Node node = tree[i];

    std::string node_type = get_node_type(node);

    printf(
      "node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",
      i,
      node.parent_index,
      node.sibling,
      node.degree,
      node.depth,
      node.height,
      node_type.c_str()
    );
  }
}
int main() {
  Node tree[MAX_NODE_SIZE];
  int node_size;

  scanf("%d%*c", &node_size);

  init_tree(tree, node_size);

  for(int i = 0; i < node_size; i++) {
    int node_index, left_child_index, right_child_index;
    scanf("%d %d %d%*c", &node_index, &left_child_index, &right_child_index);

    if(left_child_index != NULL_INDEX) {
      tree[node_index].degree++;
    }
    if(right_child_index != NULL_INDEX) {
      tree[node_index].degree++;
    }

    tree[node_index].left_child_index = left_child_index;
    tree[node_index].right_child_index = right_child_index;

    if(left_child_index != NULL_INDEX) {
      tree[left_child_index].parent_index = node_index;
      tree[left_child_index].sibling = right_child_index;
    }
    if(right_child_index != NULL_INDEX) {
      tree[right_child_index].parent_index = node_index;
      tree[right_child_index].sibling = left_child_index;
    }
  }

  int root_index = get_root_index(tree , node_size);
  set_depth(tree, root_index, 0);
  set_height(tree, root_index);

  print_tree(tree, node_size);
}
