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

	std::vector<std::string> getRange(std::string name1, std::string name2);

	GraphNode * initFind(std::string find);

	BodyNode * insertFind(std::string find);

	LeafNode * findLeaf(std::string find);

	LeafNode * getFirstLeaf();

	void setFirstLeaf(LeafNode * newFirstLeaf);

	void printAll();

	void printNodes(BodyNode * root);

	int getTotalContained();


private:
	BodyNode * root;
	LeafNode * initRoot;
	int totalContained;
	LeafNode * firstLeaf;



};


#endif // !BTREE_H
