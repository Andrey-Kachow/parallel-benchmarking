
class SequentialMatMult
{
  public:
    static void naive(std::vector<double>& mA, std::vector<double>& mB, std::vector<double>& mC,
                      int N)
    {
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                for (size_t k = 0; k < N; k++)
                {
                    mC[i * N + j] += mA[i * N + k] * mB[k * N + j];
                }
            }
        }
    }

    static void forikj(std::vector<double>& mA, std::vector<double>& mB, std::vector<double>& mC,
                       int N)
    {
        for (size_t i = 0; i < N; i++)
        {
            for (size_t k = 0; k < N; k++)
            {
                for (size_t j = 0; j < N; j++)
                {
                    mC[i * N + j] += mA[i * N + k] * mB[k * N + j];
                }
            }
        }
    }
};