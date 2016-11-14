/*
 * MyVisitableCyclicAcyclic.h
 *
 *  Created on: 12.11.2016
 *      Author: Gerd
 */

#ifndef MYVISITABLECYCLICACYCLIC_H_
#define MYVISITABLECYCLICACYCLIC_H_

#include "SwitchCyclicAcyclic.h"

#ifdef ACYCLIC
#include "MyVisitableImplAcyclic.h"
namespace Repository = MyRepositoryAcyclic;
#else
#include "MyVisitableImplCyclic.h"
namespace Repository = MyRepositoryCyclic;
#endif

#endif /* MYVISITABLECYCLICACYCLIC_H_ */
