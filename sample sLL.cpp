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
    a=p;
}

void i_af(int v){
    int k;
    cout<<"enter the key";
    
    cin>>k;
    n*p=new n;
p->d=v;
p->ne=NULL;
    n*a=s;
    while(a->ne->d!=k){
     a=a->ne;   
    }
    a=p;
    p->ne=a->ne;
}

int main(){
     i_b(19);
     i_e(34);
    return 0;
}
