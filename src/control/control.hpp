#pragma once
class control
{
public:
	int errorNo;
	
private:
	int config_state;
	int sock_state;
	
	int init_sock();
	int init_config();
	
public:
	int out_port;
	int mysql_port;
	sock_int out_server_port;
	sock_int mysql_server_port; //unsure about this
	
	config configuration;
	
	control();
	~control();
	
	int init();
	
	
	
};//replace control.hpp with this declaration
