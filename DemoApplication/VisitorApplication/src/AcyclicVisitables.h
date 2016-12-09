/*
 * AcyclicVisitables.h
 *
 *  Created on: 05.12.2016
 *      Author: Gerd
 */

#ifndef ACYCLICVISITABLES_H_
#define ACYCLICVISITABLES_H_

#include "AcyclicRepository.h"

namespace AcyclicRepository{

class E1 : public Repository::VisitableImpl<E1>
{
public:
	std::string toString() const { return "E1"; }
};
class E2 : public Repository::VisitableImpl<E2>
{
public:
	std::string toString() const { return "E2"; }
};
class E3 : public Repository::VisitableImpl<E3>
{
public:
	std::string toString() const { return "E3"; }
};

}



#endif /* ACYCLICVISITABLES_H_ */