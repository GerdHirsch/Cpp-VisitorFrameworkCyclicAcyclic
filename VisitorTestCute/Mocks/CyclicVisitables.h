/*
 * CyclicElements.h
 *
 *  Created on: 05.12.2016
 *      Author: Gerd
 */

#ifndef CYCLICVISITABLES_H_
#define CYCLICVISITABLES_H_

#include "CyclicRepository.h"

namespace CyclicRepository{
class Base : public Repository::VisitableImpl<Base>
{
public:
	std::string toString() const { return "Base"; }
};

class E1 : public Repository::VisitableImpl<E1>
{
public:
	std::string toString() const { return "E1"; }
	bool wasDefaultVisited = false;
	bool wasVisitorVisited = false;

	virtual void defaultVisited(){
		wasDefaultVisited = true;
	}
	virtual void visitorVisited(){
		wasVisitorVisited = true;
	}
};
// E2 : VisitableImpl<E2, E1> : E1 : VisitabelImpl<E1>
class E2 : public Repository::VisitableImpl<E2, E1>
{
public:
	std::string toString() const { return "E2"; }
};
class E3 : public Repository::VisitableImpl<E3>
{
public:
	std::string toString() const { return "E3"; }
	bool wasDefaultVisited = false;
	bool wasVisitorVisited = false;

	void defaultVisited(){
		wasDefaultVisited = true;
	}
	void visitorVisited(){
		wasVisitorVisited = true;
	}
};
class E4 : public Repository::VisitableImpl<E4, E3>
{
public:
	std::string toString() const { return "E4"; }
};

}

#endif /* CYCLICVISITABLES_H_ */
