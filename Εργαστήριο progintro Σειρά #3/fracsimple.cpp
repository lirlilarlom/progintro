#include <iostream>

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
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

        int g = gcd(n, d);
        n /= g;
        d /= g;

        std::cout << n << " " << d << std::endl;
    }

    return 0;
}
