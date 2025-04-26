#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

int main(){

int a[] = { 2,3,10,12,15,22 }; 
int size = 6; 
int m[1000]; 
int o[1000]; 
int num = 0; 
 
for(int i=0 ; i<size ; i++) 
{ 
 for(int j=5;j>1;j--) 
 {  
  int md = (int)pow(10.0,j*1.0); 
  int dv = (int)pow(10.0,(j-1)*1.0); 
  int t = (a[i]%md)/dv; 
  if(t > 0 ) 
  { 
   m[num] = t; 
   //cout<<m[num]<<endl; 
   num++;  
  } 
 } 
 m[num] = a[i] % 10; 
 //cout<<m[num]<<endl; 
 num++; 
 //cout<<"-------------"<<endl; 
} 
 
int l_index = 0; 
o[l_index] = m[0]; 
l_index++; 
cout<<m[0]; 
 
for(int i=1 ; i<num ; i++) 
{ 
 if( m[i] != o[l_index-1] ) 
 { 
  o[l_index] = m[i]; 
  l_index++; 
 } 
 cout<<m[i]; 
} 
cout<<endl; 
for(int i=0 ; i<l_index ; i++) 
{ 
 cout<<o[i]; 
} 
 
    return 0;
}
