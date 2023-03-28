#include "SimpleVector.h"
#include <exception>
#include <fstream>

SimpleVector& SimpleVector::operator+(const SimpleVector& other)
{
    if (size != other.size)
    {
        throw std::exception();
    }

    for (size_t i = 0; i < size; i++)
    {
        data[i] += other.data[i];
    }
    return *this;
}

SimpleVector& SimpleVector::operator-(const SimpleVector& other)
{
    if (size != other.size)
    {
        throw std::exception();
    }

    for (size_t i = 0; i < size; i++)
    {
        data[i] -= other.data[i];
    }
    return *this;
}

SimpleVector& SimpleVector::operator*(const SimpleVector& other)
{
    if (size != other.size)
    {
        throw std::exception();
    }

    for (size_t i = 0; i < size; i++)
    {
        data[i] *= other.data[i];
    }
    return *this;
}

SimpleVector& SimpleVector::operator/(const SimpleVector& other)
{
    if (size != other.size)
    {
        throw std::exception();
    }

    for (size_t i = 0; i < size; i++)
    {
        data[i] /= other.data[i];
    }
    return *this;
}

void SimpleVector::readBinaryFile()
{
    std::ifstream in_file;
    in_file.open("vector.bin", std::ios::in | std::ios::binary);
    if (!in_file.is_open())
    {
        std::cerr << "File was not found";
        return;
    }

    in_file.read((char*)this, sizeof(*this));
    in_file.close();
}

void SimpleVector::writeBinaryFile()
{
    std::ofstream out_file;
    out_file.open("vector.bin", std::ios::out | std::ios::binary);
    if (!out_file.is_open())
    {
        std::cerr << "File was not found";
        return;
    }

    out_file.write((char*)this, sizeof(*this));
    out_file.close();
}

void SimpleVector::readTextFile()
{
    std::ifstream in_file;
    in_file.open("vector.txt", std::ios::in);
    if (!in_file.is_open())
    {
        std::cerr << "File was not found";
        return;
    }

    in_file >> *this;
    in_file.close();
}

void SimpleVector::writeTextFile()
{
    std::ofstream in_file;
    in_file.open("vector.txt", std::ios::out);
    if (!in_file.is_open())
    {
        std::cerr << "File was not found";
        return;
    }

    in_file << *this;
    in_file.close();
}

std::ostream& operator<<(std::ostream& os, SimpleVector& other)
{
    for (size_t i = 0; i < other.size; i++)
    {
        os << other.data[i] << " ";
    }
    os << other.size;
    os << '\n';
    return os;
}

std::istream& operator>>(std::istream& is, SimpleVector& other)
{
    for (size_t i = 0; i < other.size; i++)
    {
        is >> other.data[i];

    }is >> other.size;
    return is;
}
