#ifndef FSEEK_H
#define FSEEK_H

#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include "GraphNode.h"
#include "friendshipGraph.h"
#include "friendNode.h"

class fseeker{
public:
	fseeker();
	std::vector<std::string> split(std::string str, char delimiter);
	void initialize(friendshipGraph * graph);
	
private:
	File * pfile;
};

#endif