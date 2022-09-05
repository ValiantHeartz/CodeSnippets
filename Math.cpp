#include <bits/stdc++.h> 
using namespace std;

// 算法一：
// S=S1+S2其中S1=sqrt(p*(p-a)*(p-b)*(p-c)); p=(a+b+c)/2
// 算法二：向量点乘
// S=S1+S2其中S1为abs(行列式的值)/2.0
// |1  1  1 |
// |x1 x2 x3|
// |y1 y2 y3|

int main(){
    string str;
    getline(cin,str);
    vector<int> vecx; //存储所有x为数组，共四位，对于(1,1),(2,2),(1,3),(0,2)为 1,2,1,0
    vector<int> vecy; //存储所有y为数组，共四位，对于(1,1),(2,2),(1,3),(0,2)为 1,2,3,2
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == '('){
            i++;
            string tempx;
            string tempy;
            while(str[i]!=','){
                tempx+=str[i];
                i++;
            }
            i++;
            while(str[i]!=')'){
                tempy+=str[i];
                i++;
            }
            vecx.push_back(stoi(tempx));
            vecy.push_back(stoi(tempy));
        }
    }
    //对数组用公式
    float s1 = (vecx[0]*vecy[1] + vecx[1]*vecy[2] + vecx[2]*vecy[0] - vecx[0]*vecy[2] - vecx[1]*vecy[0] - vecx[2]*vecy[1]);
    float s2 = (vecx[0]*vecy[2] + vecx[2]*vecy[3] + vecx[3]*vecy[0] - vecx[0]*vecy[3] - vecx[2]*vecy[0] - vecx[3]*vecy[2]);
    cout<<(s1+s2)/2;
}

int helper(vector<int> vecx, vector<int> vecy){
    long s1 = (vecx[0]*vecy[1] + vecx[1]*vecy[2] + vecx[2]*vecy[0] - vecx[0]*vecy[2] - vecx[1]*vecy[0] - vecx[2]*vecy[1]);
    long s2 = (vecx[0]*vecy[2] + vecx[2]*vecy[3] + vecx[3]*vecy[0] - vecx[0]*vecy[3] - vecx[2]*vecy[0] - vecx[3]*vecy[2]);
    long res = (s1+s2)/2;
    return res;
}
//计算四边形面积

