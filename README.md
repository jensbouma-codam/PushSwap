# Codam PushSwap 😃

![GitHub](https://img.shields.io/github/license/jensbouma/Codam-PushSwap)
![GitHub last commit](https://img.shields.io/github/last-commit/jensbouma/Codam-PushSwap)

This project is an implementation of the PushSwap sorting algorithm for the Codam curriculum. It aims to sort a stack of numbers using a limited set of operations.

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Usage](#usage)
- [Installation](#installation)
- [Contributing](#contributing)
- [License](#license)

## Description

The PushSwap algorithm is designed to sort a stack of numbers using two stacks, called Stack A and Stack B. It employs a combination of specific push, swap, and rotate operations to manipulate the stacks and achieve a sorted order.

This project provides an implementation of the PushSwap algorithm in C, along with a command-line interface for running the program.

## Features

- Sorting algorithm based on the PushSwap method.
- Command-line interface for running the program.

## Usage

To use this project, follow these steps:

1. Clone the repository using the following command:
   ```
   git clone https://github.com/jensbouma/Codam-PushSwap.git
   ```
2. Change into the project directory:
   ```
   cd Codam-PushSwap
   ```
3. Compile the program by running the make command:
   ```
   make
   ```
   This will generate an executable file named `push_swap` it to the `/bin` directory.
4. Run the PushSwap program with a list of numbers to sort. For example:
   ```
   ./bin/push_swap 5 2 8 3
   ```
   This will display the sequence of operations required to sort the numbers.

## Installation

To install this project, make sure you have the following prerequisites:

- A C compiler that supports C99 or later.
- GNU Make.

Follow the [Usage](#usage) instructions to clone the repository and compile the program.

## Contributing

Contributions to this project are welcome. If you find any issues or have suggestions for improvements, feel free to open an issue or submit a pull request on the GitHub repository.

## License

This project is licensed under the [MIT License](https://github.com/jensbouma/Codam-PushSwap/LICENSE). See the LICENSE file for more details.
