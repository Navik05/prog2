#define _CRT_SECURE_NO_WARNINGS
#define N 3
#include <iostream>

class figure
{
    float area;
    float perimeter;
    figure();
    ~figure();
};
//Конструктор
figure::figure()
{
    area = 0;
    perimeter = 0;
}
//Деструктор
figure::~figure()
{

}
//<---квадрат--->
class square :public figure
{
    float a;
    float diagonal;
public:
    void set_a(float e);
};
//Ввод стороны
void square::set_a(float e)
{
    a = e;
}
//<---круг--->
class circle :public figure
{
    float r;
    float d;
public:
    void set_r(float e);
};
//Ввод радиуса
void circle::set_r(float e)
{
    r = e;
}
//<---треугольник--->
class triangle :public figure
{
    float sides[N];
    int view;
public:
    void set_sides(float e[]);
};
//Ввод сторон
void triangle::set_sides(float e[])
{
    for (int i = 0; i < N; i++)
        sides[i] = e[i];
}



int block_int(int min, int max);
float block_float();
//void input(int type, float sides[]);
//void work();
//void output();

int main()
{
    int type, min, max, i;
    float e[N];
    square* one;
    circle* two;
    triangle* three;
    setlocale(LC_ALL, "Rus");
    printf("\n1-квадрат\n2-круг\n3-треугольник\nВыберите фигуру:");
    min = 1; max = 3;
    type = block_int(min, max);
    switch (type)
    {
    case 1:
        printf("Длина стороны квадрата:");
        one = (square*)malloc(sizeof(square));
        e[0] = block_float();
        one->set_a(e[0]);
        break;
    case 2:
        printf("Радиус круга:");
        two = (circle*)malloc(sizeof(circle));
        e[0] = block_float();
        two->set_r(e[0]);
        break;
    case 3:
        printf("Длина сторон треугольника:");
        three = (triangle*)malloc(sizeof(triangle));
        for (i = 0; i < 3; i++)
        {
            e[i] = block_float();
        }
        three->set_sides(e);
        break;
    default:;
    }
    type = 1;
    //work();
    //output();
}
//Защита на целые числа
int block_int(int min, int max)
{
    int type, f = 1;
    do {
        if (f != 1)
        {
            printf("Такого варианта нет. Попробуйте ещё раз: ");
        }
        while (scanf("%d", &type) != 1)
        {
            while (getchar() != '\n');
            printf("Ошибка. Попробуйте ещё раз: ");
        }
        f = 0;
        while (getchar() != '\n');
    } while (type<min || type>max);
    printf("\n");
    return type;
}
//Защита на дробные числа
float block_float()
{
    int f = 1;
    float e;
    do {
        if (f != 1)
        {
            printf("Такого варианта нет. Попробуйте ещё раз: ");
        }
        while (scanf("%f", &e) != 1)
        {
            while (getchar() != '\n');
            printf("Ошибка. Попробуйте ещё раз: ");
        }
        f = 0;
        while (getchar() != '\n');
    } while (e <= 0);
    printf("\n");
    return e;
}
//Ввод в структуру
//void input(int type, float sides[])
//{
//    int i = 0;
//    if (g == 0)
//    {
//        example.type = type;
//        switch (type)
//        {
//        case 1:
//            example.figure.square.a = sides[i];
//            break;
//        case 2:
//            example.figure.circle.r = sides[i];
//            break;
//        case 3:
//            for (; i < 3; i++)
//            {
//                example.figure.triangle.sides[i] = sides[i];
//            }
//            break;
//        default:;
//        }
//    }
//    else
//    {
//        (*second).type = type;
//        switch (type)
//        {
//        case 1:
//            (*second).figure.square.a = sides[i];
//            break;
//        case 2:
//            (*second).figure.circle.r = sides[i];
//            break;
//        case 3:
//            for (; i < 3; i++)
//            {
//                (*second).figure.triangle.sides[i] = sides[i];
//            }
//            break;
//        default:;
//        }
//    }
//}
//Обработка данных
//void work()
//{
//    float s, p, a[N], p2;
//    if (g == 0)
//    {
//        switch (example.type)
//        {
//        case 1:
//            a[0] = example.figure.square.a;
//            example.figure.square.diagonal = sqrtf(2) * a[0];
//            s = powf(a[0], 2);
//            p = a[0] * 4;
//            break;
//        case 2:
//            a[0] = example.figure.circle.r;
//            example.figure.circle.d = a[0] * 2;
//            s = 3.14 * pow(a[0], 2);
//            p = 3.14 * 2 * a[0];
//            break;
//        case 3:
//            for (int i = 0; i < 3; i++)
//            {
//                a[i] = example.figure.triangle.sides[i];
//            }
//            p = a[0] + a[1] + a[2];
//            p2 = p / 2;
//            s = sqrtf(p2 * (p2 - a[0]) * (p2 - a[1]) * (p2 - a[2]));
//            if (a[0] == a[1] && a[1] == a[2])
//                example.figure.triangle.view = 1;
//            else if (a[0] == a[1] || a[1] == a[2])
//                example.figure.triangle.view = 2;
//            else example.figure.triangle.view = 3;
//            break;
//        default:;
//        }
//        example.area = s;
//        example.perimeter = p;
//    }
//    else
//    {
//        switch ((*second).type)
//        {
//        case 1:
//            a[0] = (*second).figure.square.a;
//            (*second).figure.square.diagonal = sqrtf(2) * a[0];
//            s = powf(a[0], 2);
//            p = a[0] * 4;
//            break;
//        case 2:
//            a[0] = (*second).figure.circle.r;
//            (*second).figure.circle.d = a[0] * 2;
//            s = 3.14 * pow(a[0], 2);
//            p = 3.14 * 2 * a[0];
//            break;
//        case 3:
//            for (int i = 0; i < 3; i++)
//            {
//                a[i] = (*second).figure.triangle.sides[i];
//            }
//            p = a[0] + a[1] + a[2];
//            p2 = p / 2;
//            s = sqrtf(p2 * (p2 - a[0]) * (p2 - a[1]) * (p2 - a[2]));
//            if (a[0] == a[1] && a[1] == a[2])
//                (*second).figure.triangle.view = 1;
//            else if (a[0] == a[1] || a[1] == a[2])
//                (*second).figure.triangle.view = 2;
//            else (*second).figure.triangle.view = 3;
//            break;
//        default:;
//        }
//        (*second).area = s;
//        (*second).perimeter = p;
//    }
//}
////Вывод структуры
//void output()
//{
//    printf("Фигура: ");
//    if (g == 0)
//    {
//        switch (example.type)
//        {
//        case 1:
//            printf("квадрат");
//            printf("\nДиагональ: %f", example.figure.square.diagonal);
//            break;
//        case 2:
//            printf("круг");
//            printf("\nДиаметр: %f", example.figure.circle.d);
//            break;
//        case 3:
//            switch (example.figure.triangle.view)
//            {
//            case 1:
//                printf("равносторонний ");
//                break;
//            case 2:
//                printf("равнобедренный ");
//                break;
//            case 3:
//                printf("разносторонний ");
//                break;
//            default:;
//            }
//            printf("треугольник");
//            break;
//        default:;
//        }
//        printf("\nПлощадь: %f", example.area);
//        printf("\nПериметр: %f\n", example.perimeter);
//    }
//    else
//    {
//        switch ((*second).type)
//        {
//        case 1:
//            printf("квадрат");
//            printf("\nДиагональ: %f", (*second).figure.square.diagonal);
//            break;
//        case 2:
//            printf("круг");
//            printf("\nДиаметр: %f", (*second).figure.circle.d);
//            break;
//        case 3:
//            switch ((*second).figure.triangle.view)
//            {
//            case 1:
//                printf("равносторонний ");
//                break;
//            case 2:
//                printf("равнобедренный ");
//                break;
//            case 3:
//                printf("разносторонний ");
//                break;
//            default:;
//            }
//            printf("треугольник");
//            break;
//        default:;
//        }
//        printf("\nПлощадь: %f", (*second).area);
//        printf("\nПериметр: %f\n", (*second).perimeter);
//    }
//}