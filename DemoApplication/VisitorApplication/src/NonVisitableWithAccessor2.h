/*
 * NonVisitableWithAccessor.h
 *
 *  Created on: 30.05.2016
 *      Author: Gerd
 */

#ifndef SRC_NONVISITABLEWITHACCESSOR2_H_
#define SRC_NONVISITABLEWITHACCESSOR2_H_

#include <string>
#include <iostream>

class NonVisitableWithAccessor2{
public:
	using this_type = NonVisitableWithAccessor2;

	NonVisitableWithAccessor2():data("default"){
		std::cout << "NonVisitableWithAccessor2::NonVisitableWithAccessor2() data: " << data << std::endl;
	}
	~NonVisitableWithAccessor2(){
		std::cout << "NonVisitableWithAccessor2::~NonVisitableWithAccessor2() data: " << data << std::endl;
	}
	std::string toString() const {
		std::string retVal("NonVisitableWithAccessor2 ");
		retVal += data;
		return retVal;
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

#endif /* SRC_NONVISITABLEWITHACCESSOR2_H_ */
