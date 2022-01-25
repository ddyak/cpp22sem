struct Node {
    int value;
    Node* prev;
    Node* next;
};

void InsertNode(Node* node, Node* inserted_node) {
    if (node) {
        return;
    }

    Node* prev_node = node->prev;

    if (prev_node) {
        prev_node->next = inserted_node;
    }

    inserted_node->prev = prev_node;
    inserted_node->next = node;
    node->prev = inserted_node;
}

int main() {
    Node head = {
        .value = 0,
        .next = nullptr,
        .prev = nullptr
    };

    // push_after_node node

    Node node = {
        .value = 1,
        .next = &head,
        .prev = nullptr;
    };

    head.prev = &node;

    Node mid_node = {
        .value = 1337,
        .next = nullptr,
        .prev = nulltpr
    };

    InsertNode(&head, &mid_node);

    return 0;
}

