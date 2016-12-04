# Cpp-VisitorTemplateCyclicAcyclic
Prototype for Visitor to switch betwenn Cyclic/Acyclic  

between different LoggingPolicies for Acyclic Visiors

and Adapter with different StoragePolicies (ByReference, ByWeakPointer, BySharedPointer as Defaults)

switch betwenn #define ACYCLIC and not defined in Header SwitchCyclicAcyclic.h in the VisitorApplication
##hooks
Application spezific template spezialization is used to realize spezific Logging
for Elements and Adapters see:MyVisitableImplAcyclic.h

