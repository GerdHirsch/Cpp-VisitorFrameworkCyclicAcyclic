/*
 * VisitorsAcyclicBase.h
 *
 *  Created on: 11.11.2016
 *      Author: Gerd
 */

#ifndef MYVISITORACYCLICBASE_H_
#define MYVISITORACYCLICBASE_H_

#include "Element_1.h"
#include "Element_2.h"
#include "Element_3.h"
#include "NonVisitable.h"

#include <include/VisitorAcyclic.h>
#include <include/TypeFunctions.h>



namespace MyRepositoryAcyclic{

struct VisitorAcyclicBase : public VisitorAcyclic::Visitor,
	public implementsVisitor<Element_1>,
	public implementsVisitor<Element_2>,
	public implementsVisitor<NonVisitable>
{ };

using MyVisitorBase = VisitorAcyclicBase;
}

#endif /* MYVISITORACYCLICBASE_H_ */
