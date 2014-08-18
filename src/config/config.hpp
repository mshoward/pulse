#pragma once

class config
{
public:
	
	int errorNo;
	
	std::string mysql_server_port;
	std::string outbound_server_port;
	std::string next_item_to_be_determined;
	
	config(){}
	~config(){}
	int init();
};
