#include <stdio.h>
#include "graph.h"

int main()
{
    char c;
    scanf("%c", &c);
    while (1)
    {
        pnode *head;
        if (c == 'A')
        {
            c = getParmsForCreatGraph(head);

            // printf("get %c from getParmsForCreatGraph\n",c);
            break;
        }
        if (c == 'B')
        {
            printf("in B\n");
            // c=getParmsForNewNode();
            break;
        }
        if (c == 'D')
        {
            // c=getParmsForDeleteNode();
            break;
        }
        if (c == 'S')
        {
            // c=getParmsForShortRoute();
            break;
        }
        if (c == 'T')
        {
            // c=getParmsForShortRouteWithDefinedPoints();
            break;
        }
        scanf("%c", &c);
    }
}
char getParmsForCreatGraph(pnode *head)
{
    int munOfNode = 0;
    scanf("%d", &munOfNode);
    // creat nodes
    build_Nodes_graph_cmd(head);
    char c;
    scanf("%c%c", &c, &c);

    int parentNode, targetNode, weight;
    while (c == 'n')
    {
        scanf("%d", &parentNode);

        while (scanf("%d", &targetNode) == 1)
        {
            scanf("%d", &weight);
            // creat age
            build_graph_cmd(head);
        }
        scanf("%c", &c);
    }
    return c;
}

void build_Nodes_graph_cmd(pnode *head)
{


}
void build_graph_cmd(pnode *head)
{

}
