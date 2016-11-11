/*
 * VisitorsAcyclicBase.h
 *
 *  Created on: 11.11.2016
 *      Author: Gerd
 */

#ifndef MYVISITORACYCLICBASE_H_
#define MYVISITORACYCLICBASE_H_

#include "MyElementType.h"
#include <include/VisitorAcyclic.h>

namespace MyRepositoryAcyclic{

struct VisitorAcyclicBase : public VisitorAcyclic::Visitor,
	public Element_1::Visitor,
	public Element_2::Visitor
{ };

using MyVisitorBase = VisitorAcyclicBase;
}

#endif /* MYVISITORACYCLICBASE_H_ */
