#pragma once
#ifndef BTREENODE_H
#define BTREENODE_H

#include <string>
#include "LeafNode.h"



class BTreeNode {

public:
	BTreeNode();
	BTreeNode(bool isPreLeaf);

	std::string getKey();
	void setKey(std::string key);

	BTreeNode ** getLeftChildren();
	BTreeNode ** getRightChildren();

	void setLeftChildren(BTreeNode ** leftChildren);
	void setRightChildren(BTreeNode ** rightChildren);

	BTreeNode * getParent();
	void setParent(BTreeNode * parent);

	bool getPreLeaf();
	void setPreLeaf(bool isPreLeaf);

	LeafNode * getLeftLeaf();
	LeafNode * getRightLeaf();

	void setLeftLeaf(LeafNode * left);
	void setRightLeaf(LeafNode * right);


private:
	std::string key;
	BTreeNode ** leftChildren;
	BTreeNode ** rightChildren;

	BTreeNode * parent;

	bool isPreLeaf;
	LeafNode * leftLeaf;
	LeafNode * rightLeaf;





};



#endif