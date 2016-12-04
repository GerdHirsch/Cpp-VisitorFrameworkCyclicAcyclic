# Cpp-VisitorTemplateCyclicAcyclic

Prototype for Visitor to switch 

between Cyclic/Acyclic Visitors

between default and abstract implementation of Visitor::visit  

between different LoggingPolicies for Visiors (visit(..) and Visitables (accept(..)

and Adapter with different StoragePolicies (ByReference, ByWeakPointer, BySharedPointer as Defaults)

switch betwenn #define ACYCLIC and not defined in Header SwitchCyclicAcyclic.h in the VisitorApplication

##hooks
Application spezific template spezialization is used to realize spezific Logging
for Elements and Adapters see:MyVisitableImplAcyclic.h