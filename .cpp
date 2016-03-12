#include "BTree.h"

BTree::BTree()
{
	root = new BTreeNode(true);
	
}

void BTree::insert(std::string key)
{
}

void BTree::printRangeOccupation(std::string name1, std::string name2)
{
}

BTreeNode * BTree::find(std::string name)
{
	return nullptr;
}

BTreeNode * BTree::splitLeaf(BTreeNode * splitter)
{
	std::string tmp[4];
	for (int i = 0; i < splitter.getNumContained(); i++) {
		tmp[i] = splitter.get
	}
	return nullptr;
}
