#include "phus.h"
#include "SequenceReader.h"
#include <string>
#include <iostream>

#define DEFAULT_MIN_UTILITY_THRESHOLD 80

void show_usage() {

    std::cout << " ********************** PHUS algorithm *********************" << std::endl;
    std::cout
            << "Implemented program discovers high utility sequential patterns in given dataset and specified by user minimum utility threshold. \n"
               "The dataset is expected to be delivered in a file where each line contains a sequence. \n"
               "The first number is the total number of itemsets in this sequence. After that, each itemset is displayed, \nfirst by the number of items in this"
               "itemset, then followed by the items in that itemset. Cardinality of items is randomly distributed, so is the profit table. \n \n";
    std::cout << "Expected parameters: " << std::endl;
    std::cout << "-h help" << std::endl;;
    std::cout << "-i file with input data" << std::endl;
    std::cout << "-t minimum utility threshold" << std::endl;
    std::cout << "-m maximum pattern length (default: 0 - no maximum length)" << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        show_usage();
        return 1;
    }

    unsigned minimum_utility_threshold = DEFAULT_MIN_UTILITY_THRESHOLD;

    unsigned max_length = 0;
    std::string input_file;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-h") {
            show_usage();
        } else if (arg == "-i") {
            if (i + 1 < argc) {
                input_file = argv[++i];
            } else {
                std::cout << "input file not specified" << std::endl;
                return 1;
            }
        } else if (arg == "-t") {
            if (i + 1 < argc) {
                minimum_utility_threshold = std::stoi(argv[++i]);
            } else {
                std::cout << "minimum utility threshold not specified" << std::endl;
                return 1;
            }
        } else if (arg == "-m") {
            if (i + 1 < argc) {
                max_length = std::stoi(argv[++i]);
            } else {
                std::cout << "maximum pattern length not specified" << std::endl;
            }
        } else {
            std::cout << "invalid parameter " << argv[i] << std::endl;
            return 1;
        }
    }

    if (input_file.empty()){
        std::cout << "input file not specified" << std::endl;
        return 1;
    }

    SequenceReader sequence_reader;
    std::pair<SDB, ProfitTable> dataset = sequence_reader.prepare_data_for_sequence_mining(input_file);
    std::vector<Pattern> found_patterns = phus(dataset.first, dataset.second, minimum_utility_threshold, max_length);
    std::cout << "RESULT\n";
    for (const auto &pat: found_patterns)
        std::cout << pat << "\n";

    return 0;
}

