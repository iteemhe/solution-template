#!/usr/bin/env python3
# pylint: disable=all


def main():
    # print 10 random number from -100 to -100 and it's sorted in ascending order
    import random

    lst = [random.randint(-10000, 10000) for i in range(1000)]
    print(lst)
    lst.sort()
    print(lst)


if __name__ == "__main__":
    main()
