/*
 * DemoAdapter.h
 *
 *  Created on: 12.11.2016
 *      Author: Gerd
 */

#ifndef DEMOADAPTERACYCLIC_H_
#define DEMOADAPTERACYCLIC_H_

#include <vector>
#include <memory>

#include <include/VisitorAcyclic.h>
#include <include/VisitableAdapterAcyclic.h>
#include <include/StoragePolicies.h>

namespace DemoAdapterAcyclic{
using Visitable = VisitorAcyclic::Visitable;
using Visitor = VisitorAcyclic::Visitor;

using SharedPointer = std::shared_ptr<Visitable>;
using Visitables = std::vector<SharedPointer>;

} // end namespace DemoAdapter



#endif /* DEMOADAPTERACYCLIC_H_ */
