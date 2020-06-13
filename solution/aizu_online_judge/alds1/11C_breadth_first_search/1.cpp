#include <iostream>
#include <queue>

using namespace std;

const int no_edge = -1;
const int edge = 1;
const int first_visit_label = 1;
const int no_distance = -1;

int main() {
  int vertex_num;
  cin >> vertex_num;

  vector<vector<int>> matrix_graph(
    vertex_num,
    vector<int>(vertex_num, no_edge)
  );

  for(int i = 0; i < vertex_num; i++) {
    int vertex_label;
    int adjacency_num;
    cin >> vertex_label >> adjacency_num;
    for(int j = 0; j < adjacency_num; j++) {
      int adjacency_label;
      cin >> adjacency_label;
      matrix_graph[vertex_label - 1][adjacency_label - 1] = edge;
    }
  }

  queue<int> will_visit_labels;
  vector<int> distances(vertex_num, no_distance);
  distances[first_visit_label - 1] = 0;
  will_visit_labels.push(first_visit_label);

  while(!will_visit_labels.empty()) {
    int current_label = will_visit_labels.front();
    will_visit_labels.pop();

    for(int i = 0; i < vertex_num; i++) {
      int will_visit_label = i + 1;
      if(matrix_graph[current_label - 1][will_visit_label - 1] == no_edge) {
        continue;
      }
      if(distances[will_visit_label - 1] != no_distance) {
        continue;
      }
      distances[will_visit_label - 1] = distances[current_label - 1] + 1;
      will_visit_labels.push(will_visit_label);
    }
  }

  for(int i = 0; i < vertex_num; i++) {
    cout << i + 1 << ' ' << distances[i] << endl;
  }
}
