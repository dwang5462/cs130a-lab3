#pragma once
#ifndef BODYNODE.H
#define BODYNODE.H

#include <string>
#include "GraphNode.h"
class BodyNode {
public:
	BodyNode();
	BodyNode(bool isLeaf);
	void setParent(BodyNode * parent);
	BodyNode * getParent();
	void setMinKey(int minKey);
	int getMinKey();
	void setIsLeaf(bool isLeaf);
	bool getIsLeaf();
	void setNumContained(int numContained);
	int getNumContained();
	void setPrev(BodyNode * prev);
	BodyNode * getPrev();
	void setNext(BodyNode* next);
	BodyNode* getNext();

	void printNode();
	BodyNode * getChild(int pointerNum);
	void * setChild(BodyNode * newChild, int pointerNum);
	BodyNode * insertKey(std::string newKey);
	void insertLeafItem(GraphNode * leafItem);
	bool isFull();
	std::string getKey(int keyNum);
	GraphNode * getLeaf(int leafNum);
	int getKeyIndex(std::string);


private:
	BodyNode * parent;
	int minKeys;
	std::string keys[4];
	int numContained;
	BodyNode * children[5]; 
	bool isLeaf;
	GraphNode * leafItems[3];
	BodyNode* nextLeaf;
	BodyNode* prevLeaf;

};
#endif

