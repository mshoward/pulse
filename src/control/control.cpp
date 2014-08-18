#pragma once
class control
{
public:
	int errorNo;
	
private:
	int init_sock();
	int init_config();
	
public:
	sock_int out_server_port;
	sock_int mysql_server_port; //unsure about this
	
	config configuration;
	
	control();
	~control();
	
	int init();
	
	
	
};
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
		out_server_port.start(std::to_string(configuration.outbound_server_port));
		out_server_port.startAndDetatchAcceptAndReadThread();
		ret = out_server_port.errorNo;
	}
	return ret;
}

int control::init_config()
{
	
}

/***************************************************************
 * public members
 ***************************************************************/







////////////////////////////////////////////////////
/// State Queries ///
////////////////////////////////////////////////////









