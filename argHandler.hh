/*
This deals with the command line arguments
Part of the ConLangDiction project
Date: 8/12/11
By: Joe Clarke
V 0.0
*/

namespace cld {
  extern class CmdLine;
  void readArgs(int argc, char **argv);


  void readArgs(int argc, char **argv)
  {
    CmdLine arg(argc, argv);
    arg.actOnArgs();
    return;
  }


}
