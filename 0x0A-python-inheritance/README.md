# 0x0A Python - Inheritance

## Overview

This project focuses on the concept of inheritance in Python, showcasing how classes can inherit attributes and methods from other classes. The tasks aim to reinforce the understanding of inheritance, method overriding, and the creation of custom classes in Python.

## Task List

### Task 0: Lookup

Write a function that returns the list of available attributes and methods of an object.

- **Prototype:** `def lookup(obj):`
- Returns a list object.
- You are not allowed to import any module.

### Task 1: My list

Write a class `MyList` that inherits from `list`.

- Public instance method: `def print_sorted(self):` that prints the list, but sorted (ascending sort).
- You can assume that all the elements of the list will be of type `int`.
- You are not allowed to import any module.

### Task 2: Exact same object

Write a function that returns `True` if the object is exactly an instance of the specified class; otherwise `False`.

- **Prototype:** `def is_same_class(obj, a_class):`
- You are not allowed to import any module.

### Task 3: Same class or inherit from

Write a function that returns `True` if the object is an instance of, or if the object is an instance of a class that inherited from, the specified class; otherwise `False`.

- **Prototype:** `def is_kind_of_class(obj, a_class):`
- You are not allowed to import any module.

### Task 4: Only sub class of

Write a function that returns `True` if the object is an instance of a class that inherited (directly or indirectly) from the specified class; otherwise `False`.

- **Prototype:** `def inherits_from(obj, a_class):`
- You are not allowed to import any module.

### Task 5: Geometry module

Write an empty class `BaseGeometry`.

- You are not allowed to import any module.

### Task 6: Improve Geometry

Write a class `BaseGeometry` (based on 5-base_geometry.py).

- Public instance method: `def area(self):` that raises an Exception with the message `area() is not implemented`.
- You are not allowed to import any module.

### Task 7: Integer validator

Write a class `BaseGeometry` (based on 6-base_geometry.py).

- Public instance method: `def area(self):` that raises an Exception with the message `area() is not implemented`.
- Public instance method: `def integer_validator(self, name, value):` that validates `value`.
  - You can assume `name` is always a string.
  - If `value` is not an integer, raise a `TypeError` exception with the message `<name> must be an integer`.
  - If `value` is less or equal to 0, raise a `ValueError` exception with the message `<name> must be greater than 0`.
- You are not allowed to import any module.

### Task 8: Rectangle

Write a class `Rectangle` that inherits from `BaseGeometry` (7-base_geometry.py).

- Instantiation with width and height: `def __init__(self, width, height):`
  - Width and height must be private. No getter or setter.
  - Width and height must be positive integers, validated by `integer_validator`.

### Task 9: Full rectangle

Write a class `Rectangle` that inherits from `BaseGeometry` (7-base_geometry.py).

- Instantiation with width and height: `def __init__(self, width, height):`
  - Width and height must be private. No getter or setter.
  - Width and height must be positive integers validated by `integer_validator`.
  - The `area()` method must be implemented.
  - `print()` should print, and `str()` should return, the following rectangle description: `[Rectangle] <width>/<height>`.

### Task 10: Square #1

Write a class `Square` that inherits from `Rectangle` (9-rectangle.py).

- Instantiation with size: `def __init__(self, size):`
  - Size must be private. No getter or setter.
  - Size must be a positive integer, validated by `integer_validator`.
  - The `area()` method must be implemented.

### Task 11: Square #2

Write a class `Square` that inherits from `Rectangle` (9-rectangle.py). (task based on 10-square.py).

- Instantiation with size: `def __init__(self, size):`
  - Size must be private. No getter or setter.
  - Size must be a positive integer, validated by `integer_validator`.
  - The `area()` method must be implemented.
  - `print()` should print, and `str()` should return, the square description: `[Square] <width>/<height>`.

### Task 12: My integer (Advanced)

Write a class `MyInt` that inherits from `int`.

- `MyInt` is a rebel. `MyInt` has `==` and `!=` operators inverted.
- You are not allowed to import any module.

### Task 13: Can I? (Advanced)

Write a function that adds a new attribute to an object if it’s possible.

- Raise a `TypeError` exception, with the message `can't add new attribute` if the object can’t have a new attribute.
- You are not allowed to use try/except.
- You are not allowed to import any module.

## How to Run

To test each class and function, run the corresponding test file in the tests directory. For example:

```bash
python3 -m unittest tests.0-lookup_test

