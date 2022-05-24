#include <vector>
#include <iostream>
#include <fstream>  //occhio alla i
#include <cmath>


struct Boid {
    double x_{};
    double y_{};
    double v_x_{};
    double v_y_{};
};

int main() {
int num_piccioni = 0;   
std::cin >> num_piccioni;
std::vector<Boid> flock{};

std::fstream in; //file da inserire nella stessa cartella del programmaaa
   
in.open("piccioni.txt");
  double x, y, v_x, v_y;
  while (1) {
    in >> x >> y >> v_x >> v_y;
    if (!in.good()) break;
    Boid boid;
    boid.x_ = x; boid.y_ = y; boid.v_x_ = v_x ; boid.v_y_ = v_y;
    flock.push_back(boid);  
  }
  in.close();

double s, a, c;
std::cin >> s, a, c;
double d_s;
auto p = &flock[5];
double v1_x = 0;
double dist=sqrt(pow((p->x_ - it->x_),2)+(pow)((p->y_ - it->y_),2));
//auto p = flock[0];   bisogna cambiare tutte le freccine con dei puntiii
// spostare it e end che non gli piacciono!!!!!!!!!!!!!!!!!!! 
for (auto it=flock.begin(), end=flock.end(); it!=end; ++it) {
    if (dist<d_s && dist!=0)
{v1_x = v1_x - s * (it->x_ - p->x_);}}

double v1_y = 0;
//auto p = &flock[5];
for (auto it=flock.begin(), end=flock.end(); it!=end; ++it) {
    if ( double dist=sqrt(pow((p->x_ - it->x_),2)+(pow)((p->y_ - it->y_),2)); dist<d_s && dist!=0)
{v1_y = v1_y - s * (it->y_ - p->y_);}}

double v2_x = 0;
//auto p = &flock[5];
for (auto it=flock.begin(), end=flock.end(); it!=end; ++it) {
   v2_x = v2_x + (a /num_piccioni - 1) * (it->v_x_ - p->v_x_);}

double v2_y = 0;
//auto p = &flock[5];
for (auto it=flock.begin(), end=flock.end(); it!=end; ++it) {
   v2_y = v2_y + (a /num_piccioni - 1) * (it->v_y_ - p->v_y_);}




   
   
   
   
   
   
   
}









