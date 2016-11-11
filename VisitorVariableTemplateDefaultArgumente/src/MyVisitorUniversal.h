/*
 * VisitorsUniversal.h
 *
 *  Created on: 11.11.2016
 *      Author: Gerd
 */

#ifndef MYVISITORUNIVERSAL_H_
#define MYVISITORUNIVERSAL_H_

#include "MyVisitorCyclicBase.h"

#ifdef ACYCLIC
// kann nur includiert werden wenn Elemente_n auch einen Membertype Visitor definieren
#include "MyVisitorAcyclicBase.h"
namespace Repository = MyRepositoryAcyclic;
#else
#include "MyVisitorCyclicBase.h"
namespace Repository = MyRepositoryCyclic;
#endif

#include "MyElementType.h"

struct VisitorUniversal : public Repository::MyVisitorBase {

	void visit(Element_1 &d) override {
		std::cout << "VisitorUniversal::visit: " << d.toString() << std::endl;
	}
	void visit(Element_2 &d) override {
		std::cout << "VisitorUniversal::visit: " << d.toString() << std::endl;
	}
	std::string toString() const override {
		return "VisitorUniversal";
	}
};



#endif /* MYVISITORUNIVERSAL_H_ */
