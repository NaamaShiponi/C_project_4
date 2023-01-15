#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    char c;
    scanf("%c", &c);
    while (1)
    {
        pnode *head;
        switch(c)
        {
        case 'A':
            c = getParmsForCreatGraph(head);
            printf(" %c ", c);
            // printf("get %c from getParmsForCreatGraph\n",c);
            break;

        case 'B':

            printf("in B\n");
            // c=getParmsForNewNode();


            break;

        case 'D':
            // c=getParmsForDeleteNode();
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
        scanf("%c", &c);

    }
}
char getParmsForCreatGraph(pnode *head)
{
    int munOfNode = 0;
    scanf("%d", &munOfNode);
    printf("%d ", munOfNode);
    // creat nodes
    build_Nodes_graph_cmd(head,munOfNode);
    char c;
    scanf("%c%c", &c, &c);
    printf("%c ", c);

    int parentNode, targetNode, weight;
    while (c == 'n')
    {
        scanf("%d", &parentNode);
        printf("%d ", parentNode);

        while (scanf("%d", &targetNode) == 1)
        {
            printf("%d ", targetNode);
            scanf("%d", &weight);
            printf("%d ", weight);
            // creat age
            // build_graph_cmd(head);
        }
        scanf("%c", &c);
        printf("%c ", c);
    }
    return c;
}

pnode newNode(int node_num){
    pnode p=(pnode)malloc(sizeof(node)); 
    p->node_num=node_num;
    p->edges=NULL;
    p->next=NULL;
    return p;
}


void build_Nodes_graph_cmd(pnode *head,int munOfNode)
{
    head = newNode(0);

    // for (size_t i = 0; i < munOfNode; i++)
    // {
        
    //     *head->n
    //     // ->next = newNode(i);

    // }
    
    // printf("%p",head);

}
// void build_graph_cmd(pnode *head)
// {

// }
