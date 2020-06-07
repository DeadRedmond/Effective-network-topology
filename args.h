#ifndef ARGS_H
#define ARGS_H
#include <iostream>
#include <sstream>
#include <string>
#include <getopt.h>

using namespace std;

class args_t
{
public:
  //параметри
  const char *input_file; //-i
  const char *output_file;//-o
  int limit;              //-l
  args_t();
private:
  void usage();
  int getsize(char*);
};

#endif // ARGS_H