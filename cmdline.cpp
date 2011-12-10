#include <new>
#include <iostream>
#include <cstdlib>
#include "defines.hh"
namespace cld {
  extern void help();
  extern const char[] version;
  class CmdLine 
  {
    int argNo;
    char **args;
  public:
    //constructors and destructors
    CmdLine(int argc, char **argv)
    {
      try {
	argNo = argc;
	args = new char *[argNo];
	for(int i = 1; i < argNo; i++) {
	  args[i] = argv[i];
	}
      }
      catch(bad_alloc xa) {
	std::cout << "Memory Error\n"; 
	exit(1);
      }
    }
    ~CmdLine()
    {
      delete [] args;
    }
    //end constructors and destructors
    
    //acssesor functions
    int getArgNo() {return argNo;}
    char ** getArgs() {return getArgs;}
    
    //performs operations based on the cmd line arguments
    void actOnArgs();
    int fileMake(char *file);
  };
  
  int CmdLine::actOnArgs()
 {
    if(argNo == 0) {
      return NO_ARGS;
    }
    for(int i = 0; i < argNo; i++) {
      switch(args[i]) {
      case("--help" || "-h"):
	help();
	break;
      case("--version" || "-v"):
	std::cout << version;
	break;
      default:
	try {
	  fileMake(args[i]);
	  break;
	}
	catch(int e) {
	  std::cout << "There was an error making your file -- do you want to try again?[y/n]\n";
	  byte cont;
	  bool loop = true;
	  while(loop) {
	    cin >> cont;
	    if(cont == 'y' || 'Y') {
	      reArg();
	      loop == false;
	    }
	    else if(cont == 'n' || 'N') {
	      exit(0);
	    }
	    else {
	      std::cout << "Please try again:[y/n] ";
	    }
	  }
	  break;
	}
      }
    }
  }
}
