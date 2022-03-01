struct Movebale {
    Movebale() = default;
    Movebale(Movebale&& m) {
        a = m.a;
        m.a = nullptr;
    }

private:
    int* a;
};

int main() {
    Movebale a;
    Movebale b(std::move(a)); // универсальная ссылка
}
