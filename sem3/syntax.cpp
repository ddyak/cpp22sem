bool SortByName....

int main() {
    int mode;
    std::cin >> mode; // 0..10

    switch (type) {
        case 0:
            1+1;
            break;
        case 1:
            2+2;
            break;
        case 2:
        case 3:
        case 4:
            3+3;
            break;
        default:
            0/0;
            break;
    };

    enum type;

    auto f = [](double x) { return x*x; };
    std::cout << f(x) << std::endl;

    std::sort(a.begin(), a.end(), [&](const Student& lhs, const Student& rhs)
            {
                if (type == Type::Date) {
                    return lhs.date < rhs.date;
                }
                return lhs.name < rhs.name;
            }
    );
}

