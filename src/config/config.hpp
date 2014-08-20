#pragma once

class config
{
public:

private:
	std::string getWord(std::string &str);
	void stripComment(std::string &str);
	std::map<std::string, std::string> mapper;
public:
	
	int errorNo;
	std::fstream conf;
	
	config(){}
	~config(){}
	int init();
	std::string get(const char * str);
	std::string get(std::string str);
	
};

