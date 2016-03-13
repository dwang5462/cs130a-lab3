#pragma once

#ifndef BTREE_H
#define BTREE_H

#include <string>
#include <iostream>
#include "BodyNode.h"
#include "GraphNode.h"
#include "friendshipGraph.h"
#include "fseeker.h"
#include "friendNode.h"

class BTree {

public:
	BTree();

	void insert(GraphNode * insert);

	void printRangeOccupation(std::string name1, std::string name2);

	GraphNode * initFind(std::string find);

	BodyNode * insertFind(std::string find);

	GraphNode * find(std::string find);

	LeafNode * getFirstLeaf();

	void setFirstLeaf(LeafNode * newFirstLeaf);

	void printAll();

	//BTreeNode ** splitBTreeNode(BTreeNode ** splitter, BTreeNode * toAdd);

	//BodyNode * splitLeaf(BodyNode * splitter, GraphNode * toAdd);

	//int findLeftIndex(BTreeNode ** node, std::string find);


private:
	BodyNode * root;
	LeafNode * initRoot;
	int totalContained;
	LeafNode * firstLeaf;



};


#endif // !BTREE_H
