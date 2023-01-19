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


void deleteGraph_cmd(pnode* head);
void getParamsForCreatGraph();
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
void BellmanFord();
void TravellingSalesmanProblem();
void allArrPermutations();
void getParamsForNewNode();
void getParamsForDeleteNode();
void getParamsForShortRoute();
void getParamsForShortRouteWithDefinedPoints();

#endif
