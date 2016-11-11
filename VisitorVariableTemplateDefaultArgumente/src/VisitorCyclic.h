/*
 * VisitorCyclic.h
 *
 *  Created on: 10.11.2016
 *      Author: Gerd
 */

#ifndef VISITORCYCLIC_H_
#define VISITORCYCLIC_H_

#include <iostream>

namespace VisitorCyclic {

template<class VisitorBase>
class Visitable
{
public:
    virtual ~Visitable(){};
	virtual void accept(VisitorBase& visitor) = 0;
};

template<class Derived, class VisitorBase>
struct VisitableImpl : Visitable<VisitorBase> {
	void accept(VisitorBase& mv){
		std::cout << This()->toString() <<"::accept: " << mv.toString() << std::endl;
		mv.visit(*This());
	}
	Derived* This(){ return static_cast<Derived*>(this);}
};

}




#endif /* VISITORCYCLIC_H_ */
