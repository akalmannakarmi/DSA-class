#include <stdio.h>
#include <conio.h>

typedef struct rational{
    int num;
    int denom;
} rational;

rational makeRational(int,int);
rational add(rational,rational);
rational multiply(rational,rational);
void equal(rational,rational);
void print(rational);

int main(){
    rational r1,r2,r3,r4;
    r1=makeRational(5,8);
    r2=makeRational(5,8);
    r3=add(r1,r2);
    r4=multiply(r1,r2);
    equal(r1,r2);
    printf("\nThe sum is %d/%d",r3.num,r3.denom);
    printf("\nThe product is %d/%d",r4.num,r4.denom);
    print(r4);
    getch();
    return 0;
}

rational makeRational(int a,int b){
    rational r;
    r.num=a;
    r.denom=b;
    return (r);
}
rational add(rational d,rational e){
    rational n;
    n.num=d.num*e.denom+e.num*d.denom;
    n.denom=d.denom*e.denom;
    return (n);
}
rational multiply(rational p,rational q){
    rational m;
    m.num=p.num*q.num;
    m.denom=p.denom*q.denom;
    return (m);
}
void equal(rational j,rational k){
    int l=j.num*k.denom;
    int z=k.num*j.denom;
    if(l==z){
        printf("\nNumbers are equal");
    }else{
        printf("\nNumbers are not equal");
    }
}
void print(rational result){
    printf("\nThe rational number is %d/%d",result.num,result.denom);
}