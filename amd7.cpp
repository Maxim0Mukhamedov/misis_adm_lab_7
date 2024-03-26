//Голубев Иван, Горохова Полина, Мухамедов Максим. БПМ-22-1

#include <iostream>
#include <vector>

void init(std::vector<int>& v, const int& n) {
    for (int i = 0; i < n; i++) {
        v.push_back(std::rand()%1000);
    }
}

void surface(std::vector<int>& v, int i, const int& k) {
    int j;
    int m;
    int copy;
    copy = v[i];
    m = 2 * i;
    while (m <= k) {
        if (m==k) {
            j = m;
        } else if (v[m] > v[m + 1]) {
            j = m;
        } else {
            j = m + 1;
        }
        if (v[j] > copy) {
            v[i] = v[j];
            i = j;
            m = 2 * i;
        } else {
            break;
        }
    }
    v[i] = copy;
}

void sort(std::vector<int>& v, const int& n) {
    int i;
    int k;
    int w;
    for (int i = n/2; i >= 1; i--){
        surface(v,i,n);
    }
    for (k = n; k >= 1; k--) {
        surface(v,0,k);
        w = v[k];
        v[k] = v[0];
        v[0] = w;
    }
}


int main() {
    const int n = 15;
    std::vector<int> v;
    init(v,n);
    std::cout << "Начальный массив" << std::endl;
    for(auto i : v) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    sort(v,n);
    std:: cout << "Массив после сортировки" << std::endl;
    for(auto i : v) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}
