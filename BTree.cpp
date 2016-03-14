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
		//std::cout << "toinsert bodynode: " << toInsert->getKey(0) << std::endl;
		int leafIndex = toInsert->getLeftIndex(insert->getKey());
		//std::cout << "leafindex: " << leafIndex << std::endl;
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

/*std::vector<std::string> BTree::getRange(std::string name1, std::string name2)
{

}*/

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
	// int leafIndex = root->findLeftIndex(find);
	// if (leafIndex == -1) {
	// 	return root->getLeafChild(0);
	// }
	// else {
	// 	return root->getLeafChild(leafIndex);
	// }
}

GraphNode * BTree::find(std::string find)
{
	BodyNode * tmp = insertFind(find);
	int index = tmp->getLeftIndex(find);
	LeafNode * tmp2;
	tmp2 = tmp->getLeafChild(index);
	for (int i = 0; i < tmp2->getNumLeaves(); i++) {
		if (find.compare(tmp2->getLeafNode(i)->getKey()) == 0) {
			return tmp2->getLeafNode(i);
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
	//std::cout << root->getNodeChild(0)->getKey(0) <<std::endl;
	// for(int i = 0; i < root->getNumChildren(); i++){
	// 	std::cout << "Leaf " << i << ": ";
	// 	for(int j = 0; j<root->getLeafChild(i)->getNumLeaves(); j++){
	// 		std::cout << root->getLeafChild(i)->getLeafNode(j)->getKey() << ",";
	// 	}
	// 	std::cout << std::endl;
	// }
	// std::cout << std::endl;
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
}*/
