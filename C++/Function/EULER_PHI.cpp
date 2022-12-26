class EULER_PHI
{
public:
    std::vector<int> phi_1_to_n(int n) {
        vector<int> phi(n + 1);
        for (int i = 0; i <= n; i++)
            phi[i] = i;

        for (int i = 2; i <= n; i++) {
            if (phi[i] == i) {
                for (int j = i; j <= n; j += i)
                    phi[j] -= phi[j] / i;
            }
        }
        return phi;
    }
    double phi(lld n) {
        prime_factor(n); //generate prime factorization of n
        double ans = 1.00;
        for (int i = 0; i < primefactor.size(); i++) {
            ans *= double(1.00 - (1 / (primefactor[i] * 1.00)));
        }
        return ans * n;
    }
};