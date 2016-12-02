/*
 * ElementVisitor.h
 *
 *  Created on: 22.05.2016
 *      Author: Gerd
 */

#ifndef ELEMENTVISITOR_H_
#define ELEMENTVISITOR_H_

/**
 * Interface ElementVisitor Visitor::visit(ConcreteVisitable&)
 * das der ConcreteVisitor implementieren muss.
 *
 * Accessor kann eine protected Schnittstelle
 * für den Zugriff auf die privaten Elemente des ConcreteVisitable
 * zur Verfügung stellen, die der ConcreteVisitor nutzen kann
 * Das template wird in den ConcreteVisitable Klassen
 * wie folgt genutzt:
 * using Visitor = ElementVisitor<ConcreteVisitable>
 * Die verschiedenen Visitors implementieren das Interface:
 * class ConcreteVisitor : public ConcreteVisitable::Visitor { ...};
 */
// für experimente
//#define VIRTUAL virtual
#define VIRTUAL

template<class VisitableImpl>
class ElementVisitor : protected VIRTUAL VisitableImpl::Accessor
{
public:
	virtual void visit(typename VisitableImpl::ConcreteVisitable& visitable) = 0;
};

#endif /* ELEMENTVISITOR_H_ */
