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
	std::string getName(int index);
	std::string getAge(int index);
	std::string getOccupation(int index);
	void insert(std::string name, std::string age, std::string occupation, int index);
	bool isWordChar(char c);
	std::string stripWord(std::string word);
	FILE * pFile;
	FILE * readFile;

	
private:
};

#endif