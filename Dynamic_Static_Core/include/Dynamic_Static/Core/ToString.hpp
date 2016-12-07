
/*
=====================================================================================

    The MIT License(MIT)

    Copyright(c) 2016 to this->moment()->next() Dynamic_Static

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files(the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions :

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.

=====================================================================================
*/

#pragma once

#include "Dynamic_Static/Core/ToString.hpp"

#include <string>

namespace Dynamic_Static {
    /**
     * Gets the specified object's std::string representation.
     * @param [in] value The object to get the std::string representation of
     * @return The specified object's std::string representation
     */
    template <typename T>
    std::string to_string(const T& value)
    {
        return std::to_string(value);
    }

    /**
     * Gets the specified object's std::wstring representation.
     * @param [in] value The object to get the std::wstring representation of
     * @return The specified object's std::wstring representation
     */
    template <typename T>
    std::wstring to_wstring(const T& value)
    {
        return std::to_wstring(value);
    }

    /**
     * Gets the specified std::wstring's std::string representation.
     * NOTE : If the specified std::wstring contains characters that cannot be contained in an std::string the returned std::string may be incorrect
     * @param [in] wstr The std::wstring to get the std::string representation of
     * @return The specified std::wstring's std::string representation
     */
    template <>
    std::string to_string<std::wstring>(const std::wstring& wstr);

    /**
     * Gets the specified std::string's std::wstring representation.
     * @param [in] str The std::string to get the std::wstring representation of
     * @return The specified std::string's std::wstring representation
     */
    template <>
    std::wstring to_wstring<std::string>(const std::string& str);
}
