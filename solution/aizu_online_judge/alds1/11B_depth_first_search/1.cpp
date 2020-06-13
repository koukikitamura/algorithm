#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int edge = 1;
const int no_edge = 0;
const int no_time = -1;
const int no_label = -1;


// return finished time
int depth_search(
  int started_label,
  int current_time,
  vector<vector<int>> matrices_graph,
  vector<int>& discovered_times,
  vector<int>& finished_times
) {
  stack<int> visited_stack;
  int vertex_num = matrices_graph.size();
  visited_stack.push(started_label);
  discovered_times[started_label -1] = ++current_time;

  while(!visited_stack.empty()) {
    int current_label = visited_stack.top();

    // find no visited vertex
    int no_visited_label = no_label;
    for(int i = 0; i < vertex_num; i++) {
      if(matrices_graph[current_label - 1][i] != edge) {
        continue;
      }
      if(discovered_times[i] != no_time) {
        continue;
      }
      no_visited_label = i + 1;
      break;
    }

    if(no_visited_label != no_label) {
      visited_stack.push(no_visited_label);
      discovered_times[no_visited_label - 1] = ++current_time;
    } else {
      int finished_label = visited_stack.top();
      visited_stack.pop();

      finished_times[finished_label - 1] = ++current_time;
    }
  }

  return current_time;
}

int main() {
  int vertex_num;
  cin >> vertex_num;
  vector<vector<int>> matrices_graph(
    vertex_num,
    vector<int>(vertex_num, 0)
  );

  // convert to adjacency matrices graph
  for(int i = 0; i < vertex_num; i++) {
    int vertex_label;
    int adjacency_num;
    cin >> vertex_label >> adjacency_num;

    for(int j = 0; j < adjacency_num; j++) {
      int adjacency_label;
      cin >> adjacency_label;
      matrices_graph[vertex_label -1][adjacency_label - 1] = edge;
    }
  }

  vector<int> discovered_times(vertex_num, no_time);
  vector<int> finished_times(vertex_num, no_time);

  int current_time = 0;

  // Cover (DAG)Directed Acyclic Graph
  for(int i = 0; i <vertex_num; i++) {
    if(discovered_times[i] == no_time) {
      int started_label = i + 1;
      current_time = depth_search(
        started_label,
        current_time,
        matrices_graph,
        discovered_times,
        finished_times
      );
    }
  }

  for(int i = 0; i < vertex_num; i++) {
    cout << i + 1 << ' ' <<  discovered_times[i] << ' ' << finished_times[i] << endl;
  }
}
