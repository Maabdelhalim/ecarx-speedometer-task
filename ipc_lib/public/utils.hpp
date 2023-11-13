/*
 * utils.hpp
 *
 *  Created on: Nov 5, 2023
 *      Author: Mahmoud Abdelhalim
 */

#ifndef SRC_LIBS_IPC_UTILS_HPP_
#define SRC_LIBS_IPC_UTILS_HPP_

#include <sstream>

template <typename T>

std::string toString(const T &value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}

#endif /* SRC_LIBS_IPC_UTILS_HPP_ */

