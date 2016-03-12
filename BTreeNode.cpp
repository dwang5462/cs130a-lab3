#include "BTreeNode.h"

BTreeNode::BTreeNode()
{
	key = "";
	leftChildren = NULL;
	rightChildren = NULL;
	parent = NULL;
	isPreLeaf = false;
	leftLeaf = NULL;
	rightLeaf = NULL;
}

BTreeNode::BTreeNode(bool isPreLeaf)
{
	key = "";
	leftChildren = NULL;
	rightChildren = NULL;
	parent = NULL;
	isPreLeaf = true;
	leftLeaf = NULL;
	rightLeaf = NULL;
}

std::string BTreeNode::getKey()
{
	return key;
}

void BTreeNode::setKey(std::string key)
{
	this->key = key;
}

BTreeNode ** BTreeNode::getLeftChildren()
{
	return leftChildren;
}

BTreeNode ** BTreeNode::getRightChildren()
{
	return rightChildren;
}

void BTreeNode::setLeftChildren(BTreeNode ** leftChildren)
{
	this->leftChildren = leftChildren;
}

void BTreeNode::setRightChildren(BTreeNode ** rightChildren)
{
	this->leftChildren = leftChildren;
}

BTreeNode * BTreeNode::getParent()
{
	return parent;
}

void BTreeNode::setParent(BTreeNode * parent)
{
	this->parent = parent;
}

bool BTreeNode::getPreLeaf()
{
	return isPreLeaf;
}

void BTreeNode::setPreLeaf(bool isPreLeaf)
{
	this->isPreLeaf = isPreLeaf;
}

LeafNode * BTreeNode::getLeftLeaf()
{
	return leftLeaf;
}

LeafNode * BTreeNode::getRightLeaf()
{
	return rightLeaf;
}

void BTreeNode::setLeftLeaf(LeafNode * left)
{
	leftLeaf = left;
}

void BTreeNode::setRightLeaf(LeafNode * right)
{
	rightLeaf = right;
}
