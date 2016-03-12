#include "BTree.h"

BTree::BTree()
{
	initRoot = new LeafNode();
	initRoot->setIsFirstLeaf(true);
	root = NULL;
	firstLeaf = initRoot;
	totalContained = 0;
}

void BTree::insert(GraphNode * insert)
{
	if (initRoot != NULL) {
		if (!initRoot->isFull()) {
			initRoot->insertLeafNode(insert);
			totalContained++;
		}
		else {
			BTreeNode ** newRoot = new BTreeNode*[4];
			for (int i = 0; i < 4; i++) {
				newRoot[i] = NULL;
			}
			root = newRoot;
			root[0] = initRoot->split(insert);
			firstLeaf = root[0]->getLeftLeaf();
			initRoot = NULL;
			totalContained++;
		}
	}
	else {

	}
}

void BTree::printRangeOccupation(std::string name1, std::string name2)
{

}

GraphNode * BTree::initFind(LeafNode * initRoot, std::string find)
{
	for (int i = 0; i < initRoot->getNumLeaves(); i++) {
		if (initRoot->getLeafNode(i)->getKey() == find) {
			return initRoot->getLeafNode(i);
		}
	}
}

LeafNode * BTree::insertFind(BTreeNode ** root, std::string find)
{
	while (root[0]->getPreLeaf() == false) {
		int toLook = findLeftIndex(root, find);
		if (toLook == -1) {
			root = root[0]->getLeftChildren();
		}
		else {
			root = root[toLook]->getRightChildren();
		}
	}
	int leafIndex = findLeftIndex(root, find);
	if (leafIndex == -1) {
		return root[0]->getLeftLeaf();
	}
	else {
		return root[leafIndex]->getRightLeaf();
	}
}

GraphNode * BTree::find(BTreeNode ** root, std::string find)
{
	LeafNode * tmp = insertFind(root, find);
	for (int i = 0; i < tmp->getNumLeaves(); i++) {
		if (find.compare(tmp->getLeafNode(i)->getKey()) == 0) {
			return tmp->getLeafNode(i);
		}
	}
	return NULL;
}

LeafNode * BTree::getFirstLeaf()
{
	return firstLeaf;
}

void BTree::setFirstLeaf(LeafNode * newFirstLeaf)
{
	this->firstLeaf = newFirstLeaf;
}

/*BodyNode * BTree::splitLeaf(BodyNode * splitter, GraphNode * toAdd)
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
		left->setParent(parent);
		right->setParent(parent);
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
*/
int BTree::findLeftIndex(BTreeNode ** node, std::string find)
{
	int index = -1;
	for (int i = 0; i < 4; i++) {
		if (node[i] == NULL) {
			break;
		}
		else {
			if (find.compare(node[i]->getKey()) < 0) {
				continue;
			}
			index++;
		}
	}
	return index;
}
