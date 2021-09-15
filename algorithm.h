template <typename T>
class Greater
{
public:
    bool compair(T a, T b)
    {
        return a > b;
    }
};

template <typename T>
class Less
{
public:
    bool compair(T a, T b)
    {
        return a < b;
    }
};