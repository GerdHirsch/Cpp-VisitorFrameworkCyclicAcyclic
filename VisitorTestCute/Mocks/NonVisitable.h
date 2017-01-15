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

class Base{
public:
	//virtual // experimental
	std::string toString() const {
		return "Base";
	}
};
//TODO introduce Base as parameter
class NonVisitable : public Base{
public:
	std::string toString() const {
		return "NonVisitable";
	}
	bool wasDefaultVisited = false;
	bool wasVisitorVisited = false;

	void defaultVisited(){
		wasDefaultVisited = true;
	}
	void visitorVisited(){
		wasVisitorVisited = true;
	}
};



#endif /* NONVISITABLE_H_ */
