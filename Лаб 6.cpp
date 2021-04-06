// Лаб 6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<fstream>
#include<Windows.h>

struct Disciplina {
    std::string predmet;
    int ocenka;
};
struct Student {
    std::string FIO;
    int kol;
    std::vector<Disciplina> dis;
};

void baza(std::vector<Student>& z) {

    for (int i = 0; i < z.size(); i++) {
        std::string fio,fam,imia,otch;
        std::cout << "Введите Фамилию:";
        std::cin >> fam;
        std::cout << std::endl;
        std::cout << "Введите Имя:";
        std::cin >> imia;
        std::cout << std::endl;
        std::cout << "Введите Отчество:";
        std::cin >> otch;
        std::cout << std::endl;
        fio = fam +' '+ imia+ ' ' + otch;
        z[i].FIO = fio;
        std::cout<<std::endl;
        std::cout << "Введите кольво экзаменов" << std::endl;
        int q;
        std::cin >> q;
        z[i].kol = q;
        for (int t = 0; t < q; t++) {
            int o;
            Disciplina a1;
            z[i].dis.push_back(a1);
            std::string str;
            std::cout << "Введите предмет" << std::endl;
            std::cin >> str;
            z[i].dis[t].predmet = str;
            std::cout << std::endl;
            std::cout << "Введите оценку" << std::endl;
            std::cin >> o;
            z[i].dis[t].ocenka = o;
            std::cout << std::endl;
        }
    }
}
void SortFIO(std::vector<Student>& students) {
    for (size_t i = 0; i < students.size(); i++) {
        for (size_t j = 0; j < students.size() - 1; j++) {
            if (students[j].FIO >= students[j + 1].FIO) {
                std::swap(students[j], students[j + 1]);
            }
        }
    }
}
int Otlichnik(const std::vector<Student>& students) {
    int s;
    s = 0;
    for (size_t i = 0; i < students.size(); i++) {
        size_t k = 0;
        for (size_t j = 0; j < students.size() - 1; j++) {
            if (students[i].dis[j].ocenka == 5) {
                k++;
            }
        }
         if (k==students[i].kol) {
                s++;
            }
        }
    return s;
}

std::ostream& operator<<(std::ofstream& of, const std::vector<Student>& a)
{
    for (int i = 0; i < a.size(); i++) {
        for (int t = 0; t < a[i].dis.size(); t++) {
            of << a[i].dis[t].ocenka << std::endl;
            of << a[i].dis[t].predmet << std::endl;
        }
    }
    return of;
}

std::istream& operator>>(std::istream& is, std::string& text)
{
    std::string str;
    while (!is.eof())
    {
        getline(is, str);
         text+= str+' ';
    }
    return is;
}

int main()
{
    setlocale(LC_ALL, "ru");
    std::vector<Student> v;
    int a;
    std::cout << "Введите кольво студентов" << std::endl;
    std::cin >> a;
    for (int i = 0; i < a; i++) {
        Student b;
        v.push_back(b);
    }
    baza(v);
    std::string myfile = "Myfile.txt";
    std::fstream  fs;
    fs.open(myfile, std::ios::out);
    if (!fs.is_open())
    {
        std::cout << "Ошибка" << std::endl;
    }
    else {
        int vvod=1;
        std::cout << "Файл открылся" << std::endl;
        std::cout << std::endl;
        int z=0;
        if (vvod == 1) {
                for (int i = 0; i < v.size(); i++) {
                    fs << v[i].FIO << std::endl;
                    fs << v[i].kol << std::endl;
                    for (int t = 0; t < v[i].dis.size(); t++) {
                        fs << v[i].dis[t].ocenka << std::endl;
                        fs<< v[i].dis[t].predmet << std::endl;
                    }
                }
        }
    }
    fs.close();

    fs.open(myfile, std::ios::in);
    if (!fs.is_open())
    {
        std::cout << "Ошибка" << std::endl;
    }
    else {
        std::string text2;
        int vvod2 = 2;
        std::cout << "Файл открылся" << std::endl;
        std::cout << std::endl;
        int z = 0;
        if (vvod2 == 2) {
            fs >> text2;
            std::cout << text2;
        }
    }
    fs.close();

    std::string myfile2 = "Myfile2.txt";
    std::fstream  fs2;
    fs2.open(myfile2, std::ios::out|std::ios::binary);
    if (!fs2.is_open())
    {
        std::cout << "Ошибка" << std::endl;
    }
    else {
        int vvod3 = 1;
        std::cout << "Файл открылся" << std::endl;
        std::cout << std::endl;
        int z = 0;
        if (vvod3 == 1) {
            for (int i = 0; i < v.size(); i++) {
                fs2 << v[i].FIO << std::endl;
                fs2 << v[i].kol << std::endl;
                for (int t = 0; t < v[i].dis.size(); t++) {
                    fs2 << v[i].dis[t].ocenka << std::endl;
                    fs2 << v[i].dis[t].predmet << std::endl;
                }
            }
        }
    }
    fs2.close();

    fs2.open(myfile2, std::ios::in|std::ios::binary);
    if (!fs2.is_open())
    {
        std::cout << "Ошибка" << std::endl;
    }
    else {
        std::string text3;
        int vvod4 = 2;
        std::cout << "Файл открылся" << std::endl;
        std::cout << std::endl;
        if (vvod4 == 2) {
            fs2 >> text3;
            std::cout << text3;
        }
    }
    fs2.close();
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
