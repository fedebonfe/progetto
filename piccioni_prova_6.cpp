/*codice copiato da piccioni_prova_5.cpp, con ciclo con il tempo e velocità media e distanza media con rispettive incertezze */

#include <vector>
#include <iostream>
#include <fstream> //occhio alla i
#include <cmath>

struct Boid {
    double x_{};
    double y_{};
    double v_x_{};
    double v_y_{};
};

int main() {
std::cout<<"5 Inserisci il numero di piccioni"<<'\n';
int num_piccioni = 0;  //double
std::cin >> num_piccioni;
std::cout<<num_piccioni<<'\n';
std::vector<Boid> flock{};

std::fstream in; //file da inserire nella stessa cartella del programmaaa

//auto const file1 = piccioni.txt;

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

//usare il num_piccioni per fare un controllo con assert oppure per il break;








std::cout<< "Inserisci i valori di s, a, c " << '\n'; 
double s, a, c;
std::cin>> s >> a >> c;
std::cout<< s <<" "<< a <<" "<< c <<" "<< '\n';
std::cout<<"Inserisci il valore di d_s "<< '\n';
double d_s;
std::cin>> d_s;
std::cout<< d_s <<'\n';
//auto p = &flock[5];

double V_x_tot=0;
double V_y_tot=0;
double V_x_tot_2= 0;
double V_y_tot_2=0;
double dist=0;
double dist_2=0;



for(double delta_t=1; delta_t<=4; ++delta_t){
for (auto p=flock.begin(), end=flock.end(); p!=end; ++p) {

std::cout << p->x_ << '\n' << p->y_ << '\n' << p->v_x_ << '\n' << p->v_y_ << '\n'; 
/*for (auto it=flock.begin(), end=flock.end(); it!=end; ++it) {
    dist= dist+  sqrt(pow((p->x_ - it->x_),2)+(pow)((p->y_ - it->y_),2));
    std::cout<<dist<< '\n';}*/

double v1_x = 0;

//auto p = flock[0];   bisogna cambiare tutte le freccine con dei puntiii
// spostare it e end che non gli piacciono!!!!!!!!!!!!!!!!!!! 
for (auto it=flock.begin(), end=flock.end(); it!=end; ++it) {
    dist=sqrt(pow((p->x_ - it->x_),2)+(pow)((p->y_ - it->y_),2));
  //double dist=sqrt(pow((p->x_ - it->x_),2)+(pow)((p->y_ - it->y_),2));
    if (dist<d_s && dist!=0)
{v1_x = v1_x - s * (it->x_ - p->x_);}}

double v1_y = 0;
//auto p = &flock[5];
for (auto it=flock.begin(), end=flock.end(); it!=end; ++it) {
    dist=sqrt(pow((p->x_ - it->x_),2)+(pow)((p->y_ - it->y_),2));
    if(dist<d_s && dist!=0)
    //if ( double dist=sqrt(pow((p->x_ - it->x_),2)+(pow)((p->y_ - it->y_),2)); dist<d_s && dist!=0)
{v1_y = v1_y - s * (it->y_ - p->y_);}}

double v2_x = 0;
//auto p = &flock[5];
for (auto it=flock.begin(), end=flock.end(); it!=end; ++it) {
   v2_x = v2_x + (a /(num_piccioni - 1)) * (it->v_x_ - p->v_x_);}

double v2_y = 0;
//auto p = &flock[5];
for (auto it=flock.begin(), end=flock.end(); it!=end; ++it) {
   v2_y = v2_y + (a /(num_piccioni - 1)) * (it->v_y_ - p->v_y_);}


double x_cm = - (p->x_/(num_piccioni -1));
for (auto it=flock.begin(), end=flock.end(); it!=end; ++it) {
   x_cm = x_cm + (it->x_/(num_piccioni -1));} 
 
double y_cm = - (p->y_/(num_piccioni -1));
for (auto it=flock.begin(), end=flock.end(); it!=end; ++it) {
y_cm = y_cm + (it->y_/(num_piccioni -1));} 

double v3_x =0;
v3_x = c * ( x_cm - p->x_ );//!!! invertire i termini della differenza!?

double v3_y =0;
v3_y = c * ( y_cm - p->y_ ); 

p->v_x_ = p->v_x_ + v1_x + v2_x + v3_x;  
p->v_y_ = p->v_y_ + v1_y + v2_y + v3_y; 

double delta_t =1;
p->x_ = p->x_ + (p->v_x_ * delta_t);
p->y_ = p->y_ + (p->v_y_ * delta_t);

std::cout << p->x_ << '\n' << p->y_ << '\n' << p->v_x_ << '\n' << p->v_y_ << '\n'; 

//per il calcolo della media
V_x_tot= V_x_tot + p->v_x_;
V_y_tot= V_y_tot + p->v_y_;
//std::cout<< V_x_tot << '\n' << V_y_tot<< '\n';

//per il calcolo della deviazione standard della velcoità media
V_x_tot_2= V_x_tot_2 + pow(p->v_x_, 2);
V_y_tot_2= V_y_tot_2 + pow(p->v_y_, 2);
//std::cout<< V_x_tot_2 << '\n' << V_y_tot_2 << '\n';

//per il calcolo della distanza media(non è poi così vero, penso si possa cancellare)
/*for (auto it=flock.begin(), end=flock.end(); it!=end; ++it) {
    dist= dist + sqrt(pow((p->x_ - it->x_),2)+(pow)((p->y_ - it->y_),2));
    std::cout<<dist<< '\n';

}*/
}
int i=0;
//per il calcolo della distanza media
for (auto p=flock.begin(), end=flock.end(); p!=end; ++p){
    
    ++i;
    for (auto it=flock.begin() + i, end=flock.end(); it!=end; ++it) {
    dist= dist + sqrt(pow((p->x_ - it->x_),2)+pow((p->y_ - it->y_),2));
    
    std::cout<<dist<< '\n';

}

}
//std::cout<<i<< '\n';
//per il calcolo della deviazione standard della distanza media
int j=0;
for (auto p=flock.begin(), end=flock.end(); p!=end; ++p){
    
    ++j;
    for (auto it=flock.begin() + j, end=flock.end(); it!=end; ++it) {
    dist_2= dist_2 + pow((p->x_ - it->x_),2)+pow((p->y_ - it->y_),2);
    
    std::cout<<dist_2<< '\n';

}

}

double N= (double)num_piccioni / (double)(num_piccioni - 1);
double comb=((num_piccioni * (num_piccioni - 1 ))/2);
//std::cout<<N<< '\n';
double D_media= dist/ comb;
double D_media_2 = dist_2 / comb;
//std::cout<< D_media_2<< '\n';
//std::cout<< D_media_2 - pow(D_media, 2) << '\n';
double D_dev_std= sqrt((N) * (D_media_2 - pow(D_media, 2))) / sqrt((double)num_piccioni);
std::cout<<"La distanza media tra i piccioni è "<< D_media<< " +/- " << D_dev_std <<'\n';
//altro modo di calcolare la media
//double V_x_tot_2= pow(V_x_tot, 2);
//std::cout<< V_x_tot_2 << '\n';
//double V_y_tot_2= pow(V_y_tot,2);
//std::cout<< V_y_tot_2 << '\n';
//double V_media = sqrt(V_x_tot_2 + V_y_tot_2)/ num_piccioni;
//std::cout<<V_media<< '\n';

double V_media = sqrt(pow(V_x_tot, 2) + pow(V_y_tot, 2) ) / num_piccioni;

//std::cout<< num_piccioni / (num_piccioni - 1)<< '\n'; da' 1 invece che 1,5 perchè divisione tra interi
//std::cout<<  (V_x_tot_2 + V_y_tot_2 )/ num_piccioni<< '\n' ; per controllare calcoli intermedi
//std::cout<< pow( V_media, 2)<<'\n'; per controllare calcoli intermedi
double V_dev_std = sqrt(( N ) * (((V_x_tot_2 + V_y_tot_2 )/ num_piccioni ) - pow( V_media, 2))) / sqrt((double)num_piccioni);
std::cout<< "La velocità media è " << V_media<< " +/-"<< " "<< V_dev_std << '\n';

}
}