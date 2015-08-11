#include "BoxtrillsApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<BoxtrillsApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  return params;
}

BoxtrillsApp::BoxtrillsApp(InputParameters parameters) :
    MooseApp(parameters)
{

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  BoxtrillsApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  BoxtrillsApp::associateSyntax(_syntax, _action_factory);
}

BoxtrillsApp::~BoxtrillsApp()
{
}

// External entry point for dynamic application loading
extern "C" void BoxtrillsApp__registerApps() { BoxtrillsApp::registerApps(); }
void
BoxtrillsApp::registerApps()
{
  registerApp(BoxtrillsApp);
}

// External entry point for dynamic object registration
extern "C" void BoxtrillsApp__registerObjects(Factory & factory) { BoxtrillsApp::registerObjects(factory); }
void
BoxtrillsApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void BoxtrillsApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { BoxtrillsApp::associateSyntax(syntax, action_factory); }
void
BoxtrillsApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
