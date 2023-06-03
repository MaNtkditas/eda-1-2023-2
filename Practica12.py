import matplotlib.pyplot as plt
import random

times_insertion = 0
times_quick = 0
times_merge = 0

def insertionSort(arr):
    global times_insertion
    for i in range(1, len(arr)):
        times_insertion += 1
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            times_insertion += 1
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def partition(arr, low, high):
    global times_quick
    i = low - 1
    pivot = arr[high]
    for j in range(low, high):
        times_quick += 1
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quickSort(arr, low, high):
    global times_quick
    if low < high:
        pi = partition(arr, low, high)
        quickSort(arr, low, pi - 1)
        quickSort(arr, pi + 1, high)

def mergeSort(arr):
    global times_merge
    if len(arr) > 1:
        mid = len(arr) // 2
        left = arr[:mid]
        right = arr[mid:]

        mergeSort(left)
        mergeSort(right)

        i = j = k = 0

        while i < len(left) and j < len(right):
            times_merge += 1
            if left[i] < right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1

        while i < len(left):
            times_merge += 1
            arr[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            times_merge += 1
            arr[k] = right[j]
            j += 1
            k += 1

TAM = 101
eje_x = list(range(1, TAM, 1))
eje_y_insertion = []
eje_y_quick = []
eje_y_merge = []

for num in eje_x:
    lista_variable = random.sample(range(0, 100), num)
    times_insertion = 0
    insertionSort(lista_variable.copy())
    eje_y_insertion.append(times_insertion)

    lista_variable = random.sample(range(0, 100), num)
    times_quick = 0
    quickSort(lista_variable.copy(), 0, len(lista_variable) - 1)
    eje_y_quick.append(times_quick)

    lista_variable = random.sample(range(0, 100), num)
    times_merge = 0
    mergeSort(lista_variable.copy())
    eje_y_merge.append(times_merge)

fig, ax = plt.subplots(facecolor='w', edgecolor='k')

ax.plot(eje_x, eje_y_insertion, marker="o", color="b", linestyle='-', label="Insertion Sort")
ax.plot(eje_x, eje_y_quick, marker="o", color="r", linestyle='-', label="Quick Sort")
ax.plot(eje_x, eje_y_merge, marker="o", color="g", linestyle='-', label="Merge Sort")

ax.set_xlabel("x")
ax.set_ylabel("Comparisons")
ax.grid(True)
ax.legend()

plt.title("Comparison of Sorting Algorithms")
plt.show()
