#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "../include/VisitorTest.h"
#include "../include/VisitorAbstractTest.h"
#include "../include/DefaultPolicyTest.h"
#include "../include/AdapterTest.h"
#include "../include/VisitableFactoryTest.h"

void thisIsATest() {
	ASSERTM("start writing tests", false);	
}

void runAllTests(int argc, char const *argv[]){
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  listener(xmlfile.out);
	cute::makeRunner(listener,argc,argv)(VisitorTest::make_suite(), "Visitor::visit");
	cute::makeRunner(listener,argc,argv)(VisitorAbstractTest::make_suite(), "Visitor abstract");
	cute::makeRunner(listener,argc,argv)(DefaultPolicyTest::make_suite(), "Default Policy init");
	cute::makeRunner(listener,argc,argv)(AdapterTest::make_suite(), "Adapter NonVisitable");
	cute::makeRunner(listener,argc,argv)(VisitableFactoryTest::make_suite(), "Visitable Factory");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



