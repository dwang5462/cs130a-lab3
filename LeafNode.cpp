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
			//create for loop comparisons here
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
			for (int i = index; i < numLeaves; i++) {
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

/*BTreeNode * LeafNode::split(GraphNode * toAdd)
{
	BTreeNode * parent;
	GraphNode * tmp[4];
	LeafNode * left = new LeafNode();
	LeafNode * right = new LeafNode();
	for (int i = 0; i < numLeaves; i++) {
		tmp[i] = getLeafNode(i);
	}
	int index = 0;
	if (toAdd->getKey().compare(tmp[2]->getKey()) > 0)
		index = 3;
	else {
		for (int i = 0; i < 3; i++) {
			if (toAdd->getKey().compare(tmp[i]->getKey()) < 0) {
				index = i;
				break;
			}
		}
	}
	for (int i = index; i < 3; i++) {
		tmp[i + 1] = tmp[i];
	}
	tmp[index] = toAdd;
	left->insertLeafNode(tmp[0]);
	left->insertLeafNode(tmp[1]);
	left->setLeftLeaf(getLeftLeaf());
	left->setRightLeaf(right);
	right->insertLeafNode(tmp[2]);
	right->insertLeafNode(tmp[3]);
	right->setLeftLeaf(left);
	right->setRightLeaf(getRightLeaf());

	parent = new BTreeNode(true);
	left->setRightParent(parent);
	right->setLeftParent(parent);
	parent->setKey(tmp[2]->getKey());
	parent->setLeftLeaf(left);
	parent->setRightLeaf(right);
	if (getIsFirstLeaf()) {
		left->setIsFirstLeaf(true);
		this->setIsFirstLeaf(false);
	}

	return parent;
}
*/