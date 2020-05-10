#include <cstdio>
#define BUILDING_NUM 4
#define FLOAR_NUM 3
#define ROOM_NUM 10
typedef int Building[FLOAR_NUM][ROOM_NUM];

// type defは変数宣言の形に似ている。
// cpp_version >= c++11
// using Building = int[FLOAR_NUM][ROOM_NUM];

// 配列のsizeを求めたい時は siezof(array) / sizeof(array[0])

// ４つのビルにそれぞれ配列２次元配列を用意するのもあり
// 前問のトランプのマークも２次元配列でやるのもあり
// ２次元の配列は１次元配列を分割することでも表現できる。
// 3次元配列を１次元の配列で分割で表現するのは手間。

void print_building(Building building) {
  for(int i = 0; i < FLOAR_NUM; i++) {
    for(int j = 0; j < ROOM_NUM; j++) {
      printf(" %d", building[i][j]);
    }

    printf("\n");
  }
}

int main() {
  Building buildings[BUILDING_NUM] = {0};
  int notice_num;

  scanf("%d%*c", &notice_num);

  for(int i = 0; i < notice_num; i++) {
    int building_order, floor_order, room_order;
    int tenant_num;

    scanf("%d %d %d %d%*c", &building_order, &floor_order, &room_order, &tenant_num);

    buildings[building_order - 1][floor_order - 1][room_order - 1] += tenant_num;
  }

  for(int i = 0; i < BUILDING_NUM; i++) {
    print_building(buildings[i]);

    if(i != BUILDING_NUM - 1) {
      printf("####################\n");
    }
  }
}
