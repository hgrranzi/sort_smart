# sort_smart

School 21 project <br>
Creating alghoritms

## Status

IN PROGRESS

## Description

Checker <br>
This programm takes as arguments the stack <b>a</b> formatted as a list of integers. Then checker wait and read instructions on the standard input.
Once all the instructions have been read, checker executes them on the stack received as an argument. If after executing those instructions, stack <b>a</b>
is actually sorted and <b>b</b> is empty, then checker displays <b>OK</b> on the standard output. Otherwise checker displays <b>KO</b> on the standard output.

<table>
  <tr>
    <td> <b>Supported operations</b> </td> <td> sa: swap the first 2 elements at the top of stack a <br>
                                                sb: swap the first 2 elements at the top of stack b <br>
                                                ss: sa and sb at the same time <br>
                                                pa: take the first element at the top of b and put it at the top of a <br>
                                                pb: take the first element at the top of a and put it at the top of b <br>
                                                ra: shift up all elements of stack a by 1 <br>
                                                rb: shift up all elements of stack b by 1 <br>
                                                rr: ra and rb at the same time <br>
                                                rra: shift down all elements of stack a by 1 <br>
                                                rrb: shift down all elements of stack b by 1 <br>
                                                rrr: rra and rrb at the same time </td>
  </tr>
</table>

## Visualization

![demo](https://github.com/hgrranzi/sort_smart/blob/main/pic/sort_smart.gif)