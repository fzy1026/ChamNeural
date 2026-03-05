#include "../include/chamneural.h"
using namespace std;

double QuadraticLoss(double ans, double output)
{
    return 0.5 * (ans - output) * (ans - output);
}

double CrossEntropyLoss(int ans, Matrix output)
{
    return 0-log(output.Get(1,ans));
}

double HingeLoss(bool ans, double output)
{
    return max(0.0, 1-ans*output);
}

double Logistic(double x)
{
    return 1/(1+exp(-x));
}

double DLogistic(double x)
{
    double logistic = Logistic(x);
    return logistic * (1-logistic);
}

Matrix Exp(Matrix x)
{
    Matrix ans(x.height, x.width);
    for (int i = 0; i < x.height; i++)
    {
        for (int j = 0; j < x.width; j++)
        {
            ans.data[i][j] = exp(x.data[i][j]);
        }
    }
    return ans;
}

Matrix Softmax(Matrix x)
{
    if(x.width != 1)
    {
        throw "Error: Softmax function only accepts column vector.";
    }
    Matrix One = Vector(vector<double>(x.height, 1));
    return Exp(x)*(One*Exp(x)).Inverse();
}

Matrix Diag(Matrix x)
{
    if(x.width != 1)
    {
        if(x.height != x.width)
        {
            throw "Error: Diag function only accepts column vector or square matrix.";
        }
        else
        {
            Matrix ans(x.height, 1);
            for (int i = 0; i < x.height; i++)
            {
                ans.data[i][0] = x.data[i][i];
            }
            return ans;
        }
    }
    else
    {
        Matrix ans(x.height, x.height);
        ans.SetZero();
        for (int i = 0; i < x.height; i++)
        {
            ans.data[i][i] = x.data[i][0];
        }
        return ans;
    }
}

double LeakyReLU(double x, double gamma = 0.01)
{
    return (x > 0) ? x : gamma * x;
}