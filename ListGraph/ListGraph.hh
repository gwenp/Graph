#ifndef __LISTGRAPH_HH__
#define __LISTGRAPH_HH__

#include <list>
#include <vector>
#include "../graph.hh"

//TODO : MAKE THEM PRIVATE!


class Node
{
	public:
		Node( unsigned i ){id=i;};

		std::list<unsigned> successors;
		unsigned id;
};

class Arc
{
	public:
		Arc(unsigned Aid, unsigned fromNode, unsigned toNode){id = Aid; from=fromNode;to=toNode;};
		unsigned id; 
		unsigned from; //ancestor
		unsigned to;   //successor
		std::list<unsigned>::iterator itFrom;
};

//----------------------------------------------------------------------
		
class ListGraph
{
	public:
		ListGraph();
		~ListGraph();
		virtual unsigned add_node () ;
		virtual void delete_node (unsigned Nid) ;
		virtual unsigned add_arc (unsigned NidFrom, unsigned NidTo) ;
		virtual void remove_arc (unsigned Aid) ;
		virtual std::list<unsigned> list_successors (unsigned Nid) ; // doit etre remplace par std::list<unsigned> list_successors (Node* n) ; 
		virtual std::list<unsigned> list_ancestors (unsigned Nid) ; // doit etre remplace par std::list<unsigned> list_successors (Node* n) ; 
		virtual std::list<unsigned> list_arcs_from (unsigned Nid) ;
		virtual std::list<unsigned> list_arcs_to (unsigned Nid) ;
		virtual unsigned int node_count () ;
		virtual unsigned int arcs_count () ;

	private:
		
		std::vector<Node> listNodes;
		std::vector<Arc> listArcs;

		unsigned int get_next_node_id()		{ return current_node_id++; };
		Node* get_node(unsigned Nid)		{ return &listNodes.at(Nid); };
		Arc* get_arc(unsigned Aid)			{ return &listArcs.at(Aid); };
		unsigned current_node_id;
		unsigned current_arc_id;
		
		unsigned nodes_nb;
		unsigned arcs_nb;
};

#endif /* LISTGRAPH_HH */ 
