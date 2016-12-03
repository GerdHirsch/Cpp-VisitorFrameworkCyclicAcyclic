/*
 * DemoMyRepository.cpp
 *
 *  Created on: 03.12.2016
 *      Author: Gerd
 */

#include "Element_1.h"
#include "Element_2.h"
#include "Element_3.h"

#include <include/DefaultLoggingPolicy.h>

#include "VisitorCyclicRepository.h"

class A;
class B;
class C;

using typelist = VisitorCyclic::MakeTypelist<Element_1, Element_2, A, B, C>;

using Repo = VisitorCyclic::Repository
		<
			AdapterLoggingPolicy,
//			DemoLoggingPolicy,
			BaseKind::Default,
			typelist
		>;


//			Element_1, Element_2,
//			A, B>;

class B: public Repo::Visitable<B>{
public:
	std::string toString() const override { return "B"; }
};

class DemoVisitor : public Repo::VisitorBase{
public:
//	void visit(Element_1& ) override {}
	void visit(Element_2& v) {
		std::cout << toString() << "::visit(" << v.toString() << ")" << std::endl;
	}
	void visit(B& v)  {
		std::cout << toString() << "::visit(" << v.toString() << ")"  << std::endl;
	}
	std::string toString() const override { return "DemoVisitor"; }

};

template<class Adaptee>
using AdapterWeak = Repo::VisitableAdapter<Adaptee, StorageByWeakPointer<Adaptee>>;
template<class Adaptee>
using AdapterReference = Repo::VisitableAdapter<Adaptee, StorageByReference<Adaptee>>;

class A //: public Repo::Visitable<A>
{
public:
	std::string toString() const { return "A"; }
};
class C //: public Repo::Visitable<C>
{
public:
	std::string toString() const { return "C"; }
};

void demoMyRepository(){
	DemoVisitor myVisitor;
	Repo::VisitorBase & visitor = myVisitor;
	Element_1 e1;
	Element_2 e2;
	A a;
	AdapterReference<A> aA(a);
	B b;
	C c;
	Repo::AdapterByReference<C> aC(c);

	visitor.visit(e1);
	visitor.visit(e2);

	aA.accept(visitor);
	b.accept(visitor);
	aC.accept(visitor);
}
