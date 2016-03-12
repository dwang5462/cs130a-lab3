#include "friendshipGraph.h"
#include "GraphNode.h"
#include "friendNode.h"
#include "fseeker.h"
#include <fstream>
#include <vector>
#include <string>

int main() {
	fseeker seeker;
	friendshipGraph g;

	std::ifstream f;
	f.open("input.txt", std::ios::in);
	int numAdded = 0;
	if (!f) std::cerr << "File not found" << std::endl;
	else
	{
		std::string line;
		while (std::getline(f, line))
		{
			std::vector<std::string> words = seeker.split(line, ',');
			GraphNode * newNode = new GraphNode();
			newNode->setKey(words[0]);
			newNode->setDataIndex(numAdded);
			for (int i = 3; i < words.size(); i++) {
				friendNode * newfriend = new friendNode(words[i], NULL);
				newNode->addFriend(newfriend);
			}
			g.insertGraphNode(newNode);
			int index = newNode->getDataIndex();
			int profileIndex = 53 * numAdded;
			numAdded++;
			fseek(seeker.pFile, profileIndex, SEEK_SET);
			char* name = new char[words[0].size() + 1];
			memcpy(name, words[0].c_str(), words[0].size() + 1);
			fputs(name, seeker.pFile);
			fseek(seeker.pFile, 20 - strlen(name), SEEK_CUR);
			char* age = new char[words[1].size() + 1];
			memcpy(age, words[1].c_str(), words[1].size() + 1);
			fputs(age, seeker.pFile);
			fseek(seeker.pFile, 3 - strlen(age), SEEK_CUR);
			char* occupation = new char[words[2].size() + 1];
			memcpy(occupation, words[2].c_str(), words[2].size() + 1);
			fputs(occupation, seeker.pFile);
		}
	}
	/*std::cout << "Name: " << seeker.getName(0);
	std::cout << " Age: " << seeker.getAge(0);
	std::cout << " Occupation: ";
	std::cout << seeker.getOccupation(0) << std::endl;
	g.print();*/
	for (int i = 0; i < numAdded; i++) {
		std::cout << "Name: " << seeker.getName(i) << ", ";
		std::cout << " Age: " << seeker.getAge(i) << ", " ;
		std::cout << " Occupation: " << seeker.getOccupation(i) << ", ";
		std::cout << "Friends: ";
		g.printFriends(seeker.getName(i));
		std::cout << ")\n";
	}
}