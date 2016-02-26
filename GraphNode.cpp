#include "GraphNode.h"
#include <string>

GraphNode::GraphNode() {
	this->key = "";
	this->adjRoot = NULL;
	this->adjTail = NULL;
	this->dataIndex = 0;
}
	
GraphNode::GraphNode(std::string key, friendNode * adjRoot, int dataIndex){
	this->key = key;
	this->adjRoot = adjRoot;
	this->adjTail = findTail();
	this->dataIndex = dataIndex;
}
	
std::string GraphNode::getKey(){
	return this->key;
}

friendNode * GraphNode::getAdjRoot(){
	return this->adjRoot;
}

int GraphNode::getDataIndex() {
	return this->dataIndex;
}

void GraphNode::setKey(std::string key){
	this->key = key;
}

void GraphNode::setAdjRoot(friendNode * newRoot){
	this->adjRoot = newRoot;
}

void GraphNode::setDataIndex(int dataIndex){
	this->dataIndex = dataIndex;
}

friendNode * GraphNode::findTail(){
	friendNode * n;
	for(n = adjRoot;n->next!=NULL;n=n->next) {
	}
	return n;
}

void GraphNode::addFriend(friendNode * newFriend){
	adjTail->next = newFriend;
	adjTail = newFriend;
}