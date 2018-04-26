#ifndef DISTRIBUTE_H
#define DISTRIBUTE_H

#include <vector>
#include <exception>

//Ideas for improvement:
// -Should use move semantics for rvalue arguments (but then we probably can't give strong guarantee anymore)

namespace knatten {

    //This function provides the strong exception guarantee
    template <class T>
    std::vector<std::vector<T>> distribute(const std::vector<T>& vec, size_t partitions) {
        if (partitions == 0) {
            throw std::invalid_argument("Can't distribute into 0 partitions.");
        }
        auto min_elements_per_vector = vec.size() / partitions;
        auto nof_larger_vectors = vec.size() % partitions;

        std::vector<std::vector<T>> vectors;
        vectors.reserve(partitions);
        size_t elements_taken = 0;
        for(size_t i = 0; i < partitions; i++) {
            size_t elements = (i < nof_larger_vectors ? min_elements_per_vector + 1 : min_elements_per_vector);
            vectors.emplace_back(vec.cbegin() + elements_taken, vec.cbegin() + elements_taken + elements);
            elements_taken += elements;
        }
        return vectors;
    }

}

#endif
