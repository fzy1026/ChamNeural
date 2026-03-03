#ifndef CHAMNEURAL_H
#define CHAMNEURAL_H
#include "chammath.h"
#include <bits/stdc++.h>
using namespace std;

double QuadraticLoss(double ans,double output);// 二次损失函数
double CrossEntropyLoss(int ans,Matrix output);// 交叉熵损失函数
double HingeLoss(bool ans,double output);// Hinge损失函数
double Logistic(double x);// Logistic函数



#endif