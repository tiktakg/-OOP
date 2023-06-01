#include <iostream>

#define showText(text) std::cout << std::endl << text << std::endl;
#define showLine std::cout << "--------------------------" << std::endl;
#define size 10

void showArr();
void copyArr();

void sortInsertion();
void sortGnomes();
void sortShell();
void sortHora();
void sortLSD();
void sortMSD();
void sortTimsort();

int arr[size];
int defaultArr[size] = { 1,8,3,7,4,15,5,-1,34,-6 };

int main()
{
    showArr();
    showLine
        sortInsertion();


    showArr();
    showLine
        sortGnomes();

    showArr();
    showLine
        sortShell();

    showArr();
    showLine
        sortHora();

    showArr();
    showLine
        sortLSD();

    showArr();
    showLine
        sortMSD();

    showArr();
    showLine
        sortTimsort();
    showArr();
    showLine

}

void copyArr()
{
    for (int i = 0; i < size; ++i)
        arr[i] = defaultArr[i];
}

void showArr()
{
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";

    std::cout << "\n";

}

void sortInsertion()
{
    copyArr();
    showText("Sort insertion")

        for (int i = 1; i < size; i++)
            for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) // пока j>0 и элемент j-1 > j, x-массив int
                std::swap(arr[j - 1], arr[j]);

    showArr();
    copyArr();
}

void sortGnomes()
{
    showText("Sort gnomes")

        int i = 0;
    while (i < size)
    {
        if (i == 0 || arr[i - 1] <= arr[i])
            ++i;
        else {
            int tmp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = tmp;
            --i;
        }
    }

    showArr();
    copyArr();
}

void sortShell()
{
    showText("Sort shell")

        int i, j, step;
    int tmp;
    for (step = size / 2; step > 0; step /= 2)
        for (i = step; i < size; i++)
        {
            tmp = arr[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < arr[j - step])
                    arr[j] = arr[j - step];
                else
                    break;
            }
            arr[j] = tmp;
        }

    showArr();
    copyArr();
}

void sortHora()
{
    showText("Sort hora");

    void hoarasort(int* a, int first, int last);
    hoarasort(arr, 0, size - 1);

    showArr();
    copyArr();
}

void sortLSD()
{
    showText("Sort LSD")

        showArr();
    copyArr();
}

void sortMSD()
{
    showText("Sort MSD")

        showArr();
    copyArr();
}

void sortTimsort()
{
    showText("Sort timsort")

        showArr();
    copyArr();
}

void hoarasort(int* a, int first, int last)
{

    int i = first, j = last;
    double tmp, x = a[(first + last) / 2];

    do
    {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;

        if (i <= j)
        {
            if (i < j)
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        hoarasort(a, i, last);
    if (first < j)
        hoarasort(a, first, j);
}