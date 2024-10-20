#include "pch.h"

#include "matrix.hpp"
#include <SequentialMatMult.hpp>
#include <vector>
#include <memory>
#include <RowPartitionMatMult.hpp>

TEST(TestCaseName, TestName)
{
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

TEST(TestBasic5x5, TestMatrixMultiplication)
{
     int N = 5;
     std::vector<double> vM1 = {
         0, 0, 6, 0, 0, /**/
         0, 1, 0, 3, 0, /**/
         2, 0, 0, 0, 6, /**/
         0, 0, 2, 0, 0, /**/
         0, 7, 0, 2, 1  /**/
     };

     std::vector<double> vM2 = {
         6, 0, 0, 5, 0, /**/
         0, 7, 0, 0, 0, /**/
         0, 0, 1, 0, 4, /**/
         1, 0, 0, 3, 0, /**/
         0, 0, 5, 0, 0  /**/
     };

     std::vector<double> vM3_expected = {
         0,  0,  6,  0,  24, /**/
         3,  7,  0,  9,  0,  /**/
         12, 0,  30, 10, 0,  /**/
         0,  0,  2,  0,  8,  /**/
         2,  49, 5,  6,  0   /**/
     };

     auto m3 = generate_matrix(N, true);

     //SequentialMatMult::naive(vM1, vM2, *m3, N);
     //SequentialMatMult::forikj(vM1, vM2, *m3, N);
     RowPartitionMatMult::compute(vM1, vM2, *m3, N);
     
     for (int i = 0; i < N * N; i++)
     {
         EXPECT_EQ(vM3_expected[i], m3->at(i));
     }
 }