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
	using StorageType = typename StoragePolicy::StorageType;
	using ReturnType = typename StoragePolicy::ReturnType;
	using ConstReturnType = typename StoragePolicy::ConstReturnType;

	using Visitor = getVisitor<Adaptee>;

	VisitableAdapter(StorageType element): StoragePolicy(element){}

	ReturnType getVisitable() { return this->get(); }
	ConstReturnType getVisitable()const { return this->get(); }

	std::string toString() const {
		std::string message("AcyclicAdapter::");
//		message += this->getVisitable()->toString();
		message += VisitorFramework::toString(*this->getVisitable());
		return message;
	}
};
}} // namespace VisitorAcyclic
#endif /* VISITABLEADAPTERACYCLIC_H_ */
