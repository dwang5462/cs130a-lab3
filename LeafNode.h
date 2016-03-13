#pragma once
#ifndef LEAFNODE_H
#define LEAFNODE_H

#include <string>
#include "GraphNode.h"

//class BTreeNode;

class LeafNode {

public:

	LeafNode();
	int getNumLeaves();
	bool getIsFirstLeaf();
	void setIsFirstLeaf(bool isFirstLeaf);
	void insertLeafNode(GraphNode * insert);
	GraphNode * getLeafNode(int index);
	bool isFull();
	LeafNode * getLeftLeaf();
	LeafNode * getRightLeaf();
	void setLeftLeaf(LeafNode * leftLeaf);
	void setRightLeaf(LeafNode * rightLeaf);


private:

	int numLeaves;
	bool isFirstLeaf;
	GraphNode * leaves[4];
	LeafNode * left;
	LeafNode * right;



};
#endif