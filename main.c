#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <limits.h>

int main()
{
    char c;
    pnode head = NULL;
    while (scanf(" %c", &c) == 1)
    {
        switch (c)
        {
        case 'A':
            printf("in A\n");
            if (head != NULL)
                deleteGraph_cmd(&head);
            getParamsForCreatGraph(&head);
            break;

        case 'B':
            printf("in B\n");
            getParamsForNewNode(&head);
            break;

        case 'D':
            printf("in D\n");
            getParamsForDeleteNode(&head);
            break;

        case 'S':
            printf("in S\n");
            getParamsForShortRoute(&head);
            break;

        case 'T':
            printf("in T\n");
            getParamsForShortRouteWithDefinedPoints(head);
            break;
        }
    }
    deleteGraph_cmd(&head);
}

void TravellingSalesmanProblem(pnode head, int *stations, int numOfStations)
{
    int min = INT_MAX, temp;
    for (int j = 1; j <= numOfStations; j++)
    {
        for (int i = 0; i < numOfStations - 1; i++)
        {
            temp = stations[i];
            stations[i] = stations[i + 1];
            stations[i + 1] = temp;
            int temppath = 0;
            for (i = 0; i < numOfStations - 1; i++)
            {
                BellmanFord(&head, stations[i]);
                pnode bf = findNode(&head, stations[i + 1]);
                if (bf->bellmanFord < 0)
                {
                    temppath = INT_MAX;
                    break;
                }
                temppath += bf->bellmanFord;
            }
            if (temppath < min)
            {
                min = temppath;
            }
        }
    }
    if (min < INT_MAX && min > 0)
    {
        printf("TSP shortest path: %d \n", min);
    }
    else
    {
        printf("TSP shortest path: -1\n");
    }
}

void getParamsForShortRouteWithDefinedPoints(pnode head)
{
    int numOfStations;
    scanf("%d", &numOfStations);
    int *stations = (int *)malloc(numOfStations * sizeof(int));
    for (int i = 0; i < numOfStations; i++)
    {
        scanf("%d", &stations[i]);
    }

    TravellingSalesmanProblem(head, stations, numOfStations);

    free(stations);

}

void BellmanFord(pnode *head, int parentNode)
{
    pnode p = findNode(head, parentNode);
    pnode current = *head;
    int weightBF = 0;
    int countNodes = 0, i = 1;
    while (current != NULL)
    {
        current->bellmanFord = INT_MAX;
        current = current->next;
    }
    current = *head;
    p->bellmanFord = 0;

    while (current != NULL)
    {
        countNodes++;
        current = current->next;
    }
    while (i < countNodes)
    {
        current = *head;

        while (current != NULL)
        {

            weightBF = current->bellmanFord;
            if (weightBF < INT_MAX)
            {
                pedge current_edge = current->edges;
                while (current_edge != NULL)
                {

                    if (((weightBF + current_edge->weight) < current_edge->endpoint->bellmanFord))
                    {
                        current_edge->endpoint->bellmanFord = weightBF + current_edge->weight;
                    }
                    current_edge = current_edge->next;
                }
            }
            current = current->next;
        }
        i++;
    }
}

void getParamsForShortRoute(pnode *head)
{

    int parentNode, targetNode;
    scanf("%d", &parentNode);

    scanf("%d", &targetNode);

    BellmanFord(head, parentNode);
    pnode p = findNode(head, targetNode);
    if (p->bellmanFord == INT_MAX)
    {
        printf("Dijsktra shortest path: -1\n");
    }
    else
    {
        printf("Dijsktra shortest path: %d\n", p->bellmanFord);
    }

}

void deleteGraph_cmd(pnode *head)
{
    pnode p = *head;

    if (p != NULL)
    {
        p = p->next;
        while (p != NULL)
        {
            delete_node_cmd(head, p->node_num);
            p = p->next;
        }
        p = *head;
        free(p);
        *head = NULL;
    }
}

void getParamsForDeleteNode(pnode *head)
{
    int numOfNode;
    scanf("%d", &numOfNode);

    delete_node_cmd(head, numOfNode);
    print_graph(head);

}

void getParamsForNewNode(pnode *head)
{
    int parentNode, targetNode, weight;
    pnode oldNode;

    // get number of parent node
    scanf("%d", &parentNode);

    oldNode = findNode(head, parentNode);

    /*checke if this node exist
    IF YES delete all edge fo parent
    IF NO create a new node
    */
    if (oldNode == NULL)
    {
        printf("create a new node\n");
        insert_node_cmd(head, parentNode);
    }
    else
    {
        printf("delete all edge fo parent \n");
        // delete all edge fo parent
        deleteEdgeFromNode(oldNode);
    }
    // get number of target node / exits the loop when it receives A/B/D/S/T
    while (scanf("%d", &targetNode) == 1)
    {
        // get weight for edge
        scanf("%d", &weight);

        // creat edge
        newEdge(head, parentNode, targetNode, weight);
    }
    print_graph(head);
}

void getParamsForCreatGraph(pnode *head)
{
    char c;
    int munOfNode = 0;
    int parentNode, targetNode, weight;

    // get number of nodes
    scanf("%d", &munOfNode);

    // creat nodes
    build_nodes_graph_cmd(head, munOfNode);

    // get n
    scanf("%c%c", &c, &c);

    // loop to creat graph
    for (size_t i = 0; i < munOfNode-1 ; i++)
    // while (c == 'n')
    {
        // get number of parent node
        scanf("%d", &parentNode);

        // get number of target node  / exits the loop when it receives n/A/B/D/S/T
        while (scanf("%d", &targetNode) == 1)
        {

            // get weight for edge
            scanf("%d", &weight);

            // creat edge
            newEdge(head, parentNode, targetNode, weight);
        }

        // get n/A/B/D/S/T
        scanf("%c", &c);
    }
    print_graph(head);
}

void print_graph(pnode *head)
{
    pnode current = *head;

    while (current != NULL)
    {
        printf("Node %d: ", current->node_num);
        pedge current_edge = current->edges;
        while (current_edge != NULL)
        {
            printf("(%d,--- %d ---> %d) ", current->node_num, current_edge->weight, current_edge->endpoint->node_num);
            current_edge = current_edge->next;
        }
        printf("\n");
        current = current->next;
    }
}
