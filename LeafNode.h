#pragma once
#ifndef LEAFNODE_H
#define LEAFNODE_H

#include <string>
#include "GraphNode.h"

#include "BTreeNode.h"

public class LeafNode {

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
	BTreeNode * getLeftParent();
	BTreeNode * getRightParent();
	void setLeftParent(BTreeNode * leftParent);
	void setRightParent(BTreeNode * rightParent);
	BTreeNode * split(GraphNode * toAdd);



private:

	int numLeaves;
	bool isFirstLeaf;
	GraphNode * leaves[3];
	LeafNode * left;
	LeafNode * right;
	BTreeNode * leftParent;
	BTreeNode * rightParent;



};
#endif