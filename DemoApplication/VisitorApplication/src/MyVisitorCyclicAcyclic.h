/*
 * MyVisitorCyclicAcyclic.h
 *
 *  Created on: 12.11.2016
 *      Author: Gerd
 */

#ifndef MYVISITORCYCLICACYCLIC_H_
#define MYVISITORCYCLICACYCLIC_H_

#include "SwitchCyclicAcyclic.h"

#ifdef ACYCLIC
// kann nur includiert werden wenn Elemente_n auch einen Membertype Visitor definieren
#include "MyVisitorAcyclicBase.h"
namespace Repository = MyRepositoryAcyclic;
#else
#include "MyVisitorCyclicBase.h"
namespace Repository = MyRepositoryCyclic;
#endif

#endif /* MYVISITORCYCLICACYCLIC_H_ */
