/*
 * DerivedType.h
 *
 *  Created on: 10.11.2016
 *      Author: Gerd
 *      Erben die Eigenschaft "Visitable" zu sein entweder für
 *      Cyclic oder Acyclic Visitors
 */

#ifndef ELEMENT_3_H_
#define ELEMENT_3_H_

#include "MyVisitableCyclicAcyclic.h"

//vor C++11 via typedef in Template
//class Element_3 : public Repository::Repository<Element_3>::VisitableImpl{
class Element_3 : public Repository::VisitableImpl<Element_3>{
public:

	std::string toString() const override;// { return "Element_3";}
};

#endif /* ELEMENT_3_H_ */
