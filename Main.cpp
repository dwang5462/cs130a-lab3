#include "friendshipGraph.h"
#include "GraphNode.h"
#include "friendNode.h"
#include "fseeker.h"
#include "BTree.h"
#include <fstream>
#include <vector>
#include <string>



int main() {
	try
	{
		fseeker seeker;
		friendshipGraph g;
		BTree b;

		std::ifstream f;
		f.open("input1.txt", std::ios::in);
		int numAdded = 0;
		if (!f){
		  std::cerr << "File not found" << std::endl;
		  exit(1);
		}
		else
		{

			int number = 0;
			std::string line;
			std::string last = "";
			std::string lastAge = "";
			while (std::getline(f, line))
			{
				std::vector<std::string> words = seeker.split(line, ',');
				GraphNode * newNode = new GraphNode();
				newNode->setKey(words[0]);
				newNode->setDataIndex(numAdded);
				last = words.at(2);
				lastAge = words.at(1);
				for (int i = 3; i < words.size(); i++) {
					friendNode * newfriend = new friendNode(words[i], NULL);
					newNode->addFriend(newfriend);
				}
				g.insertGraphNode(newNode);
				b.insert(newNode);
				int index = newNode->getDataIndex();
				seeker.insert(words[0], words[1], words[2], numAdded);
				numAdded++;
			}

			fflush(seeker.pFile);
	
		}
		std::cout << "Welcome to Davids' World!\n";
		while (true)
		{
		  std::cout << "Commands are: PrintAll, PrintRange, Insert, AddFriend, ListFriendsInfo, and Exit" << std::endl;
		  std::cout << "Please enter command: ";
			std::string str;
			std::getline(std::cin, str);
			if (std::cin.eof())
			{
				break;
			}
			if (str.compare("Exit") == 0)
			{
			  std::cout << "Thanks for visiting Davids' World!\n";
				break;
			}
			else if (str.compare("PrintAll") == 0)
			{
				for (int i = 0; i < numAdded; i++) {
				std::cout << "Name: " << seeker.getName(i) << ", ";
				std::cout << "Age: " << seeker.getAge(i) << ", " ;
				std::cout << "Occupation: " << seeker.getOccupation(i) << ", ";
				std::cout << "Friends: ";
				g.printFriends(seeker.getName(i));
				std::cout << "\n";
				}
			}
			else if (str.compare("PrintRange") == 0)
			{
			  std::cout << "Please enter two names on separate lines.\n";
				std::string name1;
				std::string name2;
				std::getline(std::cin, name1);
				std::getline(std::cin, name2);
				std::vector<std::string> tmp = b.getRange(name1, name2);
				for (int i = 0; i < tmp.size(); i++) {
					int index = g.lookup(tmp.at(i));
					int dataindex = g.get(index)->getDataIndex();
					std::cout << "Name: " << seeker.getName(dataindex) << ", ";
					std::cout << "Age: " << seeker.getAge(dataindex) << ", ";
					std::cout << "Occupation: " << seeker.getOccupation(dataindex) << ", ";
					std::cout << "Friends: ";
					g.printFriends(tmp.at(i));
					std::cout << std::endl;
				}
			}
			else if (str.compare("Insert") == 0)
			{
			  std::cout << "Please enter name, age and occupation on separate lines.\n";
				std::string name;
				std::string age;
				std::string occupation;
				std::getline(std::cin, name);
				std::getline(std::cin, age);
				std::getline(std::cin, occupation);
				if (g.lookup(name) != -1)
					std::cout << "Person already in network.\n";
				else {
					seeker.insert(name, age, occupation, numAdded);
					GraphNode * toAdd = new GraphNode(name, NULL, numAdded);
					g.insertGraphNode(toAdd);
					b.insert(toAdd);
					numAdded++;
					std::cout << "Inserted Successfully" << std::endl;
				}

			}
			else if (str.compare("AddFriend") == 0)
			{
			  std::cout << "Please enter two names on separate lines that already exist in the network.\n";
				std::string name1;
				std::string name2;
				std::getline(std::cin, name1);
				std::getline(std::cin, name2);
				if (g.lookup(name1) == -1) {
					std::cout << "Sorry, " << name1 << " is not in the network\n";
				}
				else if (g.lookup(name2) == -1) {
					std::cout << "Sorry, " << name2 << " is not in the network\n";
				}
				else if (g.lookup(name1) == -1 && g.lookup(name2) == -1) {
					std::cout << "Sorry, " << name1 << " and " << name2 << "are not in the network\n";
				}
				else if (g.checkIfFriends(name1, name2)) {
					std::cout << "Already friends\n";
				}
				else {
					g.addFriend(name1, name2);
					std::cout << "Added friendship successfully\n";
				}
			}
			else if (str.compare("ListFriendsInfo") == 0)
			{
			  std::cout << "Please enter a name to find all friends info.\n";
				std::string name;
				std::getline(std::cin, name);
				if (g.lookup(name) == -1) {
					std::cout << "Sorry, " << name << " is not in the network\n";
				}
				else {
					int index = g.lookup(name);
					GraphNode * tmp = g.get(index);
					for (friendNode * n = tmp->getAdjRoot(); n != NULL; n = n->next) {
						int index1 = g.lookup(n->name);
						int dataindex = g.get(index1)->getDataIndex();
						std::cout << "Name: " << seeker.getName(dataindex) << ", ";
						std::cout << "Age: " << seeker.getAge(dataindex) << ", ";
						std::cout << "Occupation: " << seeker.getOccupation(dataindex);
						std::cout << "\n";
					}
				}
			}
			else if (str.compare("PrintOrder") == 0) {
				b.printAll();
			}
			else
			{
				std::cin.clear();
				std::cout << "Inputed string format was incorrect" << std::endl;
			}
		}
	}
	catch (std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	return 0;
}
