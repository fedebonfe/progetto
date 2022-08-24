#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <SFML/Graphics.hpp> 

struct Boid {
double x_{};
double y_{};
double v_x_{};
double v_y_{};
};
struct parametri{
double  s;
double  a;
double  c;
double  d_s;
double  d;
int  num_piccioni;
};

std::vector<Boid> volo(std::vector<Boid> flock, parametri k){

for (int g=0, n=flock.size(); g!=n; ++g) {

double dist=0;

double v1_x = 0;

for (int h=0, n=flock.size(); h!=n; ++h) {
dist=sqrt(pow((flock[g].x_ - flock[h].x_),2)+(pow)((flock[g].y_ - flock[h].y_),2));
if (dist<k.d_s && dist!=0 && dist<k.d)
{v1_x = v1_x - k.s * (flock[h].x_ - flock[g].x_);}}
double v1_y = 0;
for (int h=0, n=flock.size(); h!=n; ++h) {
dist=sqrt(pow((flock[g].x_ - flock[h].x_),2)+(pow)((flock[g].y_ - flock[h].y_),2));
if(dist<k.d_s && dist!=0 && dist<k.d)
{v1_y = v1_y - k.s * (flock[h].y_ - flock[g].y_);}}
double v2_x = 0;
for (int h=0, n=flock.size(); h!=n; ++h) {
dist=sqrt(pow((flock[g].x_ - flock[h].x_),2)+(pow)((flock[g].y_ - flock[h].y_),2));
if(dist<k.d){
v2_x = v2_x + (k.a /(k.num_piccioni - 1)) * (flock[h].v_x_ - flock[g].v_x_);}}

double v2_y = 0;
for (int h=0, n=flock.size(); h!=n; ++h) {
dist=sqrt(pow((flock[g].x_ - flock[h].x_),2)+(pow)((flock[g].y_ - flock[h].y_),2));
if(dist<k.d){
v2_y = v2_y + (k.a /(k.num_piccioni - 1)) * (flock[h].v_y_ - flock[g].v_y_);}}
double x_cm = - (flock[g].x_/(k.num_piccioni -1));
for (int h=0, n=flock.size(); h!=n; ++h) {
dist=sqrt(pow((flock[g].x_ - flock[h].x_),2)+(pow)((flock[g].y_ - flock[h].y_),2));
if(dist<k.d){
x_cm = x_cm + (flock[h].x_/(k.num_piccioni -1));} }
double y_cm = - (flock[g].y_/(k.num_piccioni -1));
for (int h=0, n=flock.size(); h!=n; ++h) {
dist=sqrt(pow((flock[g].x_ - flock[h].x_),2)+(pow)((flock[g].y_ - flock[h].y_),2));
if(dist<k.d){
y_cm = y_cm + (flock[h].y_/(k.num_piccioni -1));} }
double v3_x =0;
v3_x = k.c * ( x_cm - flock[g].x_ );
double v3_y =0;
v3_y = k.c * ( y_cm - flock[g].y_ );
flock[g].v_x_ = flock[g].v_x_ + v1_x + v2_x + v3_x;
flock[g].v_y_ = flock[g].v_y_ + v1_y + v2_y + v3_y;
double delta_t =1; 
flock[g].x_ = flock[g].x_ + (flock[g].v_x_ * delta_t);
flock[g].y_ = flock[g].y_ + (flock[g].v_y_ * delta_t);

}
return flock;
}

void stampa(std::vector<Boid> flock) {
for (int g=0, n=flock.size(); g!=n; ++g){
std::cout << flock[g].x_ << '\n'<< flock[g].y_ << '\n'<< flock[g].v_x_ << '\n' <<flock[g].v_y_ << '\n';
}
}

double velocita(std::vector<Boid> flock) {
double V=0;
double V_tot =0;    
    for (int g=0, n=flock.size(); g!=n; ++g){
V= sqrt(pow(flock[g].v_x_, 2) + pow(flock[g].v_y_, 2));
V_tot= V_tot + V;
    }
    return V_tot; 
}

double velocita_2(std::vector<Boid> flock) {
double V_2=0;
double V_tot_2 =0;    
    for (int g=0, n=flock.size(); g!=n; ++g){
V_2= pow(flock[g].v_x_, 2) + pow(flock[g].v_y_, 2);
V_tot_2= V_tot_2 + V_2;
    }
    return V_tot_2; 
}

