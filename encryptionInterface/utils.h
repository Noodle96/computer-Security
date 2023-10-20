#ifndef UTILS_H
#define UTILS_H
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<pair<char,int>, vector<char>> &a, pair<pair<char,int>, vector<char>> &b){
    int aPosition = a.first.second;
    int bPosition = b.first.second;
    return aPosition < bPosition;
}

#endif // UTILS_H
