#include <bits/stdc++.h>
#include "include/chammath.h"
#include "include/chamneural.h"
using namespace std;

const int Size = 2;
vector<Matrix> X;      // 样本输入
vector<double> Y;      // 样本输出
const double a = 1; // 学习率
double N;              // 样本数量
const double T = 10000; // 迭代次数
Matrix w(Size+1, 1);   // 权重矩阵

void input()
{
    ifstream in;
    in.open("data.txt");
    cout << "Input positive samples num:";
    double posNum;
    in >> posNum;
    cout << posNum << endl;
    for (int i = 1; i <= posNum; i++)
    {
        X.push_back(Matrix(Size+1, 1));
        cout << "data:";
        for (int j = 1; j <= Size; j++)
        {
            in >> X[X.size() - 1].data[j-1][0];
            cout << X[X.size() - 1].data[j-1][0] << " ";
        }
        X[X.size() - 1].data[Size][0] = 1; // 添加偏置项
        Y.push_back(1);
    }
    cout << "Input negative samples num:";
    double negNum;
    in >> negNum;
    cout << negNum << endl;
    for (int i = 1; i <= negNum; i++)
    {
        X.push_back(Matrix(Size+1, 1));
        cout << "data:";
        for (int j = 1; j <= Size; j++)
        {
            in >> X[X.size() - 1].data[j-1][0];
            cout << X[X.size() - 1].data[j-1][0] << " ";
        }
        Y.push_back(0);
    }
    N = X.size();
}

void output()
{
    while (1)
    {
        cout << "input:";
        Matrix x(Size+1, 1);
        for (int j = 1; j <= Size; j++)
        {
            cin >> x.data[j-1][0];
        }
        x.data[Size][0] = 1; // 添加偏置项
        double output = (w.Transform() * x).Get(1, 1);
        cout << "output:" << Logistic(output) <<"("<< output <<")"<< endl;
    }
}

int main()
{
    input();
    Matrix sum(Size+1, 1);
    w.SetZero();
    for (int t = 1; t <= T; t++)
    {
        sum.SetZero();
        for (int i = 1; i <= N; i++)
        {
            try
            {
                //cout<<"Debug: "<<w.Transform().Height()<<" "<<w.Transform().Width()<<endl;
                //cout<<X[i-1].Height()<<" "<<X[i-1].Width()<<endl;
                sum = sum + X[i-1] * (Y[i-1] - Logistic((w.Transform() * X[i-1]).Get(1, 1)));
            }
            catch (const char *msg)
            {
                cout << msg << endl;
            }
        }
        sum = (sum * a) / N;
        w = w + sum;
        output();
        return 0;
    }
}