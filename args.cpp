#include "args.h"

args_t::args_t(){
  static const char* opt_s="i:o:l:h?";//шаблон параметрів
  //параметри за замовчуванням
  input_file="input.txt"; //вхідний файл
  output_file="out.txt";  //вихідний файл
  limit=4;                //ліміт <4

  //обробка параметрів командного рядка
  int opt=0;
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
          getlimit(optarg);
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

/// Функція друкує повідомлення "про програму"
void args_t::usage(){
  cout<<"effective_topology - creating efficient centralized network topologies\n"
        "Parameters:\n"
        "-i\t\tInput file, default \"input.txt\"\n"
        "-o\t\tOutput file, default \"out.txt\"\n"
        "-l\t\tSets a limit, the number of nodes in the segment will not"
        " exceed it\n\t\tdefault limit <4\n"
        "-h\t\tPrint this message."<<endl;
  exit (EXIT_SUCCESS);
}

/// Функція записує параметр командного рядка в змінну limit
void args_t::getlimit (char *tmp){
  limit=atoi(tmp);
  if (limit==0){
      cerr<<"Invalid parameter \"limit\""<<endl;
      exit (EXIT_FAILURE);
    }
  limit++; //оскільки обмеження <limit
}
