#ifndef __LISTGRAPH_HH__
#define __LISTGRAPH_HH__

#include <list>
#include <vector>
#include "../graph.hh"

//TODO : MAKE THEM PRIVATE!


class Node
{
	public:
		Node(unsigned int i){id=i;deleted=false;};

		std::list<unsigned> successors;
		unsigned int id;
		bool deleted;
};

class Arc
{
	public:
		Arc(unsigned fromNode, unsigned toNode){from=fromNode;to=toNode;deleted=false;};
		unsigned from; 	//ancestor
		unsigned to;	//successor
		bool deleted;
};

//----------------------------------------------------------------------
		
class ListGraph
{
	public:
		ListGraph();
		virtual unsigned int add_node () ;
		virtual void delete_node (unsigned int id) ;
		virtual unsigned int add_arc (unsigned int from, unsigned int to) ;
		virtual void remove_arc (unsigned int id) ;
		virtual std::list<unsigned int> list_successors (unsigned int id) ;
		virtual std::list<unsigned int> list_ancestors (unsigned int id) ;
		virtual std::list<unsigned int> list_arcs_from (unsigned int id) ;
		virtual std::list<unsigned int> list_arcs() ;
		virtual std::list<unsigned int> list_nodes() ;
		virtual std::list<unsigned int> list_arcs_to (unsigned int id) ;
		virtual unsigned int node_count () ;
		virtual unsigned int arcs_count () ;

	private:
		std::vector<Node>::iterator getNodeIteratorById(unsigned int i);
		
		std::vector<Node> listNodes;
		std::vector<Arc> listArcs;
		unsigned int get_next_node_id()		{return last_node_id++;};
		unsigned int get_next_arc_id() 		{return last_arc_id++; }; 
		//~ Arc* getArcById(unsigned int i);

		unsigned int last_node_id;
		unsigned int last_arc_id;
};

#endif /* LISTGRAPH_HH */ 
