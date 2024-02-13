# 0x0B Python - Input/Output

## Overview

This project focuses on input/output operations in Python, including reading from and writing to files, working with JSON data, and processing file contents. Each task provides an opportunity to practice file handling, serialization, and deserialization, as well as working with data structures and objects in Python.


## Tests :heavy_check_mark:

* [tests/test_models](./tests/test_models): Folder containing the following independently-developed test files:
  * [test_base.py](./tests/test_models/test_base.py)
  * [test_rectangle.py](./tests/test_models/test_rectangle.py)
  * [test_square.py](./tests/test_models/test_square.py)

## Classes :cl:

### Base
Represents the "base" class for all other classes in the project. Includes:

* Private class attribute `__nb_objects = 0`.
* Public instance attribute `id`.
* Class constructor `def __init__(self, id=None):`
  * If `id` is `None`, increments `__nb_objects` and assigns its value to the public instance attribute `id`.
  * Otherwise, sets the public instance attribute `id` to the provided `id`.
* Static method `def to_json_string(list_dictionaries):` that returns the JSON string serialization of a list of dictionaries.
  * If `list_dictionaries` is `None` or empty, returns the string `"[]"`.
* Class method `def save_to_file(cls, list_objs):` that writes the JSON serialization of a list of objects to a file.
  * The parameter `list_objs` is expected to be a list of `Base`-inherited instances.
  * If `list_objs` is `None`, the function saves an empty list.
  * The file is saved with the name `<cls name>.json` (ie. `Rectangle.json`)
  * Overwrites the file if it already exists.
* Static method `def from_json_string(json_string):` that returns a list of objects deserialized from a JSON string.
  * The parameter `json_string` is expected to be a string representing a list of dictionaries.
  * If `json_string` is `None` or empty, the function returns an empty list.
* Class method `def create(cls, **dictionary):` that instantiates an object with provided attributes.
  * Instantiates an object with the attributes given in `**dictionary`.
* Class method `def load_from_file(cls):` that returns a list of objects instantiated from a JSON file.
  * Reads from the JSON file `<cls name>.json` (ie. `Rectangle.json`)
  * If the file does not exist, the function returns an empty list.
* Class method `def save_to_file_csv(cls, list_objs):` that writes the CSV serialization of a list of objects to a file.
  * The parameter `list_objs` is expected to be a list of `Base`-inherited instances.
  * If `list_objs` is `None`, the function saves an empty list.
  * The file is saved with the name `<cls name>.csv` (ie. `Rectangle.csv`)
  * Serializes objects in the format `<id>,<width>,<height>,<x>,<y>` for `Rectangle` objects and `<id>,<size>,<x>,<y>` for `Square` objects.
* Class method `def load_from_file_csv(cls):` that returns a list of objects instantiated from a CSV file.
  * Reads from the CSV file `<cls name>.csv` (ie. `Rectangle.csv`)
  * If the file does not exist, the function returns an empty list.
* Static method `def draw(list_rectangles, list_squares):` that draws `Rectangle` and `Square` instances in a GUI window using the `turtle` module.
  * The parameter `list_rectangles` is expected to be a list of `Rectangle` objects to print.
  * The parameter `list_squares` is expected to be a list of `Square` objects to print.

### Rectangle

Represents a rectangle. Inherits from `Base` with:

* Private instance attributes `__width`, `__height`, `__x`, and `__y`.
  * Each private instance attribute features its own getter/setter.
* Class constructor `def __init__(self, width, height, x=0, y=0, id=None):`
  * If either of `width`, `height`, `x`, or `y` is not an integer, raises a `TypeError` exception with the message `<attribute> must be an integer`.
  * If either of `width` or `height` is >= 0, raises a `ValueError` exception with the message `<attribute> must be > 0`.
  * If either of `x` or `y` is less than 0, raises a `ValueError` exception with the message `<attribute> must be >= 0`.
* Public method `def area(self):` that returns the area of the `Rectangle` instance.
* Public method `def display(self):` that prints the `Rectangle` instance to `stdout` using the `#` character.
  * Prints new lines for the `y` coordinate and spaces for the `x` coordinate.
* Overwrite of `__str__` method to print a `Rectangle` instance in the format `[Rectangle] (<id>) <x>/<y>`.
* Public method `def update(self, *args, **kwargs):` that updates an instance of a `Rectangle` with the given attributes.
  * `*args` must be supplied in the following order:
    * 1st: `id`
    * 2nd: `width`
    * 3rd: `height`
    * 4th: `x`
    * 5th: `y`
  * `**kwargs` is expected to be a double pointer to a dictionary of new key/value attributes to update the `Rectangle` with.
  * `**kwargs` is skipped if `*args` exists.
* Public method `def to_dictionary(self):` that returns the dictionary representation of a `Rectangle` instance.

### Square

Represents a square. Inherits from `Rectangle` with:

* Class constructor `def __init__(self, size, x=0, y=0, id=None):`
  * The `width` and `height` of the `Rectangle` superclass are assigned using the value of `size`.
* Overwrite of `__str__` method to print a `Square` instance in the format `[Square] (<id>) <x>/<y>`.
* Public method `def update(self, *args, **kwargs):` that updates an instance of a `Square` with the given attributes.
  * `*args` must be supplied in the following order:
    * 1st: `id`
    * 2nd: `size`
    * 3rd: `x`
    * 4th: `y`
  * `**kwargs` is expected to be a double pointer to a dictoinary of new key/value attributes to update the `Square` with.
  * `**kwargs` is skipped if `*args` exists.
