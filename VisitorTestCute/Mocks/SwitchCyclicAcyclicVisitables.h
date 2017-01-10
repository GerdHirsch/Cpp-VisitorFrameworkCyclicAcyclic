/*
 * SwitchCyclicAcyclicVisitables.h
 *
 *  Created on: 05.12.2016
 *      Author: Gerd
 */

#ifndef SWITCHCYCLICACYCLICVISITABLES_H_
#define SWITCHCYCLICACYCLICVISITABLES_H_
#include "SwitchCyclicAcyclicRepository.h"

namespace CyclicAcyclicRepository{

class E1 : public Repository::VisitableImpl<E1>
{
public:
//	std::string toString() const { return "E1"; } // defaut: typeid(*this).name()
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





#endif /* SWITCHCYCLICACYCLICVISITABLES_H_ */
