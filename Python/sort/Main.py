import Heap
import Sort
import random

def main():
    h = Heap.Heap()

    # Test Heap sort for correctness
    x = [random.randint(1, 1000) for i in range(10)]

    x1 = sorted(x)
    x2 = Sort.heapsort(x)

    print x1 == x2

    # Print the n smallest elements
    h.heapify(x)
    print h.nsmallest(5)

if __name__ == '__main__':
    main()
