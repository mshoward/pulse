#pragma once
/*
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
*/
/***************************************************************
 * private static members
 ***************************************************************/







/***************************************************************
 * public static members
 ***************************************************************/







/***************************************************************
 * private  members
***************************************************************/


int control::init_sock()
{
	int ret = 0;
	if(config_state)
	{
		out_server_port.init();
		out_server_port.start(out_port);
		out_server_port.startAndDetatchAcceptAndReadThread();
		ret = out_server_port.errorNo;
	}
	return ret;
}

int control::init_config()
{
	int ret = configuration.init();
	if(!ret)
	{
		out_port = std::string::stoi(configuration.get("out_server_port"));
		mysql_port = std::string::stoi(configuration.get("mysql_server_port"));
		config_state++;
	}
	
}

/***************************************************************
 * public members
 ***************************************************************/

int control::init()
{
	config_state = 0;
	sock_state = 0;
	out_port = 0;
	mysql_port = 0;
	
}





////////////////////////////////////////////////////
/// State Queries ///
////////////////////////////////////////////////////









