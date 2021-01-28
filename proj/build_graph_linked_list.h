/*
edges: node0 node1 val
1 2 10
1 4 5
2 3 5
4 3 8
2 5 5

*/
#include<iostream>
const int MAX=100;
int arr[]={1,2,10,1,4,5,2,3,5,4,3,8,2,5,5,2,7,6};
class Edge{
    public:
        int val;
        int vexid_linked_to;
        Edge* next_edge;

        Edge(int v,int vexid){
            val = v;
            vexid_linked_to=vexid;
            next_edge=NULL;
        }
};

class Graph{
    public:
        Edge* nodeList[MAX];

        void addNodeAtTail(int source_node,Edge* edge_tobeadded){
            Edge* node_ptr = nodeList[source_node];// get the header ptr 
            if(node_ptr==NULL){
                nodeList[source_node]=edge_tobeadded;
            }else{
                while(node_ptr->next_edge!=NULL){// move to the end of the list 
                    node_ptr=node_ptr->next_edge;
                }
                node_ptr->next_edge=edge_tobeadded;// add the new node as next 
            }
        }
};

Graph* build_graph_from_array(int* array,int size){
    Graph* g=new Graph();
    for(int i=0;i<size;i+=3){
        g->addNodeAtTail(array[i],new Edge(array[i+2],array[i+1]));
    }
    return g;
}

void showListedGraph(Graph* g){
    for(int i=0;i<10;i++){// as an example, just show 10 lines 
        Edge* tmpEdge = g->nodeList[i];
        if(tmpEdge!=NULL){
            std::cout<<"("<<i<<")";
            while(tmpEdge){
                std::cout<<"->(f:"<<i<<",t:"<<tmpEdge->vexid_linked_to
                    <<",val:"<<tmpEdge->val<<")";
                tmpEdge=tmpEdge->next_edge;
            }
            std::cout<<"\n";
        }
    }
}

int main(){
    Graph* g=build_graph_from_array(arr,sizeof(arr)/sizeof(arr[0]));
    showListedGraph(g);
    //std::cout<<g->nodeList[1]->val<<std::endl;
}