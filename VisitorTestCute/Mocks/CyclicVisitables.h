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

//TODO introduce Base as parameter
//class E1 : public Repository::VisitableImpl<E1, Base>
class E1 : public Repository::VisitableImpl<E1>
{
public:
	std::string toString() const { return "E1"; }
	bool visited;
	bool wasVisited() const { return visited; }
	void defaultVisited(){
		visited = true;
	}
};
class E2 : public Repository::VisitableImpl<E2>
{
public:
	std::string toString() const { return "E2"; }
	bool visited;
	bool wasVisited() const { return visited; }
	void defaultVisited(){
		visited = true;
	}

};
class E3 : public Repository::VisitableImpl<E3>
{
public:
	std::string toString() const { return "E3"; }
	bool visited;
	bool wasVisited() const { return visited; }
	void defaultVisited(){
		visited = true;
	}

};

}

#endif /* CYCLICVISITABLES_H_ */
