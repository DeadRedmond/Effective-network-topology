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
  args_t(int, char*[]);
private:
  void usage();//повідомлення про програму
  void getlimit(char*);//зчитування параметру limit
};

#endif // ARGS_H
