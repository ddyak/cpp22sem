// .h
void Search(); // interface

struct A; // declaration;
struct B;

sturct A { // definition;
public:


private:
    B* b;
};

struct B {
    A* a;
}

// .cpp
void foo(); // forward-declaration
void bar(); // forward-declaration

void foo() { // definition
    bar();
}

void bar() {
    foo();
}


int main() {
    return 0;
}
