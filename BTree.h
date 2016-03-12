#pragma once

#ifndef BTREE_H
#define BTREE_H

#include <string>
#include <iostream>
#include "BTreeNode.h"
#include "GraphNode.h"
#include "friendshipGraph.h"
#include "fseeker.h"
#include "friendNode.h"

class BTree {

public:
	BTree();

	void insert(GraphNode * insert);

	void printRangeOccupation(std::string name1, std::string name2);

	GraphNode * initFind(LeafNode * initRoot, std::string find);

	LeafNode * insertFind(BTreeNode ** root, std::string find);

	GraphNode * find(BTreeNode ** root, std::string find);

	LeafNode * getFirstLeaf();

	void setFirstLeaf(LeafNode * newFirstLeaf);

	//BodyNode * splitLeaf(BodyNode * splitter, GraphNode * toAdd);

	int findLeftIndex(BTreeNode ** node, std::string find);


private:
	BTreeNode ** root;
	LeafNode * initRoot;
	int totalContained;
	LeafNode * firstLeaf;



};


#endif // !BTREE_H
