/*
 * ConfigureDemoVisitor.h
 *
 *  Created on: 29.05.2016
 *      Author: Gerd
 */

#ifndef CONFIGUREDEMOVISITOR_H_
#define CONFIGUREDEMOVISITOR_H_

#include "Element_1.h"
#include "Element_2.h"

#include "NonVisitable.h"
#include "NonVisitableWithAccessor.h"
#include <include/TypeFunctions.h>
#include <include/VisitableAdapterAcyclic.h>
#include <iostream>

namespace DemoAdapterAcyclic{

class ConfigureDemoVisitor : public Visitor,
	public implementsVisitor<NonVisitable>, // AlternativesInterface für getVisitor
	public implementsVisitor<NonVisitableWithAccessor>,
	public implementsVisitor<Element_1>,
	public implementsVisitor<Element_2>
{
public:
	virtual void visit(NonVisitable& nv)
	{
		std::cout << "-> " << toString() << " visits " << nv.toString() << std::endl;
	}
	virtual void visit(Element_1& visited)
	{
		std::cout << "-> " << toString() << " visits " << visited.toString() << std::endl;
	}
	virtual void visit(Element_2& visited)
	{
		std::cout << "-> " << toString() << " visits " << visited.toString() << std::endl;
	}
	virtual void visit(NonVisitableWithAccessor& visited)
	{
		getVisitor<NonVisitableWithAccessor>* This = this;

		std::cout << "-> " << toString() << " visits " << visited.toString() << std::endl;
		std::cout << "Data: " << This->getData(visited) << std::endl;
		This->setData(visited, "DemoConfiguration");
		std::cout << "Data: " << This->getData(visited) << std::endl;
	}

	virtual std::string toString() const
	{
		return "ConfigureDemoVisitor";
	}
};

} // end namespace DemoAdapter

#endif /* CONFIGUREDEMOVISITOR_H_ */
