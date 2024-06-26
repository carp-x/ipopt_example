// Copyright (C) 2004, 2009 International Business Machines and others.
// All Rights Reserved.
// This code is published under the Eclipse Public License.
//
// Authors:  Carl Laird, Andreas Waechter     IBM    2004-11-05

#include "IpIpoptApplication.hpp"
#include "IpSolveStatistics.hpp"
#include "MyNLP.hpp"

#include <iostream>

using namespace Ipopt;

int main(
   int,
   char**
)
{
   // Create an instance of your nlp...
   SmartPtr<TNLP> mynlp = new MyNLP();

   // Create an instance of the IpoptApplication
   //
   // We are using the factory, since this allows us to compile this
   // example with an Ipopt Windows DLL
   SmartPtr<IpoptApplication> app = new IpoptApplication();

   // Initialize the IpoptApplication and process the options

   std::cout << "????????" << std::endl;

   ApplicationReturnStatus status;
   status = app->Initialize();
   if( status != Solve_Succeeded )
   {
      std::cout << std::endl << std::endl << "*** Error during initialization!" << std::endl;
      return (int) status;
   }

   status = app->OptimizeTNLP(mynlp);

   if( status == Solve_Succeeded )
   {
      // Retrieve some statistics about the solve
      Index iter_count = app->Statistics()->IterationCount();
      std::cout << std::endl << std::endl << "*** The problem solved in " << iter_count << " iterations!" << std::endl;

      Number final_obj = app->Statistics()->FinalObjective();
      std::cout << std::endl << std::endl << "*** The final value of the objective function is " << final_obj << '.'
                << std::endl;
   }

   return (int) status;
}
