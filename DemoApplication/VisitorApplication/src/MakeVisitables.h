/*
 * MakeVisitables.h
 *
 *  Created on: 16.01.2017
 *      Author: Gerd
 */

#ifndef MAKEVISITABLES_H_
#define MAKEVISITABLES_H_


namespace MakeVisitable{

class E1
{
public:
//	std::string toString() const { return "E1"; } // defaut: typeid(*this).name()
};
class E2
{
public:
	std::string toString() const { return "E2"; }
};
class E3
{
public:
	std::string toString() const { return "E3"; }
};

}

#endif /* MAKEVISITABLES_H_ */
