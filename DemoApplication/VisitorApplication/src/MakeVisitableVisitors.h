/*
 * MakeVisitableVisitors.h
 *
 *  Created on: 16.01.2017
 *      Author: Gerd
 */

#ifndef MAKEVISITABLEVISITORS_H_
#define MAKEVISITABLEVISITORS_H_

#include "MakeVisitables.h"
#include "NonVisitable.h"
#include "NonVisitableWithAccessor.h"
#include "MakeVisitableRepository.h"

namespace MakeVisitable{

class DemoVisitor : public Repository::visits<typelist>{
//class DemoVisitor : public Repository::visits<E1, E2, NonVisitable>{
public:
	std::string toString() const override { return "DemoVisitor"; }

	void visit(NonVisitable& v) {
		std::cout << toString() << "::visit(" << VisitorFramework::toString(v) << ")" << std::endl;
	}
	void visit(int& v) {
		std::cout << toString() << "::visit(" << VisitorFramework::toString(v) << ")" << std::endl;
	}
	void visit(double& v) {
		std::cout << toString() << "::visit(" << VisitorFramework::toString(v) << ")" << std::endl;
	}

};

}

#endif /* MAKEVISITABLEVISITORS_H_ */
