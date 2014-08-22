#pragma once

class scheduler
{
public:
	dataBucket dirty_cache;
	queue<QUESTION_RET> return_queue;
	scheduler(){}
	~scheduler(){}
	
	/**
		en_cache functions
	*/
	
	/**
		function that reads guids from a member and member function passed to it
			calls process_request inside it --> which returns the
			question by reference
	*/
	
	/**
		
	*/
};
