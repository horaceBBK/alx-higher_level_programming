#!/usr/bin/python3
def weight_average(my_list=[]):
    if not my_list:
        return 0

    total_num = 0
    total_den = 0

    for tup in my_list:
        total_num += tup[0] * tup[1]
        total_den += tup[1]

    return (total_num / total_den)
