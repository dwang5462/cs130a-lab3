#include "BodyNode.h"
#include <iostream>

BodyNode::BodyNode()
{
	for (int i = 0; i < 6; i++)
		nodeChildren[i] = NULL;
	for (int i = 0; i < 5; i++)
		keys[i] = "";
	for (int i = 0; i < 6; i++)
		leafChildren[i] = NULL;
	isPreLeaf = false;
	parent = NULL;
	numKeys = 0;
	numChildren = 0;
}

BodyNode::BodyNode(bool isPreLeaf)
{
	for (int i = 0; i < 6; i++)
		nodeChildren[i] = NULL;
	for (int i = 0; i < 5; i++)
		keys[i] = "";
	for (int i = 0; i < 6; i++)
		leafChildren[i] = NULL;
	this->isPreLeaf = isPreLeaf;
	parent = NULL;
	numKeys = 0;
	numChildren = 0;
}

void BodyNode::setParent(BodyNode * parent)
{
	this->parent = parent;
}

BodyNode * BodyNode::getParent()
{
	return parent;
}

void BodyNode::setIsPreLeaf(bool isPreLeaf)
{
	this->isPreLeaf = isPreLeaf;
}

bool BodyNode::getIsPreLeaf()
{
	return this->isPreLeaf;
}

void BodyNode::setNumKeys(int numKeys)
{
	this->numKeys = numKeys;
}

int BodyNode::getNumKeys()
{
	return this->numKeys;
}

void BodyNode::setNumChildren(int numChildren){
	this->numChildren = numChildren;
}
	
int BodyNode::getNumChildren(){
	return this->numChildren;
}

void BodyNode::printNode()
{
	std::cout << "(";
	for (int i = 0; i < numKeys-1; i++) {
		std::cout << keys[i] << ",";
	}
	std::cout << keys[numKeys - 1] << ")\n";
}

BodyNode * BodyNode::getNodeChild(int pointerNum)
{
	if(pointerNum >= 0 && pointerNum < 6)
		return this->nodeChildren[pointerNum];
}

LeafNode * BodyNode::getLeafChild(int pointerNum){
	if(pointerNum >= 0 && pointerNum < 6)
		return this->leafChildren[pointerNum];
}

void * BodyNode::setNodeChild(BodyNode * newChild, int pointerNum)
{
	if (pointerNum >= 0 && pointerNum < 6)
		nodeChildren[pointerNum] = newChild;
}

void * BodyNode::setLeafChild(LeafNode * newChild, int pointerNum){
	if(pointerNum >= 0 && pointerNum < 6)
		leafChildren[pointerNum] = newChild;
}

void BodyNode::insertKey(std::string newKey)
{
	if (!isKeysFull()) {
		if (numKeys == 0) {
			keys[0] = newKey;
		}
		else {
			//create for loop comparisons here
			int index = 0;
			if (newKey.compare(keys[numKeys - 1]) > 0)
				index = numKeys;
			else {
				for (int i = 0; i < numKeys; i++) {
					if (newKey.compare(keys[i]) < 0) {
						index = i;
						break;
					}
				}
			}
			for (int i = index; i < numKeys; i++) {
				keys[i + 1] = keys[i];
			}
			keys[index] = newKey;
		}
		numKeys++;
	}
}

// void insertNodeChild(BodyNode * toAdd){
// 	if (!isChildrenFull()) {
// 		if (numChildren == 0) {
// 			nodeChildren[0] = toAdd;
// 		}
// 		else {
// 			//create for loop comparisons here
// 			int index = 0;
// 			if (toAdd.compare(nodeChildren[numChildren - 1]) > 0)
// 				index = numChildren;
// 			else {
// 				for (int i = 0; i < numChildren; i++) {
// 					if (newKey.compare(keys[i] < 0) {
// 						index = i;
// 						break;
// 					}
// 				}
// 			}
// 			for (int i = index; i < numKeys; i++) {
// 				keys[i + 1] = keys[i];
// 			}
// 			keys[index] = newKey;
// 		}
// 		numKeys++;
// 	}
// }

