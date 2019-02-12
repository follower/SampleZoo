// Autogenerated by codegen.lua during premake process

#pragma once

namespace Samples
{
    namespace _1d
    {
        namespace Regular
        {
            inline void AutoTest(void)
            {
                // Regular
                {
                    std::vector<float> samples;
                    Regular(samples, 16);
                    FILE* file = fopen("output/samples/_1d/regular/Regular.txt", "w+b");
                    fprintf(file, "Regular %zu samples\r\n  Discrepancy: %0f\r\n  Wrap: %0f\r\n\r\n",
                        samples.size(),
                        Tests::_1d::Discrepancy::CalculateDiscrepancy(samples),
                        Tests::_1d::Discrepancy::CalculateDiscrepancyWrapAround(samples)
                    );
                    fclose(file);
                    Tests::_1d::Numberline::MakeNumberline("output/samples/_1d/regular/Regular.png", samples, 512);
                }
                // RegularCentered
                {
                    std::vector<float> samples;
                    RegularCentered(samples, 16);
                    FILE* file = fopen("output/samples/_1d/regular/RegularCentered.txt", "w+b");
                    fprintf(file, "RegularCentered %zu samples\r\n  Discrepancy: %0f\r\n  Wrap: %0f\r\n\r\n",
                        samples.size(),
                        Tests::_1d::Discrepancy::CalculateDiscrepancy(samples),
                        Tests::_1d::Discrepancy::CalculateDiscrepancyWrapAround(samples)
                    );
                    fclose(file);
                    Tests::_1d::Numberline::MakeNumberline("output/samples/_1d/regular/RegularCentered.png", samples, 512);
                }
                // RegularCenteredOffset
                {
                    std::vector<float> samples;
                    RegularCenteredOffset(samples, 16);
                    FILE* file = fopen("output/samples/_1d/regular/RegularCenteredOffset.txt", "w+b");
                    fprintf(file, "RegularCenteredOffset %zu samples\r\n  Discrepancy: %0f\r\n  Wrap: %0f\r\n\r\n",
                        samples.size(),
                        Tests::_1d::Discrepancy::CalculateDiscrepancy(samples),
                        Tests::_1d::Discrepancy::CalculateDiscrepancyWrapAround(samples)
                    );
                    fclose(file);
                    Tests::_1d::Numberline::MakeNumberline("output/samples/_1d/regular/RegularCenteredOffset.png", samples, 512);
                }
            }
        };
    };
};
