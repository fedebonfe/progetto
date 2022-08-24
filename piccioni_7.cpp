//file cpp per hpp, creato classe parametri e classe Boid con metodi volo e bordi ed errori
//#include <vector>
#include "piccioni_2.hpp" 
#include <iostream>
#include <fstream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <stdexcept>  
#include <string>  

/*struct Boid {
double x_{};
double y_{};
double v_x_{};
double v_y_{};
};*/


/* class parametri{
 double s_;
double a_;
double c_;
double d_s_;
double d_;
int num_piccioni_;

public: */
parametri::parametri(double s, double a, double c, double d_s, double d, int num_piccioni)
: s_{s}, a_{a}, c_{c}, d_s_{d_s}, d_{d}, num_piccioni_{num_piccioni} {
    if(d_s<0){throw std::runtime_error{"il valore del parametro d_s deve essere positivo"};}
    if(d<0){throw std::runtime_error{"il valore del parametro d deve essere positivo"};}
    if(d_s>d){throw std::runtime_error{"il valore del parametro d_s deve essere minore di d"};}
    if(num_piccioni<=1){throw std::runtime_error{"numero di boids insufficiente"};} 
}
double parametri::s(){return s_;}
double parametri::a(){return a_;}
double parametri::c(){return c_;}
double parametri::d_s(){return d_s_;}
double parametri::d(){return d_;}
int parametri::num_piccioni(){return num_piccioni_;}
//};





/* class Boid {
 double x_{};
 double y_{};
 double v_x_{};
 double v_y_{};
public: */
Boid::Boid(double x, double y, double v_x, double v_y) : x_{x}, y_{y}, v_x_{v_x}, v_y_{v_y} { 
/*if((x>1000) | (x<0)){ 
throw std::runtime_error{"posizione iniziale in x non valida"};
}
if((y>500) | (y<0)){ 
throw std::runtime_error{"posizione iniziale in y non valida"};
}
if((v_x>8) | (v_x<-8)){ 
throw std::runtime_error{"velocità iniziale in x oltre la velocità limite"};
}
if((v_y>8) | (v_y<-8)){ 
throw std::runtime_error{"velocità iniziale in y oltre la velocità limite"};
}*/
}
double Boid::x(){return x_;}
double Boid::y(){return y_;}
double Boid::v_x(){return v_x_;}
double Boid::v_y(){return v_y_;} 

//std::vector<Boid> volo(std::vector<Boid> flock, parametri k){
Boid& Boid::volo(Boid& b, std::vector<Boid>& flock, parametri& k){
//for (int g=0, n=flock.size(); g!=n; ++g) {


double dist=0;

double v1_x = 0;

for (int h=0, n=flock.size(); h!=n; ++h) {
dist=sqrt(pow((b.x_ - flock[h].x_),2)+(pow)((b.y_ - flock[h].y_),2));
if (dist<k.d_s() && dist!=0 && dist<k.d())
{v1_x = v1_x - k.s() * (flock[h].x_ - b.x_);}}
double v1_y = 0;
for (int h=0, n=flock.size(); h!=n; ++h) {
dist=sqrt(pow((b.x_ - flock[h].x_),2)+(pow)((b.y_ - flock[h].y_),2));
if(dist<k.d_s() && dist!=0 && dist<k.d())
{v1_y = v1_y - k.s() * (flock[h].y_ - b.y_);}}
double v2_x = 0;
for (int h=0, n=flock.size(); h!=n; ++h) {
dist=sqrt(pow((b.x_ - flock[h].x_),2)+(pow)((b.y_ - flock[h].y_),2));
if(dist<k.d()){
v2_x = v2_x + (k.a() /(k.num_piccioni() - 1)) * (flock[h].v_x_ - b.v_x_);}}

double v2_y = 0;
for (int h=0, n=flock.size(); h!=n; ++h) {
dist=sqrt(pow((b.x_ - flock[h].x_),2)+(pow)((b.y_ - flock[h].y_),2));
if(dist<k.d()){
v2_y = v2_y + (k.a() /(k.num_piccioni() - 1)) * (flock[h].v_y_ - b.v_y_);}}
double x_cm = - (b.x_/(k.num_piccioni() -1));
for (int h=0, n=flock.size(); h!=n; ++h) {
dist=sqrt(pow((b.x_ - flock[h].x_),2)+(pow)((b.y_ - flock[h].y_),2));
if(dist<k.d()){
x_cm = x_cm + (flock[h].x_/(k.num_piccioni() -1));} }
double y_cm = - (b.y_/(k.num_piccioni() -1));
for (int h=0, n=flock.size(); h!=n; ++h) {
dist=sqrt(pow((b.x_ - flock[h].x_),2)+(pow)((b.y_ - flock[h].y_),2));
if(dist<k.d()){
y_cm = y_cm + (flock[h].y_/(k.num_piccioni() -1));} }
double v3_x =0;
v3_x = k.c() * ( x_cm - b.x_ );
double v3_y =0;
v3_y = k.c() * ( y_cm - b.y_ );
b.v_x_ = b.v_x_ + v1_x + v2_x + v3_x;
b.v_y_ = b.v_y_ + v1_y + v2_y + v3_y;

//velocita limite
if(b.v_x_>8){b.v_x_ =8;}
if(b.v_x_<-8){b.v_x_ =-8;}
if(b.v_y_>8){b.v_y_ =8;}
if(b.v_y_<-8){b.v_y_ =-8;}

double delta_t =1; 
b.x_ = b.x_ + (b.v_x_ * delta_t);
b.y_ = b.y_ + (b.v_y_ * delta_t);

//}
return b;
}