double distanza(std::vector<Boid> flock) {
  double dist = 0;
  int i=0;
for (int g=0, n=flock.size(); g!=n; ++g){
++i;
for (int h=0 +i , n=flock.size(); h!=n; ++h) {
dist= dist + sqrt(pow((flock[g].x_ - flock[h].x_),2)+pow((flock[g].y_ - flock[h].y_),2));
}  }  
return dist;
}

double distanza_2(std::vector<Boid> flock) {
    double dist_2 = 0;
    int j=0;
for (int g=0, n=flock.size(); g!=n; ++g){
++j;
for (int h=0 +j, n=flock.size(); h!=n; ++h) {
dist_2= dist_2 + pow((flock[g].x_ - flock[h].x_),2)+pow((flock[g].y_ - flock[h].y_),2);
}   }
return dist_2;
}

std::vector<Boid> bordi(std::vector<Boid> flock){

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

}
return flock;
}

std::vector<Boid> v_limite(std::vector<Boid> flock){

for (int g=0, n=flock.size(); g!=n; ++g) {  
if(flock[g].v_x_>8){flock[g].v_x_ =8;}
if(flock[g].v_x_<-8){flock[g].v_x_ =-8;}
if(flock[g].v_y_>8){flock[g].v_y_ =8;}
if(flock[g].v_y_<-8){flock[g].v_y_ =-8;}

}
return flock;
}

int main() {
parametri k;
std::cout<<" Inserisci il numero di piccioni"<<'\n';

std::cin >> k.num_piccioni;
std::cout<<k.num_piccioni<<'\n';
std::vector<Boid> flock{};
std::fstream in;
int z=0;
in.open("piccioni.txt");
double x, y, v_x, v_y;
while ( z<k.num_piccioni) {
in >> x >> y >> v_x >> v_y;
if (!in.good()) break;
Boid boid;
boid.x_ = x; boid.y_ = y; boid.v_x_ = v_x ; boid.v_y_ = v_y;
flock.push_back(boid);
++z;
}
in.close();

std::cout<< "Inserisci i valori di s, a, c " << '\n';

std::cin>> k.s >> k.a >> k.c;
std::cout<< k.s <<" "<< k.a <<" "<< k.c <<" "<< '\n';
std::cout<<"Inserisci il valore di d_s "<< '\n';

std::cin>> k.d_s;
std::cout<< k.d_s <<'\n';
std::cout<<"Inserisci il valore di d "<< '\n';

std::cin>>k.d;
std::cout<<k.d<< '\n';

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
sf::CircleShape piccione (3);
piccione.setFillColor(sf::Color::Magenta);

for(int i=1; i<=k.num_piccioni; ++i){ stormo.push_back(piccione); }

while(window.isOpen()){

sf::Event evnt;
   while(window.pollEvent(evnt)) {

   if(evnt.type == evnt.Closed) {
    window.close(); }
   }

window.clear();
window.draw(sfondo);
for(int i=1; i<=k.num_piccioni; ++i)  {

stormo[i-1].setPosition(sf::Vector2f(flock[i-1].x_, flock[i-1].y_));
window.draw(stormo[i-1]);
}
 window.display();
////////////////////////////////////////////////////////

//for(int T=1; T<=T_max; ++T){

flock = volo(flock, k);
stampa(flock);

double V_tot = velocita(flock);
double V_tot_2 = velocita_2(flock);

double V_media=V_tot / k.num_piccioni;
double V_dev_std = sqrt(((V_tot_2/k.num_piccioni) - pow(V_media,2))/(k.num_piccioni -1));

std::cout<< "La velocità media è " << V_media << " +/- " << V_dev_std << '\n';

double dist = distanza(flock);
double dist_2 = distanza_2(flock);

int comb=((k.num_piccioni * (k.num_piccioni - 1 ))/2);
double D_media= dist/ comb;
double D_media_2 = dist_2 / comb;
double D_dev_std = sqrt((D_media_2 - pow(D_media,2))/(k.num_piccioni -1));
std::cout<<"La distanza media tra i piccioni è "<< D_media << " +/- " << D_dev_std <<'\n';

flock = bordi(flock);
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
flock = v_limite(flock);
/*for (int g=0, n=flock.size(); g!=n; ++g) {  
if(flock[g].v_x_>8){flock[g].v_x_ =8;}
if(flock[g].v_x_<-8){flock[g].v_x_ =-8;}
if(flock[g].v_y_>8){flock[g].v_y_ =8;}
if(flock[g].v_y_<-8){flock[g].v_y_ =-8;}

}*/

//}
}
}
 
