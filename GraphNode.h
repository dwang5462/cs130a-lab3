#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include "friendNode.h"
#include <string>

class GraphNode{
public:
	GraphNode();
	GraphNode(std::string key, friendNode * adjRoot, int dataIndex);
	std::string getKey();
	friendNode * getAdjRoot();
	int getDataIndex();
	void setKey(std::string key);
	void setAdjRoot(friendNode * newRoot);
	void setDataIndex(int dataIndex);
	friendNode * findTail();
	void addFriend(friendNode * newFriend);


private:
	std::string key;
	friendNode * adjRoot;
	friendNode * adjTail;
	int dataIndex;
};

#endif