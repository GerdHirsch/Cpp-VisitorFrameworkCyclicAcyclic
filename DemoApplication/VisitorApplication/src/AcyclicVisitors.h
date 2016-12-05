/*
 * AcyclicVisitors.h
 *
 *  Created on: 05.12.2016
 *      Author: Gerd
 */

#ifndef ACYCLICVISITORS_H_
#define ACYCLICVISITORS_H_


#include "AcyclicVisitables.h"
#include "NonVisitableWithAccessor.h"
#include "AcyclicRepository.h"


namespace AcyclicRepository{

class DemoVisitor13 : public Repository::Visitor,
	public Repository::implementsVisitor<E1>,
	public Repository::implementsVisitor<E3>
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

class DemoVisitor23 : public Repository::Visitor,
	public Repository::implementsVisitor<E2>,
	public Repository::implementsVisitor<E3>,
	public Repository::implementsVisitor<NonVisitableWithAccessor>
{
public:
	void visit(E2& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
	}
	void visit(E3& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
	}
	void visit(NonVisitableWithAccessor& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
		std::cout << this->getData(v) << std::endl;
		this->setData(v, "DemoVisitor23::Data");
		std::cout << this->getData(v) << std::endl;
	}
	std::string toString() const override { return "DemoVisitor23"; }

};


} // end namespace




#endif /* ACYCLICVISITORS_H_ */
