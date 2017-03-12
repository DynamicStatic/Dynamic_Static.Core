
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

#include "Dynamic_Static/Math/Defines.hpp"

#if defined(DYNAMIC_STATIC_VISUAL_STUDIO)
#pragma warning(push, 0)
#endif

#include <glm/glm.hpp>

#include <array>

namespace Dynamic_Static {
    namespace Math {
        /**
         * Representation of a 3D translation, rotation, and scale.
         */
        struct Matrix4x4 final {
        public:
            /**
             * Constant Matrix4x4
             *  [1, 0, 0, 0]
             *  [0, 1, 0, 0]
             *  [0, 0, 1, 0]
             *  [0, 0, 0, 1]
             */
            static const Matrix4x4 Identity;

        public:
            union {
                std::array<std::array<float, 4>, 4> values;
                struct {
                    float m00, m10, m20, m30;
                    float m01, m11, m21, m31;
                    float m02, m12, m22, m32;
                    float m03, m13, m23, m33;
                };
            };

            /**
             * Gets the std::string representation of this Matrix4x4.
             */
            inline std::string to_string() const
            {
                return "[TODO : Matrix4x4.to_string()]";
            }
        };

        static_assert(
            sizeof(Matrix4x4) == sizeof(float) * 16,
            "sizeof(Matrix4x4) must equal sizeof(float) * 16"
        );
    } // namespace Math
} // namespace Dynamic_Static

#if defined(DYNAMIC_STATIC_VISUAL_STUDIO)
#pragma warning(pop)
#endif
