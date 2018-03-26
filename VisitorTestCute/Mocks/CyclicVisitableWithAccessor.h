/*
 * NonVisitableWithAccessor.h
 *
 *  Created on: 30.05.2016
 *      Author: Gerd
 */

#ifndef SRC_CYCLICVISITABLEWITHACCESSOR_H_
#define SRC_CYCLICVISITABLEWITHACCESSOR_H_

#include <string>
#include <iostream>


#include "CyclicRepository.h"

namespace CyclicRepository{

class VisitableWithAccessor : public AccessorRepository::VisitableImpl<VisitableWithAccessor>{
public:
	using this_type = VisitableWithAccessor;

	VisitableWithAccessor():data(false){
		std::cout << "VisitableWithAccessor::VisitableWithAccessor() data: " << data << std::endl;
	}
	~VisitableWithAccessor(){
		std::cout << "VisitableWithAccessor::~VisitableWithAccessor() data: " << data << std::endl;
	}
	std::string toString_() const {
		std::string retVal("VisitableWithAccessor ");
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

class VisitableWithAccessor2 : public AccessorRepository::VisitableImpl<VisitableWithAccessor2>{
public:
	using this_type = VisitableWithAccessor2;

	VisitableWithAccessor2():data(false){
		std::cout << "VisitableWithAccessor2::VisitableWithAccessor2() data: " << data << std::endl;
	}
	~VisitableWithAccessor2(){
		std::cout << "VisitableWithAccessor2::~VisitableWithAccessor2() data: " << data << std::endl;
	}
	std::string toString_() const {
		std::string retVal("VisitableWithAccessor2 ");
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

}//end namespace

#endif /* SRC_CYCLICVISITABLEWITHACCESSOR_H_ */
