/*
 * VisitableAdapterStoragePolicy.h
 *
 *  Created on: 28.05.2016
 *      Author: Gerd
 */

#ifndef VISITABLEADAPTERACYCLIC_H_
#define VISITABLEADAPTERACYCLIC_H_

#include "Visitor.h"
#include "../StoragePolicies.h"
#include "../DefaultPolicy.h"
#include "../TypeFunctions.h"
#include "../has_method_toString.h"

namespace VisitorFramework{
namespace Acyclic{

template<
	class Adaptee,
	class StoragePolicy = StorageByReference<Adaptee>,
	class LoggingPolicy = VisitorFramework::StdOutLoggingPolicy
		>
struct VisitableAdapter :
		VisitableImpl<
				Adaptee, //ConcreteVisitable
				VisitableAdapter<Adaptee, StoragePolicy, LoggingPolicy>,//VisitableImplementation
				LoggingPolicy>,
		StoragePolicy
{
	//TODO merge Cyclci/Acyclic Implementation
	using ReferenceType = typename StoragePolicy::ReferenceType;
	using ReturnType = typename StoragePolicy::ReturnType;
	using ConstReturnType = typename StoragePolicy::ConstReturnType;

	using Visitor = getVisitor<Adaptee>;

//	VisitableAdapter(StorageType element): StoragePolicy(element){}
	VisitableAdapter(ReferenceType element): StoragePolicy(element){}

	ReturnType getVisitable() { return this->get(); }
	ConstReturnType getVisitable()const { return this->get(); }

	std::string toString() const {
		std::string message("AcyclicAdapter::");
		//TODO wo gehört die prüfung hin?
		auto visitable = this->getVisitable();
		if(visitable)
			message += VisitorFramework::toString(*this->getVisitable());
		else
			message += typeid(Adaptee).name();
		return message;
	}
};
}} // namespace VisitorAcyclic
#endif /* VISITABLEADAPTERACYCLIC_H_ */
