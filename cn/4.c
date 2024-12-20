#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define NUM_NODES 5

int graph[NUM_NODES][NUM_NODES] = {
    {0, 10, 0, 30, 100},
    {10, 0, 50, 0, 0},
    {0, 50, 0, 20, 10},
    {30, 0, 20, 0, 60},
    {100, 0, 10, 60, 0}
};

void dijkstra(int);
int find_min_distance(int[], bool[]);

int main(){
    int start = 0;
    dijkstra(start);
    return 0;
}

void dijkstra(int start){
    int distance[NUM_NODES];
    bool visited[NUM_NODES];

    for(int i = 0; i < NUM_NODES; i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[start] = 0;

    for(int count = 0; count < NUM_NODES - 1; count++){
        int u = find_min_distance(distance, visited);

        visited[u] = true;

        for(int v = 0; v < NUM_NODES; v++){
            if(!visited[v] && graph[u][v] && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v]){
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    printf("NODE\tDISTANCE FROM SOURCE\n");
    for(int i = 0; i < NUM_NODES; i++){
        printf("%d\t%d\n", i, distance[i]);
    }
}

int find_min_distance(int distance[], bool visited[]){
    int min = INT_MAX, min_index = -1;
    for(int i = 0; i < NUM_NODES; i++){
        if(!visited[i] && distance[i] <= min){
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}
