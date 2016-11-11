/*
 * MyVisitorBase.h
 *
 *  Created on: 11.11.2016
 *      Author: Gerd
 */

#ifndef MYVISITORCYCLICBASE_H_
#define MYVISITORCYCLICBASE_H_

#include <iostream>

class Element_1;
class Element_2;
class Element_3;

namespace MyRepositoryCyclic{

struct VisitorCyclicBase{
	virtual ~VisitorCyclicBase(){}
	virtual void visit(Element_1 &d) = 0;
	virtual void visit(Element_2 &d) = 0;
	virtual void visit(Element_3 &d){
		std::cout << this->toString() << "::visit(Element_3&) is not implemented" << std::endl;
	}
	virtual std::string toString() const = 0;
};

using MyVisitorBase = VisitorCyclicBase;
}

#endif /* MYVISITORCYCLICBASE_H_ */
