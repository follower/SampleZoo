// Autogenerated by codegen.lua during premake process

#pragma once

namespace Samples
{
    namespace _1d
    {
        namespace IrrationalNumbers
        {
            inline void AutoTest(void)
            {
                // GoldenRatio
                {
                    std::vector<float> samples;
                    GoldenRatio(samples, 16);
                }
                // Pi
                {
                    std::vector<float> samples;
                    Pi(samples, 16);
                }
                // Sqrt2
                {
                    std::vector<float> samples;
                    Sqrt2(samples, 16);
                }
            }
        };
    };
};
