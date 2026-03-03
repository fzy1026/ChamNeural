
#include "../include/chammath.h"
using namespace std;



Matrix::Matrix()
{
    height = 0;
    width = 0;
}

Matrix::Matrix(int H, int W)
{
    height = H;
    width = W;
    data.resize(H);
    for (int i = 0; i < H; i++)
    {
        data[i].resize(W);
    }
}

void Matrix::SetZero()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            data[i][j] = 0;
        }
    }
}

void Matrix::SetIdentity()
{
    SetZero();
    for (int i = 0; i < min(height, width); i++)
    {
        data[i][i] = 1;
    }
}

bool Matrix::Set(int x, int y, double val)
{
    if (InRange(x, 1, height) && InRange(y, 1, width))
    {
        data[x-1][y-1] = val;
        return 1;
    }
    return 0;
}

double Matrix::Get(int x, int y)
{
    if (InRange(x, 1, height) && InRange(y, 1, width))
    {
        return data[x-1][y-1];
    }
    return 0;
}

Matrix Matrix::operator+(const Matrix &a) const
{
    if (height != a.height || width != a.width)
    {
        throw "Error: Matric size mismatch in addition.";
    }
    Matrix ans(height, width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ans.data[i][j] = data[i][j] + a.data[i][j];
        }
    }
    return ans;
}

Matrix Matrix::operator*(const Matrix &a) const
{
    if (width != a.height)
    {
        throw "Error: Matric size mismatch in multiplication.";
    }
    Matrix ans(height, a.width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < a.width; j++)
        {
            for (int k = 0; k < width; k++)
            {
                ans.data[i][j] += data[i][k] * a.data[k][j];
            }
        }
    }
    return ans;
}

Matrix Matrix::operator*(const double &a) const
{
    Matrix ans(height, width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ans.data[i][j] = data[i][j] * a;
        }
    }
    return ans;
}

Matrix Matrix::operator*(const float &a) const
{
    Matrix ans(height, width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ans.data[i][j] = data[i][j] * a;
        }
    }
    return ans;
}

Matrix Matrix::operator*(const int &a) const
{
    Matrix ans(height, width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ans.data[i][j] = data[i][j] * a;
        }
    }
    return ans;
}

Matrix Matrix::operator*(const long &a) const
{
    Matrix ans(height, width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ans.data[i][j] = data[i][j] * a;
        }
    }
    return ans;
}

Matrix Matrix::operator*(const long long &a) const
{
    Matrix ans(height, width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ans.data[i][j] = data[i][j] * a;
        }
    }
    return ans;
}

Matrix Matrix::operator/(const double &a) const
{
    Matrix ans(height, width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ans.data[i][j] = data[i][j] / a;
        }
    }
    return ans;
}

Matrix Matrix::operator/(const float &a) const
{
    Matrix ans(height, width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ans.data[i][j] = data[i][j] / a;
        }
    }
    return ans;
}

Matrix Matrix::operator/(const int &a) const
{
    Matrix ans(height, width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ans.data[i][j] = data[i][j] / a;
        }
    }
    return ans;
}

Matrix Matrix::operator/(const long &a) const
{
    Matrix ans(height, width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ans.data[i][j] = data[i][j] / a;
        }
    }
    return ans;
}

Matrix Matrix::operator/(const long long &a) const
{
    Matrix ans(height, width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ans.data[i][j] = data[i][j] / a;
        }
    }
    return ans;
}

Matrix Matrix::SubMatrix(int x, int y)
{
    if (height <= 1 || width <= 1 || !InRange(x, 0, height - 1) || !InRange(y, 0, width - 1))
    {
        throw "Error: Cannot get submatric.";
    }
    Matrix ans(height - 1, width - 1);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i < x && j < y)
            {
                ans.data[i][j] = data[i][j];
            }
            else if (i < x && j > y)
            {
                ans.data[i][j - 1] = data[i][j];
            }
            else if (i > x && j < y)
            {
                ans.data[i - 1][j] = data[i][j];
            }
            else if (i > x && j > y)
            {
                ans.data[i - 1][j - 1] = data[i][j];
            }
            else
            {
            }
        }
    }
    return ans;
}

double Matrix::Minor(int x, int y)
{
    Matrix sub = SubMatrix(x, y);
    return sub.Det();
}

double Matrix::Cofactor(int x, int y)
{
    double minor = Minor(x, y);
    if ((x + y) % 2 == 0)
        return minor;
    else
        return -minor;
}

