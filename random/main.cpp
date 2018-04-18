//#include "singleton.h"
#include "singleton_crtp.cpp"
int main()
{
        A *a = A::Instance();
            A *aa= A::Instance();

                B *b = B::Instance();

                    float f=0.00001;
                        std::cout<<f<<std::endl;
}

