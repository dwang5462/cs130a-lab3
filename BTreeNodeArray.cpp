#include "BTreeNodeArray.h"

BTreeNodeArray::BTreeNodeArray(){
	array = new BTreeNode*[4];
	for(int i = 0; i<4; i++){
		arry[i] = NULL;
	}
	numContained = 0;
	parent = NULL;
}

void BTreeNodeArray::insert(BTreeNode * toAdd){
	
}
	BTreeNode * split();
	bool isFull();
	void setParent(BTreeNodeArray * parent);
	BTreeNodeArray * getParent();