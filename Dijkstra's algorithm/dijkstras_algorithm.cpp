#include <iostream>
#include <fstream>
#include <vector>

/*
    Dijkstra's algorithm to find the shortest path between a and b.
    It picks the unvisited vertex with the lowest distance,
    calculates the distance through it to each unvisited neighbor,
    and updates the neighbor's distance if smaller.
*/

const int N = 5;

struct Edge
{
    int v2;
    int scales;
};

typedef std::vector<std::vector<Edge> > TGRAPH;
TGRAPH graph;

void load(TGRAPH& graph)
{
    int n, m, v1, v2;
    Edge ed;
    std::ifstream in("graph.txt");
    in >> n >> m;
    graph.resize(n);

    for (int i = 0; i < m; i++)
    {
        in >> v1 >> ed.v2 >> ed.scales;
        graph[v1].push_back(ed);
    }
    in.close();
}

void dijkstra(TGRAPH graph, int start, std::vector<int>& cost)
{
    Edge ed;
    int i, j, k , v1;
    std::vector<bool> visited;
    visited.resize(graph.size(), false);
    cost[start] = 0;

    for (i = 0; i < graph.size() - 1; i++)
    {
        k = 0;
        while (visited[k])
            k++;
        v1 = k;

        for (j = k + 1; j < graph.size(); j++)
            if (!visited[j] && cost[j] < cost[v1])
                v1 = j;
        visited[v1] = true;

        for (j = 0; j < graph[v1].size(); j++)
        {
            ed = graph[v1][j];
            if (!visited[ed.v2] && cost[v1] + ed.scales < cost[ed.v2])
                cost[ed.v2] = cost[v1] + ed.scales;
        }
    }
}

int main()
{
    load(graph);
    std::vector<int> cost;
    cost.resize(graph.size(), 1000);
    int start;
    std::cout << "Start vertex number: ";
    std::cin >> start;
    dijkstra(graph, start, cost);
    std::cout << "Cost of getting from vertex " << start << " to vertex: \n";

    for (int i = 0; i < graph.size(); i++)
        if (i != start)
            std::cout << i << ": " << cost[i] << '\n';

    return 0;
}
