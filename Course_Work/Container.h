#include "IlligalArraySizeException.h"
#include "IndexOutOfBoundException.h"

template<typename T> class Container
{
private:
    int c_length;
    T* c_data;

public:
    Container() : c_length(0), c_data(nullptr){}

    Container(int length) : c_length(length)
    {
        try
        {
            if (length <= 0)
                throw new IlligalArraySizeException(length);
        }
        catch (IlligalArraySizeException ex)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4);
            cout << "\t\t\t" << ex.what() << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
            system("pause");
        }
        if (length > 0)
            c_data = new T[length];
        else
            c_data = nullptr;
    }

    ~Container()
    {
        delete[] c_data;
    }

    T& operator[](int index)
    {
        try
        {
            if (index >= 0 && index <= c_length)
            {
                return c_data[index];
            }
            else
                throw new IndexOutOfBoundException(index);
        }
        catch (IndexOutOfBoundException ex)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4);
            cout << "\t\t\t" << ex.what() << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
            system("pause");
        }
    }
    void erase()
    {
        delete[] c_data;
        c_data = nullptr;
        c_length = 0;
    }
    void insertBefore(T value, int index)
    {
        try
        {
            if (index >= 0 && index <= c_length)
            {
                T* data = new T[c_length + 1];

                for (int before = 0; before < index; ++before)
                    data[before] = c_data[before];

                data[index] = value;

                for (int after = index; after < c_length; ++after)
                    data[after + 1] = c_data[after];
                delete[] c_data;
                c_data = data;
                ++c_length;
            }
            else
                throw new IndexOutOfBoundException(index);
        }
        catch (IndexOutOfBoundException ex)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4);
            cout << "\t\t\t" << ex.what() << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
            system("pause");
        }
    }
    void remove(int index)
    {
        try
        {
            if (index >= 0 && index <= c_length)
            {
                if (c_length == 1)
                {
                    erase();
                    return;
                }

                T* data = new T[c_length - 1];
                for (int before = 0; before < index; ++before)
                    data[before] = c_data[before];

                for (int after = index + 1; after < c_length; ++after)
                    data[after - 1] = c_data[after];

                delete[] c_data;
                c_data = data;
                --c_length;
            }
            else
                throw new IndexOutOfBoundException(index);
        }
        catch (IndexOutOfBoundException ex)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4);
            cout << "\t\t\t" << ex.what() << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
            system("pause");
        }
        
    }
    int size() { return c_length; }

    void add(T value) {
        insertBefore(value, c_length);
    }
};