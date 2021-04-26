# Практическая работа №3

Цель: научиться разрабатывать односзязные списки и функции действий над ними.

## Ход работы:
1. Разработать функции, реализующие некоторые действия над списками. Функции представлены в таблице 1;
2. Используя функции реализовать программу, которая выполняет некоторые действия, согласно заданию.

### 1. Разработка функций к работе;

Первоначально было проведено ознакомление с материалом по [односвязным спискам](https://rtfm.co.ua/c-svyazannye-spiski/). Далее была составлена таблица названий функций, необходимых для реализации в программе.
Таблица 1 - Функции для реализации

Тип данных | Название			 | Назначение функции|
--- | --- | ---|
void|init|инициализация пустого списка|
void|clean|удалить все элементы из списка|
bool|is_empty|проверка на пустоту списка|
int|find|поиск элемента по значению. вернуть NULL если эжемент не найден|
int|push_back|вставка значения в конец списка, вернуть 0 если успешно|
int|push_front|вставка значения в начало списка, вернуть 0 если успешно|
int|insert_after|вставка значения после указанного узла, вернуть 0 если успешно|
int|remove_node|удалить первый элемент из списка с указанным значением, вернуть 0 если успешно|
void|print|вывести все значения из списка в прямом порядке через пробел, после окончания вывода перейти на новую строку|

Далее был представлен код реализаций заданых функций из таблицы 1.

```
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct unit
{
    int value;
    struct unit *next;
} unit;

typedef struct list
{
    struct list *first;
} list;

//Инициализация пустого списка
void init(list *l)
{
    l->first = NULL;
}

// удалить все элементы из списка
void clean(list *l)
{
    unit *f;
    unit *part = l->first;
    while(part)
    {
        if (part == l)
        {
            if (f->next == NULL)
            {
                free(part);
            }
            l = part->next;
            free(part);
            part = l;
        }
        else
        {
            if (part->next != NULL)
            {
                f->next = part->next;
                free(part);
                part = f->next;
            }
            else
            {
                f->next = NULL;
                free(part);
            }
        }
        f = part;
        part = f->next;
    }
}

//Проверка на пустоту списка
bool is_empty(list *l)
{
    if(l->first == NULL)
    {
        //printf("Список пустой\n");
        return true;
    }
    else
    {
        //printf("Список содержит элемент(ы)\n");
        return false;
    }
}

//Поиск элемента списка. Вернуть NULL если элемент не найден
void find(list *l, int value)
{
    bool success = false;

    for(unit *f = l->first; f; f = f->next)
    {
        if(f->value == value)
        {
            printf("%d ", 1);
            success = true;
            break;
        }
    }

    if(success != true)
    {
        printf("%d ", 0);
    }
}

//Вставка значения в конец списка, вернуть 0 если успешно
int push_back(list *l, int value)
{
    unit *f;
    f = l->first;
    if (f == NULL)
    {
        l->first = value;
        f->next = NULL;
    }
    else
    {
        while (f->next != NULL)
        {
            f = f->next;
        }
        f->next = (unit*)malloc(sizeof(unit));
        f->next->value = value;
        f->next->next = NULL;
        return 0;
    }
}

//Вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int value)
{
    unit *f;
    f = (unit*)malloc(sizeof(unit));
    f->value = value;
    f->next = l->first;
    l->first = f;
    return 0;
}

//Вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(list *l, int value, int mesto)
{
    int i = 0;
    unit *f;
    f = (unit*)malloc(sizeof(unit));
    f->value = value;
    f->next = NULL;
    unit *f1 = l->first;
    for(i=1; i<mesto; i++)
    {
        if((f1->next == NULL) & (i<mesto))
        {
            return 1;
        }
        else
        {
            f1 = f1->next;
        }
    }
    if (mesto == 0)
    {
        f->next = l;
        l = f;
        return 0;
    }
    else
    {
        if (f1->next != NULL)
        {
            f->next = f1->next;
        }
        f1->next = f;
        return 0;
    }
}

//Удалить первый элемент из списка с указанным значением, вернуть 0 если успешно
int remove_node(list *l, int value)
{
    unit *f;
    unit *current = l->first;
    while(current)
    {
        if (current->value == value)
        {
            if (current == l->first)
            {
                if (current->next == NULL)
                {
                    free(current);
                    break;
                }
                else
                {
                    l->first = current->next;
                    free(current);
                    current = l->first;
                    break;
                }

            }
            else
            {
                if (current->next != NULL)
                {
                    f->next = current->next;
                    free(current);
                    current = f->next;
                    break;
                }
                else
                {
                    f->next = NULL;
                    free(current);
                    break;
                }
            }
        }
        f = current;
        current = f->next;
    }
    return 0;
}

//Вывод
void print(list *l)
{
    unit *f;
    f = l->first;
    while(f != NULL)
    {
        printf("%d ", f->value);
        f = f->next;
    }
    printf("\n");
}
```

### 2. Реализация программы с помощью разработанных функций

Далее представлено основное тело программы(main), в котором содержиться описание решения поставленной задачи, с помощью функций, реализованных в 1 пунке.

```
int main()
{
    int n = 0, a = 0, i = 0, k1 = 0, k2 = 0, k3 = 0, m=0, t=0, j=0, x=0, z=0;
    scanf("%d", &n);
    list l;

    init(&l);

    for(i=1; i<=n; i++)
    {
        scanf("%d", &a);
        if (is_empty(&l) == true)
        {
            push_front(&l, a);
        }
        else
        {
            push_back(&l, a);
        }
    }

    print(&l);

    scanf("%d", &k1);
    scanf("%d", &k2);
    scanf("%d", &k3);
    find(&l, k1);
    find(&l, k2);
    find(&l, k3);
    printf("\n");

    scanf("%d", &m);
    push_back(&l, m);
    print(&l);

    scanf("%d", &t);
    push_front(&l, t);
    print(&l);

    scanf("%d", &j);
    scanf("%d", &x);
    insert_after(&l, x, j);
    print(&l);

    scanf("%d", &z);
    remove_node(&l, z);
    print(&l);

    //clean
    //clean(&l);

    return 0;
}
```

Далее, на рисунке 1, был представлен пример работы программы.

![](/pr3/1.png)

Рисунок 1 - Пример работы программы

Вывод: в ходе выполнения практической работы были получены навыки работы с односвязными списками.
