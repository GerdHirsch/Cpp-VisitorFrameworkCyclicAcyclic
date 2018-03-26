/*
 * AcyclicVisitors.h
 *
 *  Created on: 05.12.2016
 *      Author: Gerd
 */

#ifndef ACYCLICVISITORS_H_
#define ACYCLICVISITORS_H_

#include "AcyclicRepository.h"

#include "AcyclicVisitables.h"
#include "NonVisitableWithAccessor.h"


namespace AcyclicRepository{

class DemoVisitor13 : public Repository::visits<E1, E3>
{
public:
	void visit(E1& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
	}
	void visit(E3& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
	}
	std::string toString() const override { return "DemoVisitor13"; }

};

class DemoVisitor23 : public Repository::visits<E2, E3, NonVisitableWithAccessor, NonVisitableWithAccessor2>
{
public:
	void visit(E2& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
	}
	void visit(E3& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
	}
	void visit(NonVisitableWithAccessor& v) {
		using Accessor = NonVisitableWithAccessor::Accessor;
		std::cout << toString() << "::visit(" << VisitorFramework::toString(v) << ")" << std::endl;
		std::cout << this->Accessor::getData(v) << std::endl;
		Accessor::setData(v, "DemoVisitor23::Data");
//		this->Accessor::setData(v, "DemoVisitor23::Data");
		std::cout << this->Accessor::getData(v) << std::endl;
	}
	void visit(NonVisitableWithAccessor2& v) {
		using Accessor = NonVisitableWithAccessor2::Accessor;
		std::cout << toString() << "::visit(" << VisitorFramework::toString(v) << ")" << std::endl;
		std::cout << this->Accessor::getData(v) << std::endl;
		Accessor::setData(v, "DemoVisitor23::Data");
//		this->Accessor::setData(v, "DemoVisitor23::Data");
		std::cout << this->Accessor::getData(v) << std::endl;
	}
	std::string toString() const override { return "DemoVisitor23"; }

};


} // end namespace




#endif /* ACYCLICVISITORS_H_ */
