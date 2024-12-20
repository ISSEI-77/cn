#include<stdio.h>

#define INF 9999
#define MAX_NODES 4

int cost[MAX_NODES][MAX_NODES] = {
    {0, 1, 4, INF},
    {1, 0, 2, 6},
    {4, 2, 0, 3},
    {INF, 6, 3, 0}
};

void distance_routing_algorithm();

int main(){
    printf("Predefined cost matrix\n");
    for(int i = 0; i < MAX_NODES; i++){
        for(int j = 0; j < MAX_NODES; j++){
            if(cost[i][j] == INF){
                printf("INF\t");
            } else {
                printf("%d\t", cost[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nRouting Tables\n");
    distance_routing_algorithm();
    return 0;
}

void distance_routing_algorithm(){
    int distance[MAX_NODES][MAX_NODES], next_hop[MAX_NODES][MAX_NODES];

    for(int i = 0; i < MAX_NODES; i++){
        for(int j = 0; j < MAX_NODES; j++){
            distance[i][j] = cost[i][j];
            if(cost[i][j] != INF && i != j){
                next_hop[i][j] = j;
            } else {
                next_hop[i][j] = -1;
            }
        }
    }

    for(int k = 0; k < MAX_NODES; k++){
        for(int i = 0; i < MAX_NODES; i++){
            for(int j = 0; j < MAX_NODES; j++){
                if(distance[i][j] > distance[i][k] + distance[k][j]){
                    distance[i][j] = distance[i][k] + distance[k][j];
                    next_hop[i][j] = next_hop[i][k];
                }
            }
        }
    }

    for(int i = 0; i < MAX_NODES; i++){
        printf("Routing tables for node %d\n", i);
        printf("Destination\tCOST\tNEXT_HOP\n");
        for(int j = 0; j < MAX_NODES; j++){
            if(j != i){
                printf("%d\t%d\t", j, distance[i][j]);
                if(next_hop[i][j] != -1){
                    printf("%d\n", next_hop[i][j]);
                } else {
                    printf("-\n");
                }
            }
        }
        printf("\n");
    }
}
