<br/>
<p align="center">
  <a href="https://github.com/rkrocha/42cursus/blob/master/subjects/00.libft.pdf">
    <img src="https://github.com/rkrocha/42cursus/blob/master/badges/libftm.png" alt="Logo" width="150" height="150">
  </a>

  <p align="center">
    A C library, the first assignment from 42's cursus.
    <br/>
    <br/>
  </p>
</p>



## About The Project

C programming can be very tedious when one doesn’t have access to those highly useful standard functions. This project gives you the opportunity to re-write those functions, understand them, and learn to use them. This library will help you for all your future C projects.

For more information check out this project's [PDF](https://github.com/rkrocha/42cursus/blob/master/subjects/00.libft.pdf).

## Built With

Pure C.

## Prerequisites

* A Shell terminal
* gcc compiler
* make command

### Installation

1. Clone the repo

```sh
git clone git@github.com:rkrocha/libft.git
```

2. Compile the library

```sh
make
```

## Usage

1. Include the libft header in your program:

```c
#include "libft.h"
```

2. Call the functions you wish to use in your program, and compile it as such:

```sh
gcc <your_program>.c -I<path/to/libft_folder> -L<path/to/libft_folder> -lft
```
