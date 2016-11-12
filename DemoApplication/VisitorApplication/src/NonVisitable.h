/*
 * NonVisitable.h
 *
 *  Created on: 22.05.2016
 *      Author: Gerd
 */

#ifndef NONVISITABLE_H_
#define NONVISITABLE_H_

#include <string>
#include <iostream>

class NonVisitable{
public:
	NonVisitable(){
		std::cout << "NonVisitable::NonVisitable()" << std::endl;
	}
	~NonVisitable(){
		std::cout << "NonVisitable::~NonVisitable()" << std::endl;
	}
	std::string toString() const {
		return "NonVisitable";
	}
};



#endif /* NONVISITABLE_H_ */
