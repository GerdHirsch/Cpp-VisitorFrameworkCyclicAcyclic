/*
 * Element1.h
 *
 *  Created on: 12.11.2016
 *      Author: Gerd
 */

#ifndef ELEMENT_1_H_
#define ELEMENT_1_H_

#include "DemoSwitchCyclicAcyclic.h"
//ab C++11 via using ...
class Element_1 : public Repository::VisitableImpl<Element_1>
{
public:

	std::string toString() const override; //{ return "Element_1";}
};



#endif /* ELEMENT_1_H_ */
