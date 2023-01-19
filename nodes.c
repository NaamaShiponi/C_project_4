#include <stdio.h>
// #include "nodes.h"
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include <limits.h>

void delete_node_cmd(pnode *head, int numOfNode)
{
    pnode oldNode = findNode(head, numOfNode);
    deleteEdgeFromNode(oldNode);
    deleteEdgeToNode(head, numOfNode);
    pnode p = *head;
    if (p != NULL)
    {
        while (p->next != NULL)
        {
            if (p->next->node_num == numOfNode)
            {
                pnode temp = p->next;
                p->next = temp->next;
                free(temp);
                break;
            }
            p = p->next;
        }
        pnode p = *head;
        if (p->node_num == numOfNode)
        {
            *head = p->next;
        }
    }

    // delete node
}

void build_nodes_graph_cmd(pnode *head, int numOfNode)
{
    pnode p = newNode(0);
    *head = p;

    for (size_t i = 1; i < numOfNode; i++)
    {
        p->next = newNode(i);
        p = p->next;
    }
}

void insert_node_cmd(pnode *head, int numNode)
{

    pnode newNod = newNode(numNode);
    pnode p = *head;

    // add in the start node list
    if (p != NULL)
    {
        newNod->next = *head;
    }
    *head = newNod;


}

void printNodes(pnode *head)
{
    pnode p = *head;
    while (p != NULL)
    {
        printf("node- %d \n", p->node_num);
        p = p->next;
    }
}

pnode newNode(int node_num)
{
    pnode p = (pnode)malloc(sizeof(node));
    p->node_num = node_num;
    p->edges = NULL;
    p->next = NULL;
    p->bellmanFord = INT_MAX;
    return p;
}

pnode findNode(pnode *head, int node_num)
{

    pnode p = *head;
    while (p != NULL)
    {
        if (p->node_num == node_num)
        {
            return p;
        }
        p = p->next;
    }

    return NULL;
}
