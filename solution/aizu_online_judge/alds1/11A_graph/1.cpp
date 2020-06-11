#include <iostream>
#include <vector>

using namespace std;

const int edge = 1;
const int no_edge = 0;

int main() {
  int vertex_num;
  cin >> vertex_num;

  // init
  vector<vector<int>> list_graph(
    vertex_num,
    vector<int>(vertex_num, 0)
  );

  // convert
  for(int i = 0; i < vertex_num; i++) {
    int vertex_label;
    int adjacency_vertex_num;
    cin >> vertex_label >> adjacency_vertex_num;

    for(int j = 0; j < adjacency_vertex_num; j++) {
      int adjacency_vertex_label;
      cin >> adjacency_vertex_label;

      list_graph[vertex_label - 1][adjacency_vertex_label - 1] = edge;
    }
  }


  // print
  for(int i = 0; i < vertex_num; i++) {
    for(int j = 0; j < vertex_num; j++) {
      cout << list_graph[i][j];

      if(j != vertex_num - 1) {
        cout << ' ';
      }
    }
    cout << endl;
  }
}
