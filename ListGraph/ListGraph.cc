#include "ListGraph.hh"

ListGraph::ListGraph()
{
	nb_nodes = 0;
	nb_arcs = 0;
}

Node* ListGraph::add_node ()  //O(1)
{
	listNodes.push_back(Node(this));
	std::list<Node>::iterator it = listNodes.end();
	Node* n = &(*it);
	n->it = it;
	return n;
}

void ListGraph::delete_node (Node* n) // pb: O(n*m) != O(m)
{
	for(std::list<Node>::iterator it=listNodes.begin();it!=listNodes.end();it++)
	{
		for(std::list<Node*>::iterator it2=(*it).successors.begin();it2!=(*it).successors.end();it2++)
		{
			if(*it2==n)
				(*it).successors.erase(it2);
		}
		listNodes.erase(n->it);
	}
}

NodeArc ListGraph::add_arc (Node* from, Node* to) //O(1)
{
	from->successors.push_back(to);
	return NodeArc(from,to,from->successors.end());
}

void ListGraph::remove_arc (NodeArc* a) //O(1)
{
	a->to->successors.erase(a->it);
}

std::list<Node*> ListGraph::getSuccessors(Node* from) //O(1)
{
	return from->successors;
}

std::list<NodeArc> ListGraph::getArcsFrom(Node* from) //O(m)
{
	std::list<NodeArc> lA;
	for(std::list<Node*>::iterator it=from->successors.begin(); it!=from->successors.end();it++)
	{
		lA.push_back(NodeArc(from, (*it),it));
	}
	return lA;
}

std::list<NodeArc> ListGraph::getArcsTo(Node* to) 
{
	std::list<NodeArc> lA;
	for(std::list<Node>::iterator it=listNodes.begin(); it!=listNodes.end();it++)
	{
		for(std::list<Node*>::iterator it2=(*it).successors.begin();it2!=(*it).successors.end();it2++)
		{
			
		}
	}
	return lA;
}

//======================================================================
