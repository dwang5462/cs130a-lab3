#include "GraphNode.h"
#include "friendshipGraph.h"
#include "fseeker.h"
#include <string>
#include <iostream>

using namespace std;

int main(){
	friendshipGraph g;
	//fseeker seeker;
	//seeker.go(g);
	// g.insertGraphNode(Bob);
	 GraphNode* Joe = new GraphNode("Joe");
	 g.insertGraphNode(Joe);
	 std::cout << "after joe\n";
	 GraphNode* Jim = new GraphNode("Jim");
	 g.insertGraphNode(Jim);
	 g.addFriend("Bob", "Jim");
	 g.addFriend("Jim","Joe");
	 g.addFriend("Bob","Joe");
	 std::cout<<"before print\n";
	g.print();

	return 0;
}
