#include "friendshipGraph.h"

friendshipGraph::friendshipGraph() {
	GraphNode * newTable = new GraphNode*[TABLE_SIZE];
}

void friendshipGraph::hash(std::string str, int seed=0) {
	int hash = seed;
	for(int i = 0;i<str.length();i++){
		hash = hash*101 + str[i];
	}
	return hash%TABLE_SIZE;
}