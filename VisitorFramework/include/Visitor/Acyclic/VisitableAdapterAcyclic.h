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

namespace VisitorFramework{

namespace Acyclic{

template<
	class Adaptee,
	class StoragePolicy = StorageByReference<Adaptee>,
	class LoggingPolicy = VisitorFramework::DemoLoggingPolicy
		>
class VisitableAdapter :
		public VisitableImpl<
				Adaptee, //ConcreteVisitable
				VisitableAdapter<Adaptee, StoragePolicy, LoggingPolicy>,//VisitableImplementation
				LoggingPolicy>,
		public StoragePolicy
{
public:
	using StorageType = typename StoragePolicy::StorageType;
	using ReturnType = typename StoragePolicy::ReturnType;
	using ConstReturnType = typename StoragePolicy::ConstReturnType;

	using Visitor = getVisitor<Adaptee>;

	VisitableAdapter(StorageType element): StoragePolicy(element){}

	ReturnType getVisitable() { return this->get(); }
	ConstReturnType getVisitable()const { return this->get(); }

	std::string toString() const {
		std::string message("AcyclicAdapter::");
		message += this->getVisitable()->toString();
		return message;
	}
};
}} // namespace VisitorAcyclic
#endif /* VISITABLEADAPTERACYCLIC_H_ */
