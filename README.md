# Generic Ring Buffer (C++ Templates)

A robust, type-safe, and static-memory **Circular Buffer** implementation designed for Embedded C++ applications.

Unlike standard C implementations, this project leverages **C++ Templates** to handle any data type (`uint8_t`, `float`, `structs`) with a single codebase, while strictly avoiding dynamic memory allocation (`malloc`/`new`) to prevent heap fragmentation.

## 🚀 Key Features

* **Template-Based Generics:** One driver supports multiple data types (e.g., storing GPS coordinates as `int` or Temperature data as `float`).
* **Object-Oriented Design (OOP):** Encapsulates buffer logic, head/tail pointers, and status flags within a clean C++ Class structure.
* **Zero-Heap Usage:** Uses stack/static arrays determined at compile-time via non-type template parameters (`<typename T, int SIZE>`).
* **Safe & Efficient:** Includes boundary checks and boolean return types for error handling, optimized for O(1) performance.

## 🛠️ Technical Concepts

* **C++ Templates:** For creating generic, reusable drivers.
* **Encapsulation:** Protecting critical pointers (`head`, `tail`) from external corruption.
* **Reference Passing:** Using `&data` for efficient read operations without copying large objects.
* **Initialization Lists:** Efficient constructor usage for member initialization.

## 💻 Usage Example

```cpp
// Create a buffer for 100 float values (e.g., Sensor Data)
RingBuffer<float, 100> sensorBuf;

// Write Data
sensorBuf.Write(24.5f);

// Read Data
float val;
if (sensorBuf.Read(val)) {
    // Process val...
}

## AUTHOR
Ahmet Emin Satilmis Mathematics Engineering Student at Yıldız Technical University Focus areas: Embedded Systems, C/C++, Real-Time Operating Systems
