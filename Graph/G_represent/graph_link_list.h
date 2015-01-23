// =====================================================================================
//
//       Filename:  graph_link_list.h
//
//    Description:  
//
//        Version:  1.0
//        Created:  01/21/2015 10:02:23 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Chen Xie (Neil), xiec@usc.edu
//   Organization:  USC
//
// =====================================================================================
//
#ifndef  graph_link_list_INC
#define  graph_link_list_INC

#define	MAX_NUM_NODE 100			// 

struct Node_t {
	int index;
	int weight;
	Node_t *next;
};				// ---  end of struct Node_t  ---
// =================================================================
//        Class:  C_graph
//  Description:  
// ==================================================================
class C_graph
{
	public:
		C_graph ();                             // constructor 
		void add_edge(int node1, int node2, int weight);
		void delete_edge(int node1, int node2);
		int num_node_in_graph();
		void print_graph();
		void print_one_node(int root);

	protected:
		void add_node(int root, int index, int weight);
		void delete_node(int root, int index);

	private:
		Node_t *head[MAX_NUM_NODE];
		int numNode;
		void create_node(int index, int weight, Node_t **rv);
}; // -----  end of class C_graph  ----- 

#endif   // ----- #ifndef graph_link_list_INC  ----- 
