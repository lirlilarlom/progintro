#include <iostream>

bool isNeg(int a, int b)
{
    return (a > 0 && b < 0) || (a < 0 && b > 0);
}

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

void simplify(int &a, int &b)
{
    int g = gcd(a, b);
    a /= g;
    b /= g;
}

int main()
{
    int N, n1, d1, n2, d2, n, d;
    char c;
    
    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        c = getchar();
        std::cin >> n1 >> d1 >> n2 >> d2;

        if (d1 == 0 || d2 == 0) std::cout << "error" << std::endl;

        switch (c)
        {
            case '+':
            n = n1 * d2 + n2 * d1;  
            d = d1 * d2;
            break;  

        case '-':
            n = n1 * d2 - n2 * d1;  
            d = d1 * d2;
            break;  

        case '*':
            n = n1 * n2;  
            d = d1 * d2;
            break;  

        case '/':
            if (n2 == 0)
            {
                std::cout << "error" << std::endl;
                continue;  
            } 
            n = n1 * d2;  
            d = n2 * d1;
            break;
        }

        if (isNeg(n, d)) std::cout << "-";

        n = std::abs(n);
        d = std::abs(d);

        simplify(n, d);
        std::cout << n / d << " " << n % d << " " << d << std::endl;
    }

    return 0;
}
