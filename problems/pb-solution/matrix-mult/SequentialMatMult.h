
class SequentialMatMult
{
  public:
    static void naive(double* mA, double* mB, double* mC, int N)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    mC[i * N + j] += mA[i * N + k] * mB[k * N + j];
                }
            }
        }
    }

    static void forikj(double* mA, double* mB, double* mC, int N)
    {
        for (int i = 0; i < N; i++)
        {
            for (int k = 0; k < N; k++)
            {
                for (int j = 0; j < N; j++)
                {
                    mC[i * N + j] += mA[i * N + k] * mB[k * N + j];
                }
            }
        }
    }
};