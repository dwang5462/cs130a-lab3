
#include "GraphNode.h"
#include <string>

GraphNode::GraphNode() {
	this->key = "";
    this->adjRoot = NULL;
	this->dataIndex = 0;
}

GraphNode::GraphNode(std::string key){
	this->key = key;
    this->adjRoot = NULL;
	this->dataIndex = 0;
}
GraphNode::GraphNode(std::string key, friendNode * adjRoot, int dataIndex){
	this->key = key;
	this->adjRoot = adjRoot;
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

void GraphNode::addFriend(friendNode * newFriend){
        if(adjRoot == NULL){
            adjRoot = newFriend;
        }
        else{
            newFriend->next = adjRoot;
            adjRoot = newFriend;
        }
}

void GraphNode::printFriendList(){
    if(adjRoot != NULL) {
        friendNode* n;
        for(n = adjRoot; n->next!=NULL;n=n->next){
		std::cout<<n->name<<",";
	}
        std::cout<<n->name;
    }
}
