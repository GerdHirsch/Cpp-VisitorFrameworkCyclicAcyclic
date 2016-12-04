/*
 * DemoSwitchCyclicAcyclic.h
 *
 *  Created on: 04.12.2016
 *      Author: Gerd
 */

#ifndef DEMOSWITCHCYCLICACYCLIC_H_
#define DEMOSWITCHCYCLICACYCLIC_H_


#include "MyTypeList.h"

#include "NonVisitable.h"

#include <iostream>
#include <Visitor/Cyclic/Visitor.h>
#include <Visitor/Acyclic/Repository.h>
#include <Visitor/DefaultLoggingPolicy.h>

namespace VF = VisitorFramework;
using Repository = VF::Acyclic::Repository
//using Repository = VF::Cyclic::Repository
		<
		VisitorFramework::AdapterLoggingPolicy,
		VisitorFramework::DemoLoggingPolicy,
		BaseKind::Default,
		typelist
		>;
#endif /* DEMOSWITCHCYCLICACYCLIC_H_ */
