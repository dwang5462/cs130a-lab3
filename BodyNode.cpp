#include "BodyNode.h"
#include <iostream>

BodyNode::BodyNode()
{
	for (int i = 0; i < 5; i++)
		children[i] = NULL;
	for (int i = 0; i < 4; i++)
		keys[i] = "";
	for (int i = 0; i < 3; i++)
		leafItems[i] = NULL;
	isLeaf = false;
	parent = NULL;
	numContained = 0;
	minKeys = 2;
}

BodyNode::BodyNode(bool isLeaf)
{
	for (int i = 0; i < 5; i++)
		children[i] = NULL;
	for (int i = 0; i < 4; i++)
		keys[i] = "";
	for (int i = 0; i < 3; i++)
		leafItems[i] = NULL;
	this->isLeaf = isLeaf;
	parent = NULL;
	numContained = 0;
	minKeys = 2;
}

void BodyNode::setParent(BodyNode * parent)
{
	this->parent = parent;
}

BodyNode * BodyNode::getParent()
{
	return parent;
}

void BodyNode::setMinKey(int minKeys)
{
	this->minKeys = minKeys;
}

int BodyNode::getMinKey()
{
	return this->minKeys;
}

void BodyNode::setIsLeaf(bool isLeaf)
{
	this->isLeaf = isLeaf;
}

bool BodyNode::getIsLeaf()
{
	return this->isLeaf;
}

void BodyNode::setNumContained(int numContained)
{
	this->numContained = numContained;
}

int BodyNode::getNumContained()
{
	return this->numContained;
}

void BodyNode::setPrev(BodyNode * prev)
{
	this->prevLeaf = prev;
}

BodyNode * BodyNode::getPrev()
{
	return prevLeaf;
}

void BodyNode::setNext(BodyNode * next)
{
	this->nextLeaf = next;
}

BodyNode * BodyNode::getNext()
{
	return nextLeaf;
}

void BodyNode::printNode()
{
	std::cout << "(";
	for (int i = 0; i < numContained-1; i++) {
		std::cout << keys[i] << ",";
	}
	std::cout << keys[numContained - 1] << ")\n";
}

BodyNode * BodyNode::getChild(int pointerNum)
{
	if(pointerNum >= 0 && pointerNum < 5)
	return this->children[pointerNum];
}

void * BodyNode::setChild(BodyNode * newChild, int pointerNum)
{
	if (pointerNum >= 0 && pointerNum < 5)
		children[pointerNum] = newChild;
}

BodyNode * BodyNode::insertKey(std::string newKey)
{
	if (!isFull()) {
		if (numContained == 0) {
			keys[0] = newKey;
		}
		else if (numContained == 1) {
			if (newKey.compare(keys[0]) < 0) {
				keys[1] = keys[0];
				keys[0] = newKey;
			}
			else {
				keys[1] = newKey;
			}
		}
		else {
			//create for loop comparisons here
			int index = 0;
			if (newKey.compare(keys[0]) > 0 && newKey.compare(keys[1]) < 0) {
				index = 1;
			}
			if (newKey.compare(keys[1]) > 0) {
				index = 2;
			}
			if (numContained == 3) {
				if (newKey.compare(keys[2]) > 0) {
					index = 3;
				}
			}
			for (int i = index; i < numContained; i++) {
				keys[i + 1] = keys[i];
			}
			keys[index] = newKey;
		}
		numContained++;
	}
}

void BodyNode::insertLeafItem(GraphNode * leafItem)
{
	if (isFull()) {
		if (numContained == 0) {
			leafItems[0] = leafItem;
		}
		/*else if (numContained == 1) {
			if (leafItem->getKey().compare(leafItems[0]->getKey()) < 0) {
				leafItems[1] = leafItems[0];
				leafItems[0] = leafItem;
			}
			else {
				leafItems[1] = leafItem;
			}
		}*/
		else {
			//create for loop comparisons here
			int index = 0;
			if (leafItem->getKey().compare(leafItems[numContained - 1]->getKey()) > 0)
				index = numContained;
			else {
				for (int i = 0; i < numContained; i++) {
					if (leafItem->getKey().compare(leafItems[i]->getKey()) < 0) {
						index = i;
						break;
					}
				}
			}
			/*
			if (leafItem->getKey().compare(leafItems[0]->getKey()) > 0 && leafItem->getKey().compare(leafItems[1]->getKey()) < 0) {
				index = 1;
			}
			if (leafItem->getKey().compare(leafItems[1]->getKey()) > 0) {
				index = 2;
			}
			if (numContained == 3) {
				if (leafItem->getKey().compare(leafItems[2]->getKey()) > 0) {
					index = 3;
				}
			}*/
			for (int i = index; i < numContained; i++) {
				keys[i + 1] = keys[i];
			}
			leafItems[index] = leafItem;
		}
		numContained++;
	}
}

bool BodyNode::isFull()
{
	if (isLeaf && numContained == 3) {
		return true;
	}
	else if (numContained == 4) {
		return true;
	}
	else { 
		return false; 
	}
}

std::string BodyNode::getKey(int keyNum)
{
	if (keyNum < 4) {
		return keys[keyNum];
	}
	else {
		return "ERROR";
	}
}

GraphNode * BodyNode::getLeaf(int leafNum)
{
	if (leafNum < 3) {
		return leafItems[leafNum];
	}
	else {
		return NULL;
	}
}

int BodyNode::getKeyIndex(std::string key)
{
	for (int i = 0; i < numContained; i++) {
		if (keys[i].compare(key) == 0) {
			return i;
		}
	}
	return -1;
}
