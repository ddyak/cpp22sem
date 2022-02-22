// image_processor.cpp / or main.cpp
// BMPReader.h / .cpp + test
// BMPWriter.h / .cpp + test
// Filters.h / .cpp   + test
// Getopt.h / .cpp    + test
// FilterContoller.h / .cpp + test

// CMakeLists.txt
// include/*.h              // #include "inlcude/Filters.h"
// src/*.cpp + main.cpp
// tests/*.cpp
// examples/original.png
// examples/negative.png
// examples/blur.png
// readme.md

// hex visualize - xxd

struct FilterOptions {
    std::string filter_name;
    std::vector<std::string> params;
};

struct ParsedInput {
    std::string input_file;
    std::string output_file;
    std::vector<FilterOptions> filter_options;
};

ParsedInput ParseCommandLine(int argc, char** argv) { return {}; }

class BMPReader {
public:
    BMPReader(const std::strign& filename);
    void read();
    void close();
    Image output_image() const;
private:
    // ifstream // opened file
};

class ImageProcessor {
    std::vector<Filter*> filters;

public:
    ImageProcessor(const FilterOptions& filter_options) {
//        FilterCrop a;
//        filters.push_back(&a); not working

        filters.push_back(new FilterCrop());
        filters.push_back(new FilterNeg());
        filters.push_back(new FilterCrop());
        filters.push_back(new FilterNeg());
    }

    ApplyFilters(Image& image) {
        for (const auto& filter : filters) {
            filter->Apply(image);
        }
    }
};

int main(int argc, char** argv) {
    const auto parsed_input = ParseCommandLine(argc, argv);

    BMPReader bmp_reader(parsed_input.input_file);
    bmp_reader.read();
    bmp_reader.close();
    Image image = bmp_reader.output_image();

    ImageProcessor image_processor(parsed_input.filter_options);
    image_processor.ApplyFilters(image);

    BMRWrite bmp_writer(parsed_input.output_file);
    bmp_writer.write(image);
    bmr_write.close();

    return 0;
}

