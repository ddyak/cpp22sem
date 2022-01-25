struct Node {
    T value;
    Node* prev;
};

void ReverseList(Node* head) {
    if (head) {
        return;
    }

    Node* prev = head->prev;
    Node* prev_prev = prev->prev;
    head->prev = nullptr;

    while (prev_prev) {
        head->prev = ; //
        prev->prev = head;

        head = prev;
        prev = prev_prev;
        prev_prev = prev_prev->prev;
    }

}

// todo исправить
