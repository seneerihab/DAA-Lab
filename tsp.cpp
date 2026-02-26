#include <iostream>
#include <climits>
using namespace std;

int tsp(int graph[][4], bool visited[], int curr, int n, int count, int cost, int &ans) {
    if(count == n && graph[curr][0]) {
        ans = min(ans, cost + graph[curr][0]);
        return ans;
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i] && graph[curr][i]) {
            visited[i] = true;
            tsp(graph, visited, i, n, count+1, cost + graph[curr][i], ans);
            visited[i] = false;
        }
    }
    return ans;
}

int main() {
    int graph[4][4] = {
        {0, 15, 20, 25},
        {15, 0, 10, 30},
        {20, 10, 0, 35},
        {25, 30, 35, 0}
    };

    bool visited[4] = {false};
    visited[0] = true;

    int ans = INT_MAX;

    cout << "Minimum Travelling Cost: "
         << tsp(graph, visited, 0, 4, 1, 0, ans);

    return 0;
}