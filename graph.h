#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
    int bellmanFord;
} node, *pnode;


void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);


char getParmsForCreatGraph();
void build_nodes_graph_cmd(pnode *head,int numOfNode);
pnode newNode();
void printNodes();
void newEdge(pnode *head,int parentNode,int targetNode,int weight);
void print_graph();
pnode findNode();
void  deleteEdgeFromNode(pnode oldNode);
void deleteEdgeToNode();
void insert_node_cmd();
void delete_node_cmd();
void deleteGraph_cmd(pnode* head);
void BellmanFord();
void TravellingSalesmanProblem();


char getParmsForNewNode();
char getParmsForDeleteNode();
char getParmsForShortRoute();
char getParmsForShortRouteWithDefinedPoints();

#endif
