// Link problem : https://www.spoj.com/problems/SPRING/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
#include <functional>
using namespace std;

#define oo INT_MAX
#define pb push_back
#define mp make_pair

int N, M, D;

double Dijkstra(vector<vector<pair<double, int>>> &node, int from, int to)
{
    vector<double> dist(N + 2, oo);
    priority_queue<pair<double, int>, vector<pair<double, int>>,
                   greater<pair<double, int>>>
        Q;
    dist[from] = 0.0;
    Q.push(make_pair(0.0, from));
    while (!Q.empty())
    {
        pair<double, int> curr = Q.top();
        Q.pop();
        double ftemp = curr.first;
        int stemp = curr.second;
        if (stemp == to)
            return dist[to];
        int node_size = node[stemp].size();
        for (int i = 0, _node_size = (node_size); i < _node_size; i++)
        {
            double cost = node[stemp][i].first;
            int next = node[stemp][i].second;
            if (cost + ftemp < dist[next])
            {
                dist[next] = cost + ftemp;
                Q.push(make_pair(dist[next], next));
            }
        }
    }
    return -1;
}

int main()
{
    while (scanf("%d%d%d", &N, &M, &D) == 3)
    {
        vector<vector<pair<double, int>>> node(N);

        while (M--)
        {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            double w_ratio = (double)1 / w;
            node[a].pb(mp((double)w_ratio, b));
            node[b].pb(mp((double)w_ratio, a));
        }

        double res = Dijkstra(node, 0, N - 1);
        double Fmax = D / res;
        if (Fmax < 0.0)
            Fmax = 0.0;
        printf("%.2f\n", Fmax);
    }
    return 0;
}