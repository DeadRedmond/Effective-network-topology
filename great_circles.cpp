#include "great_circles.h"

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
