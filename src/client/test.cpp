


#include <iostream>
//#include <chrono>
//#include <thread>
#include <string>
using std::string;
using std::cout;
using std::endl;

void a(string msg, int n)
{
	cout << "Thread " << n << " says: " << msg << endl;
}


int main() 
{
	cout << "hello world" << endl;
	/*
	int er = 0;
	cout << "check: " << er++ << endl;
	//threadCaller();
	string str = "n";
	cout << "check: " << er++ << endl;
	for(int i = 0; i < 10; i++)
	{
		cout << "check: " << er++ << endl;
		string temp = str;
		std::thread thr(a, temp, i);
		thr.detach();
		str += 'n';
	}
	cout << "check: " << er++ << endl;
	std::this_thread::sleep_for(std::chrono::seconds(5));
	*/ 
	return 0;
}
