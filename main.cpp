#include <iostream>
#include <math.h>
using namespace std;

class fvec_t
{
public:
    float x,y,z;
    fvec_t(){x=0;y=0;z=0;}
    fvec_t(float x1,float y1,float z1)
       {x=x1;y=y1;z=z1;}
    fvec_t(const fvec_t &vec){
       x=vec.x;y=vec.y;z=vec.z;}
};

fvec_t operator+(const fvec_t &veca){
   return fvec_t(veca.x,veca.y,veca.z);};
fvec_t operator+(const fvec_t &veca, const fvec_t &vecb){
   return fvec_t(veca.x+vecb.x,veca.y+vecb.y,veca.z+vecb.z);};
fvec_t operator+(const float val,const fvec_t &veca){
   return fvec_t(veca.x+val,veca.y+val,veca.z+val);};
fvec_t operator+(const fvec_t &veca,const float val){
   return fvec_t(veca.x+val,veca.y+val,veca.z+val);};
fvec_t operator+(const double val,const fvec_t &veca){
   return fvec_t(veca.x+val,veca.y+val,veca.z+val);};
fvec_t operator+(const fvec_t &veca,const double val){
   return fvec_t(veca.x+val,veca.y+val,veca.z+val);};
fvec_t operator+(const int val,const fvec_t &veca){
   return fvec_t(veca.x+val,veca.y+val,veca.z+val);};
fvec_t operator+(const fvec_t &veca,const int val){
   return fvec_t(veca.x+val,veca.y+val,veca.z+val);};
fvec_t operator-(const fvec_t &veca){
   return fvec_t(-veca.x,-veca.y,-veca.z);};
fvec_t operator-(const fvec_t &veca, const fvec_t &vecb){
   return fvec_t(veca.x-vecb.x,veca.y-vecb.y,veca.z-vecb.z);};
fvec_t operator%(const fvec_t &veca, const fvec_t &vecb){
   return fvec_t(veca.y*vecb.z-veca.z*vecb.y,
                 veca.z*vecb.x-veca.x*vecb.z,
                 veca.x*vecb.y-veca.y*vecb.x);};
fvec_t operator-(const float val,const fvec_t &veca){
   return fvec_t(-veca.x+val,-veca.y+val,-veca.z+val);};
fvec_t operator-(const fvec_t &veca,const float val){
   return fvec_t(veca.x-val,veca.y-val,veca.z-val);};
fvec_t operator-(const double val,const fvec_t &veca){
   return fvec_t(-veca.x+val,-veca.y+val,-veca.z+val);};
fvec_t operator-(const fvec_t &veca,const double val){
   return fvec_t(veca.x-val,veca.y-val,veca.z-val);};
fvec_t operator-(const int val,const fvec_t &veca){
   return fvec_t(-veca.x+val,-veca.y+val,-veca.z+val);};
fvec_t operator-(const fvec_t &veca,const int val){
   return fvec_t(veca.x-val,veca.y-val,veca.z-val);};
//fvec_t operator*(const fvec_t &veca){
//   return fvec_t(veca.x,veca.y,veca.z);};
float operator*(const fvec_t &veca, const fvec_t &vecb){
   return (veca.x*vecb.x+veca.y*vecb.y+veca.z*vecb.z);};
fvec_t operator*(const float val,const fvec_t &veca){
   return fvec_t(veca.x*val,veca.y*val,veca.z*val);};
fvec_t operator*(const fvec_t &veca,const float val){
   return fvec_t(veca.x*val,veca.y*val,veca.z*val);};
fvec_t operator*(const double val,const fvec_t &veca){
   return fvec_t(veca.x*val,veca.y*val,veca.z*val);};
fvec_t operator*(const fvec_t &veca,const double val){
   return fvec_t(veca.x*val,veca.y*val,veca.z*val);};
fvec_t operator*(const int val,const fvec_t &veca){
   return fvec_t(veca.x*val,veca.y*val,veca.z*val);};
fvec_t operator*(const fvec_t &veca,const int val){
   return fvec_t(veca.x*val,veca.y*val,veca.z*val);};
fvec_t cross(const fvec_t &a, const fvec_t &b){
return fvec_t(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);};
float norm(const fvec_t &a){return sqrtf(a*a);};


template<typename T>
class vec_t
{
public:
	typedef T element_type;
    T x,y,z;
    //vec_t () : vec_t (0, 0, 0) {} // Oder std::nan
    vec_t (const T &x, const T &y, const T &z)
        : x(x), y(y), z(z) {}

