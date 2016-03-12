#include "LeafNode.h"

LeafNode::LeafNode()
{
	numLeaves = 0;
	leftParent = NULL;
	rightParent = NULL;
	left = NULL;
	right = NULL;
}

void LeafNode::insertLeafNode(GraphNode * insert)
{

}

GraphNode * LeafNode::getLeafNode(int index)
{
	return leaves[index];
}

bool LeafNode::isFull()
{
	if (numLeaves == 3)
		return true;
	else
		return false;
}

LeafNode * LeafNode::getLeftLeaf()
{
	return nullptr;
}

LeafNode * LeafNode::getRightLeaf()
{
	return nullptr;
}

void LeafNode::setLeftLeaf(LeafNode * set)
{
}

void LeafNode::setRightLeaf(LeafNode * set)
{
}

BodyNode * LeafNode::getLeftParent()
{
	return nullptr;
}

BodyNode * LeafNode::getRightParent()
{
	return nullptr;
}

void LeafNode::setLeftParent(BodyNode * set)
{
}

void LeafNode::setRightParent(BodyNode * set)
{
}
