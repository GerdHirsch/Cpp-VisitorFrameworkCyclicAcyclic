/*
 * DemoVisitorCyclic.cpp
 *
 *  Created on: 27.11.2016
 *      Author: Gerd
 */

#include "DemoRunVisitor.h"
#include "Element_1.h"
#include "Element_2.h"
#include "Element_3.h"

#include <include/VisitorCyclic.h>

#include <iostream>

using VisitorBase = VisitorCyclic::visitsDefault<Element_1, Element_2, Element_3>;
//using VisitorBase = VisitorCyclic::visitsAbstract<Element_1, Element_2, Element_3>;

template<class Adaptee>
using MyAdapter = VisitorCyclic::VisitableAdapter<Adaptee, StorageByReference<Adaptee>, VisitorBase>;

class MyVisitor : public VisitorBase {
public:
	void visit(Element_1& v) override {
		std::cout << "MyVisitor::visit(" << v.toString() << "& v)" << std::endl;
	}
//	void visit(Element_2& v) override {
//		std::cout << "MyVisitor::visit(" << v.toString() << "& v)" << std::endl;
//	}
//	void visit(Element_3& v) override {
//		std::cout << "MyVisitor::visit(" << v.toString() << "& v)" << std::endl;
//	}


	std::string toString() const override{ return "MyVisitor"; }
};

void demoVisitorCyclic(){
	using namespace std;
	cout << "=========== demoVisitorCyclic() ===========" << endl;

	MyVisitor v;
	Element_1 e1;
	Element_2 e2;
	MyAdapter<Element_1> adapterE1(e1);
	MyAdapter<Element_2> adapterE2(e2);

	adapterE1.accept(v);
	adapterE2.accept(v);
}
