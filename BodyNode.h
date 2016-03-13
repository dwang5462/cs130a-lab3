#pragma once
#ifndef BODYNODE_H
#define BODYNODE_H

#include <string>
#include "GraphNode.h"
#include "LeafNode.h"

class BodyNode {
public:
	BodyNode();
	BodyNode(bool isPreLeaf);
	void setParent(BodyNode * parent);
	BodyNode * getParent();
	void setIsPreLeaf(bool isPreLeaf);
	bool getIsPreLeaf();
	void setNumKeys(int numKeys);
	int getNumKeys();
	void setNumChildren(int numChildren);
	int getNumChildren();

	void printNode();
	BodyNode * getNodeChild(int pointerNum);
	LeafNode * getLeafChild(int pointerNum);
	void * setNodeChild(BodyNode * newChild, int pointerNum);
	void * setLeafChild(LeafNode * newChild, int pointerNum);
	void insertKey(std::string newKey);
	//void insertNodeChild(BodyNode * toAdd);
	BodyNode * insertLeafItem(GraphNode * leafItem, int leafIndex);
	BodyNode * splitBodyNode(BodyNode * splitter);
	bool isKeysFull();
	bool isChildrenFull();
	std::string getKey(int keyNum);
	GraphNode * getLeaf(int leafNum);
	int getKeyIndex(std::string key);
	int getLeftIndex(std::string key);


private:
	BodyNode * parent;
	std::string keys[5];
	int numKeys;
	int numChildren;
	BodyNode * nodeChildren[6]; 
	bool isPreLeaf;
	LeafNode * leafChildren[6];
};
#endif

