#pragma once

template<size_t Dimensions>
class Vector {
    float data[Dimensions];
public:
    Vector() { for (size_t i = 0; i < Dimensions; i++) data[i] = 0; }
    Vector(float value) { for (size_t i = 0; i < Dimensions; i++) data[i] = value; }
    float  operator[] (size_t index) const { return data[index]; }
    float& operator[] (size_t index) { return data[index]; }

    Vector<Dimensions> operator+ (Vector<Dimensions> v)
    {
        Vector<Dimensions> Res;
        for (size_t i = 0; i < Dimensions; i++)
        {
            Res[i] = data[i] + v.data[i];
        }

        return Res;
    }

    Vector<Dimensions> operator- (Vector<Dimensions> v)
    {
        Vector<Dimensions> Res;
        for (size_t i = 0; i < Dimensions; i++)
        {
            Res[i] = data[i] - v.data[i];
        }

        return Res;
    }

    Vector<Dimensions> operator* (float n)
    {
        Vector<Dimensions> Res;
        for (size_t i = 0; i < Dimensions; i++)
        {
            Res[i] = data[i] * n;
        }

        return Res;
    }

    friend Vector<Dimensions> operator* (float n, Vector<Dimensions> v)
    {
        Vector<Dimensions> Res;
        for (size_t i = 0; i < Dimensions; i++)
        {
            Res[i] = v.data[i] * n;
        }

        return Res;
    }

    Vector<Dimensions> operator/ (float n)
    {
        Vector<Dimensions> Res;
        for (size_t i = 0; i < Dimensions; i++)
        {
            Res[i] = data[i] / n;
        }

        return Res;
    }

    friend Vector<Dimensions> operator/ (float n, Vector<Dimensions> v)
    {
        Vector<Dimensions> Res;
        for (size_t i = 0; i < Dimensions; i++)
        {
            Res[i] = v.data[i] / n;
        }

        return Res;
    }

    Vector<Dimensions> operator- ()
    {
        Vector<Dimensions> Res;
        for (size_t i = 0; i < Dimensions; i++)
        {
            Res[i] = -data[i];
        }

        return Res;
    }

    Vector<Dimensions> operator! ()
    {
        for (size_t i = 0; i < Dimensions; i++)
        {
            if (data[i] != 0)
            {
                Vector<Dimensions> Res;
                return Res;
            }
        }

        Vector<Dimensions> Res(1);
        return Res;
    }

    friend Vector<Dimensions> average_value(Vector<Dimensions> v1, Vector<Dimensions> v2)
    {
        Vector<Dimensions> Res;

        for (size_t i = 0; i < Dimensions; i++)
        {
            Res.data[i] = (v1.data[i] + v2.data[i]) / 2;
        }

        return Res;
    }


};