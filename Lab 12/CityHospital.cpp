#include <iostream>
#include <vector>
#include <queue>

using namespace std;

double averagetime(vector<vector<int>>& graph, int source) {
    int n = graph.size();
    vector<int> time(n, INT_MAX);
    time[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != 0) {
                int weight = graph[u][v];
                if (time[u] != INT_MAX && time[u] + weight < time[v]) {
                    time[v] = time[u] + weight;
                    pq.push(make_pair(time[v], v));
                }
            }
        }
    }

    int total = 0;
    for (int i = 0; i < n; ++i) {
        if (time[i] == 0) continue;
        total += time[i];
    }

    double avgtime = (double) total / (n-1);
    return avgtime;
}


int main() {
    // This is the graph given in the question.
    vector<vector<int>> graph = {
            {0, 10, 0, 0, 15, 5},
            {10, 0, 10, 30, 0, 0},
            {0, 10, 0, 12, 5, 0},
            {0, 30, 12, 0, 0, 20},
            {15, 0, 5, 0, 0, 0},
            {5, 0, 0, 20, 0, 0}
    };

    int n = graph.size();
    double mintime = INT_MAX;
    vector<string> selected;
    cout << "City" << "\t|   " << "Average Time" << endl;
    for(int i=0; i<n; i++) {
        double avgtime = averagetime(graph, i);
        cout << "City" << i << "\t|   " << avgtime << endl;
        if (avgtime == mintime) {
            selected.push_back("City" + to_string(i));
        } else if (avgtime < mintime) {
            mintime = avgtime;
            selected.clear();
            selected.push_back("City"+ to_string(i));
        }
    }

    cout << "\nTherefor selected city/cities  ->  ";
    for(string city: selected) {
        cout << city << "  ";
    }
    cout << endl;

    return 0;
}
