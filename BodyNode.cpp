#include "BodyNode.h"
#include <iostream>

BodyNode::BodyNode()
{

}

void BodyNode::setParent(BodyNode * parent)
{
	this->parent = parent;
}

BodyNode * BodyNode::getParent()
{
	return parent;
}

void BodyNode::printNode()
{
	std::cout << "(";
	for (int i = 0; i < numContained-1; i++) {
		std::cout << keys[i] << ",";
	}
	std::cout << keys[numContained - 1] << ")\n";
}

BodyNode * BodyNode::getPointer(int pointerNum)
{
	if (pointerNum == 1) return onePointer;
	if (pointerNum == 2) return twoPointer;
	if (pointerNum == 3) return threePointer;
	if (pointerNum == 4) return fourPointer;
	if (pointerNum == 5) return fivePointer;
}

int BodyNode::insert(std::string newKey)
{
	if (!isFull()) {
		if (numContained == 0) {
			keys[0] = newKey;
			return 2;
		}
		else if (numContained == 1) {
			if (newKey.compare(keys[0] < 0)) {
				keys[1] = keys[0];
				keys[0] = newKey;
			}
			else {
				keys[1] = newKey;
			}
		}
		else if (numContained == 2) {
			if (newKey.compare(keys[0]) < 0) {
				for (int i = 0; i < numContained; i++) {
					keys[i + 1] = keys[i];
				}
				keys[0] = newKey;
				return 2;
			}
		}
		else if ()
	}
}

bool BodyNode::isFull()
{
	if (numContained == 4) {
		return true;
	}
	return false;
}
