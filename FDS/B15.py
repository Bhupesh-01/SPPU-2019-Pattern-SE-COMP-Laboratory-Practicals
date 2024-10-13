""" Write a python program to store second year percentage of
students in array. Write function for sorting array of floating point numbers in ascending order using merge Sort
"""
def merge_sort(arr):
    if len(arr) > 1:
        # Finding the mid of the array
        mid = len(arr) // 2

        # Dividing the array elements
        left_half = arr[:mid]
        right_half = arr[mid:]

        # Recursively sorting the left and right halves
        merge_sort(left_half)
        merge_sort(right_half)

        i = j = k = 0

        # Copy data to temp arrays L[] and R[]
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        # Checking if any element was left
        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

def print_array(arr):
    for i in range(len(arr)):
        print(f"{arr[i]:.2f}", end=" ")
    print()

# Example usage
student_percentages = [72.5, 85.3, 91.2, 78.9, 68.4, 88.0]

print("Original array:")
print_array(student_percentages)

merge_sort(student_percentages)

print("Sorted array in ascending order:")
print_array(student_percentages)
