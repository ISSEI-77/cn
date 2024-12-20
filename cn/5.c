#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

#define MAX_NODES 5
#define INF INT_MAX

int graph[MAX_NODES][MAX_NODES] = {
    {0, 1, 3, INF, INF},
    {1, 0, INF, 4, 5},
    {3, INF, 0, INF, 6},
    {INF, 4, INF, 0, 2},
    {INF, 5, 6, 2, 0}
};

void prims_broadcast_tree();

int main(){
    printf("Broadcasting Tree using Prim's Algorithm\n");
    prims_broadcast_tree();
    return 0;
}

void prims_broadcast_tree(){
    int parent[MAX_NODES];
    int weight[MAX_NODES];
    bool in_tree[MAX_NODES];

    for(int i = 0; i < MAX_NODES; i++){
        in_tree[i] = false;
        weight[i] = INF;
    }

    weight[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < MAX_NODES - 1; count++){
        int min_weight = INF, u = -1;

        for(int v = 0; v < MAX_NODES; v++){
            if(!in_tree[v] && weight[v] < min_weight){
                min_weight = weight[v];
                u = v;
            }
        }
        in_tree[u] = true;

        for(int v = 0; v < MAX_NODES; v++){
            if(graph[u][v] && !in_tree[v] && graph[u][v] < weight[v]){
                weight[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nEDGE    WEIGHT\n");
    for(int i = 1; i < MAX_NODES; i++){
        printf("%d-%d\t%d\n", parent[i], i, weight[i]);
    }
}
