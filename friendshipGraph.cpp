#include "friendshipGraph.h"

friendshipGraph::friendshipGraph() {
	TABLE_SIZE = 211;
	table = new GraphNode*[TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++) {
		table[i] = NULL;
	}
}

int friendshipGraph::hash(std::string str, int seed) {
	int hash = seed;
	for(int i = 0;i<str.length();i++){
		hash = (hash*101 + str[i]) %TABLE_SIZE;
	}
	return hash;
}

void friendshipGraph::insertGraphNode(GraphNode * n){
        if(lookup(n->getKey())!=-1){
		return;
	}
	int index = hash(n->getKey(),0);
	while(table[index] != NULL){
		if(index == TABLE_SIZE-1){
			index = 0;
		}
		else{
			index++;
		}
	}
	n->setDataIndex(index);
	table[index] = n;
}

int friendshipGraph::lookup(std::string key) {
	int index = hash(key, 0);
	while(table[index] != NULL){
		if(table[index]->getKey() == key){
			return index;
		}
		if(index == TABLE_SIZE-1){
			index = 0;
		}
		else{
			index++;
		}
	}
	return -1;
}

void friendshipGraph::addFriend(std::string name1, std::string name2){
	int index1 = lookup(name1);
	int index2 = lookup(name2);
	/*if (index1 < 0 && index2 >= 0) {
		friendNode * newFriend1 = new friendNode(name1, NULL);
		table[index2]->addFriend(newFriend1);
	}
	if (index2 < 0 && index1 >= 0) {
		friendNode * newFriend2 = new friendNode(name2, NULL);
		table[index1]->addFriend(newFriend2);
	}
	*/
	if(index1 < 0 || index2 < 0) {
		return;
	}
	friendNode * newFriend1 = new friendNode(name1,NULL);
	friendNode * newFriend2 = new friendNode(name2,NULL);
	table[index1]->addFriend(newFriend2);
	table[index2]->addFriend(newFriend1);
}

void friendshipGraph::print(){
	std::cout << "{";
	for (int i=0;i<TABLE_SIZE;++i){
		if(table[i]!=NULL){
			std::cout<<"["<<table[i]->getKey()<<"("<<table[i]->getDataIndex()<<"): ";
			table[i]->printFriendList();
                        std::cout<<"]";
		}
	}
	std::cout << "}\n";
}
