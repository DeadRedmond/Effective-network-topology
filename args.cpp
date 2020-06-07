#include "args.h"

args_t::args_t(){
  static const char* opt_s="i:o:l:h?";
  int opt=0;
  input_file="input.txt";
  output_file="out.txt";

  opt=getopt(__argc, __argv, opt_s);
  while(opt!=-1){
      switch (opt) {
        case 'i':
          input_file=optarg;
          break;

        case 'o':
          output_file=optarg;
          break;

        case 'l':
          limit=getsize(optarg);
          break;

        case 'h':
        case '?':
          usage();
          break;

        default: break;
        }
      opt=getopt(__argc, __argv, opt_s);
    }
}

void args_t::usage(){
  cout<<"effective_topology - creating efficient centralized network topologies"<<endl;
  exit (EXIT_SUCCESS);
}

int args_t::getsize (char *tmp){
  int x=atoi(tmp);
  if (x==0){
      cerr<<"Invalid parameter \"limit\""<<endl;
      exit (EXIT_FAILURE);
    }
  return (x+1);
}
