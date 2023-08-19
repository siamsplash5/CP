//Prim's Algorithm to find minimum spanning tree (value) for connected graph

#include <bits/stdc++.h>
using namespace std;
#define test int t; cin >>t; while(t--)
typedef long long int lld;
#define mxs 100005

int main() {
    lld numberOfNodes, numberOfEdges; cin >> numberOfNodes >> numberOfEdges;
    vector<pair<lld, lld>> g[numberOfNodes + 2];
    //generating graph from edges
    for (int i = 0; i < numberOfEdges; i++) {
        lld u, v, d; cin >> u >> v >> d;
        g[u].push_back({v, d});
        g[v].push_back({u, d});
    }

    //Taking 'cost' array to track minimum edge value we need to reach ith node
    int cost[numberOfEdges + 2];

    //Taking 'taken' array to track the node we've taken so far
    bool taken[n + 2];

    //initialize the 'cost' and 'taken' array
    for (int i = 0; i < n; i++) {
        taken[i] = false;
        cost[i] = 1e9; //initialize with maximum value as cost we will store will be minimum
    }

    //taking min-heap priority_queue
    //first element: the cost of path, we want to sort the priority_queue based on cost
    //second element:  the node where the path goes

    priority_queue <pair<lld, lld>, vector<pair<lld, lld>>, greater<pair<lld, lld>>> q;

    // starting node
    int firstNode = 0;

    //push it initial cost value = 0, as if the total node = 1, there will be no edge
    q.push({0, firstNode});

    //marking the cost of the node as 0
    cost[0] = 0;
    lld mst = 0;

    while (!q.empty()) {
        //pop the top element
        pair<lld, lld> tmp = q.top();
        q.pop();

        //check if the node already taken
        if (taken[tmp.second]) {
            continue;
        }

        //mark the node if not taken
        taken[tmp.second] = true;

        //add the cost to mst
        mst += tmp.first;

        for (auto it : g[tmp.second]) {
            lld node = it.first;
            lld nodeCost = it.second;

            //check the node already taken or not
            if (taken[node])continue;

            //update the cost of a node if the nodeCost is lower than the current
            //this condition will avoid pushing the already pushed node and also ensure the best one has pushed

            if (nodeCost < cost[node]) {
                cost[node] = nodeCost;
                q.push({nodeCost, node});
            }
        }
    }
    cout << mst << endl;

    return 0;
}