Boid& Boid::bordi(Boid& b){

//for (int g=0, n=flock.size(); g!=n; ++g) {
//esce solo a sinistra
if( b.x_<0 && b.y_<500 && b.y_>0) { b.x_ = b.x_ + 1000; b.y_ = 500 - b.y_;}
//esce solo a destra
if( b.x_>1000 && b.y_<500 && b.y_>0) { b.x_ = b.x_ - 1000; b.y_ = 500 - b.y_;}
// esce solo in alto
if( b.y_<0 && b.x_<1000 && b.x_>0) { b.y_ = b.y_ + 500; b.x_ = 1000 - b.x_;}
//esce solo in basso
if( b.y_>500 && b.x_<1000 && b.x_>0) { b.y_ = b.y_ - 500; b.x_ = 1000 - b.x_;}
//esce in angolo alto a sinistra
if( b.x_ <0 && b.y_<0) { b.x_ = b.x_ +1000; b.y_ = b.y_ +500;}
//esce in angolo alto a destra
if( b.x_ >1000 && b.y_<0) { b.x_ = b.x_ -1000; b.y_ = b.y_ +500;}
//esce in angolo basso a sinistra
if( b.x_ <0 && b.y_>500) { b.x_ = b.x_ +1000; b.y_ = b.y_ -500;}
//esce in angolo basso a destra
if( b.x_ >1000 && b.y_>500) { b.x_ = b.x_ -1000; b.y_ = b.y_ -500;}

//}
return b;
}


//};






void stampa(std::vector<Boid>& flock) {
for (int g=0, n=flock.size(); g!=n; ++g){
std::cout << flock[g].x() << '\t' << '\t' << flock[g].y() << '\t' << '\t' << flock[g].v_x() << '\t' << '\t' <<flock[g].v_y() << '\n';
}
}

double velocita(std::vector<Boid>& flock) {
double V=0;
double V_tot =0;    
    for (int g=0, n=flock.size(); g!=n; ++g){
V= sqrt(pow(flock[g].v_x(), 2) + pow(flock[g].v_y(), 2));
V_tot= V_tot + V;
    }
    return V_tot; 
}


double velocita_2(std::vector<Boid>& flock) {
double V_2=0;
double V_tot_2 =0;    
    for (int g=0, n=flock.size(); g!=n; ++g){
V_2= pow(flock[g].v_x(), 2) + pow(flock[g].v_y(), 2);
V_tot_2= V_tot_2 + V_2;
    }
    return V_tot_2; 
}


double distanza(std::vector<Boid>& flock) {
  double dist = 0;
  int i=0;
for (int g=0, n=flock.size(); g!=n; ++g){
++i;
for (int h=0 +i , n=flock.size(); h!=n; ++h) {
dist= dist + sqrt(pow((flock[g].x() - flock[h].x()),2)+pow((flock[g].y() - flock[h].y()),2));
}  }  
return dist;
}

double distanza_2(std::vector<Boid>& flock) {
    double dist_2 = 0;
    int j=0;
for (int g=0, n=flock.size(); g!=n; ++g){
++j;
for (int h=0 +j, n=flock.size(); h!=n; ++h) {
dist_2= dist_2 + pow((flock[g].x() - flock[h].x()),2)+pow((flock[g].y() - flock[h].y()),2);
}   }
return dist_2;
}





