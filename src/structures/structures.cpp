#pragma once
/**
	GUID
*/



bool GUID::matches(GUID &uid)
{
	return guid == uid.guid;
}

GUID& GUID::operator=(GUID &uid)
{
	guid = uid.guid;
	return *this;
}


/**
	end GUID
*/




/**
	QUESTION
*/

bool QUESTION::fits(Demographic &dem)
{
	if (demo != NULL)
	{
		return demo->fits(dem);
	}
	return true;
}

bool QUESTION::fits(USER &usr)
{
	if (demo != NULL)
		return demo->fits(usr);
	return true;
}

/**
	end QUESTION
*/

/**
	Demographic
*/

bool Demographic::tempFits(Demographic &dem)
{
	for(int i = 0; i < MAX_DEM_FIELDS; i++)
	{
		if
		(
			(fields[i] != dem.fields[i]) &&
			(fields[i] > 0) && (dem.fields[i] > 0)
		)
		{
			return false;
		}
	}
	return true;
}

bool Demographic::fits(Demographic &dem)
{
	return tempFits(dem);
}

bool Demographic::fits(USER &usr)
{
	if (usr.demo != NULL)
	{
		return fits( *(usr.demo));//dereference pointer
	}
	return true;
}

bool Demographic::fits(QUESTION &quest)
{
	if (quest.demo != NULL)
	{
		return fits( *(quest.demo));//dereference pointer
	}
	return true;
}


/**
	end Demographic
*/
/**
	USER
	
	USER();
	USER(GUID guid);
	USER(std::string str);
	~USER(){};
	
	int init();
	int init(GUID guid);
	int init(std::string str);
*/



USER::USER()
{
	guid.guid = "";
	demo = NULL;
}
USER::USER(GUID uid)
{
	guid = uid;
}
USER::USER(std::string str)
{
	guid.guid = str;
}

int USER::init()
{
	guid.guid = "";
	return 0;
}

int USER::init(GUID uid)
{
	guid = uid;
	return 0;
}

int USER::init(std::string str)
{
	guid.guid = str;
	return 0;
}



/**
	end USER
*/
