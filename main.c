#include <stdio.h>
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
    build_Nodes_graph_cmd(head);
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
            build_graph_cmd(head);
        }
        scanf("%c", &c);
        printf("%c ", c);
    }
    return c;
}

void build_Nodes_graph_cmd(pnode *head)
{

    
}
void build_graph_cmd(pnode *head)
{

}
