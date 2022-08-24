#include <iostream>
#include "vector"

std::vector<std::vector<float>> inputMatrix(std::string prompt,int sizeRow,int sizeCol){
    std::cout << prompt << std::endl;
    std::vector<std::vector<float>> a(sizeRow);
    for (int i=0;i<sizeRow;++i){
        a[i].resize(sizeCol);
        for(int k=0;k<sizeCol;++k){
            std::cin >> a[i][k];
        }
    }
    return a;
}
std::vector<float> inputVector(std::string prompt,int sizeRow){
    std::cout << prompt << std::endl;
    std::vector<float> a(sizeRow);
    for(int k=0;k<sizeRow;++k){
        std::cin >>a[k];
    }
    return a;
}

void printVector(std::vector<float> a){
    for(int i=0;i<a.size();++i){
       std::cout << a[i]<<"\n";
    }
}

std::vector<float> multiVectorToMatrix(std::vector<float> a, std::vector<std::vector<float>> b ){
    std::vector<float> c(a.size());
    float sum=0;
    for(int i=0;i<b.size();++i){
        sum=0;
        for(int k=0;k<b[i].size();++k){
            sum+=a[k]*b[i][k];
        }
        c[i]=sum;
    }
    return c;
}

int main() {
    std::vector<float> a;
    std::vector<std::vector<float>> b;
    a= inputVector("Input vector:",4);
    b= inputMatrix("Input matrix:",4,4);
    std::vector<float> c= multiVectorToMatrix(a,b);
    std::cout << "Multiplication of Matrix and Vector:" << std::endl;
    printVector(c);
}
