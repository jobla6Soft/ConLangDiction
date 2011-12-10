/*
This f/ile deals with the turning on of ConLangDiction ,reading commands from command line etc
Date: 8/12/11
By: Joe Clarke
V0.0
*/

#include <iostream>
#include "argHandle.hh"
#include "details.hh"

int main(int argc, char *argv[])
{
  cld::readArgs(argc, argv);
  return 0;
}
