#include <iostream>

using namespace std;
/*
//Проверка числа на четность используя его представление в двоичной системе счисления
bool IsEven(int num) {
    int is_even;

    __asm {
        mov eax, num
        and eax, 1
        cmp eax, 0
        je label
        mov edx, 0
        jmp finish
    label:
        mov edx, 1
    finish:
         mov is_even, edx
    }

    return is_even;
}
*/

/*
//Проверка числа на четность делением
bool IsEven_(int num) {
    int is_even;

    __asm {
        mov eax, num
        mov ebx, 2
        cdq
        idiv ebx
        mov ebx, 0
        cmp edx, ebx
        je if1
        mov edx, 0
        jmp finish
     if1:
        mov edx, 1
     finish:
        mov is_even, edx
    }

    return is_even;
}
*/

/*
//Сумма чисел от 1 до N
int Sum1N(int num) {
    int sum = 0;

    __asm {
        mov edx, 0
        mov eax, num
     for_label:
        add edx, eax
        sub eax, 1
        cmp eax, 0
        jne for_label
        mov sum, edx
    }

    return sum;
}
*/

/*
//Сумма элементов массива
int Sum(int* array, int num) {
    int sum = 0;

    __asm {
        mov edx, 0
        mov ecx, num
        mov esi, array
     for_label:
        add edx, [esi]
        add esi, 4
        loop for_label
        mov sum, edx
    }

    return sum;
}
*/

//Сумма элементов массива <= 10
int SumLessTen(int* array, int num) {
    int sum = 0;

    __asm {
        mov esi, array
        mov eax, 0
        mov ecx, num
        for_label :
        cmp[esi], 10
            jge skip_element
            add eax, [esi]
            skip_element :
            add esi, 4
            loop for_label
            mov sum, eax
    }

    return sum;
}

//Реверс массива
void ReverseArray(int* array, int num) {
    _asm {
        mov esi, array
        mov ecx, 0
        mov edi, num
        sub edi, 1
        for_label:
        cmp ecx, edi
            je finish
            mov eax, [esi + 4 * ecx]
            mov ebx, [esi + 4 * edi]
            mov[esi + 4 * ecx], ebx
            mov[esi + 4 * edi], eax
            add ecx, 1
            sub edi, 1
            mov eax, 0
            jmp for_label
            finish :
        nop
    }
}

//Проверка числа на простоту
bool IsPrime(int num) {
    int is_prime = 0;

    _asm {
        mov eax, num
        mov ebx, 2
        for_label:
        cdq
            idiv ebx
            cmp edx, 0
            je check
            cmp ebx, num
            jge prime
            add ebx, 1
            mov eax, num
            jmp for_label
            check :
        cmp ebx, num
            je prime
            one1 :
        mov ecx, 0
            mov is_prime, ecx
            jmp finish
            prime :
        mov eax, num
            cmp eax, 1
            je one1
            mov ecx, 1
            mov is_prime, ecx
            finish :
        nop
    }

    return is_prime;
}

//Проверка числа на совершенство
bool IsPerfect(int num) {
    int is_perfect = 0;

    __asm {
        mov ecx, num
        sub ecx, 1
        mov ebx, 0
        for_label:
        mov eax, num
            mov edx, 0
            idiv ecx
            cmp edx, 0
            jne check
            add ebx, ecx
            check :
        loop for_label
            mov eax, num
            mov is_perfect, 0
            cmp eax, ebx
            jne finish
            mov is_perfect, 1
            finish:
        nop
    }

    return is_perfect;
}

int main() {
    int* array = new int[5];

    for (int i = 0; i < 5; ++i) {
        array[i] = rand() % 20;
    }

    cout << "Array: ";
    for (int i = 0; i < 5; ++i) {
        cout << array[i] << ' ';
    }

    cout << endl;

    //Сумма элементов массива <= 10
    cout << "SumLessTen: " << SumLessTen(array, 5) << endl;


    //Проверка числа на простоту
    int is_prime;
    cout << "Enter a number to test for primality: ";
    cin >> is_prime;
    if (IsPrime(is_prime)) {
        cout << is_prime << ' ' << "is prime" << endl;
    }
    else {
        cout << is_prime << ' ' << "is not prime" << endl;
    }

    cout << endl;

    //Проверка числан на совершенство
    int is_perfect;
    cout << "Enter a number to test for perfection: ";
    cin >> is_perfect;
    if (IsPerfect(is_perfect)) {
        cout << is_perfect << ' ' << "is perfect" << endl;
    }
    else {
        cout << is_perfect << ' ' << "is not perfect" << endl;
    }

    cout << endl;

    //Реверс массива
    cout << "Array before using Reverse: ";
    for (int i = 0; i < 5; ++i) {
        cout << array[i] << ' ';
    }
    cout << endl;

    ReverseArray(array, 5);

    cout << "Array after using Reverse: ";
    for (int i = 0; i < 5; ++i) {
        cout << array[i] << ' ';
    }
    return 0;
}