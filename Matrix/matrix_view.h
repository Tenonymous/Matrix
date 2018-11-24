//
//  matrix.h
//  Matrix
//
//  Created by Tobiasz Filar on 20/11/2018.
//  Copyright © 2018 Tobiasz Filar. All rights reserved.
//

#pragma once

//Header files here
#include <array>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <exception>

namespace mtrx
{
    using std::array;
    
    //iterator and range_class will be prepare
    template <typename T, size_t ROW, size_t COL>
    struct matrix_iterator;
    template <typename T, size_t ROW, size_t COL>
    struct matrix_range;
    
    template <typename T, size_t ROW, size_t COL>
    class matrix
    {
    public:
        constexpr matrix() noexcept
        {
            for (auto& row : matrix_view) {
                std::fill(std::begin(row), std::end(row), 0);
            }
        }
        constexpr matrix(T value) noexcept
        {
            for (auto& row : matrix_view) {
                std::fill(std::begin(row), std::end(row), value);
            }
        }
        
        matrix(matrix&&) = default;
        matrix& operator =(matrix&&) = default;
        
        matrix(const matrix&) = default;
        matrix& operator =(const matrix&) = default;
        
        
        constexpr array<T, COL>& operator[](size_t index)
        {
            if (index >= ROW)
                throw std::out_of_range("Out of range");
            return matrix_view[index];
        }
        
        constexpr const array<T, COL> operator[](size_t index) const
        {
            if (index >= ROW)
                throw std::out_of_range("Out of range");
            return matrix_view[index];
        }
        
        
        matrix<T, ROW, COL>& operator *=(T value)
        {
            *this = *this *value;
            return *this;
        }
        
        
        matrix<T, ROW, COL>& operator +=(matrix<T, ROW, COL> m)
        {
            *this = *this + m;
            return *this;
        }
        
        auto begin() const
        {
            return matrix_view.begin();
        }
        
        auto end() const
        {
            return matrix_view.end();
        }
        
        auto begin()
        {
            return matrix_view.begin();
        }
        
        auto end() {
            return matrix_view.end();
        }
        
        
    private:
        array<array<T, COL>, ROW> matrix_view;
        
    };
    
    template <typename T, size_t ROW, size_t COL>
    matrix<T, ROW, COL> operator +(matrix<T, ROW, COL> m1, matrix<T, ROW, COL> m2)
    {
        matrix<T, ROW, COL> temp;
        for (size_t row{0}; row != ROW; ++row) {
            for (size_t col{0}; col != COL; ++col) {
                temp[row][col] = m1[row][col] + m2[row][col];
            }
        }
        return temp;
    }
    
    
    template <typename T, size_t ROW, size_t COL>
    matrix<T, ROW, COL> operator *(matrix<T, ROW, COL> m, T value)
    {
        matrix<T, ROW, COL> matrix_copy = m;
        for (auto& row : matrix_copy) {
            std::transform(std::begin(row), std::end(row), std::begin(row), [=](auto elem) {
                return elem * value;
            });
        }
        
        return matrix_copy;
    }
    
    
    
    template <typename T, size_t ROW, size_t COL>
    matrix<T, ROW, COL> operator *(T value, matrix<T, ROW, COL> m)
    {
        return m * value;
    }
    
    template <typename T, size_t ROW, size_t COL>
    void show_mtr(matrix<T, ROW, COL> m)
    {
        for (auto row : m) {
            for (auto col : row)
                std::cout << col;
            std::cout << '\n';
        }
    }
    
    template <typename T, size_t ROW, size_t COL>
    std::ostream& operator <<(std::ostream& os, matrix<T, ROW, COL> m)
    {
        for (auto row : m) {
            for (auto col : row)
                os << col;
            os << '\n';
        }
        return os;
    }
    
    template <typename T, size_t ROW, size_t COL>
    std::istream& operator >>(std::istream& is, matrix<T, ROW, COL>& m)
    {
        for (auto& row : m) {
            for (auto& col : row) {
                is >> col;
            }
        }
        return is;
    }
    
}
