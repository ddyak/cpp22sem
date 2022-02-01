struct Document {
    Document() {}; // default constructor
    Document(std::string_view filename) {
        file.open(filename);
    }

    Document(const Document& doc) {
        file = doc.file;
        relevance = doc.relevance;
    }

    ~Document() {
        if (file.open()) {
            file.close();
        }
    }

    std::string_view document_text;
    std::vector<std::string_view> words;
    double relevance = 0;

    File file;
};

class Index {
    std::string_view text;
    std::vector<Document> documents;
};

class SearchEngine {
public:
    std::vector<std::string_view>& Search(std::string_view query, std::size_t doc_cnt=10) const {
        Document a("file.txt");
        return {};
    };

    void DoPreprocessIndex();

private:
    Index index;
};


int main() {
    SearchEngine engine;
    Document a;

    auto top_documents = engine.Search("котик");
}
