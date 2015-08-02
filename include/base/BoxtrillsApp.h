#ifndef BOXTRILLSAPP_H
#define BOXTRILLSAPP_H

#include "MooseApp.h"

class BoxtrillsApp;

template<>
InputParameters validParams<BoxtrillsApp>();

class BoxtrillsApp : public MooseApp
{
public:
  BoxtrillsApp(const std::string & name, InputParameters parameters);
  virtual ~BoxtrillsApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* BOXTRILLSAPP_H */
