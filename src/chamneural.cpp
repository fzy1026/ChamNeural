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