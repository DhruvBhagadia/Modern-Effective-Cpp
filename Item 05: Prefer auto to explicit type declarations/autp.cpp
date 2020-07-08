/*
	Advantages of using auto
	1. initialization of auto variables is mandatory hence no chance of undefined behavior
	2. Saves time being utilized in specifying long name types of variables
*/
#include<unordered_map>

using namespace std;

int main(){
    int a; //uninitialized
    
    //auto a; gives error
    auto b = 10; //needs initialization
    
	unordered_map<string, int> m;
	for(auto i: m){ 
	    //without use of auto: for(pair<string, int>& i) and hence auto saves time
	    //do stuff
	}

	return 0;
}
