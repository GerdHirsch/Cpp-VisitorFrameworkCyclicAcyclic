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
#include "NonVisitableWithAccessor.h"

#include <Visitor/Acyclic/Visitor.h>
#include <Visitor/Acyclic/TypeFunctions.h>



namespace MyRepositoryAcyclic{
using MyVisitorBase = Acyclic::VisitorBase
		<
		Element_1,
		Element_2,
		NonVisitable,
		NonVisitableWithAccessor
		>;
}

#endif /* MYVISITORACYCLICBASE_H_ */
