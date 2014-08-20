#pragma once
/*
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
*/



/***************************************************************
 * private  members
***************************************************************/

std::string config::getWord(std::string &str)
{
	/** consumes first word of the string */
	std::string ret = "";
	int spa = 0;
	unsigned int i = 0;
	for(i = 0; (i < str.length()) && (spa < 2); i++)
	{
		if(spa > 0)
		{
			if(!std::isspace(str[i]))
				ret += str[i];
		}
		
		if(std::isspace(str[i]))
		{
			spa++;
		}
	}
	str = str.substr(i, str.length());
	return ret;
}

void config::stripComment(std::string &str)
{
	str = ((str.find('#') == std::string::npos) ? 
		str :
		str.substr(str.find('#'), str.length()));
}

/***************************************************************
 * public members
 ***************************************************************/



int config::init()
{
	int ret = 0;
	std::string line;
	std::string val;
	std::string test;
	std::string prop;
	
	conf.open(CONF_PATH, std::ios::in);
	if(!conf.is_open())
	{
		errorNo = ret = -1;
		return ret;
	}
	while(!conf.eof())
	{
		line.clear();
		getline(conf, line);
		stripComment(line);
		
		//prop name
		prop = getWord(line);
		if(prop != "")
		{
			test = getWord(line);
			if(test == "=")
			{
				val = getWord(line);
				if(val != "")
				{
					mapper[prop] = val;
				}
			}
		}
	}
	conf.close();
	return ret;
}

std::string config::get(const char *str)
{
	std::string newstr = "";
	int i = 0;
	while(str[i] != 0)
	{
		newstr += str[i];
		i++;
	}
	return get(newstr);
}

std::string config::get(std::string str)
{
	return mapper[str];
}



////////////////////////////////////////////////////
/// State Queries ///
////////////////////////////////////////////////////








