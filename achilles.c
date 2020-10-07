#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define COMPUTATIONS 10000000
// 10^7 computations ~19secs @ pc's of dept.

int gcd(int a, int b) {
    if (b == 0) return a;
       return gcd(b, a%b);
}

bool prime_num(int x){
    if(x%3!=0){
        int y=5;
        while(y*y<=x){
            if( x%y==0 || x%(y+2)==0 ) return 0;
            y+=6;
        }
        return 1;
    }
    return 0;
}

bool powerful(int x){
    int p=0, p2=0, n=x;
    
    while(x%2==0 || x%3==0) {if(x%2==0) p++, x/=2; else p2++, x/=3;}

    if(p==1 || p2==1) return 0;

    for(int j=5; j*j<=n; j+=6){
    p=0, p2=0;

        if(x%j==0 || x%(j+2)==0){
            while(x%j==0) p++, x/=j;
            while(x%(j+2)==0) p2++, x/=j+2;
        }else continue;

        if(p==1 || p2==1) return 0;
    }

    if (x>1) return 0;

    return 1;
}

bool achilles(int x){
    int mkd=-1, p=0, p2=0, n=x;

    while(x%2==0 || x%3==0) if(x%2==0) p++, x/=2; else p2++, x/=3;
    if(p>1 && p2>1) mkd=gcd(p, p2);
    if(p>1 && p2<1) mkd=p;
    if(p<1 && p2>1) mkd=p2;

    for(int j=5; j*j<=n; j+=6){
    p=0, p2=0;
            
        if(x%j==0 || x%(j+2)==0){
            while(x%j==0) p++, x/=j;
            while(x%(j+2)==0) p2++, x/=j+2;
        }else continue;
    
        if(p>1 && p2>1){
            if(mkd==-1) mkd=gcd(p, p2);
            else mkd=gcd(mkd, p), mkd=gcd(mkd, p2); 
        }

        if(p>1 && p2<1){
            if(mkd!=-1) mkd=gcd(mkd, p); else mkd=p;
        }

        if(p<1 && p2>1){
            if(mkd!=-1) mkd=gcd(mkd, p2); else mkd=p2;
        }
    
    }

    if (x>1 || mkd!=1) return 0;

    return 1;
}

int main( void ){

int achillescounter=0;
long int t=time(NULL);
srand((unsigned int) t);

for(int i=1; i<=COMPUTATIONS; i++){
/*  unsigned int x=i, n=x, mkd=-1; (first part of exercise for checking consecutive numbers) */
    unsigned int y = rand(), z=rand();
    unsigned int x = ((y % 32768) + 1) * ((z % 32768) + 1) + 1, n=x, mkd=-1; 
    
    if(powerful(x) && achilles(x) && (!prime_num(x) || x%2==0))
        printf("%d is Achilles number\n", n), achillescounter++;
}

printf("Found %d Achilles out of %d tested numbers\n", achillescounter, COMPUTATIONS);

    return 0;
}
