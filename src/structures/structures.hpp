#pragma once

class QUESTION;
class Demographic;
class RESPONSE;
class USER;
class GUID;

class GUID
{
public:
	std::string guid;
	GUID& operator=(GUID &uid);
	bool matches(GUID &uid);
};

class QUESTION
{
	/**
		All memory allocation is handled by other sections - Demographic pointers
		are pointers to a demographic held in storage by something else.
	*/
	public:
	std::string question_text;
	unsigned int question_id;
	unsigned int priority_class;
	int requested_responses;
	int current_responses;
	unsigned int target_demographic;
	Demographic *demo;
	
	QUESTION();
	~QUESTION(){}
	
	bool fits(Demographic &dem);
	bool fits(USER &usr);
};



//Still under construction
class Demographic
{
	/**
		Easiest way to compare demographics is to abstract them into numbers.
		e.g. race could be fields[0], min_age could be fields[1], etc.
		
		Fields that don't matter can be 0 or less than 0.
		
		There is difficulty in describing something like this in programming.
			An elegant, proper description will be the result of proper description
			in the database and communication between the people working on the database.
			
		For now, I will implement a temporary cursory comparison function and craft a
		better one once the Demographic architecture is more settled.
	*/
public:
	unsigned int demographic_id;
	int fields[MAX_DEM_FIELDS];///MAX_DEM_FIELDS is defined in defs.hpp
	
	Demographic(){memset(fields, 0, sizeof(fields)); demographic_id = 0;}
	~Demographic(){}
	
	bool fits(Demographic &dem);
	bool fits(USER &usr);
	bool fits(QUESTION &quest);
	bool tempFits(Demographic &dem);
};


class USER
{
	/**
		A user has a guid, and a demographic
		
		All memory allocation is handled by other sections - Demographic pointers
		are pointers to a demographic held in storage by something else.
	*/
	
public:
	GUID guid;
	Demographic *demo;
	bool matches(GUID &uid);
	
	USER();
	USER(GUID uid);
	USER(std::string str);
	~USER(){};
	
	int init();
	int init(GUID uid);
	int init(std::string str);
};


class RESPONSE
{
public:
	std::string response;
	GUID guid;
};
