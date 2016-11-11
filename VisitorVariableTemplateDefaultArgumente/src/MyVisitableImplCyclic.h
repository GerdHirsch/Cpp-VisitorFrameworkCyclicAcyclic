/*
 * MyVisitableImplCyclic.h
 *
 *  Created on: 11.11.2016
 *      Author: Gerd
 */

#ifndef MYVISITABLEIMPLCYCLIC_H_
#define MYVISITABLEIMPLCYCLIC_H_

#include <iostream>

#include "VisitorCyclic.h"
#include "MyVisitorCyclicBase.h"

class Element_1;
class Element_2;
class Element_3;

namespace MyRepositoryCyclic{
// ab C++11
template
	<
	class ConcreteVisitable,
	class VisitableImplementation = ConcreteVisitable
	>
using Visitable = VisitorCyclic::VisitableImpl<ConcreteVisitable, MyVisitorBase>;

// bis C++11
template<class ConcreteVisitable, class VisitableImplementation = ConcreteVisitable>
class Repository{
public:
	typedef VisitorCyclic::VisitableImpl<ConcreteVisitable, MyVisitorBase> Visitable;
};

}

#endif /* MYVISITABLEIMPLCYCLIC_H_ */
