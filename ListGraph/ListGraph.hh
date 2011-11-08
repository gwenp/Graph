#ifndef __LISTGRAPH_HH__
#define __LISTGRAPH_HH__

#include <list>
#include <vector>
#include "../graph.hh"

class Node;
class NodeArc;


//----------------------------------------------------------------------
		
class ListGraph
{
	public:
		ListGraph();
		virtual Node* add_node () ; 						//	O(1)
		virtual void delete_node (Node* n) ;									//	O(n*m)
		virtual NodeArc add_arc (Node* from, Node* to) ;						//	O(1)
		virtual void remove_arc (NodeArc* a) ;									//	O(1)

		
		std::list<Node*> getSuccessors(Node* from);
		std::list<Node*> getPredecesseurs(Node* from); 	//TODO
		
		std::list<NodeArc> getArcsFrom(Node* from);
		std::list<NodeArc> getArcsTo(Node* from);
		
	private:
		std::vector<Node>::iterator getNodeIteratorById(unsigned int i);
		
		unsigned int nb_nodes;
		unsigned int nb_arcs;
		 
		std::list<Node> listNodes;
};


class NodeArc
{
	public :
		NodeArc(Node* f,Node* t,std::list<Node*>::iterator iterator){to=t;from=f;it=iterator;}
		Node* to;	
		Node* from;	
		std::list<Node*>::iterator it;	
	private:
};

class Node
{
	public:
		Node(ListGraph* l){ };

		std::list<Node*> successors;
		std::list<Node>::iterator it;
};

#endif /* LISTGRAPH_HH */ 