    template<typename U>
    vec_t(const vec_t<U>& v) : x(v.x), y(v.y), z(v.z) {}

    vec_t operator+() const { return vec_t (x,y,z); }

    template<typename U>
    vec_t operator+(const vec_t<U>& w)const {
        return vec_t (x+w.x,y+w.y,z+w.z);}

   template<typename U>
    vec_t operator%(const vec_t<U>& w)const {
        return vec_t (y*w.z-z*w.y,
                    z*w.x-x*w.z,
                    x*w.y-y*w.x);}

    template<typename U>
    vec_t cross(const vec_t<U>& w)const {
      return vec_t (y*w.z-z*w.y,
                    z*w.x-x*w.z,
                    x*w.y-y*w.x); }

    T norm()const {return( sqrt(x*x+y*y+z*z));}

    vec_t operator-() const {return vec_t (-x,-y,-z);}

    template<typename U>
    vec_t operator-(const vec_t<U>& w)const {
      return vec_t (x-w.x,y-w.y,z-w.z);}

    T operator * (const vec_t &w) const
           { return x*w.x+y*w.y+z*w.z;}
};

/**********************************************************/
int main()
/**********************************************************/
{


fvec_t  ea (1,2,3);
fvec_t  eb {1,2,3};

fvec_t  ec=ea+eb;

printf("%f \r\n",norm(ec)-sqrt(2*2+4*4+6*6));
printf("%f \r\n",norm(+ea+fvec_t(1,2,3))-sqrt(2*2+4*4+6*6));
printf("%f \r\n",norm(+ea-fvec_t(1,2,3)));
ec=fvec_t(3,2,1);
printf("%f \r\n",norm(cross(ea,ec)-fvec_t(-4,8,-4)));
printf("%f \r\n",norm(ea%ec-fvec_t(-4,8,-4)));
printf("%f \r\n",norm(ea-fvec_t(1,2,3)));
printf("%f \r\n",norm(-fvec_t(1,2,3)+ea));
printf("%f \r\n",norm(1+ea-fvec_t(2,3,4)));
printf("%f \r\n",norm(ea-fvec_t(2,3,4)+1));
printf("%f \r\n",ea*ea-(1+4+9));

printf("xxxxxxxxxxxxxxxxxxxxxxxxxxx\r\n");

vec_t<double> ab(1,2,3);
vec_t<double> aa(1,2,3);
printf("%f \r\n",aa.norm()-sqrt(1*1+2*2+3*3));
printf("%f \r\n",vec_t<double>(1,2,3).norm()-sqrt(1*1+2*2+3*3));
printf("%f \r\n", (vec_t<double>(1,2,3)-aa).norm());
printf("%f \r\n", (aa-vec_t<double>(1,2,3)).norm());
printf("%f \r\n", (-vec_t<double>(1,2,3)+aa).norm());
printf("%f \r\n", (vec_t<double>(1,2,3)*vec_t<double>(1,2,3)-(1+4+9)));

vec_t<float> af(1,2,3);
printf("%f \r\n",af.norm()-sqrt(1*1+2*2+3*3));
printf("%f \r\n",vec_t<float>(1,2,3).norm()-sqrt(1*1+2*2+3*3));
printf("%f \r\n", (vec_t<float>(1,2,3)-aa).norm());
printf("%f \r\n", (aa-vec_t<float>(1,2,3)).norm());
printf("%f \r\n", (-vec_t<float>(1,2,3)+af).norm());
printf("%f \r\n", (vec_t<float>(1,2,3)*vec_t<float>(1,2,3)-(1+4+9)));
printf("%f \r\n",vec_t<int>(1,2,3).norm());

vec_t<float> ag(1,2,3);
vec_t<float> ah(3,2,1);
vec_t<float> ai = ag.cross(ah)-vec_t<float>(-4,8,-4);
vec_t<float> aj = ag%ah-vec_t<float>(-4,8,-4);
printf("%f %f\r\n",ai.norm(),aj.norm());
vec_t<float> ak = vec_t<float>(1,2,3).cross(vec_t<float>(3,2,1))-vec_t<float>(-4,8,-4);
printf("%f  \r\n",(vec_t<float>(1,2,3).cross(vec_t<float>(3,2,1))-vec_t<float>(-4,8,-4)).norm());

return 0;
}
