
/*
==========================================
    Copyright (c) 2016 Dynamic_Static
    Licensed under the MIT license
    http://opensource.org/licenses/MIT
==========================================
*/

#pragma once

#include "Dynamic_Static/Core/Math/Defines.hpp"
#if defined(DYNAMIC_STATIC_DISABLE_MATH_BUILD)

#include "Dynamic_Static/Core/Defines.hpp"
#include "Dynamic_Static/Core/Math/Defines.hpp"

namespace Dynamic_Static {

    struct Color final
    {
        Color() = delete;
        static const glm::vec4 White;                /*!< { 1.0f,       1.0f,       1.0f,       1.0f } */
        static const glm::vec4 Black;                /*!< { 0.0f,       0.0f,       0.0f,       1.0f } */
        static const glm::vec4 Transparent;          /*!< { 0.0f,       0.0f,       0.0f,       0.0f } */
        static const glm::vec4 AliceBlue;            /*!< { 0.941177f,  0.972549f,  1.0f,       1.0f } */
        static const glm::vec4 AntiqueWhite;         /*!< { 0.980392f,  0.921569f,  0.843137f,  1.0f } */
        static const glm::vec4 Aqua;                 /*!< { 0.0f,       1.0f,       1.0f,       1.0f } */
        static const glm::vec4 Aquamarine;           /*!< { 0.498039f,  1.0f,       0.831373f,  1.0f } */
        static const glm::vec4 Azure;                /*!< { 0.941177f,  1.0f,       1.0f,       1.0f } */
        static const glm::vec4 Beige;                /*!< { 0.960784f,  0.960784f,  0.862745f,  1.0f } */
        static const glm::vec4 Bisque;               /*!< { 1.0f,       0.894118f,  0.768628f,  1.0f } */
        static const glm::vec4 BlanchedAlmond;       /*!< { 1.0f,       0.921569f,  0.803922f,  1.0f } */
        static const glm::vec4 Blue;                 /*!< { 0.0f,       0.0f,       1.0f,       1.0f } */
        static const glm::vec4 BlueViolet;           /*!< { 0.541176f,  0.168627f,  0.886275f,  1.0f } */
        static const glm::vec4 Brown;                /*!< { 0.647059f,  0.164706f,  0.164706f,  1.0f } */
        static const glm::vec4 BurlyWood;            /*!< { 0.870588f,  0.721569f,  0.529412f,  1.0f } */
        static const glm::vec4 CadetBlue;            /*!< { 0.372549f,  0.619608f,  0.627451f,  1.0f } */
        static const glm::vec4 Chartreuse;           /*!< { 0.498039f,  1.0f,       0.0f,       1.0f } */
        static const glm::vec4 Chocolate;            /*!< { 0.823529f,  0.411765f,  0.117647f,  1.0f } */
        static const glm::vec4 Coral;                /*!< { 1.0f,       0.498039f,  0.313726f,  1.0f } */
        static const glm::vec4 CornflowerBlue;       /*!< { 0.392157f,  0.584314f,  0.929412f,  1.0f } */
        static const glm::vec4 Cornsilk;             /*!< { 1.0f,       0.972549f,  0.862745f,  1.0f } */
        static const glm::vec4 Crimson;              /*!< { 0.862745f,  0.0784314f, 0.235294f,  1.0f } */
        static const glm::vec4 Cyan;                 /*!< { 0.0f,       1.0f,       1.0f,       1.0f } */
        static const glm::vec4 DarkBlue;             /*!< { 0.0f,       0.0f,       0.545098f,  1.0f } */
        static const glm::vec4 DarkCyan;             /*!< { 0.0f,       0.545098f,  0.545098f,  1.0f } */
        static const glm::vec4 DarkGoldenrod;        /*!< { 0.721569f,  0.52549f,   0.0431373f, 1.0f } */
        static const glm::vec4 DarkGray;             /*!< { 0.662745f,  0.662745f,  0.662745f,  1.0f } */
        static const glm::vec4 DarkGreen;            /*!< { 0.0f,       0.392157f,  0.0f,       1.0f } */
        static const glm::vec4 DarkKhaki;            /*!< { 0.741176f,  0.717647f,  0.419608f,  1.0f } */
        static const glm::vec4 DarkMagenta;          /*!< { 0.545098f,  0.0f,       0.545098f,  1.0f } */
        static const glm::vec4 DarkOliveGreen;       /*!< { 0.333333f,  0.419608f,  0.184314f,  1.0f } */
        static const glm::vec4 DarkOrange;           /*!< { 1.0f,       0.54902f,   0.0f,       1.0f } */
        static const glm::vec4 DarkOrchid;           /*!< { 0.6f,       0.196078f,  0.8f,       1.0f } */
        static const glm::vec4 DarkRed;              /*!< { 0.545098f,  0.0f,       0.0f,       1.0f } */
        static const glm::vec4 DarkSalmon;           /*!< { 0.913726f,  0.588235f,  0.478431f,  1.0f } */
        static const glm::vec4 DarkSeaGreen;         /*!< { 0.560784f,  0.737255f,  0.545098f,  1.0f } */
        static const glm::vec4 DarkSlateBlue;        /*!< { 0.282353f,  0.239216f,  0.545098f,  1.0f } */
        static const glm::vec4 DarkSlateGray;        /*!< { 0.184314f,  0.309804f,  0.309804f,  1.0f } */
        static const glm::vec4 DarkTurquoise;        /*!< { 0.0f,       0.807843f,  0.819608f,  1.0f } */
        static const glm::vec4 DarkViolet;           /*!< { 0.580392f,  0.0f,       0.827451f,  1.0f } */
        static const glm::vec4 DeepPink;             /*!< { 1.0f,       0.0784314f, 0.576471f,  1.0f } */
        static const glm::vec4 DeepSkyBlue;          /*!< { 0.0f,       0.74902f,   1.0f,       1.0f } */
        static const glm::vec4 DimGray;              /*!< { 0.411765f,  0.411765f,  0.411765f,  1.0f } */
        static const glm::vec4 DodgerBlue;           /*!< { 0.117647f,  0.564706f,  1.0f,       1.0f } */
        static const glm::vec4 Firebrick;            /*!< { 0.698039f,  0.133333f,  0.133333f,  1.0f } */
        static const glm::vec4 FloralWhite;          /*!< { 1.0f,       0.980392f,  0.941177f,  1.0f } */
        static const glm::vec4 ForestGreen;          /*!< { 0.133333f,  0.545098f,  0.133333f,  1.0f } */
        static const glm::vec4 Fuchsia;              /*!< { 1.0f,       0.0f,       1.0f,       1.0f } */
        static const glm::vec4 Gainsboro;            /*!< { 0.862745f,  0.862745f,  0.862745f,  1.0f } */
        static const glm::vec4 GhostWhite;           /*!< { 0.972549f,  0.972549f,  1.0f,       1.0f } */
        static const glm::vec4 Gold;                 /*!< { 1.0f,       0.843137f,  0.0f,       1.0f } */
        static const glm::vec4 Goldenrod;            /*!< { 0.854902f,  0.647059f,  0.12549f,   1.0f } */
        static const glm::vec4 Gray;                 /*!< { 0.501961f,  0.501961f,  0.501961f,  1.0f } */
        static const glm::vec4 Green;                /*!< { 0.0f,       1.0f,       0.0f,       1.0f } */
        static const glm::vec4 GreenYellow;          /*!< { 0.678431f,  1.0f,       0.184314f,  1.0f } */
        static const glm::vec4 Honeydew;             /*!< { 0.941177f,  1.0f,       0.941177f,  1.0f } */
        static const glm::vec4 HotPink;              /*!< { 1.0f,       0.411765f,  0.705882f,  1.0f } */
        static const glm::vec4 IndianRed;            /*!< { 0.803922f,  0.360784f,  0.360784f,  1.0f } */
        static const glm::vec4 Indigo;               /*!< { 0.294118f,  0.0f,       0.509804f,  1.0f } */
        static const glm::vec4 Ivory;                /*!< { 1.0f,       1.0f,       0.941177f,  1.0f } */
        static const glm::vec4 Khaki;                /*!< { 0.941177f,  0.901961f,  0.54902f,   1.0f } */
        static const glm::vec4 Lavender;             /*!< { 0.901961f,  0.901961f,  0.980392f,  1.0f } */
        static const glm::vec4 LavenderBlush;        /*!< { 1.0f,       0.941177f,  0.960784f,  1.0f } */
        static const glm::vec4 LawnGreen;            /*!< { 0.486275f,  0.988235f,  0.0f,       1.0f } */
        static const glm::vec4 LemonChiffon;         /*!< { 1.0f,       0.980392f,  0.803922f,  1.0f } */
        static const glm::vec4 LightBlue;            /*!< { 0.678431f,  0.847059f,  0.901961f,  1.0f } */
        static const glm::vec4 LightCoral;           /*!< { 0.941177f,  0.501961f,  0.501961f,  1.0f } */
        static const glm::vec4 LightCyan;            /*!< { 0.878431f,  1.0f,       1.0f,       1.0f } */
        static const glm::vec4 LightGoldenrodYellow; /*!< { 0.980392f,  0.980392f,  0.823529f,  1.0f } */
        static const glm::vec4 LightGray;            /*!< { 0.827451f,  0.827451f,  0.827451f,  1.0f } */
        static const glm::vec4 LightGreen;           /*!< { 0.564706f,  0.933333f,  0.564706f,  1.0f } */
        static const glm::vec4 LightPink;            /*!< { 1.0f,       0.713726f,  0.756863f,  1.0f } */
        static const glm::vec4 LightSalmon;          /*!< { 1.0f,       0.627451f,  0.478431f,  1.0f } */
        static const glm::vec4 LightSeaGreen;        /*!< { 0.12549f,   0.698039f,  0.666667f,  1.0f } */
        static const glm::vec4 LightSkyBlue;         /*!< { 0.529412f,  0.807843f,  0.980392f,  1.0f } */
        static const glm::vec4 LightSlateGray;       /*!< { 0.466667f,  0.533333f,  0.6f,       1.0f } */
        static const glm::vec4 LightSteelBlue;       /*!< { 0.690196f,  0.768628f,  0.870588f,  1.0f } */
        static const glm::vec4 LightYellow;          /*!< { 1.0f,       1.0f,       0.878431f,  1.0f } */
        static const glm::vec4 Lime;                 /*!< { 0.0f,       1.0f,       0.0f,       1.0f } */
        static const glm::vec4 LimeGreen;            /*!< { 0.196078f,  0.803922f,  0.196078f,  1.0f } */
        static const glm::vec4 Linen;                /*!< { 0.980392f,  0.941177f,  0.901961f,  1.0f } */
        static const glm::vec4 Magenta;              /*!< { 1.0f,       0.0f,       1.0f,       1.0f } */
        static const glm::vec4 Maroon;               /*!< { 0.501961f,  0.0f,       0.0f,       1.0f } */
        static const glm::vec4 MediumAquamarine;     /*!< { 0.4f,       0.803922f,  0.666667f,  1.0f } */
        static const glm::vec4 MediumBlue;           /*!< { 0.0f,       0.0f,       0.803922f,  1.0f } */
        static const glm::vec4 MediumOrchid;         /*!< { 0.729412f,  0.333333f,  0.827451f,  1.0f } */
        static const glm::vec4 MediumPurple;         /*!< { 0.576471f,  0.439216f,  0.858824f,  1.0f } */
        static const glm::vec4 MediumSeaGreen;       /*!< { 0.235294f,  0.701961f,  0.443137f,  1.0f } */
        static const glm::vec4 MediumSlateBlue;      /*!< { 0.482353f,  0.407843f,  0.933333f,  1.0f } */
        static const glm::vec4 MediumSpringGreen;    /*!< { 0.0f,       0.980392f,  0.603922f,  1.0f } */
        static const glm::vec4 MediumTurquoise;      /*!< { 0.282353f,  0.819608f,  0.8f,       1.0f } */
        static const glm::vec4 MediumVioletRed;      /*!< { 0.780392f,  0.0823529f, 0.521569f,  1.0f } */
        static const glm::vec4 MidnightBlue;         /*!< { 0.0980392f, 0.0980392f, 0.439216f,  1.0f } */
        static const glm::vec4 MintCream;            /*!< { 0.960784f,  1.0f,       0.980392f,  1.0f } */
        static const glm::vec4 MistyRose;            /*!< { 1.0f,       0.894118f,  0.882353f,  1.0f } */
        static const glm::vec4 Moccasin;             /*!< { 1.0f,       0.894118f,  0.709804f,  1.0f } */
        static const glm::vec4 NavajoWhite;          /*!< { 1.0f,       0.870588f,  0.678431f,  1.0f } */
        static const glm::vec4 Navy;                 /*!< { 0.0f,       0.0f,       0.501961f,  1.0f } */
        static const glm::vec4 OldLace;              /*!< { 0.992157f,  0.960784f,  0.901961f,  1.0f } */
        static const glm::vec4 Olive;                /*!< { 0.501961f,  0.501961f,  0.0f,       1.0f } */
        static const glm::vec4 OliveDrab;            /*!< { 0.419608f,  0.556863f,  0.137255f,  1.0f } */
        static const glm::vec4 Orange;               /*!< { 1.0f,       0.647059f,  0.0f,       1.0f } */
        static const glm::vec4 OrangeRed;            /*!< { 1.0f,       0.270588f,  0.0f,       1.0f } */
        static const glm::vec4 Orchid;               /*!< { 0.854902f,  0.439216f,  0.839216f,  1.0f } */
        static const glm::vec4 PaleGoldenrod;        /*!< { 0.933333f,  0.909804f,  0.666667f,  1.0f } */
        static const glm::vec4 PaleGreen;            /*!< { 0.596078f,  0.984314f,  0.596078f,  1.0f } */
        static const glm::vec4 PaleTurquoise;        /*!< { 0.686275f,  0.933333f,  0.933333f,  1.0f } */
        static const glm::vec4 PaleVioletRed;        /*!< { 0.858824f,  0.439216f,  0.576471f,  1.0f } */
        static const glm::vec4 PapayaWhip;           /*!< { 1.0f,       0.937255f,  0.835294f,  1.0f } */
        static const glm::vec4 PeachPuff;            /*!< { 1.0f,       0.854902f,  0.72549f,   1.0f } */
        static const glm::vec4 Peru;                 /*!< { 0.803922f,  0.521569f,  0.247059f,  1.0f } */
        static const glm::vec4 Pink;                 /*!< { 1.0f,       0.752941f,  0.796079f,  1.0f } */
        static const glm::vec4 Plum;                 /*!< { 0.866667f,  0.627451f,  0.866667f,  1.0f } */
        static const glm::vec4 PowderBlue;           /*!< { 0.690196f,  0.878431f,  0.901961f,  1.0f } */
        static const glm::vec4 Purple;               /*!< { 0.501961f,  0.0f,       0.501961f,  1.0f } */
        static const glm::vec4 Red;                  /*!< { 1.0f,       0.0f,       0.0f,       1.0f } */
        static const glm::vec4 RosyBrown;            /*!< { 0.737255f,  0.560784f,  0.560784f,  1.0f } */
        static const glm::vec4 RoyalBlue;            /*!< { 0.254902f,  0.411765f,  0.882353f,  1.0f } */
        static const glm::vec4 SaddleBrown;          /*!< { 0.545098f,  0.270588f,  0.0745098f, 1.0f } */
        static const glm::vec4 Salmon;               /*!< { 0.980392f,  0.501961f,  0.447059f,  1.0f } */
        static const glm::vec4 SandyBrown;           /*!< { 0.956863f,  0.643137f,  0.376471f,  1.0f } */
        static const glm::vec4 SeaGreen;             /*!< { 0.180392f,  0.545098f,  0.341176f,  1.0f } */
        static const glm::vec4 SeaShell;             /*!< { 1.0f,       0.960784f,  0.933333f,  1.0f } */
        static const glm::vec4 Sienna;               /*!< { 0.627451f,  0.321569f,  0.176471f,  1.0f } */
        static const glm::vec4 Silver;               /*!< { 0.752941f,  0.752941f,  0.752941f,  1.0f } */
        static const glm::vec4 SkyBlue;              /*!< { 0.529412f,  0.807843f,  0.921569f,  1.0f } */
        static const glm::vec4 SlateBlue;            /*!< { 0.415686f,  0.352941f,  0.803922f,  1.0f } */
        static const glm::vec4 SlateGray;            /*!< { 0.439216f,  0.501961f,  0.564706f,  1.0f } */
        static const glm::vec4 Snow;                 /*!< { 1.0f,       0.980392f,  0.980392f,  1.0f } */
        static const glm::vec4 SpringGreen;          /*!< { 0.0f,       1.0f,       0.498039f,  1.0f } */
        static const glm::vec4 SteelBlue;            /*!< { 0.27451f,   0.509804f,  0.705882f,  1.0f } */
        static const glm::vec4 Tan;                  /*!< { 0.823529f,  0.705882f,  0.54902f,   1.0f } */
        static const glm::vec4 Teal;                 /*!< { 0.0f,       0.501961f,  0.501961f,  1.0f } */
        static const glm::vec4 Thistle;              /*!< { 0.847059f,  0.74902f,   0.847059f,  1.0f } */
        static const glm::vec4 Tomato;               /*!< { 1.0f,       0.388235f,  0.278431f,  1.0f } */
        static const glm::vec4 Turquoise;            /*!< { 0.25098f,   0.878431f,  0.815686f,  1.0f } */
        static const glm::vec4 Violet;               /*!< { 0.933333f,  0.509804f,  0.933333f,  1.0f } */
        static const glm::vec4 Wheat;                /*!< { 0.960784f,  0.870588f,  0.701961f,  1.0f } */
        static const glm::vec4 WhiteSmoke;           /*!< { 0.960784f,  0.960784f,  0.960784f,  1.0f } */
        static const glm::vec4 Yellow;               /*!< { 1.0f,       1.0f,       0.0f,       1.0f } */
        static const glm::vec4 YellowGreen;          /*!< { 0.603922f,  0.803922f,  0.196078f,  1.0f } */
    };

} // namespace Dynamic_Static

#endif
