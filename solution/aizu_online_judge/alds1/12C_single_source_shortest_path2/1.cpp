#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

struct Node {
  int label;
  int weight;

  bool operator>(const Node& other) const{
    return weight > other.weight;
  }
};

using ListGraph = vector<vector<Node>>;


const int max_num = numeric_limits<int>::max();


// priority_queueはpriorityが大きいのもから取り出す。
// デフォルトでは < (less<T>)を要素の比較に用いる。
// lessの場合要素が小さい時に入れ替える、つまりmaxHeapであり、priortyが大きいものから取り出される。

vector<int> shortest_cost(ListGraph &list_graph, int started_label) {
  vector<bool> visited_vertices(list_graph.size() ,false);
  vector<int> costs(list_graph.size(), max_num);
  priority_queue<Node, vector<Node>, greater<Node>> adjacency_costs;

  costs[started_label] = 0;
  adjacency_costs.push({started_label, costs[started_label]});

  while(!adjacency_costs.empty()) {
    Node nearest_node = adjacency_costs.top();
    adjacency_costs.pop();

    if(nearest_node.weight != costs[nearest_node.label]) {
      continue;
    }

    for(int i = 0; i < list_graph[nearest_node.label].size(); i++) {
      Node adjacency = list_graph[nearest_node.label][i];
      if(visited_vertices[adjacency.label]) {
        continue;
      }

      if(costs[nearest_node.label] + adjacency.weight < costs[adjacency.label]) {
        costs[adjacency.label] = costs[nearest_node.label] + adjacency.weight;
        adjacency_costs.push({adjacency.label, costs[adjacency.label]});
      }
    }
  }

  return costs;
}

int main() {
  int vertex_num;
  ListGraph list_graph;
  cin >> vertex_num;
  list_graph.resize(vertex_num);

  for(int i = 0; i < vertex_num; i++) {
    int label, degree;
    cin >> label >> degree;
    list_graph[i].resize(degree);

    for(int j = 0; j < degree; j++) {
      Node adjacency;
      cin >> adjacency.label >> adjacency.weight;

      list_graph[i][j] = adjacency;
    }
  }

  vector<int> costs = shortest_cost(list_graph, 0);

  for(int i = 0; i < costs.size(); i++) {
    cout << i << ' ' << costs[i] << endl;
  }
}