* Public method `def to_dictionary(self):` that returns the dictionary representation of a `Square`.


## Task List

### Task 0: Read file

Write a function that reads a text file (UTF8) and prints it to stdout.

- **Prototype:** `def read_file(filename="")`
- You must use the with statement.
- You don’t need to manage file permission or file doesn't exist exceptions.
- You are not allowed to import any module.

### Task 1: Write to a file

Write a function that writes a string to a text file (UTF8) and returns the number of characters written.

- **Prototype:** `def write_file(filename="", text="")`
- You must use the with statement.
- You don’t need to manage file permission exceptions.
- Your function should create the file if it doesn’t exist.
- Your function should overwrite the content of the file if it already exists.
- You are not allowed to import any module.

### Task 2: Append to a file

Write a function that appends a string at the end of a text file (UTF8) and returns the number of characters added.

- **Prototype:** `def append_write(filename="", text="")`
- If the file doesn’t exist, it should be created.
- You must use the with statement.
- You don’t need to manage file permission or file doesn't exist exceptions.
- You are not allowed to import any module.

### Task 3: To JSON string

Write a function that returns the JSON representation of an object (string).

- **Prototype:** `def to_json_string(my_obj)`
- You don’t need to manage exceptions if the object can’t be serialized.

### Task 4: From JSON string to Object

Write a function that returns an object (Python data structure) represented by a JSON string.

- **Prototype:** `def from_json_string(my_str)`
- You don’t need to manage exceptions if the JSON string doesn’t represent an object.

### Task 5: Save Object to a file

Write a function that writes an Object to a text file, using a JSON representation.

- **Prototype:** `def save_to_json_file(my_obj, filename)`
- You must use the with statement.
- You don’t need to manage exceptions if the object can’t be serialized.
- You don’t need to manage file permission exceptions.

### Task 6: Create object from a JSON file

Write a function that creates an Object from a “JSON file”.

- **Prototype:** `def load_from_json_file(filename)`
- You must use the with statement.
- You don’t need to manage exceptions if the JSON string doesn’t represent an object.
- You don’t need to manage file permissions / exceptions.

### Task 7: Load, add, save

Write a script that adds all arguments to a Python list, and then save them to a file.

- You must use your function `save_to_json_file` from 5-save_to_json_file.py.
- You must use your function `load_from_json_file` from 6-load_from_json_file.py.
- The list must be saved as a JSON representation in a file named add_item.json.
- If the file doesn’t exist, it should be created.
- You don’t need to manage file permissions / exceptions.

### Task 8: Class to JSON

Write a function that returns the dictionary description with simple data structure for JSON serialization of an object.

- **Prototype:** `def class_to_json(obj)`
- obj is an instance of a Class.
- All attributes of the obj Class are serializable: list, dictionary, string, integer and boolean.
- You are not allowed to import any module.

### Task 9: Student to JSON

Write a class `Student` that defines a student.

- **Attributes:**
  - first_name
  - last_name
  - age
- **Instantiation:** `def __init__(self, first_name, last_name, age)`
- Public method `def to_json(self):` that retrieves a dictionary representation of a Student instance.

### Task 10: Student to JSON with filter

Write a class `Student` that defines a student.

- **Attributes:**
  - first_name
  - last_name
  - age
- **Instantiation:** `def __init__(self, first_name, last_name, age)`
- Public method `def to_json(self, attrs=None):` that retrieves a dictionary representation of a Student instance:
  - If `attrs` is a list of strings, only attribute names contained in this list must be retrieved.
  - Otherwise, all attributes must be retrieved.
- You are not allowed to import any module.

### Task 11: Student to disk and reload

Write a class `Student` that defines a student.

- **Attributes:**
  - first_name
  - last_name
  - age
- **Instantiation:** `def __init__(self, first_name, last_name, age)`
- Public method `def to_json(self, attrs=None):` that retrieves a dictionary representation of a Student instance:
  - If `attrs` is a list of strings, only attributes name contain in this list must be retrieved.
  - Otherwise, all attributes must be retrieved.
- Public method `def reload_from_json(self, json):` that replaces all attributes of the Student instance.
  - You can assume json will always be a dictionary.
  - A dictionary key will be the public attribute name.
  - A dictionary value will be the value of the public attribute.
- You are not allowed to import any module.

### Task 12: Pascal's Triangle

Create a function `def pascal_triangle(n):` that returns a list of lists of integers representing the Pascal’s triangle of n.

- Returns an empty list if n <= 0.
- You can assume n will be always an integer.
- You are not allowed to import any module.

### Task 13: Search and update (Advanced)

Write a function that inserts a line of text to a file, after each line containing a specific string.

- **Prototype:** `def append_after(filename="", search_string="", new_string="")`
- You must use the with statement.
- You don’t need to manage file permission or file doesn't exist exceptions.
- You are not allowed to import any module.

### Task 14: Log parsing (Advanced)

Write a script that reads stdin line by line and computes metrics.

- Input format: `<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>`.
- Each 10 lines and after a keyboard interruption (CTRL + C), prints those statistics since the beginning:
  - Total file size: File size: `<total size>` (where `<total size>` is the sum of all previous).
  - Number of lines by status code: (possible status codes: 200, 301, 400, 401, 403, 404, 405, and 500).
    - If a status code doesn’t appear, don’t print anything for this status code.
    - Format: `<status code>: <number>`.
    - Status codes should be

