/*
 * MyVisitorBase.h
 *
 *  Created on: 11.11.2016
 *      Author: Gerd
 */

#ifndef MYVISITORCYCLICBASE_H_
#define MYVISITORCYCLICBASE_H_

#include <iostream>
#include <include/VisitorCyclic.h>

#include "NonVisitable.h"

class Element_1;
class Element_2;
class Element_3;
class NonVisitableWithAccessor;

namespace MyRepositoryCyclic{

struct VisitorCyclicBase;

using Visitable = VisitorCyclic::Visitable<VisitorCyclicBase>;

struct VisitorCyclicBase{
	virtual ~VisitorCyclicBase(){}
	virtual void visit(Element_1 &e) = 0;
	virtual void visit(Element_2 &e) = 0;
//	virtual void visit(Element_3 &e){
//		//cannot dynamic_cast '& e' source is a pointer to incomplete type
//		Visitable* vp = dynamic_cast<Visitable*>(&e);
//		if(vp)
//			this->visit(*vp);
//	}
	virtual void visit(NonVisitable &d) = 0;
	virtual void visit(Visitable &d){
		std::cout << this->toString() << "::visit(" << d.toString() <<"&) is not implemented" << std::endl;
	}
	virtual void visit(NonVisitableWithAccessor&d){
		std::cout << this->toString() << "::visit(NonVisitableWithAccessor&) is not implemented" << std::endl;
	}
	virtual std::string toString() const = 0;
};

using MyVisitorBase = VisitorCyclicBase;

}

#endif /* MYVISITORCYCLICBASE_H_ */
