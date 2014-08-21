#pragma once

class QUESTION;
class Demographic;
class USER;
class GUID;

class GUID
{
	std::string guid;
	
};

class QUESTION
{
	public:
	std::string question_text;
	unsigned int question_id;
	unsigned int priority_class;
	int requested_responses;
	int current_responses;
	unsigned int target_demographic;
	
	QUESTION(){}
	~QUESTION(){}
	
	bool fits(Demographic &demo);
	bool fits(USER &usr);
};



//Still under construction
class Demographic
{
	unsigned int demographic_id;
	int min_age;
	int max_age;
	int race;
	int major;
	int major_2;
	int minor;
	int dorm;
	int year_classification;
	int hair_color;
	int eye_color;
	int height;
	int blood_type;
};


class USER
{
	GUID guid;
	
};


