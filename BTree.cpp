#include "BTree.h"

BTree::BTree()
{
	root = new BodyNode(true);
	
}

void BTree::insert(std::string key)
{
}

void BTree::printRangeOccupation(std::string name1, std::string name2)
{
}

BodyNode * BTree::find(std::string name)
{
	return nullptr;
}

BodyNode * BTree::splitLeaf(BodyNode * splitter, GraphNode * toAdd)
{
	BodyNode * parent;
	GraphNode * tmp[4];
	BodyNode * left = new BodyNode(true);
	BodyNode * right = new BodyNode(true);
	for (int i = 0; i < splitter->getNumContained(); i++) {
		tmp[i] = splitter->getLeaf(i);
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
	left->insertLeafItem(tmp[0]);
	left->insertLeafItem(tmp[1]);
	left->setPrev(splitter->getPrev());
	left->setNext(right);
	right->insertLeafItem(tmp[2]);
	right->insertLeafItem(tmp[3]);
	right->setPrev(left);
	right->setNext(splitter->getNext());

	if (splitter->getParent() == NULL) {
		parent = new BodyNode();
		left->setParent(Parent);
		right->setParent(Parent);
		parent->insertKey(tmp[2]->getKey());
		parent->setChild(left, 0);
		parent->setChild(right, 1);
	}
	else {
		parent = splitter->getParent();
		BodyNode * parent = parent->insertKey(tmp[2]->getKey());
		int index = parent->getKeyIndex(tmp[2]->getKey());
		parent->setChild(left, index);
		parent->setChild(right, index + 1);
	}
	return parent;
}
