#ifndef CHAMNEURAL_H
#define CHAMNEURAL_H
#include "chammath.h"
#include <bits/stdc++.h>
using namespace std;

double QuadraticLoss(double ans,double output);// 二次损失函数
double CrossEntropyLoss(int ans,Matrix output);// 交叉熵损失函数
double HingeLoss(bool ans,double output);// Hinge损失函数
double Logistic(double x);// Logistic函数
double DLogistic(double x);// Logistic函数的导数
Matrix Softmax(Matrix x);// Softmax函数
Matrix Exp(Matrix x);// 矩阵的指数函数
Matrix Diag(Matrix x);// 将一个列向量变为对角矩阵或提取一个矩阵的对角线元素组成一个列向量
double LeakyReLU(double x,double gamma);// LeakyReLU函数



#endif