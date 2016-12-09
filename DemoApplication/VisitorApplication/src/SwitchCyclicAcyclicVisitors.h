/*
 * SwitchCyclicAcyclicVisitors.h
 *
 *  Created on: 05.12.2016
 *      Author: Gerd
 */

#ifndef SWITCHCYCLICACYCLICVISITORS_H_
#define SWITCHCYCLICACYCLICVISITORS_H_

#include "SwitchCyclicAcyclicVisitables.h"
#include "NonVisitable.h"
#include "SwitchCyclicAcyclicRepository.h"

namespace CyclicAcyclicRepository{

class DemoVisitor : public Repository::visits<E1, E2, NonVisitable>{
public:
	std::string toString() const override { return "DemoVisitor"; }
	void visit(E1& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
	}
	void visit(NonVisitable& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
	}
//	void visit(E2& v) {
//		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
//	}

};

class DemoVisitor13 : public Repository::visits<E1, E3, NonVisitable>{
public:
	void visit(E1& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
	}
	void visit(E3& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
	}
	void visit(NonVisitable& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
	}
	std::string toString() const override { return "DemoVisitor13"; }

};

class DemoVisitor23 : public Repository::visits<E1, E2, E3, NonVisitable>{
public:
	void visit(E1& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
	}
	void visit(E2& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
	}
	void visit(E3& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
	}
	void visit(NonVisitable& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
	}
	std::string toString() const override { return "DemoVisitor23"; }

};

} // end namespace

#endif /* SWITCHCYCLICACYCLICVISITORS_H_ */
