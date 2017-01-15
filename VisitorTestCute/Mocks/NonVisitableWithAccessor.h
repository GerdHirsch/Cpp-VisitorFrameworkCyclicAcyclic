/*
 * NonVisitableWithAccessor.h
 *
 *  Created on: 30.05.2016
 *      Author: Gerd
 */

#ifndef SRC_NONVISITABLEWITHACCESSOR_H_
#define SRC_NONVISITABLEWITHACCESSOR_H_

#include <string>
#include <iostream>

class NonVisitableWithAccessor{
public:
	using this_type = NonVisitableWithAccessor;

	NonVisitableWithAccessor():data("default"){
		std::cout << "NonVisitableWithAccessor::NonVisitableWithAccessor() data: " << data << std::endl;
	}
	~NonVisitableWithAccessor(){
		std::cout << "NonVisitableWithAccessor::~NonVisitableWithAccessor() data: " << data << std::endl;
	}
	std::string toString_() const {
		std::string retVal("NonVisitableWithAccessor ");
		retVal += data;
		return retVal;
	}
	bool wasDefaultVisited = false;
	bool wasVisitorVisited = false;

	void defaultVisited(){
		wasDefaultVisited = true;
	}
	void visitorVisited(){
		wasVisitorVisited = true;
	}
	class Accessor{
	protected:
		static void setData(this_type& This, std::string data){
			This.data = data;
		}
		static std::string getData(this_type& This){
			return This.data;
		}
	};
private:
	std::string data;
};

#endif /* SRC_NONVISITABLEWITHACCESSOR_H_ */
