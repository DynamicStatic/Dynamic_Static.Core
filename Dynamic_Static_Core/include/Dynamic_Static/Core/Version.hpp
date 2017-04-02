
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

#include "Dynamic_Static/Core/Defines.hpp"
#include "Dynamic_Static/Core/IPrintable.hpp"

namespace Dynamic_Static {
    /**
     * Represents a Version number with major, minor, and patch fields.
     */
    struct Version final
        : public IPrintable {
    public:
        uint32_t major { 0 };
        uint32_t minor { 0 };
        uint32_t patch { 0 };

        /**
         * Constructs an instance of Version.
         */ 
        Version() = default;

        /**
         * Constructs an instance of Version with specified values for major, minor, and patch.
         * @param [in] major This Version's major value
         * @param [in] minor This Version's minor value
         * @param [in] patch This Version's patch value
         */
        Version(uint32_t major, uint32_t minor, uint32_t patch);

        /**
         * Gets a value indicating whether or not any field in this Version is non zero.
         * @return Whether or not any field in this Version is non zero
         */
        operator bool() const;

    public:
        /**
         * Gets the std::string representation of this Version.
         * @return The std::string representation of this Version
         */
        std::string to_string() const override;
    };
} // namespace Dynamic_Static

namespace Dynamic_Static {
    /**
     * Gets the current Dynamic_Static_Core Version.
     * @return The current Dynamic_Static_Core Version
     */
    const Version& current_version();
} // namespace Dynamic_Static
