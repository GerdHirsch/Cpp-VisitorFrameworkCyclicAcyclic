/*
 * MyTypeList.h
 *
 *  Created on: 04.12.2016
 *      Author: Gerd
 */

#ifndef MYTYPELIST_H_
#define MYTYPELIST_H_

#include <Visitor/MakeTypelist.h>

class Element_1;
class Element_2;
class NonVisitable;
class NonVisitableWithAccessor;

using typelist = VisitorFramework::MakeTypelist
		<
		Element_1,
		Element_2,
		NonVisitable,
		NonVisitableWithAccessor
		>;

#endif /* MYTYPELIST_H_ */
