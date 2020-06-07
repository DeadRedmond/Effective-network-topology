#include "func.h"
/// Функція зчитує координати з файлу
vector<coord> read(){
  vector <coord> nodes;
  if (__argc==1){
      //відкриваємо файл
      ifstream input("input.txt");
      if (!input.is_open()){
          cerr<<"Can not read \"input.txt\""<<endl;
            return nodes;
      }
      //зчитуємо вміст по рядку
      else {
          string line;
          while (getline(input, line)){
              coord tmp;
              istringstream iss(line);
              iss>>tmp.llng>>tmp.llt;
              nodes.push_back(tmp);
          }
          return nodes;
      }
    }
  else {
      //відкриваємо файл
      ifstream input(__argv[1]);
      if (!input.is_open()){
          cerr<<"Can not read \""<<__argv[1]<<"\""<<endl;
            return nodes;
      }
      //зчитуємо вміст по рядку
      else {
          string line;
          while (getline(input, line)){
              coord tmp;
              istringstream iss(line);
              iss>>tmp.llng>>tmp.llt;
              nodes.push_back(tmp);
          }
          return nodes;
      }
    }
}
/// Функція друкує двомірну матрицю в файл out.txt
int write(bool **matrix, int size){
  remove ("output.txt");
  ofstream output("out.txt", ofstream::trunc);
  if (!output.is_open()){
      cerr<<"Can not write to \"out.txt\""<<endl;
      return 2;
    }
  else {
      //output.width(5);
      for (int i=0; i<size; i++){
          for (int j=0; j<size; j++)
              output<<matrix[i][j]<<"\t";
          output<<endl;
      }
      output.close();
      return 0;
    }
}

///*функція приймає координати двох точок і повертає відстань між ними в метрах
int get_distance(double llat1, double llong1, double llat2, double llong2) {

  //приведення до радіан
  double lat1 = llat1*M_PI/180;
  double lat2 = llat2*M_PI/180;
  double long1 = llong1*M_PI/180;
  double long2 = llong2*M_PI/180;

  //косинуси і синуси широт, и різниці довгот
  double cl1 = cos(lat1);
  double cl2 = cos(lat2);
  double sl1 = sin(lat1);
  double sl2 = sin(lat2);
  double delta = long2 - long1;
  double cdelta = cos(delta);
  double sdelta = sin(delta);

  //вимірювання відстані за формулою гаверсинуса
  double y = sqrt(pow(cl2*sdelta,2)+pow(cl1*sl2-sl1*cl2*cdelta,2));
  double x = sl1*sl2+cl1*cl2*cdelta;
  double ad = atan2(y,x);
  int dist = (int)round(ad*RAD);
  return dist;
}

