#pragma once
#ifndef BODYNODE.H
#define BODYNODE.H

#include <string>

class BodyNode {
public:
	BodyNode();
	void setParent(BodyNode * parent);
	BodyNode * getParent();
	void printNode();
	BodyNode * getPointer(int pointerNum);
	void insert(std::string newKey);
	bool isFull();


private:
	BodyNode * parent;
	std::string keys[4];
	int numContained;
	BodyNode * onePointer;
	BodyNode * twoPointer;
	BodyNode * threePointer;
	BodyNode * fourPointer;
	BodyNode * fivePointer;
};
#endif

