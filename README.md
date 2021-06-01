# sort_smart

School 21 project <br>
Creating an effective sorting alghoritm

## Status

IN PROGRESS

## Description

We have at our disposal a set of int values, 2 stacks and a set of
instructions to manipulate both stacks. The goal of the project is to write two programs, one - for take and execute instructions, another - for calculate and display the list of those instructions.

### Allowed instructions

<table>
  <tr>
    <td> <b>sa</b> </td> <td> swap the first 2 elements at the top of stack a </td>
  </tr>
  <tr>
    <td> <b>sb</b> </td> <td> swap the first 2 elements at the top of stack b </td>
  </tr>
  <tr>
    <td> <b>ss</b> </td> <td> a and sb at the same time </td>
  </tr>
  <tr>
    <td> <b>pa</b> </td> <td> take the first element at the top of b and put it at the top of a </td>
  </tr>
  <tr>
    <td> <b>pb</b> </td> <td> stake the first element at the top of a and put it at the top of b </td>
  </tr>
  <tr>
    <td> <b>ra</b> </td> <td> shift up all elements of stack a by 1 </td>
  </tr>
  <tr>
    <td> <b>rb</b> </td> <td> shift up all elements of stack b by 1 </td>
  </tr>
  <tr>
    <td> <b>rr</b> </td> <td> ra and rb at the same time </td>
  </tr>
  <tr>
    <td> <b>rra</b> </td> <td> shift down all elements of stack a by 1 </td>
  </tr>
  <tr>
    <td> <b>rrb</b> </td> <td> shift down all elements of stack b by 1 </td>
  </tr>
  <tr>
    <td> <b>rrr</b> </td> <td> rra and rrb at the same time </td>
  </tr>
</table>

### checker

This program takes as arguments the stack <b>a</b> formatted as a list of integers. Then checker waitd and reads instructions on the standard input. Once all the instructions have been read, checker executes them on the integer arguments received. If after executing those instructions, stack <b>a</b> is actually sorted and <b>b</b> is empty, then checker displays <b>OK</b> on the standard output. Otherwise checker displays <b>KO</b> on the standard output.

### sort_smart

This program takes as arguments the stack <b>a</b> formatted as a list of integers and displays the smallest list of instructions possible to sort the stack <b>a</b>.

## Installation

    git clone --recurse-submodules https://github.com/hgrranzi/sort_smart.git
    ./run.sh


## Getting started

to run sort_smart:

    ./sort_smart 3 2 1 0
    pb
    sa
    rra
    pa
    ra

to run checker:

    ./checker 3 2 1 0
    pb
    sa
    rra
    pa
    ra
    OK

to run both:

    ./sort_smart 3 2 1 0 | ./checker 3 2 1 0
    OK
    ARG="3 2 1 0"; ./push_swap $ARG | ./checker_OS $ARG
    OK

## Visualization

To get the visualization run the checker program with flag <b>-v</b>:

    ./sort_smart 3 2 1 0 | ./checker -v 3 2 1 0

![demo](https://github.com/hgrranzi/sort_smart/blob/main/pic/sort_smart.gif)

Keyboard control

<ul>
  <li><b>P</b>      pause</li>
  <li><b>→</b>      move one step forward</li>
  <li><b>Space</b>  play</li>
  <li><b>↓</b>      slow down</li>
  <li><b>↑</b>      accelerate</li>
  <li><b>Esc</b>    exit</li>
</ul>
