#include <iostream>
#include "IOHandle.h"

using namespace std;

int main(){
	IOHandle handle;
	while(handle.exit() == false){
		handle.run();
	}
	return 0;
}