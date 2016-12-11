# Cpp-VisitorTemplateCyclicAcyclic

A Framework for the Visitor Pattern to switch 

between Cyclic/Acyclic Visitors

between default and abstract implementation of Visitor::visit  

between different LoggingPolicies for Visior::visit(..) and Visitables::accept(..)

and Adapter with different StoragePolicies (ByReference, ByWeakPointer, BySharedPointer as Defaults)

switch betwenn cyclic and acyclic in Header SwitchCyclicAcyclicRepository.h by exchanging 
namespace CAR = VisitorFramework::Cyclic with = VisitorFramework::Acyclic

##hooks
Application spezific template spezialization is used to realize spezific Logging
for Elements and Adapters