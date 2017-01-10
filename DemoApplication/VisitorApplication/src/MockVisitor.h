/*
 * MockVisitor.h
 *
 *  Created on: 09.01.2017
 *      Author: Gerd
 */

#ifndef MOCKS_MOCKVISITOR_H_
#define MOCKS_MOCKVISITOR_H_

#include <Visitor/has_method_toString.h>
//#include "NonVisitable.h"
class NonVisitable;

namespace VisitorTestMock{

template<class Repository, class Visitable, class ...pack>
struct MockVisitor : public Repository:: template visits<Visitable, pack...>{
public:
	bool visitableVisited = false;
//	std::string toString() const override { return "MockVisitor"; }

	void visit(Visitable& v) {
		std::cout << this->toString() << "::visit("
				<< VisitorFramework::toString(v) << ")" << std::endl;
		visitableVisited = true;
	}
	void visit(NonVisitable& v) {
		std::cout << this->toString() << "::visit(" << VisitorFramework::toString(v) << ")" << std::endl;
	}
	std::string toString() const override{ return "MockVisitor";}
};

}

#endif /* MOCKS_MOCKVISITOR_H_ */
