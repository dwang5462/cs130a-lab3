#ifndef FRIENDSHIPGRAPH_H
#define FRIENDSHIPGRAPH_H

#include "GraphNode.h"
#include "friendNode.h"
#include "fseeker.h"
#include <iostream>
#include <string>
#include <cstdlib>

class friendshipGraph {
public:
	friendshipGraph();
	int hash(std::string str, int seed);
	int lookup(std::string key);
	void insertGraphNode(GraphNode * n);
	void addFriend(std::string name1, std::string name2);
	void print();
	void printFriends(std::string key);




private:
	GraphNode ** table;
	int TABLE_SIZE;

};

#endif