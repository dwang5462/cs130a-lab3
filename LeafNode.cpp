#include "LeafNode.h"

LeafNode::LeafNode()
{
	numLeaves = 0;
	left = NULL;
	right = NULL;
}

int LeafNode::getNumLeaves()
{
	return numLeaves;
}

bool LeafNode::getIsFirstLeaf()
{
	return isFirstLeaf;
}

void LeafNode::setIsFirstLeaf(bool isFirstLeaf)
{
	this->isFirstLeaf = isFirstLeaf;
}

void LeafNode::insertLeafNode(GraphNode * insert)
{
	if (!isFull()) {
		if (numLeaves == 0) {
			leaves[0] = insert;
		}
		else {
			int index = 0;
			if (insert->getKey().compare(leaves[numLeaves - 1]->getKey()) > 0)
				index = numLeaves;
			else {
				for (int i = 0; i < numLeaves; i++) {
					if (insert->getKey().compare(leaves[i]->getKey()) < 0) {
						index = i;
						break;
					}
				}
			}
			for (int i = numLeaves-1; i >= index; i--) {
				leaves[i + 1] = leaves[i];
			}
			leaves[index] = insert;
		}
		numLeaves++;
	}
}

GraphNode * LeafNode::getLeafNode(int index)
{
	return leaves[index];
}

bool LeafNode::isFull()
{
	if (numLeaves == 4)
		return true;
	else
		return false;
}

LeafNode * LeafNode::getLeftLeaf()
{
	return left;
}

LeafNode * LeafNode::getRightLeaf()
{
	return right;
}

void LeafNode::setLeftLeaf(LeafNode * leftLeaf)
{
	left = leftLeaf;
}

void LeafNode::setRightLeaf(LeafNode * rightLeaf)
{
	right = rightLeaf;
}

