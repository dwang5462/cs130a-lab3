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

	void insert(std::string key);

	void printRangeOccupation(std::string name1, std::string name2);

	BodyNode * find(std::string name);

	BodyNode * splitLeaf(BodyNode * splitter, GraphNode * toAdd);


private:
	BTreeNode * root;



};


#endif // !BTREE_H
