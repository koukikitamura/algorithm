#include <iostream>
#include <vector>

using namespace std;

vector<int> components;

// used_borderが3のとき0, 1, 2まで使用済み。
bool can_construct(int target, int used_border) {
  if(target == 0) {
    return true;
  }
  if(used_border > components.size()) {
    return false;
  }

  return can_construct(target - components[used_border - 1], used_border + 1) ||
    can_construct(target, used_border + 1);
}


int main() {
  int component_num;
  cin >> component_num;
  components.resize(component_num);

  for(int i = 0; i < component_num; i++) {
    cin >> components[i];
  }

  int target_num;
  cin >> target_num;
  for(int i = 0; i < target_num; i++) {
    int target;
    cin >> target;
    bool constratable = can_construct(target, 1);

    if(constratable) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}