/* std::vector<Boid> v_limite(std::vector<Boid> flock){

for (int g=0, n=flock.size(); g!=n; ++g) {  
if(flock[g].v_x_>8){flock[g].v_x_ =8;}
if(flock[g].v_x_<-8){flock[g].v_x_ =-8;}
if(flock[g].v_y_>8){flock[g].v_y_ =8;}
if(flock[g].v_y_<-8){flock[g].v_y_ =-8;}

}
return flock;
} */


int main() {
//parametri k{0,0,0,0,0,0};
std::cout<<" Inserisci il numero di piccioni"<<'\n';
int par_n_p;
std::cin>> par_n_p;
std::cout<<par_n_p<<'\n';

parametri k{0,0,0,0,0,par_n_p};
try{k={0,0,0,0,0,par_n_p};} 
catch(std::runtime_error& e){std::cerr<< e.what() <<'\n';}


std::vector<Boid> flock{};
std::fstream in;
int z=0;
std::string file;
std::cout<< "inserisci il nome del file " << '\n'; 
std::cin>> file;
in.open(file);
double x, y, v_x, v_y;
while ( z<k.num_piccioni()) {
in >> x >> y >> v_x >> v_y;
if (!in.good()) break;
Boid boid{x,y,v_x,v_y};
//boid.x = x; boid.y = y; boid.v_x = v_x ; boid.v_y = v_y;
flock.push_back(boid);
++z;
}
in.close();

if(z<k.num_piccioni()){throw std::runtime_error{"dati insufficienti"};}

/*for (int g=0, n=flock.size(); g!=n; ++g){
if(flock[g].x()<0 | flock[g].x()>1000 | flock[g].y()<0 | flock[g].y()>500 | flock[g].v_x()<-8 | flock[g].v_x()>8 | flock[g].v_y()<-8 | flock[g].v_y()>8)
{std::cout<< "boid " << g+1 << '\n'; break;}}*/

for (int g=0, n=flock.size(); g!=n; ++g){
/*try{flock[g]; 
//flock[g].x(); 
} 
catch(std::runtime_error& e){std::cerr<< e.what() <<'\n';}*/

if((flock[g].x()>1000) | (flock[g].x()<0)){ 
std::cout<< "attenzione al boid " << g+1 << '\n';
throw std::runtime_error{"posizione iniziale in x non valida"};
}
if((flock[g].y()>500) | (flock[g].y()<0)){ 
std::cout<< "attenzione al boid " << g+1 << '\n';
throw std::runtime_error{"posizione iniziale in y non valida"};
}
if((flock[g].v_x()>8) | (flock[g].v_x()<-8)){ 
std::cout<< "attenzione al boid " << g+1 << '\n';
throw std::runtime_error{"velocità iniziale in x oltre la velocità limite"};
}
if((flock[g].v_y()>8) | (flock[g].v_y()<-8)){ 
std::cout<< "attenzione al boid " << g+1 << '\n';
throw std::runtime_error{"velocità iniziale in y oltre la velocità limite"};
}

}





std::cout<< "Inserisci i valori di s, a, c " << '\n';
double par_s, par_a, par_c;
std::cin>> par_s >> par_a >> par_c;
std::cout<< par_s <<" "<< par_a <<" "<< par_c <<" "<< '\n';
std::cout<<"Inserisci il valore di d_s "<< '\n';
double par_d_s;
std::cin>> par_d_s;
std::cout<< par_d_s <<'\n';
std::cout<<"Inserisci il valore di d "<< '\n';
double par_d;
std::cin>> par_d;
std::cout<< par_d << '\n';

k={par_s,par_a,par_c,par_d_s,par_d,par_n_p}; 
try{k={par_s,par_a,par_c,par_d_s,par_d,par_n_p};} 
catch(std::runtime_error& e){std::cerr<< e.what() <<'\n';}


/* int T_max = 0;
std::cout<< "inserisci il valore di T_max " << '\n';
std::cin>> T_max;
std::cout<< T_max << '\n'; */


//////////////////////////////////////////////////////////
sf::RenderWindow window(sf::VideoMode(1000,500), "piccioni in volo", sf::Style::Default);
sf::RectangleShape sfondo(sf::Vector2f(1000.0f,500.0f));

window.setFramerateLimit(10);


sf::Texture cielo;
cielo.loadFromFile("cielo.jpg");
sfondo.setTexture(&cielo);

std::vector<sf::CircleShape> stormo;
sf::CircleShape piccione(3); 
piccione.setOrigin(3,3);
piccione.setFillColor(sf::Color::Magenta);

for(int i=1; i<=k.num_piccioni(); ++i){ stormo.push_back(piccione); }


while(window.isOpen()){

sf::Event evnt;
   while(window.pollEvent(evnt)) {

   if(evnt.type == evnt.Closed) {
    window.close(); }
   }


window.clear();
window.draw(sfondo);
for(int i=1; i<=k.num_piccioni(); ++i)  {

stormo[i-1].setPosition(sf::Vector2f(flock[i-1].x(), flock[i-1].y()));
window.draw(stormo[i-1]);
}
 window.display();
////////////////////////////////////////////////////////


//for(int T=1; T<=T_max; ++T){
for (int g=0, n=flock.size(); g!=n; ++g) {

flock[g] = flock[g].volo(flock[g], flock, k); }

//flock = v_limite(flock);

stampa(flock);

double V_tot = velocita(flock);
double V_tot_2 = velocita_2(flock);


double V_media=V_tot / k.num_piccioni();
double V_dev_std = sqrt(((V_tot_2/k.num_piccioni()) - pow(V_media,2))/(k.num_piccioni() -1));

std::cout<< "La velocità media è " << V_media << " +/- " << V_dev_std << '\n';

double dist = distanza(flock);
double dist_2 = distanza_2(flock);

int comb=((k.num_piccioni() * (k.num_piccioni() - 1 ))/2);
double D_media= dist/ comb;
double D_media_2 = dist_2 / comb;
double D_dev_std = sqrt((D_media_2 - pow(D_media,2))/(k.num_piccioni() -1));
std::cout<<"La distanza media tra i piccioni è "<< D_media << " +/- " << D_dev_std <<'\n';

for (int g=0, n=flock.size(); g!=n; ++g) {  
flock[g] = flock[g].bordi(flock[g]);
}
/*
for (int g=0, n=flock.size(); g!=n; ++g) {
//esce solo a sinistra
if( flock[g].x_<0 && flock[g].y_<500 && flock[g].y_>0) { flock[g].x_ = flock[g].x_ + 1000; flock[g].y_ = 500 - flock[g].y_;}
//esce solo a destra
if( flock[g].x_>1000 && flock[g].y_<500 && flock[g].y_>0) { flock[g].x_ = flock[g].x_ - 1000; flock[g].y_ = 500 - flock[g].y_;}
// esce solo in alto
if( flock[g].y_<0 && flock[g].x_<1000 && flock[g].x_>0) { flock[g].y_ = flock[g].y_ + 500; flock[g].x_ = 1000 - flock[g].x_;}
//esce solo in basso
if( flock[g].y_>500 && flock[g].x_<1000 && flock[g].x_>0) { flock[g].y_ = flock[g].y_ - 500; flock[g].x_ = 1000 - flock[g].x_;}
//esce in angolo alto a sinistra
if( flock[g].x_ <0 && flock[g].y_<0) { flock[g].x_ = flock[g].x_ +1000; flock[g].y_ = flock[g].y_ +500;}
//esce in angolo alto a destra
if( flock[g].x_ >1000 && flock[g].y_<0) { flock[g].x_ = flock[g].x_ -1000; flock[g].y_ = flock[g].y_ +500;}
//esce in angolo basso a sinistra
if( flock[g].x_ <0 && flock[g].y_>500) { flock[g].x_ = flock[g].x_ +1000; flock[g].y_ = flock[g].y_ -500;}
//esce in angolo basso a destra
if( flock[g].x_ >1000 && flock[g].y_>500) { flock[g].x_ = flock[g].x_ -1000; flock[g].y_ = flock[g].y_ -500;} 

}*/
//flock = v_limite(flock);
/*for (int g=0, n=flock.size(); g!=n; ++g) {  
if(flock[g].v_x_>8){flock[g].v_x_ =8;}
if(flock[g].v_x_<-8){flock[g].v_x_ =-8;}
if(flock[g].v_y_>8){flock[g].v_y_ =8;}
if(flock[g].v_y_<-8){flock[g].v_y_ =-8;}

}*/


//}
}
}