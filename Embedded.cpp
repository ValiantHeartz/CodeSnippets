#include <bits/stdc++.h>
using namespace std;

uint8_t str_cpy(char* src, char* dst){
   if(src == NULL || dst == NULL) return -1;
   while((*dst++=*src++) != '\0'); //*dsc=*src,返回*dsc
   return 0;
}

bool bigDuan(){
   short n = 1;
   if(*(char*)n == 1) return false;
   else return true; 
}
int main(){
   cout<<bigDuan();
}