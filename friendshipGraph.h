#ifndef FRIENDSHIPGRAPH_H
#define FRIENDSHIPGRAPH_H

#include "GraphNode.h"

class friendshipGraph {
public:
	friendshipGraph();
	void hash(std::string str, int seed=0);



private:
	GraphNode ** table;
	int TABLE_SIZE = 211;

};

#endif