#!/usr/bin/python3
def complex_delete(my_dict, value):
    copy_dict = my_dict.copy()
    for k, v in copy_dict.items():
        if value == v:
            my_dict.pop(k)
    return my_dict
