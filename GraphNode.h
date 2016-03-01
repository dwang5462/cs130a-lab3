#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include "friendNode.h"
#include <string>
#include <iostream>

class GraphNode{
public:
	GraphNode();
	GraphNode(std::string key);
	GraphNode(std::string key, friendNode * adjRoot, int dataIndex);
	std::string getKey();
	friendNode * getAdjRoot();
	int getDataIndex();
	void setKey(std::string key);
	void setAdjRoot(friendNode * newRoot);
	void setDataIndex(int dataIndex);
	void addFriend(friendNode * newFriend);
	void printFriendList();


private:
	std::string key;
	friendNode * adjRoot;
	int dataIndex;
};

#endif
