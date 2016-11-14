/*
 * VisitorsUniversal.h
 *
 *  Created on: 11.11.2016
 *      Author: Gerd
 */

#ifndef MYVISITORUNIVERSAL1_H_
#define MYVISITORUNIVERSAL1_H_

#include "NonVisitable.h"
#include "NonVisitableWithAccessor.h"
#include "MyVisitorCyclicAcyclic.h"

namespace DemoSwitchCyclicAcyclic{

struct VisitorUniversal1 : public Repository::MyVisitorBase {

	void visit(Element_1 &d) override {
		std::cout << toString() << "::visit: " << d.toString() << std::endl;
	}
	void visit(Element_2 &d) override {
		std::cout << toString() << "::visit: " << d.toString() << std::endl;
	}
	void visit(NonVisitable &d) override {
		std::cout << toString() << "::visit: " << d.toString() << std::endl;
	}
	void visit(NonVisitableWithAccessor &d) override {
		std::cout << toString() << "::visit: " << d.toString() << std::endl;
	}
	std::string toString() const override {
		return "VisitorUniversal1";
	}
};

}

#endif /* MYVISITORUNIVERSAL1_H_ */
