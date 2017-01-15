/*
 * VisitableAdapterStoragePolicy.h
 *
 *  Created on: 28.05.2016
 *      Author: Gerd
 */

#ifndef VISITABLEADAPTERACYCLIC_H_
#define VISITABLEADAPTERACYCLIC_H_

#include "Visitable.h"
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
				LoggingPolicy,
				Visitable,
				VisitableAdapter<Adaptee, StoragePolicy, LoggingPolicy>//VisitableImplementation
				>,
		StoragePolicy
{
	//TODO merge Cyclic/Acyclic Implementation
	using LValueReferenceType = typename StoragePolicy::LValueReferenceType;
	using RValueReferenceType = typename StoragePolicy::RValueReferenceType;

	using ReturnType = typename StoragePolicy::ReturnType;
	using ConstReturnType = typename StoragePolicy::ConstReturnType;

	using Visitor = getVisitor<Adaptee>;

	VisitableAdapter(LValueReferenceType element): StoragePolicy(element){}
	VisitableAdapter(RValueReferenceType element): StoragePolicy(std::forward<RValueReferenceType>(element)){}

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
