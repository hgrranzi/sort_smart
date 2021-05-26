# sort_smart

School 21 project <br>
Creating alghoritms

## Status

IN PROGRESS

## Description

We have at our disposal a set of int values, 2 stacks and a set of
instructions to manipulate both stacks. The goal of the project is to write two programs, one - for take and execute instructions, another - for calculate and display the list of those instructions.

### checker

This program takes as arguments the stack <b>a</b> formatted as a list of integers. Then checker wait and read instructions on the standard input.
Once all the instructions have been read, checker executes them on the stack received as an argument. If after executing those instructions, stack <b>a</b>
is actually sorted and <b>b</b> is empty, then checker displays <b>OK</b> on the standard output. Otherwise checker displays <b>KO</b> on the standard output.

<table>
  <tr>
    <td> <b>sa</b> </td> <td> swap the first 2 elements at the top of stack a </td>
    <td> <b>sb</b> </td> <td> swap the first 2 elements at the top of stack b </td>
    <td> <b>ss</b> </td> <td> a and sb at the same time </td>
    <td> <b>pa</b> </td> <td> take the first element at the top of b and put it at the top of a </td>
    <td> <b>pb</b> </td> <td> stake the first element at the top of a and put it at the top of b </td>
    <td> <b>ra</b> </td> <td> shift up all elements of stack a by 1 </td>
    <td> <b>rb</b> </td> <td> shift up all elements of stack b by 1 </td>
    <td> <b>rr</b> </td> <td> ra and rb at the same time </td>
    <td> <b>rra</b> </td> <td> shift down all elements of stack a by 1 </td>
    <td> <b>rrb</b> </td> <td> shift down all elements of stack b by 1 </td>
    <td> <b>rrr</b> </td> <td> rra and rrb at the same time </td>
  </tr>
</table>

### sort_smart

This program takes as arguments the stack <b>a</b> formatted as a list of integers and displays the smallest list of instructions possible to sort the stack <b>a</b>.

## Visualization

![demo](https://github.com/hgrranzi/sort_smart/blob/main/pic/sort_smart.gif)