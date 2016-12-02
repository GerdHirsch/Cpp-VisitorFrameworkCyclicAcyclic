/*
 * Element_2.h
 *
 *  Created on: 12.11.2016
 *      Author: Gerd
 */

#ifndef ELEMENT_2_H_
#define ELEMENT_2_H_

#include "MyVisitableCyclicAcyclic.h"

//vor C++11 via typedef in Template
class Element_2 : public Repository::Repository<Element_2>::VisitableImpl{
public:

	std::string toString() const override; //{ return "Element_2";}
};

#endif /* ELEMENT_2_H_ */
