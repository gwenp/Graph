#include "ListGraph.hh"

ListGraph::ListGraph()
{
	last_node_id = 1;
	last_arc_id = 1;
}

unsigned int ListGraph::add_node () 
{
	unsigned int r = get_next_node_id ();
	listNodes.at(r) = Node(r);
	last_node_id++;
	
	return r;
}

void ListGraph::delete_node (unsigned int id) 
{
	listNodes.at(id).deleted = true;
	//NODELIST: listNodes.erase(listNodes.at(id));
	
	for(std::vector<Arc>::iterator it=listArcs.begin();it!=listArcs.end();it++)
	{
		if((*it).deleted==false && ((*it).from == id || (*it).to == id))
		{
			(*it).deleted=true;
		}
		
		//TODO:delete references
	}
}

unsigned int ListGraph::add_arc (unsigned int from, unsigned int to)
{
	listNodes.at(from).successors.push_back(listNodes.at(to).id);
	listArcs.push_back(Arc(from,to));
	
	unsigned r=last_arc_id;
	last_arc_id++;
	
	return r;
}

void ListGraph::remove_arc (unsigned int id)
{
	listArcs.at(id).deleted = true;
}

std::list<unsigned int> ListGraph::list_successors (unsigned int id)
{
	return listNodes.at(id).successors;
}

std::list<unsigned int> ListGraph::list_ancestors (unsigned int id)
{
	std::list<unsigned> r;
	for(std::vector<Arc>::iterator it= listArcs.begin();it!=listArcs.end();it++)
	{
		//TODO: check if it's (*it).from instead of (*it).to
		if((*it).from==id)
			r.push_back((*it).from);
	}
	return r;
}

std::list<unsigned int> ListGraph::list_arcs_from (unsigned int id)
{
	
}

std::list<unsigned int> ListGraph::list_arcs()
{}

std::list<unsigned int> ListGraph::list_nodes()
{}

std::list<unsigned int> ListGraph::list_arcs_to (unsigned int id)
{}

unsigned int ListGraph::node_count () 
{}

unsigned int ListGraph::arcs_count () 
{}

//======================================================================

std::vector<Node>::iterator ListGraph::getNodeIteratorById(unsigned int i)
{
	bool found = false;
	std::vector<Node>::iterator it = listNodes.begin();
	
	while(found == false && it!=listNodes.end())
	{
		if(it->id == i)
			found = true;
		it++;
	}
	if(found==true)
		return it;
}

//~ Arc* ListGraph::getArcById(unsigned int i)
//~ {
	//~ bool found=false;
	//~ std::list<Arc>::iterator it = listArcs.begin();
	//~ 
	//~ while(found == false && it!=listArcs.end())
	//~ {
		//~ if(it->id == i)
			//~ found = true;	
		//~ it++;
	//~ }
	//~ return &(*it);
//~ }
