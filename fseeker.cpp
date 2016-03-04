#include "fseeker.h"

fseeker::fseeker() {
	pfile = fopen("ProfileData.txt", "w");
}

std::vector<std::string> fseeker::split(std::string str, char delimiter) {
	std::vector<std::string> internal;
	std::stringstream ss(str);       // turn the string into a stream.
	std::string tok;

	while(getline(ss, tok, delimiter))
	{
		internal.push_back(tok);
	}

	return internal;
}

void fseeker::initialize(friendshipGraph * graph) {
	std::ifstream f;
	f.open("input.txt", std::ios::in);
	if(!f) std::cerr << "File not found" << std::endl;
	else
	{
		FILE *pFile;
		pFile = fopen("ProfileData.txt","w");
		std::string line;
		while(std::getline(f, line))
		{
			std::vector<std::string> words = split(line, ',');
			GraphNode * newNode = new GraphNode();
			newNode->setKey(words[0]);
			for(int i = 3; i < words.size();i++) {
				friendNode * newfriend = new friendNode(words[i],NULL);
				newNode->addFriend(newfriend);
			}
			graph->insertGraphNode(newNode);
			int index = newNode->getDataIndex();
			int profileIndex = 53*index;
			fseek(pFile, profileIndex, SEEK_SET);
			char* name = new char[words[0].size()+1];
			memcpy(name,words[0].c_str(),words[0].size()+1);
			fputs(name,pFile);
			fseek(pFile, 20-strlen(name), SEEK_CUR);
			char* age = new char[words[1].size()+1];
			memcpy(age,words[1].c_str(),words[1].size()+1);
			fputs(age,pFile);
			fseek(pFile, 3-strlen(age),SEEK_CUR);
			char* occupation = new char[words[2].size()+1];
			memcpy(occupation,words[2].c_str(),words[2].size()+1);
			fputs(occupation,pFile);
		}
		fclose(pFile);
	}
}

void fseeker::insert(std::string name, std::string age, std::string occupation, int index) {
	
}