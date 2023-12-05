// 到达首都的最少油耗
// https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital
// INLINE  ../../images/graphs/minimum_fuel_cost_to_report_to_the_capital.jpeg

#include <headers.hpp>

class Solution {
public:
  long long int minimumFuelCost(vector<vector<int>> &roads, int seats) {
    int n = roads.size() + 1;
    vector<vector<int>> graph(n);
    for (auto &road : roads) {
      int src = road[0], dest = road[1];
      graph[src].push_back(dest);
      graph[dest].push_back(src);
    }

    long long int totalCost = 0;
    traverse(0, -1, graph, totalCost, seats);
    return totalCost;
  }

private:
  int traverse(int node, int parent, vector<vector<int>> &graph,
               long long int &cost, int seats) {
    int total = 1;
    for (int neighbour : graph[node]) {
      if (neighbour != parent) {
        int sub_total = traverse(neighbour, node, graph, cost, seats);
        cost += (long long int)ceil(
            (double)sub_total /
            seats); // casting to double for correct division and then
                    // converting back to long long int
        total += sub_total;
      }
    }
    return total;
  }
};