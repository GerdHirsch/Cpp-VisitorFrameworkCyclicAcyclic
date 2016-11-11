/*
 * DerivedType.h
 *
 *  Created on: 10.11.2016
 *      Author: Gerd
 *      Erben die Eigenschaft "Visitable" zu sein entweder für
 *      Cyclic oder Acyclic Visitors
 */

#ifndef MYELEMENTTYPE_H_
#define MYELEMENTTYPE_H_

#include "MyVisitableImplCyclic.h"
#include "MyVisitableImplAcyclic.h"

#ifdef ACYCLIC
namespace Repository = MyRepositoryAcyclic;
#else
namespace Repository = MyRepositoryCyclic;
#endif

//ab C++11 via using ...
class Element_1 : public Repository::Visitable<Element_1>{
public:

	std::string toString() const { return "Element_1";}
};

//vor C++11 via typedef in Template
class Element_2 : public Repository::Repository<Element_2>::Visitable{
public:

	std::string toString() const { return "Element_2";}
};

class Element_3 : public Repository::Repository<Element_3>::Visitable{
public:

	std::string toString() const { return "Element_3";}
};

#endif /* MYELEMENTTYPE_H_ */
