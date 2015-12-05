#include <iostream>
#include <fstream>

using namespace std;

//Equations of Lorentz model

double f1(double x, double y, double z, double t){
  double a=10.0;
  return a*(y-x); 
}

double f2(double x, double y, double z, double t){
  double b=28.0;
  return x*(b-z)-y; 
}

double f3(double x, double y, double z, double t){
  double c=8.0/3.0;
  return x*y-c*z; 
}

//Runge-Kutta 4th order algorithm


void writing(double x, double y, double z, double t, double dt){
  double k11, k21, k31, k12, k22, k32, k13, k23, k33, k14, k24, k34;
  
  ofstream myfile;
  
  myfile.open ("Rungekutta.txt");
  
  for(t=0; t<=100; t+=dt){
  k11 = f1(x, y, z, t);
  k21 = f2(x, y, z, t);
  k31 = f3(x, y, z, t);
  
  k12 = f1(x+dt*k11/2., y+dt*k21/2., z+dt*k31/2., t+dt/2.);
  k22 = f2(x+dt*k11/2., y+dt*k21/2., z+dt*k31/2., t+dt/2.);
  k32 = f3(x+dt*k11/2., y+dt*k21/2., z+dt*k31/2., t+dt/2.);
  
  k13 = f1(x+dt*k12/2., y+dt*k22/2., z+dt*k32/2., t+dt/2.);
  k23 = f2(x+dt*k12/2., y+dt*k22/2., z+dt*k32/2., t+dt/2.);
  k33 = f3(x+dt*k12/2., y+dt*k22/2., z+dt*k32/2., t+dt/2.);
  
  k14 = f1(x+dt*k13, y+dt*k23, z+dt*k33, t+dt);
  k24 = f2(x+dt*k13, y+dt*k23, z+dt*k33, t+dt);
  k34 = f3(x+dt*k13, y+dt*k23, z+dt*k33, t+dt);
    
  x += dt*(k11 + 2*k12 + 2*k13 + k14)/6.;
  y += dt*(k21 + 2*k22 + 2*k23 + k24)/6.;
  z += dt*(k31 + 2*k32 + 2*k33 + k34)/6.;
  
  myfile << t << "\t" << x << "\t" << y << "\t" << z << endl;
  }
  
  myfile.close();
}


int main(){
  
  //initial conditions
  double x=1.;
  double y=1.;
  double z=1.;
  
  double t, dt;
  
  cout << "dt="; 
  cin >> dt;
  
  writing(x, y, z, t, dt);
  
  
 return 0; 
}