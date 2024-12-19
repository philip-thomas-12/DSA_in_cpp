#include <iostream>
using namespace std;
struct n{
    int d;
    n*ne;
};
n*s=NULL;

void i_b(int v){
n*p=new n;
p->d=v;
p->ne=NULL;

if(s==NULL){
s=p;
}
}
void i_e(int v){
    n*p=new n;
p->d=v;
p->ne=NULL;
    n*a=s;
    while(a->ne!=NULL){
     a=a->ne;   
    }
    a->ne=p;
}

void i_af(int v){
    int k;
    cout<<"enter the key";
    
    cin>>k;
    n*p=new n;
p->d=v;
p->ne=NULL;
    n*a=s;
    while ( a->d != k) {
        a = a->ne;
    }
    p->ne=a->ne;
    a->ne=p;
}
void d_f(){
    n*a=s;
    s=a->ne;
    delete a;
}
void d_e(){
   n*a=s;
    while(a->ne!=NULL){
     a=a->ne;   
    }
    a->ne=NULL;
    delete a;
}
void dis(){
    n*a=s;
    while(a!=NULL){
        cout<<a->d<<endl;
        a=a->ne;
    }
}

int main(){
    i_b(19);
    dis();
    i_e(34);
    dis();
    i_af(23);
    dis();
    d_f();
    dis();
    d_e();
    dis();
    return 0;
}
