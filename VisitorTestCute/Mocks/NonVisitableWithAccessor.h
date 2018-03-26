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

	NonVisitableWithAccessor():data(false){
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
		static void setData(this_type& This, bool data){
			This.data = data;
		}
		static bool getData(this_type& This){
			return This.data;
		}
	};
private:
	bool data;
};
class NonVisitableWithAccessor2{
public:
	using this_type = NonVisitableWithAccessor2;

	NonVisitableWithAccessor2():data(false){
		std::cout << "NonVisitableWithAccessor2::NonVisitableWithAccessor2() data: " << data << std::endl;
	}
	~NonVisitableWithAccessor2(){
		std::cout << "NonVisitableWithAccessor2::~NonVisitableWithAccessor2() data: " << data << std::endl;
	}
	std::string toString_() const {
		std::string retVal("NonVisitableWithAccessor2 ");
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
		static void setData(this_type& This, bool data){
			This.data = data;
		}
		static bool getData(this_type& This){
			return This.data;
		}
	};
private:
	bool data;
};

#endif /* SRC_NONVISITABLEWITHACCESSOR_H_ */
