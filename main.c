#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    char c;
    scanf("%c", &c);
    pnode head = NULL;
    while (c != EOF && c != 'E')
    {
        switch (c)
        {
        case 'A':
            if (head == NULL)
            {
                c = getParmsForCreatGraph(&head);
            }
            else
            {
                deleteGraph_cmd(&head);
                c = getParmsForCreatGraph(&head);
            }
            // print_graph(&head);

            break;

        case 'B':
            printf("in B\n");
            c = getParmsForNewNode(&head);
            break;

        case 'D':
            printf("in D\n");
            c = getParmsForDeleteNode(&head);
            break;

        case 'S':
            // c=getParmsForShortRoute();
            break;

        case 'T':
            // c=getParmsForShortRouteWithDefinedPoints();
            break;

            // operator doesn't match any case constant +, -, *, /
            // default:
            //     printf("Error! operator is not correct");
        }
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
            p=p->next;
        }
        p = *head;
        free(p);
        *head = NULL;
        

    }
}

char getParmsForDeleteNode(pnode *head)
{
    int numOfNode;
    char c;
    scanf("%d", &numOfNode);

    delete_node_cmd(head, numOfNode);
    print_graph(head);

    scanf("%c", &c);
    return c;
}

char getParmsForNewNode(pnode *head)
{
    char c;
    int parentNode, targetNode, weight;
    pnode oldNode;

    // get number of parent node
    scanf("%d", &parentNode);
    /*checke if this node exist
    IF YES delete all edge fo parent
    IF NO create a new node
    */
    oldNode = findNode(head, parentNode);

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

    // get n/A/B/D/S/T
    scanf("%c", &c);
    return c;
}

char getParmsForCreatGraph(pnode *head)
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
    while (c == 'n')
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
    return c;
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
