#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAX_COMMAND_LENGTH 12

// 双方向連結リストは番兵を置いてリングにするとkeyによる検索とfirstとlastの探索が行いやすい。
// 文字列の比較は strncmp(str1, str2, until) == 0
// c++は 1 は真で 0 は偽

struct Node {
  Node *prev, *next;
  int key;
};

Node *guard_node;

void init_list() {
  guard_node = (Node *)malloc(sizeof(Node));
  guard_node->prev = guard_node;
  guard_node->next = guard_node;
}

void insert_node(int new_key) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->key = new_key;
  new_node->prev = guard_node;
  new_node->next = guard_node->next;

  new_node->prev->next = new_node;
  new_node->next->prev = new_node;
}

void delete_node(Node *deleted_node) {
  if(deleted_node == guard_node) {
    return;
  }

  deleted_node->prev->next = deleted_node->next;
  deleted_node->next->prev = deleted_node->prev;
  free(deleted_node);
}

void delete_node_by_key(int key) {
  Node* current_node = guard_node->next;

  while(true) {
    if(current_node == guard_node) {
      break;
    }

    if(current_node->key == key) {
      break;
    }

    current_node = current_node->next;
  }

  // Find
  if(current_node != guard_node) {
    delete_node(current_node);
  }
}

void delete_first_node() {
  delete_node(guard_node->next);
}

void delete_last_node() {
  delete_node(guard_node->prev);
}

void print_node() {
  Node *current_node = guard_node->next;

  while(true) {
    if(current_node == guard_node) {
      break;
    }

    // Last print
    if (current_node->next == guard_node) {
      printf("%d", current_node->key);
    } else {
      printf("%d ", current_node->key);
    }

    current_node = current_node->next;
  }

  printf("\n");
}


int main() {
  int command_number, command_arg;
  char command[MAX_COMMAND_LENGTH];

  init_list();

  scanf("%d", &command_number);

  for(int i = 0; i < command_number; i++) {
    scanf("%s", command);

    if(strncmp(command, "insert", 5) == 0) {
      scanf("%d", &command_arg);
      insert_node(command_arg);
    } else if(strncmp(command, "delete", 5) == 0) {
      if(strncmp(command, "deleteFirst", 11) == 0) {
        delete_first_node();
      } else if(strncmp(command, "deleteLast", 10) == 0) {
        delete_last_node();
      } else {
        scanf("%d", &command_arg);
        delete_node_by_key(command_arg);
      }
    }
  }

  print_node();
}
