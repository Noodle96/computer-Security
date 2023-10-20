#ifndef UTILS_H
#define UTILS_H
#include <bits/stdc++.h>
using namespace std;
bool my_cmp(pair<string, vector<char>> &a, pair<string, vector<char>> &b){
    int aPosition = a.first[1];
    int bPosition = b.first[1];
    return aPosition < bPosition;
}

#endif // UTILS_H