Matrix Matrix::Transform()
{
    Matrix ans(width, height);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ans.data[j][i] = data[i][j];
        }
    }
    return ans;
}

double Matrix::Det()
{
    if (height != width)
    {
        throw "Error: Only square matric can calculate determinant.";
        return 0;
    }

    if (height == 1)
    {
        return data[0][0];
    }
    else if (height == 2)
    {
        return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    }
    else
    {
        double ans = 0;
        for (int j = 0; j < width; j++)
        {
            ans += data[0][j] * Cofactor(0, j);
        }
        return ans;
    }
}

Matrix Matrix::Adj()
{
    Matrix ans(height, width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ans.data[j][i] = Cofactor(i, j);
        }
    }
    return ans;
}

Matrix Matrix::Inverse()
{
    double determinant = Det();
    if (determinant == 0)
    {
        throw "Error: Singular matric has no inverse matric.";
    }
    Matrix adj = Adj();
    return adj / determinant;
}

Matrix Matrix::Link(const Matrix &a)
{
    if (height != a.height)
    {
        throw "Error: Matric size mismatch in linking.";
    }
    Matrix ans(height, width + a.width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ans.data[i][j] = data[i][j];
        }
        for (int j = 0; j < a.width; j++)
        {
            ans.data[i][j + width] = a.data[i][j];
        }
    }
    return ans;
}
void Matrix::SetSize(int H,int W)
{
    height = H;
    width = W;
    data.clear();
    data.resize(height, vector<double>(width, 0));
}

double Matrix::Height()
{
    return height;
}

double Matrix::Width()
{
    return width;
}


Matrix Vector(vector<double> v)
{
    Matrix ans(v.size(), 1);
    for (int i = 0; i < v.size(); i++)
    {
        ans.data[i][0] = v[i];
    }
    return ans;
}

Matrix Number(double x)
{
    Matrix ans(1, 1);
    ans.data[0][0] = x;
    return ans;
}

bool MatrixAddable(const Matrix &a, const Matrix &b)
{
    return (a.height == b.height) && (a.width == b.width);
}

bool MatrixMultipliable(const Matrix &a, const Matrix &b)
{
    return a.width == b.height;
}

int RAND()
{
	return rand() * RAND_MAX + rand();
}


//生成[min,max]范围内，步长为Div的随机数
double Rand(double Min, double Max, double Div)
{
	int nmin = floor(Min / Div);
	int nmax = floor(Max / Div);
	return double(RAND() % (nmax - nmin + 1) + nmin) * Div;
}


bool InRange(double x, double L, double R, bool HL, bool HR)
{
	if (L > R)
	{
        swap(L, R);
		swap(HL, HR);
	}

	bool ans = 1;

	if (HL)
		ans = ans && x >= L;
	else
		ans = ans && x > L;

	if (HR)
		ans = ans && x <= R;
	else
		ans = ans && x < R;

	return ans;
}

bool AngleIsInRange(double x, double L, double R, bool HL, bool HR)
{
	while(R < L)
		R += 2 * PI;
	while(R - L > 2*PI)
		R -= 2 * PI;
	while (x < L)
		x += 2 * PI;
	while(x - 2*PI > L)
		x -= 2 * PI;
	bool ans = 1;
	if(HL)
		ans = ans && x >= L;
	else
		ans = ans && x > L;
	if(HR)
		ans = ans && x <= R;
	else
		ans = ans && x < R;

	return ans;
}

bool Equal(double a, double b, double eps)
{
	return fabs(a - b) < eps;
}

bool Equal(float a, float b, float eps)
{
	return fabs(a - b) < eps;
}

bool EqualZero(double a, double eps)
{
	return fabs(a) < eps;
}

bool EqualZero(float a, float eps)
{
	return fabs(a) < eps;
}

bool AngleIntersects(double AStartAng,double AEndAng,double BStartAng,double BEndAng)//检测两个角是否有重合部分
{
    if(AStartAng > AEndAng)
        swap(AStartAng,AEndAng);
    if(BStartAng > BEndAng)
        swap(BStartAng,BEndAng);
    while(!InRange(AStartAng - BStartAng,0,2*PI,1,0))
    {
        if(BStartAng > AStartAng)
        {
            BStartAng-=2*PI;
            BEndAng -= 2*PI;
        }
        else
        {
            BStartAng += 2*PI;
            BEndAng += 2*PI;
        }
    }
    return InRange(BStartAng,AStartAng,AEndAng);
}