BodyNode * BodyNode::insertLeafItem(GraphNode * leafItem, int leafIndex)
{
	leafChildren[leafIndex]->insertLeafNode(leafItem);
	if(leafChildren[leafIndex]->isFull()){
		LeafNode * left = new LeafNode();
		LeafNode * right = new LeafNode();
		left->insertLeafNode(leafChildren[leafIndex]->getLeafNode(0));
		left->insertLeafNode(leafChildren[leafIndex]->getLeafNode(1));
		right->insertLeafNode(leafChildren[leafIndex]->getLeafNode(2));
		right->insertLeafNode(leafChildren[leafIndex]->getLeafNode(3));
		if(leafChildren[leafIndex]->getIsFirstLeaf()){
			left->setIsFirstLeaf(true);
		}
		if(isChildrenFull() == false){
			for(int i = leafIndex+1; i < 6; i++){
				leafChildren[i+1] = leafChildren[i];
			}
		}
		leafChildren[leafIndex] = left;
		leafChildren[leafIndex+1] = right;
		std::string toAdd = right->getLeafNode(0)->getKey();
		insertKey(toAdd);
		if(isKeysFull()){
			return splitBodyNode(this);
		}
	}
	return this;
}

BodyNode * splitBodyNode(BodyNode * splitter){
	BodyNode * left = new BodyNode(true);
	BodyNode * right = new BodyNode(true);
	BodyNode * parent;
	if(splitter->getIsPreLeaf() == true){
		left->setLeafChild(splitter->getLeafChild(0), 0);
		left->setLeafChild(splitter->getLeafChild(1), 1);
		left->setLeafChild(splitter->getLeafChild(2), 2);
		left->insertKey(splitter->getKey(0));
		left->insertKey(splitter->getKey(1));
		right->setLeafChild(splitter->getLeafChild(3), 0);
		right->setLeafChild(splitter->getLeafChild(4), 1);
		right->setLeafChild(splitter->getLeafChild(5), 2);
		right->insertKey(splitter->getKey(3));
		right->insertKey(splitter->getKey(4));
	}
	else{
		left->setNodeChild(splitter->getNodeChild(0), 0);
		left->setNodeChild(splitter->getNodeChild(1), 1);
		left->setNodeChild(splitter->getNodeChild(2), 2);
		left->insertKey(splitter->getKey(0));
		left->insertKey(splitter->getKey(1));
		right->setNodeChild(splitter->getNodeChild(3), 0);
		right->setNodeChild(splitter->getNodeChild(4), 1);
		right->setNodeChild(splitter->getNodeChild(5), 2);
		right->insertKey(splitter->getKey(3));
		right->insertKey(splitter->getKey(4));
	}
	if(splitter->getParent() == NULL){
		parent = new BodyNode();
		parent->setNodeChild(left,0);
		parent->setNodeChild(right,1);
		parent->insertKey(splitter->getKey(2));
	}
	else {
		parent = splitter->getParent();
		parent->insertKey(splitter->getKey(2));
		int index = parent->getKeyIndex(splitter->getKey(2));
		for(int i = index+1; i<parent->getNumChildren(); i++){
			parent->setNodeChild(parent->getNodeChild(i), i+1);
		}
		parent->setNodeChild(left, index);
		parent->setNodeChild(right, index + 1);
		if(parent->isKeysFull() == true||parent->isChildrenFull() == true){
			return splitBodyNode(parent);
		}
	}
	return parent;
}

bool BodyNode::isKeysFull()
{
	if (numKeys == 5) {
		return true;
	}
	else { 
		return false; 
	}
}

bool BodyNode::isChildrenFull(){
	if (numChildren == 6) {
		return true;
	}
	return false;
}

std::string BodyNode::getKey(int keyNum)
{
	if (keyNum < 5) {
		return keys[keyNum];
	}
	else {
		return "ERROR";
	}
}

int BodyNode::getKeyIndex(std::string key)
{
	for (int i = 0; i < numKeys; i++) {
		if (keys[i].compare(key) == 0) {
			return i;
		}
	}
	return -1;
}

int BodyNode::getLeftIndex(std::string key){
	int index = -1;
	for (int i = 0; i < 4; i++) {
		if (keys[i] == "") {
			break;
		}
		else {
			if (key.compare(keys[i]) < 0) {
				continue;
			}
			index++;
		}
	}
	return index;
}