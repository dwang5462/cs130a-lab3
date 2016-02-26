#ifndef FRIENDNODE_H
#define FRIENDNODE_H

#include <string>

class friendNode{
public:
	friendNode(std::string name, friendNode * next) {
		this->name = name;
		this->next = next;
	}
	std::string name;
	friendNode * next;

private:

};

#endif