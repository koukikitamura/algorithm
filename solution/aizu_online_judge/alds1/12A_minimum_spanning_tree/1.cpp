#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using MatrixGraph = vector<vector<int>>;

const int no_edege = -1;
const int started_label = 1;
const int no_label = -1;
const int max_weight = 2'000;

int total_weight(MatrixGraph matrix_graph, int started_label) {
  vector<bool> visited_labels(matrix_graph.size(), false);
  visited_labels[started_label - 1] = true;
  int weight_sum = 0;

  while(true) {
    // Find min const label from adjaceny labels;
    int min_const_label = no_label;
    int min_weight = max_weight + 1;
    for(int i = 0; i < matrix_graph.size(); i++) {
      if(!visited_labels[i]) {
        continue;
      }
      for(int j = 0; j < matrix_graph.size(); j++) {
        if(visited_labels[j]) {
          continue;
        }

        if(matrix_graph[i][j] < min_weight) {
          min_const_label = j;
          min_weight = matrix_graph[i][j];
        }
      }
    }
    if(min_weight > max_weight) {
      break;
    }

    weight_sum += min_weight;
    visited_labels[min_const_label] = true;
  }

  return weight_sum;
}

int main() {
  int vertex_num;
  cin >> vertex_num;
  MatrixGraph matrix_graph(vertex_num, vector<int>(vertex_num, no_edege));

  // Init
  for(int i = 0; i < vertex_num; i++) {
    for(int j = 0 ;j < vertex_num; j++) {
      int weight;
      cin >> weight;
      if(weight == no_edege) {
        matrix_graph[i][j] = max_weight + 1;
        continue;
      }
      matrix_graph[i][j] = weight;
    }
  }

  cout << total_weight(matrix_graph, started_label) << endl;
}
