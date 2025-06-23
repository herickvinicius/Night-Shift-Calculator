
# Night Shift Calculator

A small C program to calculate worked hours—including night-shift calculation, overtime, and negative hours—based on clock-in/out times.

## 🧰 Features
- Calculates total hours worked per shift.
- Automatically handles overnight shifts (crossing midnight).
- Computes negative hours (if finish time is before start time).
- Simple, console-based tool with no external dependencies.

## 🧪 Requirements
- GCC (or any ISO C99-compatible compiler)

## 🚀 Build & Run
Compile the source code:
```bash
gcc -std=c99 -Wall -o night_shift_calculator night_shift_calculator.c -lm
````

Run the executable:

```bash
./night_shift_calculator
```

You’ll be prompted to enter a start time and finish time of both work shift and interval considered as 'Night Hours' IN MINUTES (e.g., `22:00 06:00` will be 1320 and 360), and the program will output:

* Total hours worked (interval in minutes)
* Night-shift hours (based on your shift definition, e.g., from 1320 to 300)
* Any negative hours if applicable

## 🛠️ Usage Example

```
Enter start time (Minutes): 1080
Enter end time (Minutes): 360

Enter night hours start time (Minutes): 1320
Enter end time (Minutes): 300

Do you want to calculate with Night Factor? [y/n]

Worked hours: 420
Night-shift hours: 480
```

## 📦 Files

* `night_shift_calculator.c` – Main source code.


## 🦶 Next Steps

* Accept hour format as input.
* Rethink the 'calculateNightFactor' function.


## 🤝 Contributing

Contributions and improvements are welcome:

1. Fork the repo
2. Create a new branch for your feature or fix
3. Commit your changes with clear messages
4. Open a Pull Request for review

## 📄 License

This project is not licensed. Do whatever you want with it.

---
