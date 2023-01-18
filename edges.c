#include <stdio.h>
#include <stdlib.h>

#include "edges.h"
#include "graph.h"

void newEdge(pnode *head, int parentNode, int targetNode, int weight)
{
    pedge p = (pedge)malloc(sizeof(edge));
    p->weight = weight;
    p->next = NULL;
    p->endpoint = findNode(head, targetNode);
    pnode pNode = findNode(head, parentNode);
    if (pNode->edges == NULL)
    {
        pNode->edges = p;
    }
    else
    {
        pedge pEdge = pNode->edges;
        while (pEdge->next != NULL)
        {
            pEdge = pEdge->next;
        }
        pEdge->next = p;
    }
}

void deleteEdgeFromNode(pnode oldNode)
{
    pedge pEdge = oldNode->edges;
    pedge ptemp;
    printf("deleteEdgeFromNode \n");
    while (pEdge != NULL)
    {
        ptemp = pEdge;
        pEdge = pEdge->next;
        printf("delete:(%d,--- %d ---> %d)\n", oldNode->node_num, ptemp->weight, ptemp->endpoint->node_num);
        free(ptemp);
    }
    oldNode->edges = NULL;
}

void deleteEdgeToNode(pnode *head, int numoldNode)
{
    pnode pNode = *head;
    pedge pEdge, temp;
    while (pNode != NULL)
    {
        if (pNode->edges != NULL)
        {
            pEdge = pNode->edges;
            
            while (pEdge->next != NULL)
            {
                if (pEdge->next->endpoint->node_num == numoldNode)
                {
                    temp = pEdge->next;
                    pEdge->next = temp->next;
                    free(temp);
                }
                else
                {
                    pEdge = pEdge->next;
                }
            }
            pEdge= pNode->edges;
            if (pEdge->endpoint->node_num == numoldNode)
            {
                temp = pEdge;
                pNode->edges = pEdge->next;
                free(temp);
            }
        }
        pNode = pNode->next;
    }
}
