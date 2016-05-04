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
		initRoot->insertLeafNode(insert);
		if (initRoot->isFull() == false) {
			totalContained++;
		}
		else {
			BodyNode * newRoot = new BodyNode(true);
			root = newRoot;
			LeafNode * left = new LeafNode();
			LeafNode * right = new LeafNode();
			left->insertLeafNode(initRoot->getLeafNode(0));
			left->insertLeafNode(initRoot->getLeafNode(1));
			left->setLeftLeaf(initRoot->getLeftLeaf());
			left->setRightLeaf(right);
			left->setIsFirstLeaf(true);
			right->insertLeafNode(initRoot->getLeafNode(2));
			right->insertLeafNode(initRoot->getLeafNode(3));
			right->setLeftLeaf(left);
			right->setRightLeaf(initRoot->getRightLeaf());
			root->insertKey(right->getLeafNode(0)->getKey());
			root->setLeafChild(left, 0);
			root->setLeafChild(right, 1);
			firstLeaf = left;
			initRoot = NULL;
			totalContained++;
		}
	}
	else {
		BodyNode * toInsert = insertFind(insert->getKey());
		int leafIndex = toInsert->getLeftIndex(insert->getKey());
		BodyNode * topParent = toInsert->insertLeafItem(insert, leafIndex);
		BodyNode * tmp = topParent;
		while(tmp->getIsPreLeaf() == false){
			tmp = tmp->getNodeChild(0);
		}
		LeafNode * isFirst = tmp->getLeafChild(0);
		if(isFirst->getIsFirstLeaf()) {
			firstLeaf = isFirst;
		}
		if(topParent->getParent() == NULL) {
			root = topParent;
		}
	}
	totalContained++;
}

std::vector<std::string> BTree::getRange(std::string name1, std::string name2)
{
	if (name1.compare(name2) > 0) {
		std::string tmp = name1;
		name1 = name2;
		name2 = tmp;
	}
	std::vector<std::string> relevant;
	LeafNode * tmp = findLeaf(name1);
	int index = 0;
	for (int i = 0; i < tmp->getNumLeaves(); i++) {
		if (name1.compare(tmp->getLeafNode(i)->getKey()) == 0) {
			index = i;
			break;
		}
		if (name1.compare(tmp->getLeafNode(i)->getKey()) > 0) {
			index++;
		}
	}
	if (index < 3) {
		for (int i = index; i < tmp->getNumLeaves(); i++) {
			if (name2.compare(tmp->getLeafNode(i)->getKey()) < 0) {
				return relevant;
			}
			relevant.push_back(tmp->getLeafNode(i)->getKey());
		}
	}
	tmp = tmp->getRightLeaf();
	int state = 0;
	while (tmp != NULL) {
		for (int i = 0; i < tmp->getNumLeaves(); i++) {
			if (name2.compare(tmp->getLeafNode(i)->getKey()) < 0) {
				state = 1;
				break;
			}
			relevant.push_back(tmp->getLeafNode(i)->getKey());
			if (name2.compare(tmp->getLeafNode(i)->getKey()) == 0) {
				state = 1;
				break;
			}
		}
		if (state == 1) {
			break;
		}
		tmp = tmp->getRightLeaf();
	}
	return relevant;
}

GraphNode * BTree::initFind(std::string find)
{
	for (int i = 0; i < initRoot->getNumLeaves(); i++) {
		if (initRoot->getLeafNode(i)->getKey() == find) {
			return initRoot->getLeafNode(i);
		}
	}
}

BodyNode * BTree::insertFind(std::string find)
{
	BodyNode * tmp = root;
	while (tmp->getIsPreLeaf() == false) {
		int toLook = tmp->getLeftIndex(find);
		tmp = tmp->getNodeChild(toLook);
	}
	return tmp;
}

LeafNode * BTree::findLeaf(std::string find)
{
	BodyNode * tmp = insertFind(find);
	int index = tmp->getLeftIndex(find);
	LeafNode * tmp2;
	tmp2 = tmp->getLeafChild(index);
	return tmp2;
}

LeafNode * BTree::getFirstLeaf()
{
	return firstLeaf;
}

void BTree::setFirstLeaf(LeafNode * newFirstLeaf)
{
	this->firstLeaf = newFirstLeaf;
}

void BTree::printAll(){
	LeafNode * start = firstLeaf;
	LeafNode * start1 = firstLeaf;
	std::cout << "Root: ";
	for(int i = 0; i < root->getNumKeys(); i++) {
		std::cout << root->getKey(i) << ",";
	}
	std::cout << "numkeys: " << root->getNumKeys();
	std::cout << std::endl;
	std::cout << "nodes: \n";
	printNodes(root);
	std::cout << "(\n";
	int leafNum = 1;
	while(start != NULL){
		std::cout << "In Leaf " << leafNum << ": ";
		for(int i = 0; i<3; i++){
			if(start->getLeafNode(i) != NULL)
				std::cout << start->getLeafNode(i)->getKey() << ",";
		}
		std::cout << "numLeaves: " << start->getNumLeaves();
		std::cout << std::endl;
		start = start->getRightLeaf();
		leafNum++;
	}
	while (start1 != NULL) {
		for (int i = 0; i<3; i++) {
			if (start1->getLeafNode(i) != NULL)
				std::cout << start1->getLeafNode(i)->getKey() << ",";
		}
		start1 = start1->getRightLeaf();
	}
	std::cout << ")\n";

}

void BTree::printNodes(BodyNode * tmp){
	if (tmp == NULL) {
		return;
	}
	for(int i = 0; i<tmp->getNumChildren(); i++){
			printNodes(tmp->getNodeChild(i));
	}
	for (int i = 0; i < tmp->getNumKeys(); i++) {
		std::cout << tmp->getKey(i) << ",";
	}
	std::cout << std::endl;
}
int BTree::getTotalContained()
{
	return totalContained;
}
